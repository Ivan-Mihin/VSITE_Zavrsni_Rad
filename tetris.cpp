#include "tetris.h"

void Tetris::initialize()
{
	board.assign(BOARD_ROWS, std::vector<int>(BOARD_COLUMNS, 0));

	fallingTetromino = director.createRandomTetromino();
    ghostTetromino = new Tetromino(*fallingTetromino);

	for (int i = 0; i < 6; i++)
	{
		inventory.push_back(director.createRandomTetromino());
	}

    setTetrominoStartingPosition(fallingTetromino, 0, 4);
    setTetrominoStartingPosition(ghostTetromino, 0, 4);

    commandMoveDown = new CommandMoveDown(fallingTetromino);

    tetrominoTexture.loadFromFile("Resources/Sprites/tetromino.png");
    tetrominoSprite.setTexture(tetrominoTexture);
    tetrominoSprite.setTextureRect(sf::IntRect(0, 0, TEXTURE_SIZE, TEXTURE_SIZE));

    ghostTetrominoTexture.loadFromFile("Resources/Sprites/tetromino_ghost.png");
    ghostTetrominoSprite.setTexture(ghostTetrominoTexture);
    ghostTetrominoSprite.setTextureRect(sf::IntRect(0, 0, TEXTURE_SIZE, TEXTURE_SIZE));

    boardTexture.loadFromFile("Resources/Sprites/board.png");
    boardSprite.setTexture(boardTexture);
    boardSprite.setPosition(220, 25);

    boardFrame.setPosition(210, 15);
    boardFrame.setSize(sf::Vector2f(380, 770));
    boardFrame.setFillColor(sf::Color::White);

    clock.restart();
    fallInterval = 0.5f;

    tetrominoCanLock = false;
    lockDelayDuration = 1.0f;

    scoreManager.addObserver(&scoreDisplay);

    gameOver = false;
}

