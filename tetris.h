#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "tetromino.h"
#include "user_input.h"

class Tetris
{
private:
	static const int BOARD_ROWS = 25;
	static const int BOARD_COLUMNS = 12;
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
	float fallInterval;

	CommandMoveLeft* commandMoveLeft;
	CommandMoveRight* commandMoveRight;
	CommandMoveDown* commandMoveDown;
	
public:
	void initialize();
	void setTetrominoStartingPosition(std::vector<std::vector<int>> grid, std::vector<std::vector<int>> shapeMatrix, int startRow, int startColumn);
	bool isValidPosition(std::vector<Square> nextPosition);

	void handleInput(sf::Event event);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
};