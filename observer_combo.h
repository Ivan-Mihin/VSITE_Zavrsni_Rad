#pragma once
#include <SFML/Graphics.hpp>
#include "audio.h"
#include "lock_delay.h"
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

	sf::Clock clockForChangingColor;
	AudioCombo audioCombo;
	LockDelay lockDelay;

	void setTextColor(sf::Text* text);

public:
    ObserverCombo();

	void draw(sf::RenderWindow& window);
	void playComboSound();
	void update(std::pair<std::string, int> updateData) override;

	void resetLockDelayRectangle();
	void setLockDelayRectangle(float t, float currentValue);
	void setLockDelayColor(sf::Color color);
};