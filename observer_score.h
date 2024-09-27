#pragma once
#include <SFML/Graphics.hpp>
#include "observer.h"
#include "manager_score.h"

class ObserverScore : public Observer 
{
private:
    int score;

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
    ObserverScore();

	void draw(sf::RenderWindow& window);
	void resetLockDelayRectangle();
	void setLockDelayColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void update(std::pair<std::string, int> updateData) override;
};