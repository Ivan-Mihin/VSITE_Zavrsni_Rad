#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "tetromino.h"
#include "user_input.h"

class Tetris
{
private:
	static const int BOARD_WIDTH = 12;
	static const int BOARD_HEIGHT = 25;
	static const int FRAMERATE = 60;
	static const int TEXTURE_SIZE = 30;

	std::vector<std::vector<int>> board;

	TetrominoDirector director;
	Tetromino* fallingTetromino;
	std::vector<Tetromino*> inventory;

	sf::Texture tetrominoTexture;
	sf::Sprite tetrominoSprite;

	sf::Texture boardTexture;
	sf::Sprite boardSprite;
	sf::RectangleShape boardFrame;

	sf::Clock clock;

	CommandMoveLeft* commandMoveLeft;
	CommandMoveRight* commandMoveRight;
	InputHandler* inputHandler;
	
public:
	void initialize();
	bool isValidMove(Tetromino* fallingTetromino, std::vector<std::vector<int>> newPosition);
	void lockPiece();
	void clearLines();
	bool isGameOver();

	void handleInput(sf::Event event);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
};