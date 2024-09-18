#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "audio.h"
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
	Tetromino* ghostTetromino;
	std::vector<Tetromino*> inventory;

	sf::Texture tetrominoTexture;
	sf::Sprite tetrominoSprite;

	sf::Texture ghostTetrominoTexture;
	sf::Sprite ghostTetrominoSprite;

	sf::Texture boardTexture;
	sf::Sprite boardSprite;

	sf::Texture gameOverLineTexture;
	sf::Sprite gameOverLineSprite;

	sf::RectangleShape boardFrame;

	sf::Texture mainMenuBackground;
	sf::Sprite mainMenuBackgroundSprite;

	sf::Font inventoryFont;
	sf::Text inventoryText;
	sf::FloatRect inventoryTextBounds;
	sf::RectangleShape inventoryTextFrame;
	sf::RectangleShape inventoryFrame;

	sf::RectangleShape scoreFrame;

	sf::Clock clock;
	float fallInterval;

	sf::Clock lockDelayTimer;
	bool tetrominoCanLock;
	float lockDelayDuration;

	CommandMoveDown* commandMoveDown;

	ScoreManager scoreManager;
	ScoreDisplay scoreDisplay;

	Audio audio;

public:
	bool gameOver;

	void initialize();
	void setTetrominoStartingPosition(Tetromino* tetromino, int startRow, int startColumn);
	bool isValidPosition(std::vector<Square> nextPosition);
	void lockTetromino();
	void clearFullLines();
	void resetFallingTetromino();
	void hardDrop();
	bool isGameOver();

	void handleInput(sf::Event event);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
};