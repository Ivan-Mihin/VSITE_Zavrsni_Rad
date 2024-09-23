#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "audio.h"
#include "tetromino.h"
#include "command.h"
#include "manager_score.h"
#include "observer_score.h"
#include "manager_combo.h"
#include "observer_combo.h"

class Tetris
{
private:
	static const int BOARD_ROWS = 25;
	static const int BOARD_COLUMNS = 12;
	static const int TEXTURE_SIZE = 30;

	Audio audio;
	sf::Texture background;
	sf::Sprite backgroundSprite;
	sf::Font font;

	// Board
	std::vector<std::vector<int>> board;
	sf::Texture boardTexture;
	sf::Sprite boardSprite;
	sf::Texture boardGameOverLineTexture;
	sf::Sprite boardGameOverLineSprite;
	sf::RectangleShape boardOuterRectangle;

	// Tetromino
	TetrominoDirector director;
	Tetromino* fallingTetromino;
	Tetromino* ghostTetromino;
	std::vector<Tetromino*> inventory;
	sf::Texture tetrominoTexture;
	sf::Sprite tetrominoSprite;
	sf::Texture ghostTetrominoTexture;
	sf::Sprite ghostTetrominoSprite;

	// Inventory Text Label
	sf::RectangleShape inventoryTextLabelOuterRectangle;
	sf::RectangleShape inventoryTextLabelInnerRectangle;
	sf::Text inventoryTextLabel;

	// Inventory
	sf::RectangleShape inventoryOuterRectangle;
	sf::RectangleShape inventoryNextTetrominoInnerRectangle;
	sf::RectangleShape inventoryInnerRectangle;

	// Score
	sf::RectangleShape scoreOuterRectangle;
	sf::RectangleShape scoreTextLabelInnerRectangle;
	sf::RectangleShape scoreValueInnerRectangle;
	sf::Text scoreTextLabel;
	sf::Text scoreValue;

	// Combo
	sf::RectangleShape comboOuterRectangle;
	sf::RectangleShape comboTextLabelInnerRectangle;
	sf::RectangleShape comboValueInnerRectangle;
	sf::Text comboTextLabel;
	sf::Text comboValue;
	bool isComboActive;
		
	// Lock Delay
	sf::Clock lockDelayClock;
	bool isLockDelayActive;
	float lockDelayDuration;
	float lockDelaySizeIncreaseStartValue;
	float lockDelaySizeIncreaseEndValue;

	float lockDelayBoardRectangleStartX, lockDelayBoardRectangleStartY, lockDelayBoardRectangleEndX, lockDelayBoardRectangleEndY;
	sf::RectangleShape lockDelayBoardRectangle;

	float lockDelayScoreRectangleStartX, lockDelayScoreRectangleStartY, lockDelayScoreRectangleEndX, lockDelayScoreRectangleEndY;
	sf::RectangleShape lockDelayScoreRectangle;

	float lockDelayInventoryTextLabelRectangleStartX, lockDelayInventoryTextLabelRectangleStartY, lockDelayInventoryTextLabelRectangleEndX, lockDelayInventoryTextLabelRectangleEndY;
	sf::RectangleShape lockDelayInventoryTextLabelRectangle;

	float lockDelayInventoryRectangleStartX, lockDelayInventoryRectangleStartY, lockDelayInventoryRectangleEndX, lockDelayInventoryRectangleEndY;
	sf::RectangleShape lockDelayInventoryRectangle;

	float lockDelayComboRectangleStartX, lockDelayComboRectangleStartY, lockDelayComboRectangleEndX, lockDelayComboRectangleEndY;
	sf::RectangleShape lockDelayComboRectangle;

	// Observer
	ManagerScore managerScore;
	ObserverScore observerScore;
	ManagerCombo managerCombo;
	ObserverCombo observerCombo;

	// Color
	sf::Clock colorClock;
	float colorChangeCycle;
	sf::Color inventoryNextTetrominoInnerRectangleStartColor;
	sf::Color inventoryNextTetrominoInnerRectangleEndColor;
	sf::Color innerRectangleColor;

	CommandMoveDown* commandMoveDown;
	sf::Clock clockForFallingTetromino;
	float durationBeforeFallingTetrominoMovesDown;

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
	void comboCheck();

	void handleInput(sf::Event event);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
};