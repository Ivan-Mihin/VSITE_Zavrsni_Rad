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
#include "board.h"

class Tetris
{
private:
	const int TEXTURE_SIZE = 30;

	Audio audio;
	Board board;
	sf::Texture background;
	sf::Sprite backgroundSprite;
	sf::Font font;

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
		
	// Lock Delay
	sf::Clock lockDelayClock;
	bool isLockDelayActive;
	float lockDelayDuration;
	float lockDelaySizeIncreaseStartValue;
	float lockDelaySizeIncreaseEndValue;

	float lockDelayInventoryTextLabelRectangleStartX, lockDelayInventoryTextLabelRectangleStartY, lockDelayInventoryTextLabelRectangleEndX, lockDelayInventoryTextLabelRectangleEndY;
	sf::RectangleShape lockDelayInventoryTextLabelRectangle;

	float lockDelayInventoryRectangleStartX, lockDelayInventoryRectangleStartY, lockDelayInventoryRectangleEndX, lockDelayInventoryRectangleEndY;
	sf::RectangleShape lockDelayInventoryRectangle;

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

	sf::Clock clockForFallingTetromino;
	float durationBeforeFallingTetrominoMovesDown;

public:
	bool gameOver;

	void initialize();
	void setTetrominoStartingPosition(Tetromino* tetromino, int startRow, int startColumn);
	void lockTetromino();
	void clearFullLines();
	void resetFallingTetromino();
	bool isGameOver();
	void lockDelayRectangleReset();
	sf::Color colorPicker(TetrominoColor fallingTetromino);


	void handleInput(sf::Event event);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
};