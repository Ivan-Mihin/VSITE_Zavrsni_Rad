#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "audio.h"
#include "board.h"
#include "command.h"
#include "held_tetromino.h"
#include "manager_combo.h"
#include "manager_score.h"
#include "observer_combo.h"
#include "observer_score.h"
#include "tetromino.h"
#include "tetromino_builder.h"

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
	HeldTetromino* heldTetromino;
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
	bool isLockDelayActive;
	sf::Clock lockDelayClock;
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
	~Tetris();

	bool gameOver;

	void initialize();

	sf::Color colorPicker(TetrominoColor fallingTetromino);
	bool isGameOver();
	void lockDelayRectangleReset();
	void lockTetromino();
	void resetColors();
	void resetFallingTetromino();
	void setTetrominoPosition(Tetromino* tetromino, int startRow, int startColumn);

	void handleInput(sf::Event event);
	void update(float deltaTime);
	void render(sf::RenderWindow& window);
};