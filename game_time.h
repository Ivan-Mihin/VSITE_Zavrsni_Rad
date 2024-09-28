#pragma once
#include <SFML/Graphics.hpp>

class GameTime
{
private:
	sf::Clock clock;
	sf::Time lastTime;
	sf::Time interval;

	sf::Font font;
	sf::Color innerRectangleColor;

	sf::RectangleShape outerRectangle;
	sf::RectangleShape textLabelInnerRectangle; 
	sf::RectangleShape valueInnerRectangle;
	sf::Text textLabel;
	sf::Text value;

	float lockDelayRectangleStartX, lockDelayRectangleStartY, lockDelayRectangleEndX, lockDelayRectangleEndY;
	sf::RectangleShape lockDelayRectangle;

public:
	GameTime();

	bool didOneSecondElapse();
	void draw(sf::RenderWindow& window);
	float getTimeAsFloat();
	void resetLockDelayRectangle();
	void setLockDelayColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void setTimeAsString();
};