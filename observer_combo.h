#pragma once
#include <SFML/Graphics.hpp>
#include "audio.h"
#include "manager_combo.h"
#include "observer.h"

class ObserverCombo : public Observer
{
private:
    int combo;

	// Draw
	sf::Font font;
	sf::Color innerRectangleColor;
	sf::RectangleShape outerRectangle;
	sf::RectangleShape textLabelInnerRectangle, valueInnerRectangle;
	sf::Text textLabel, value;
	sf::RectangleShape lockDelayRectangle;
	float lockDelayRectangleStartX, lockDelayRectangleStartY, lockDelayRectangleEndX, lockDelayRectangleEndY;

	// Clock
	sf::Clock clockForChangingColor;

	// Audio
	AudioCombo audioCombo;

	void setTextColor(sf::Text* text);

public:
    ObserverCombo();

	void draw(sf::RenderWindow& window);
	void playComboSound();
	void resetLockDelayRectangle();
	void setLockDelayColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void update(std::pair<std::string, int> updateData) override;
};