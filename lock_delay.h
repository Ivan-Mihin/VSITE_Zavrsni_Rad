#pragma once
#include <SFML/Graphics.hpp>

struct LockDelay
{
	LockDelay(float width, float height);

	sf::RectangleShape rectangle;
	sf::Vector2f start;
	sf::Vector2f end;
	const float DEFAULT_WIDTH;
	const float DEFAULT_HEIGHT;

	void resetRectangle();
	void setRectangle(float t, float currentValue);
	void setColor(sf::Color color);
};