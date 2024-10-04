#pragma once
#include <SFML/Graphics.hpp>
#include "lock_delay.h"
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
	LockDelay lockDelay;

public:
    ObserverScore();

	void draw(sf::RenderWindow& window);
	void update(std::pair<std::string, int> updateData) override;

	void resetLockDelayRectangle();
	void setLockDelayRectangle(float t, float currentValue);
	void setLockDelayColor(sf::Color color);
};