#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "tetromino.h"
#include "command.h"
#include "score_manager.h"
#include "score_display.h"

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

	sf::Clock lockDelayTimer;
	bool tetrominoCanLock;
	float lockDelayDuration;

	CommandMoveDown* commandMoveDown;

	ScoreManager scoreManager;
	ScoreDisplay scoreDisplay;

public:

	bool isGameOver = false;

	void initialize();
	void setTetrominoStartingPosition(int startRow, int startColumn);
	bool isValidPosition(std::vector<Square> nextPosition);
	void lockTetromino();
	void clearFullLines();
	void resetFallingTetromino();
	void hardDrop();
	bool gameOver();

	void handleInput(sf::Event event);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
};