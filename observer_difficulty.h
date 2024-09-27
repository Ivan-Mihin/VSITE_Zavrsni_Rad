#pragma once
#include <SFML/Graphics.hpp>
#include "manager_difficulty.h"
#include "observer.h"

class ObserverDifficulty : public Observer
{
private:
	int difficulty;
	int score;
	ManagerDifficulty& managerDifficulty;

	sf::Font font;
	sf::Color innerRectangleColor;

	sf::RectangleShape outerRectangle;
	sf::RectangleShape textLabel1InnerRectangle;
	sf::RectangleShape textLabel2InnerRectangle;
	sf::Text textLabel1;
	sf::Text textLabel2;

	float lockDelayRectangleStartX, lockDelayRectangleStartY, lockDelayRectangleEndX, lockDelayRectangleEndY;
	sf::RectangleShape lockDelayRectangle;

	sf::Clock clock;
	float duration;
	bool didDifficultyIncrease;

public:
	ObserverDifficulty(ManagerDifficulty& manager);

	void draw(sf::RenderWindow& window);
	void resetLockDelayRectangle();
	void setValueColor();
	void setLockDelayColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void update(std::pair<std::string, int> updateData) override;
};