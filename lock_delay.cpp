#include "lock_delay.h"

LockDelay::LockDelay(float width, float height) 
    : DEFAULT_WIDTH(width), DEFAULT_HEIGHT(height) {}

void LockDelay::resetRectangle()
{
    rectangle.setSize(sf::Vector2f(DEFAULT_WIDTH, DEFAULT_HEIGHT));
    rectangle.setPosition(sf::Vector2f(start.x, start.y));
}

void LockDelay::setRectangle(float t, float currentValue)
{
    float currentSizeX = start.x + t * (end.x - start.x);
    float currentSizeY = start.y + t * (end.y - start.y);

    rectangle.setSize(sf::Vector2f(DEFAULT_WIDTH + currentValue, DEFAULT_HEIGHT + currentValue));
    rectangle.setPosition(currentSizeX, currentSizeY);
}

void LockDelay::setColor(sf::Color color)
{
    rectangle.setFillColor(color);
}