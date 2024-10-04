#pragma once
#include <SFML/Graphics.hpp>
#include "lock_delay.h"
#include "Tetromino.h"

class HeldTetromino
{
private:
	Tetromino* tetromino;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Font font;
	sf::Color innerRectangleColor;

	sf::RectangleShape outerRectangle;
	sf::RectangleShape textLabelInnerRectangle;
	sf::RectangleShape tetrominoInnerRectangle;
	sf::Text textLabel;
	sf::Text noHeldTetromino;
	sf::Clock clock;

	LockDelay lockDelay;

public:
	HeldTetromino();
	~HeldTetromino();

	bool isTetrominoHeld;

	void draw(sf::RenderWindow& window);
	void drawNoHeldTetrominoText();
	Tetromino* getTetromino();
	void setTetromino(Tetromino* tetromino);

	void resetLockDelayRectangle();
	void setLockDelayRectangle(float t, float currentValue);
	void setLockDelayColor(sf::Color color);
};