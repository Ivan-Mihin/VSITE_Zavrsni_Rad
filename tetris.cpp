#include "tetris.h"
#include "user_input.h"

void Tetris::initialize()
{
	board.assign(BOARD_ROWS, std::vector<int>(BOARD_COLUMNS, 0));

	fallingTetromino = director.createRandomTetromino();

	for (int i = 0; i < 6; i++)
	{
		inventory.push_back(director.createRandomTetromino());
	}

    commandMoveLeft = new CommandMoveLeft(fallingTetromino);
    commandMoveRight = new CommandMoveRight(fallingTetromino);
    commandMoveDown = new CommandMoveDown(fallingTetromino);

    tetrominoTexture.loadFromFile("Resources/Sprites/tetromino.png");
    tetrominoSprite.setTexture(tetrominoTexture);
    tetrominoSprite.setTextureRect(sf::IntRect(0, 0, TEXTURE_SIZE, TEXTURE_SIZE));

    boardTexture.loadFromFile("Resources/Sprites/board.png");
    boardSprite.setTexture(boardTexture);
    boardSprite.setPosition(220, 25);

    boardFrame.setPosition(210, 15);
    boardFrame.setSize(sf::Vector2f(380, 770));
    boardFrame.setFillColor(sf::Color::White);

    setTetrominoStartingPosition(board, fallingTetromino->getShapeMatrix(), 0, 4);

    clock.restart();
    fallInterval = 0.5f;
}

void Tetris::setTetrominoStartingPosition(std::vector<std::vector<int>> grid, std::vector<std::vector<int>> shapeMatrix, int startRow, int startColumn)
{
    std::vector<Square> squares;

    for (int i = 0; i < fallingTetromino->getShapeMatrix().size(); ++i)
    {
        for (int j = 0; j < fallingTetromino->getShapeMatrix()[i].size(); ++j)
        {
            if (fallingTetromino->getShapeMatrix()[i][j] == 1)
            {
                if (fallingTetromino->getShape() == TetrominoShape::Shape_O)
                {
                    squares.push_back(Square(j + startColumn + 1, i + startRow));
                }
                else
                {
                    squares.push_back(Square(j + startColumn, i + startRow));
                }
            }
        }
    }

    fallingTetromino->setSquares(squares);
}

bool Tetris::isValidPosition(std::vector<Square> nextPosition)
{
    for (int i = 0; i < 4; i++)
    {
        if (nextPosition[i].getX() < 0 || nextPosition[i].getX() >= BOARD_COLUMNS || nextPosition[i].getY() >= BOARD_ROWS)
        {
            return false;
        }
        else if (board[nextPosition[i].getY()][nextPosition[i].getX()])
        {
            return false;
        }
    }

    return true;
}

void Tetris::handleInput(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
        {
            std::vector<Square> nextPosition;
            nextPosition = fallingTetromino->getSquares();

            for (int i = 0; i < 4; i++)
            {
                nextPosition[i].setX(fallingTetromino->getSquares()[i].getX() - 1);
            }

            if (isValidPosition(nextPosition))
            {
                commandMoveLeft->execute();
            }

            break;
        }
        case sf::Keyboard::Right:
        {
            std::vector<Square> nextPosition;
            nextPosition = fallingTetromino->getSquares();

            for (int i = 0; i < 4; i++)
            {
                nextPosition[i].setX(fallingTetromino->getSquares()[i].getX() + 1);
            }

            if (isValidPosition(nextPosition))
            {
                commandMoveRight->execute();
            }

            break;
        }
        default:
            break;
        }
    }
}

void Tetris::update(float deltaTime)
{
    if (clock.getElapsedTime().asSeconds() >= fallInterval)
    {
        std::vector<Square> nextPosition;
        nextPosition = fallingTetromino->getSquares();

        for (int i = 0; i < 4; i++)
        {
            nextPosition[i].setY(fallingTetromino->getSquares()[i].getY() + 1);
        }

        if (isValidPosition(nextPosition))
        {
            commandMoveDown->execute();
        }
        else
        {

        }

        clock.restart();
    }
}

void Tetris::render(sf::RenderWindow& window)
{
    window.draw(boardFrame);
    window.draw(boardSprite);

    // Draw Tetromino
    for (int i = 0; i < 4; i++)
    {
        tetrominoSprite.setTextureRect(sf::IntRect((int)fallingTetromino->getColor() * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE));
        tetrominoSprite.setPosition(fallingTetromino->getSquares()[i].getX() * TEXTURE_SIZE + 220, fallingTetromino->getSquares()[i].getY() * TEXTURE_SIZE + 25);
        window.draw(tetrominoSprite);
    }

    // Draw Inventory Tetrominos
    for (int index = 0; index < inventory.size(); index++)
    {
        for (int x = 0; x < inventory[index]->getShapeMatrix().size(); ++x)
        {
            for (int y = 0; y < inventory[index]->getShapeMatrix().size(); ++y)
            {
                int offsetFromBoardX = TEXTURE_SIZE;
                int offsetFromBoardY = TEXTURE_SIZE;

                if (inventory[index]->getShapeMatrix()[y][x])
                {
                    if (inventory[index]->getShape() == TetrominoShape::Shape_O)
                    {
                        offsetFromBoardX += TEXTURE_SIZE;
                    }
                    else if (inventory[index]->getShape() == TetrominoShape::Shape_I)
                    {
                        offsetFromBoardY -= 15;
                    }
                    else
                    {
                        offsetFromBoardX += TEXTURE_SIZE / 2;
                    }

                    tetrominoSprite.setTextureRect(sf::IntRect((int)inventory[index]->getColor() * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE));
                    tetrominoSprite.setPosition(590 + offsetFromBoardX + TEXTURE_SIZE * x, 114 + offsetFromBoardY + (90 * index) + TEXTURE_SIZE * y);
                    window.draw(tetrominoSprite);
                }
            }
        }
    }
}