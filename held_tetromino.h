#pragma once
#include <SFML/Graphics.hpp>
#include "Tetromino.h"

class HeldTetromino
{
private:
	sf::Font font;
	sf::Color innerRectangleColor;

	sf::RectangleShape outerRectangle;
	sf::RectangleShape textLabelInnerRectangle;
	sf::RectangleShape tetrominoInnerRectangle;
	sf::Text textLabel;
	sf::Clock clock;
	sf::Text noHeldTetromino;
	Tetromino* tetromino;
	sf::Texture texture;
	sf::Sprite sprite;

	float lockDelayRectangleStartX, lockDelayRectangleStartY, lockDelayRectangleEndX, lockDelayRectangleEndY;
	sf::RectangleShape lockDelayRectangle;

public:
	HeldTetromino();

	bool isTetrominoHeld;

	void draw(sf::RenderWindow& window);
	void drawNoHeldTetrominoText();
	Tetromino* getTetromino();
	void resetLockDelayRectangle();
	void setLockDelayColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void setTetromino(Tetromino* tetromino);
};