void Tetris::setTetrominoStartingPosition(Tetromino* tetromino, int startRow, int startColumn)
{
    std::vector<Square> squares;

    for (int i = 0; i < tetromino->getShapeMatrix().size(); ++i)
    {
        for (int j = 0; j < tetromino->getShapeMatrix()[i].size(); ++j)
        {
            if (tetromino->getShapeMatrix()[i][j] == 1)
            {
                if (tetromino->getShape() == TetrominoShape::Shape_O)
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

void Tetris::lockTetromino()
{
    for (int i = 0; i < fallingTetromino->getSquares().size(); ++i) 
    {
        int x = fallingTetromino->getSquares()[i].getX();
        int y = fallingTetromino->getSquares()[i].getY();

        board[y][x] = static_cast<int>(fallingTetromino->getColor());
    }
}

void Tetris::clearFullLines()
{
    for (int row = 0; row < BOARD_ROWS; ++row)
    {
        bool isFull = true;

        for (int col = 0; col < BOARD_COLUMNS; ++col)
        {
            if (board[row][col] == 0)
            {
                isFull = false;
                break;
            }
        }

        if (isFull)
        {
            for (int r = row; r > 0; --r)
            {
                board[r] = board[r - 1];
            }

            board[0] = std::vector<int>(BOARD_COLUMNS, 0);
            --row;

            scoreManager.increaseScore(10);
        }
    }
}

void Tetris::resetFallingTetromino()
{
    delete fallingTetromino;
    delete ghostTetromino;
    delete commandMoveDown;

    fallingTetromino = inventory[0];
    ghostTetromino = new Tetromino(*inventory[0]);

    inventory.erase(inventory.begin());
    inventory.push_back(director.createRandomTetromino());
    setTetrominoStartingPosition(fallingTetromino, 0, 4);
    setTetrominoStartingPosition(ghostTetromino, 0, 4);

    commandMoveDown = new CommandMoveDown(fallingTetromino);
}

void Tetris::hardDrop()
{
    std::vector<Square> nextPosition = fallingTetromino->getSquares();

    while (true)
    {
        for (int i = 0; i < 4; i++)
        {
            nextPosition[i].setY(fallingTetromino->getSquares()[i].getY() + 1);
        }

        if (isValidPosition(nextPosition))
        {
            fallingTetromino->setSquares(nextPosition);
        }
        else
        {
            break;
        }
    }
}

bool Tetris::isGameOver()
{
    for (int column = 0; column < BOARD_COLUMNS; ++column)
    {
        if (board[1][column])
        {
            return true;
        }
    }

    return false;
}

void Tetris::handleInput(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
        {
            CommandMoveLeft* commandMoveLeft = new CommandMoveLeft(fallingTetromino);
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

            delete commandMoveLeft;

            break;
        }
        case sf::Keyboard::Right:
        {
            CommandMoveRight* commandMoveRight = new CommandMoveRight(fallingTetromino);

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

            delete commandMoveRight;

            break;
        }
        case sf::Keyboard::Up:
        {
            Tetromino* temporaryTetromino = new Tetromino(*fallingTetromino);
            CommandRotate* temporaryCommandRotate = new CommandRotate(temporaryTetromino);

            temporaryCommandRotate->execute();

            if (isValidPosition(temporaryTetromino->getSquares()))
            {
                fallingTetromino->setShapeMatrix(temporaryTetromino->getShapeMatrix());
                fallingTetromino->setSquares(temporaryTetromino->getSquares());
            }

            delete temporaryTetromino;
            delete temporaryCommandRotate;

            break;
        }
        case sf::Keyboard::Down:
        {
            hardDrop();
            lockTetromino();

            if (isGameOver())
            {
                gameOver = true;

                delete fallingTetromino;
                delete ghostTetromino;

                for (Tetromino* tetromino : inventory)
                {
                    delete tetromino;
                }
            }
            else
            {
                clearFullLines();
                resetFallingTetromino();
            }

            break;
        }
        default:
        {
            break;
        }
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

            tetrominoCanLock = false;
            lockDelayTimer.restart();
        }
        else
        {
           
            if (!tetrominoCanLock)
            {
                tetrominoCanLock = true;
                lockDelayTimer.restart();
            }
            else
            {
                if (lockDelayTimer.getElapsedTime().asSeconds() >= lockDelayDuration)
                {
                    lockTetromino();

                    if (isGameOver())
                    {
                        gameOver = true;

                        delete fallingTetromino;
                        delete ghostTetromino;

                        for (Tetromino* tetromino : inventory)
                        {
                            delete tetromino;
                        }
                    }
                    else
                    {
                        clearFullLines();
                        resetFallingTetromino();
                    }
                }
            }
        }

        clock.restart();
    }

    ghostTetromino->setSquares(fallingTetromino->getSquares());

    for (int i = 0; i < 4; i++)
    {
        while (isValidPosition(ghostTetromino->getSquares()))
        {
            for (int i = 0; i < 4; i++)
            {
                ghostTetromino->getSquares()[i].setY(ghostTetromino->getSquares()[i].getY() + 1);
            }
        }

        for (int j = 0; j < 4; j++)
        {
            ghostTetromino->getSquares()[j].setY(ghostTetromino->getSquares()[j].getY() - 1);
        }
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

    // Draw Ghost Tetromino
    for (int i = 0; i < 4; i++)
    {
        ghostTetrominoSprite.setTextureRect(sf::IntRect((int)ghostTetromino->getColor() * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE));
        ghostTetrominoSprite.setPosition(ghostTetromino->getSquares()[i].getX() * TEXTURE_SIZE + 220, ghostTetromino->getSquares()[i].getY() * TEXTURE_SIZE + 25);
        window.draw(ghostTetrominoSprite);
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

    // Draw Placed Pieces
    for (int i = 0; i < BOARD_ROWS; ++i) 
    {
        for (int j = 0; j < BOARD_COLUMNS; ++j) 
        {
            // Only draw non-empty cells
            if (board[i][j] != 0) {
                // Create a rectangle for each block
                sf::RectangleShape block(sf::Vector2f(TEXTURE_SIZE, TEXTURE_SIZE));

                // Set the block's position on the screen
                tetrominoSprite.setPosition(220 + j * TEXTURE_SIZE, 25 + i * TEXTURE_SIZE);

                // Set the block's color based on the value in the board
                tetrominoSprite.setTextureRect(sf::IntRect(board[i][j] * TEXTURE_SIZE, 0, TEXTURE_SIZE, TEXTURE_SIZE));
                
                // Draw the block
                window.draw(tetrominoSprite);
            }
        }
    }

    scoreDisplay.draw(window);
}