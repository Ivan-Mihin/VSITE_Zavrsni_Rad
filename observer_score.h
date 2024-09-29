#pragma once
#include <SFML/Graphics.hpp>
#include "manager_score.h"
#include "observer.h"

class ObserverScore : public Observer 
{
private:
    int score;

	// Draw
	sf::Font font;
	sf::Color innerRectangleColor;
	sf::RectangleShape outerRectangle;
	sf::RectangleShape textLabelInnerRectangle, valueInnerRectangle;
	sf::Text textLabel, value;
	sf::RectangleShape lockDelayRectangle;
	float lockDelayRectangleStartX, lockDelayRectangleStartY, lockDelayRectangleEndX, lockDelayRectangleEndY;


public:
    ObserverScore();

	void draw(sf::RenderWindow& window);
	void resetLockDelayRectangle();
	void setLockDelayColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void update(std::pair<std::string, int> updateData) override;
};