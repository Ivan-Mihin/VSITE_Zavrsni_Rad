#pragma once
#include <SFML/Graphics.hpp>
#include "lock_delay.h"
#include "manager_difficulty.h"
#include "observer.h"

class ObserverDifficulty : public Observer
{
private:
	int scoreDifficulty;
	int timeDifficulty;
	const int MAX_SCORE_DIFFICULTY_LEVEL = 6;
	const int MAX_TIME_DIFFICULTY_LEVEL = 6;
	bool isScoreDifficultyIncreased;
	bool isTimeDifficultyIncreased;
	int score;
	ManagerDifficulty& managerDifficulty;
	LockDelay lockDelay;

	// Draw
	sf::Font font;
	sf::Color innerRectangleColor;
	sf::RectangleShape outerRectangle;
	sf::RectangleShape textLabel1InnerRectangle, textLabel2InnerRectangle, textLabel3InnerRectangle;
	sf::Text textLabel1, textLabel2, textLabel3;

	// Time
	sf::Clock clockForDrawing;
	sf::Clock clockForChangingColor;
	const float duration = 6.0f;

	void setTextColor(sf::Text* text);
	void updateDifficultyBasedOnScore();

public:
	ObserverDifficulty(ManagerDifficulty& manager);

	void draw(sf::RenderWindow& window);
	void update(std::pair<std::string, int> updateData) override;
	void updateDifficultyBasedOnTime(float timeValue);

	void resetLockDelayRectangle();
	void setLockDelayRectangle(float t, float currentValue);
	void setLockDelayColor(sf::Color color);
};