#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "square.h"

class Board
{
private:
	std::vector<std::vector<int>> board;

	sf::RectangleShape outerRectangle;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Texture gameOverLineTexture;
	sf::Sprite gameOverLineSprite;

	float lockDelayRectangleStartX, lockDelayRectangleStartY, lockDelayRectangleEndX, lockDelayRectangleEndY;
	sf::RectangleShape lockDelayRectangle;

public:
	Board();

	int BOARD_ROWS = 25;
	int BOARD_COLUMNS = 12;

	void setColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void resetLockDelayRectangle();
	bool isValidPosition(std::vector<Square> nextPosition);
	std::vector<std::vector<int>>& getBoard();
	void draw(sf::RenderWindow& window);
};