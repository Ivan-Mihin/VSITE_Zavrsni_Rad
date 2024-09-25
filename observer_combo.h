#pragma once
#include <SFML/Graphics.hpp>
#include "audio.h"
#include "manager_combo.h"
#include "observer.h"

class ObserverCombo : public Observer
{
private:
    int combo;

	Audio audio;
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
    ObserverCombo();

	void draw(sf::RenderWindow& window);
	void playComboSound();
	void resetLockDelayRectangle();
	void setColor(sf::Color color);
	void setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue);
	void update(int combo) override;
};