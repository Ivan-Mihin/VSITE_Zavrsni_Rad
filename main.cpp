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
    RenderWindow window(VideoMode(800, 800), "TETRIS!", Style::Close);

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Board game_board;

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            game_board.board[i][j] = 0;
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

    // create falling tetromino
    TetrominoDirector director;
    Tetromino* fallingTetromino = director.createRandomTetromino();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Black);

        // Draw Backboard
        RectangleShape backboardShape;
        backboardShape.setPosition(190, 15);
        backboardShape.setSize(Vector2f(380, 770));
        backboardShape.setFillColor(Color::White);
        window.draw(backboardShape);

        // Draw Board
        boardSprite.setPosition(200, 25);
        window.draw(boardSprite);

        window.display();
    }

    delete fallingTetromino;

    return 0;
}