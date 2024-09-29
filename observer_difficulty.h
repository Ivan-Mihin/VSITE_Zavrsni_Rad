#pragma once
#include <SFML/Graphics.hpp>
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

	// Draw
	sf::Font font;
	sf::Color innerRectangleColor;
	sf::RectangleShape outerRectangle;
	sf::RectangleShape textLabel1InnerRectangle, textLabel2InnerRectangle, textLabel3InnerRectangle;
	sf::Text textLabel1, textLabel2, textLabel3;
	sf::RectangleShape lockDelayRectangle;
	float lockDelayRectangleStartX, lockDelayRectangleStartY, lockDelayRectangleEndX, lockDelayRectangleEndY;

	// Time
	sf::Clock clockForDrawing;
	sf::Clock clockForChangingColor;
	const float duration = 6.0f;

	void setTextColor(sf::Text* textLabel);
	void updateDifficultyBasedOnScore();
	void update(std::pair<std::string, int> updateData) override;

public:
	ObserverDifficulty(ManagerDifficulty& manager);

	void draw(sf::RenderWindow& window);
	void resetLockDelayRectangle();
	void setLockDelayColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void updateDifficultyBasedOnTime(float timeValue);
};