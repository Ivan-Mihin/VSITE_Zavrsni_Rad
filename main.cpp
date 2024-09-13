#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "board.h"
#include "tetromino.h"

using namespace sf;
using namespace std;

int main()
{
    const int WINDOW_LENGTH = 800;
    const int WINDOW_WIDTH = 800;

    RenderWindow window(VideoMode(WINDOW_LENGTH, WINDOW_WIDTH), "TETRIS!", Style::Close);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Board gameBoard;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            gameBoard.board[i][j] = 0;
        }
    }
        
    Texture tetrominoTexture;
    tetrominoTexture.loadFromFile("Resources/Sprites/tetromino.png");
    int textureSize = 30;
    Sprite tetrominoSprite(tetrominoTexture);
    tetrominoSprite.setTextureRect(IntRect(0, 0, textureSize, textureSize));

    Texture boardTexture;
    boardTexture.loadFromFile("Resources/Sprites/board.png");
    Sprite boardSprite(boardTexture);

    // Create falling tetromino
    TetrominoDirector director;
    Tetromino* fallingTetromino = director.createRandomTetromino();

    bool gameInFocus = true;
    bool keyLeftNotYetPressed = true;
    bool keyRightNotYetPressed = true;
    bool moveLeft = false;
    bool moveRight = false;

    vector<Tetromino*> inventory;

    for (int i = 0; i < 6; ++i)
    {
        inventory.push_back(director.createRandomTetromino());
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::GainedFocus) gameInFocus = true;
            if (event.type == Event::LostFocus) gameInFocus = false;

            if (gameInFocus && event.type == Event::KeyReleased) 
            {
                if (event.key.code == Keyboard::Left) keyLeftNotYetPressed = true;
                if (event.key.code == Keyboard::Right) keyRightNotYetPressed = true;
            }

            if (event.type == Event::Closed)
                window.close();
        }

        if (gameInFocus) 
        {
            if (Keyboard::isKeyPressed(Keyboard::Left) && keyLeftNotYetPressed) 
            {
                keyLeftNotYetPressed = false;
                moveLeft = true;
            }

            if (Keyboard::isKeyPressed(Keyboard::Right) && keyRightNotYetPressed)
            {
                keyRightNotYetPressed = false;
                moveRight = true;
            }

            if (moveLeft)
            {
                for (int i = 0; i < 4; i++)
                {
                    fallingTetromino->getSquares()[i].setX(fallingTetromino->getSquares()[i].getX() - 1);
                }

                moveLeft = false;
            }

            if (moveRight) 
            {
                for (int i = 0; i < 4; i++) 
                {
                    fallingTetromino->getSquares()[i].setX(fallingTetromino->getSquares()[i].getX() + 1);
                }

                moveRight = false;
            }   
        }

        window.clear(Color::Black);

        // Draw Backboard
        RectangleShape backboardShape;
        backboardShape.setPosition(BOARD_POSITION_X - 10, BOARD_POSITION_Y - 10);
        backboardShape.setSize(Vector2f(380, 770));
        backboardShape.setFillColor(Color::White);
        window.draw(backboardShape);

        // Draw Board
        boardSprite.setPosition(BOARD_POSITION_X, BOARD_POSITION_Y);
        window.draw(boardSprite);

        // Draw Tetromino
        for (int i = 0; i < 4; i++)
        {
            tetrominoSprite.setTextureRect(IntRect((int)fallingTetromino->getColor() * textureSize, 0, textureSize, textureSize));
            tetrominoSprite.setPosition(fallingTetromino->getSquares()[i].getX() * textureSize + BOARD_POSITION_X, fallingTetromino->getSquares()[i].getY() * textureSize + BOARD_POSITION_Y);
            window.draw(tetrominoSprite);
        }

        // Draw Inventory Tetrominos
        for (int index = 0; index < inventory.size(); index++)
        {
            for (int x = 0; x < inventory[index]->getShapeMatrix().size(); ++x)
            {
                for (int y = 0; y < inventory[index]->getShapeMatrix().size(); ++y)
                {
                    int offsetFromBoardX = textureSize;
                    int offsetFromBoardY = textureSize;

                    if (inventory[index]->getShapeMatrix()[y][x])
                    {
                        if (inventory[index]->getShape() == TetrominoShape::Shape_O)
                        {
                            offsetFromBoardX += textureSize;
                        }
                        else if (inventory[index]->getShape() == TetrominoShape::Shape_I)
                        {
                            offsetFromBoardY -= 15;
                        }
                        else
                        {
                            offsetFromBoardX += textureSize / 2;
                        }

                        tetrominoSprite.setTextureRect(IntRect((int)inventory[index]->getColor() * textureSize, 0, textureSize, textureSize));
                        tetrominoSprite.setPosition(590 + offsetFromBoardX + textureSize * x, 114 + offsetFromBoardY + (90 * index) + textureSize * y);
                        window.draw(tetrominoSprite);
                    }
                }
            }
        }

        window.display();
    }

    delete fallingTetromino;

    return 0;
}