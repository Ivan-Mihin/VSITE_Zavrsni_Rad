#pragma once
#include <SFML/Graphics.hpp>
#include "observer.h"
#include "manager_combo.h"
#include "audio.h"

class ObserverCombo : public Observer
{
private:
    int combo;
	sf::Font font;
	sf::Color innerRectangleColor;
	Audio audio;

	sf::RectangleShape outerRectangle;
	sf::RectangleShape textLabelInnerRectangle;
	sf::RectangleShape valueInnerRectangle;
	sf::Text comboTextLabel;
	sf::Text comboValue;

	float lockDelayRectangleStartX, lockDelayRectangleStartY, lockDelayRectangleEndX, lockDelayRectangleEndY;
	sf::RectangleShape lockDelayRectangle;

public:
    ObserverCombo();

	void setColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void resetLockDelayRectangle();
	void playComboSound();

	void update(int combo) override;
	void draw(sf::RenderWindow& window);
};