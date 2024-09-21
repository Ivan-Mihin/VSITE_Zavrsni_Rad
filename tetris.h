#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "audio.h"
#include "tetromino.h"
#include "command.h"
#include "score_manager.h"
#include "observer_score.h"

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

	sf::Texture background;
	sf::Texture boardTexture;
	sf::Texture boardGameOverLineTexture;
	sf::Texture tetrominoTexture;
	sf::Texture ghostTetrominoTexture;

	sf::Sprite backgroundSprite;
	sf::Sprite boardSprite;
	sf::Sprite boardGameOverLineSprite;
	sf::Sprite tetrominoSprite;
	sf::Sprite ghostTetrominoSprite;

	sf::RectangleShape boardOuterRectangle;
	sf::RectangleShape inventoryTextLabelOuterRectangle;
	sf::RectangleShape inventoryTextLabelInnerRectangle;
	sf::RectangleShape inventoryRectangle;
	sf::RectangleShape scoreOuterRectangle;
	sf::RectangleShape scoreTextLabelInnerRectangle;
	sf::RectangleShape scoreValueInnerRectangle;

	sf::Font font;

	sf::Text inventoryTextLabel;
	sf::Text scoreTextLabel;
	sf::Text scoreValue;

	float lockDelayBoardRectangleStartX, lockDelayBoardRectangleStartY, lockDelayBoardRectangleEndX, lockDelayBoardRectangleEndY;
	float lockDelayScoreRectangleStartX, lockDelayScoreRectangleStartY, lockDelayScoreRectangleEndX, lockDelayScoreRectangleEndY;
	float lockDelayInventoryTextLabelRectangleStartX, lockDelayInventoryTextLabelRectangleStartY, lockDelayInventoryTextLabelRectangleEndX, lockDelayInventoryTextLabelRectangleEndY;
	float lockDelayInventoryRectangleStartX, lockDelayInventoryRectangleStartY, lockDelayInventoryRectangleEndX, lockDelayInventoryRectangleEndY;

	sf::RectangleShape lockDelayBoardRectangle;
	sf::RectangleShape lockDelayScoreRectangle;
	sf::RectangleShape lockDelayInventoryTextLabelRectangle;
	sf::RectangleShape lockDelayInventoryRectangle;

	float lockDelaySizeIncreaseStartValue;
	float lockDelaySizeIncreaseEndValue;

	CommandMoveDown* commandMoveDown;

	ScoreManager scoreManager;
	ObserverScore observerScore;

	Audio audio;

	sf::Color innerRectangleColor;



	sf::Clock clockForFallingTetromino;
	float durationBeforeFallingTetrominoMovesDown;


	bool tetrominoHasLanded;
	float lockDelayDuration;

	sf::Clock lockDelayClock;
	bool isLockDelayActive;

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
	void lockDelayRectangleReset();
	sf::Color colorPicker(TetrominoColor fallingTetromino);

	void handleInput(sf::Event event);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
};