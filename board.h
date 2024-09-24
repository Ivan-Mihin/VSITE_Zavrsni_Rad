#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

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
	const int BOARD_ROWS = 25;
	const int BOARD_COLUMNS = 12;

	void setColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void resetLockDelayRectangle();
	std::vector<std::vector<int>>& getBoard();
	void draw(sf::RenderWindow& window);
};