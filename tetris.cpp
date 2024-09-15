#include "tetris.h"

void Tetris::initialize()
{
	board.assign(BOARD_HEIGHT, std::vector<int>(BOARD_WIDTH, 0));

	fallingTetromino = director.createRandomTetromino();

	for (int i = 0; i < 6; i++)
	{
		inventory.push_back(director.createRandomTetromino());
	}

    commandMoveLeft = new CommandMoveLeft(fallingTetromino);
    commandMoveRight = new CommandMoveRight(fallingTetromino);
    inputHandler = new InputHandler(commandMoveLeft, commandMoveRight);

    tetrominoTexture.loadFromFile("Resources/Sprites/tetromino.png");
    tetrominoSprite.setTexture(tetrominoTexture);
    tetrominoSprite.setTextureRect(sf::IntRect(0, 0, TEXTURE_SIZE, TEXTURE_SIZE));

    boardTexture.loadFromFile("Resources/Sprites/board.png");
    boardSprite.setTexture(boardTexture);
    boardSprite.setPosition(220, 25);

    boardFrame.setPosition(210, 15);
    boardFrame.setSize(sf::Vector2f(380, 770));
    boardFrame.setFillColor(sf::Color::White);
}

void Tetris::handleInput(sf::Event event)
{
    inputHandler->handleInput(event);
}

void Tetris::update(float deltaTime)
{

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