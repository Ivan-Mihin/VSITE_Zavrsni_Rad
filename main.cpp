#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "board.h"
#include "game.h"
#include "state_main_menu.h"
#include "user_input.h"
#include "tetromino.h"

int main()
{
    Game& game = Game::getInstance();
    game.changeState(new MainMenuState());
    game.run();

    return 0;
}

//const int WINDOW_LENGTH = 800;
    //const int WINDOW_WIDTH = 800;

    //RenderWindow window(VideoMode(WINDOW_LENGTH, WINDOW_WIDTH), "TETRIS!", Style::Close);

    //std::srand(static_cast<unsigned int>(std::time(nullptr)));

    //Board gameBoard;

    //for (int i = 0; i < HEIGHT; i++)
    //{
    //    for (int j = 0; j < WIDTH; j++)
    //    {
    //        gameBoard.board[i][j] = 0;
    //    }
    //}
    //    
    //Texture tetrominoTexture;
    //tetrominoTexture.loadFromFile("Resources/Sprites/tetromino.png");
    //int textureSize = 30;
    //Sprite tetrominoSprite(tetrominoTexture);
    //tetrominoSprite.setTextureRect(IntRect(0, 0, textureSize, textureSize));

    //Texture boardTexture;
    //boardTexture.loadFromFile("Resources/Sprites/board.png");
    //Sprite boardSprite(boardTexture);

    //// Create falling tetromino
    //TetrominoDirector director;
    //Tetromino* fallingTetromino = director.createRandomTetromino();

    //CommandMoveLeft moveLeftCmd(fallingTetromino);
    //CommandMoveRight moveRightCmd(fallingTetromino);

    //// Create the InputHandler
    //InputHandler inputHandler(&moveLeftCmd, &moveRightCmd);

    //vector<Tetromino*> inventory;

    //for (int i = 0; i < 6; ++i)
    //{
    //    inventory.push_back(director.createRandomTetromino());
    //}

    //while (window.isOpen())
    //{
    //    Event event;
    //    while (window.pollEvent(event))
    //    {
    //        inputHandler.handleInput(event);

    //        if (event.type == Event::Closed)
    //            window.close();
    //    }

    //    window.clear(Color::Black);

    //    // Draw Backboard
    //    RectangleShape backboardShape;
    //    backboardShape.setPosition(BOARD_POSITION_X - 10, BOARD_POSITION_Y - 10);
    //    backboardShape.setSize(Vector2f(380, 770));
    //    backboardShape.setFillColor(Color::White);
    //    window.draw(backboardShape);

    //    // Draw Board
    //    boardSprite.setPosition(BOARD_POSITION_X, BOARD_POSITION_Y);
    //    window.draw(boardSprite);

    //    // Draw Tetromino
    //    for (int i = 0; i < 4; i++)
    //    {
    //        tetrominoSprite.setTextureRect(IntRect((int)fallingTetromino->getColor() * textureSize, 0, textureSize, textureSize));
    //        tetrominoSprite.setPosition(fallingTetromino->getSquares()[i].getX() * textureSize + BOARD_POSITION_X, fallingTetromino->getSquares()[i].getY() * textureSize + BOARD_POSITION_Y);
    //        window.draw(tetrominoSprite);
    //    }

    //    // Draw Inventory Tetrominos
    //    for (int index = 0; index < inventory.size(); index++)
    //    {
    //        for (int x = 0; x < inventory[index]->getShapeMatrix().size(); ++x)
    //        {
    //            for (int y = 0; y < inventory[index]->getShapeMatrix().size(); ++y)
    //            {
    //                int offsetFromBoardX = textureSize;
    //                int offsetFromBoardY = textureSize;

    //                if (inventory[index]->getShapeMatrix()[y][x])
    //                {
    //                    if (inventory[index]->getShape() == TetrominoShape::Shape_O)
    //                    {
    //                        offsetFromBoardX += textureSize;
    //                    }
    //                    else if (inventory[index]->getShape() == TetrominoShape::Shape_I)
    //                    {
    //                        offsetFromBoardY -= 15;
    //                    }
    //                    else
    //                    {
    //                        offsetFromBoardX += textureSize / 2;
    //                    }

    //                    tetrominoSprite.setTextureRect(IntRect((int)inventory[index]->getColor() * textureSize, 0, textureSize, textureSize));
    //                    tetrominoSprite.setPosition(590 + offsetFromBoardX + textureSize * x, 114 + offsetFromBoardY + (90 * index) + textureSize * y);
    //                    window.draw(tetrominoSprite);
    //                }
    //            }
    //        }
    //    }

    //    window.display();
    //}

    //delete fallingTetromino;

    //for (int i = 0; i < inventory.size(); i++)
    //{
    //    delete inventory[i];
    //}