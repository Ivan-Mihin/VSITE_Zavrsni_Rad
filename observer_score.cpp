#include "observer_score.h"

ObserverScore::ObserverScore() : lockDelay(150.0f, 120.0f)
{
    score = 0;

    // Draw
    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    innerRectangleColor.r = 25;
    innerRectangleColor.g = 25;
    innerRectangleColor.b = 25;

    outerRectangle.setPosition(20, 15);
    outerRectangle.setSize(sf::Vector2f(170, 140));
    outerRectangle.setFillColor(sf::Color::Black);

    textLabelInnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10);
    textLabelInnerRectangle.setSize(sf::Vector2f(150, 60));
    textLabelInnerRectangle.setFillColor(innerRectangleColor);

    valueInnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10 + textLabelInnerRectangle.getSize().y);
    valueInnerRectangle.setSize(sf::Vector2f(150, 60));
    valueInnerRectangle.setFillColor(innerRectangleColor);

    textLabel.setFont(font);
    textLabel.setCharacterSize(30);
    textLabel.setFillColor(sf::Color::White);
    textLabel.setString("Score");
    textLabel.setOrigin(textLabel.getLocalBounds().left + textLabel.getLocalBounds().width / 2.0f,
        textLabel.getLocalBounds().top + textLabel.getLocalBounds().height / 2.0f);
    textLabel.setPosition(textLabelInnerRectangle.getPosition().x + textLabelInnerRectangle.getLocalBounds().left + textLabelInnerRectangle.getLocalBounds().width / 2.0f,
        textLabelInnerRectangle.getPosition().y + textLabelInnerRectangle.getLocalBounds().top + textLabelInnerRectangle.getLocalBounds().height / 2.0f);

    value.setFont(font);
    value.setCharacterSize(30);
    value.setFillColor(sf::Color::White);
    value.setString("0");
    value.setOrigin(value.getLocalBounds().left + value.getLocalBounds().width / 2.0f,
        value.getLocalBounds().top + value.getLocalBounds().height / 2.0f);
    value.setPosition(valueInnerRectangle.getPosition().x + valueInnerRectangle.getLocalBounds().left + valueInnerRectangle.getLocalBounds().width / 2.0f,
        valueInnerRectangle.getPosition().y + valueInnerRectangle.getLocalBounds().top + valueInnerRectangle.getLocalBounds().height / 2.0f);

    lockDelay.start.x = textLabelInnerRectangle.getPosition().x;
    lockDelay.start.y = textLabelInnerRectangle.getPosition().y;
    lockDelay.end.x = outerRectangle.getPosition().x;
    lockDelay.end.y = outerRectangle.getPosition().y;
    lockDelay.rectangle.setPosition(sf::Vector2f(lockDelay.start.x, lockDelay.start.y));
    lockDelay.rectangle.setSize(sf::Vector2f(lockDelay.DEFAULT_WIDTH, lockDelay.DEFAULT_HEIGHT));
}

void ObserverScore::draw(sf::RenderWindow& window)
{
    window.draw(outerRectangle);
    window.draw(lockDelay.rectangle);
    window.draw(textLabelInnerRectangle);
    window.draw(valueInnerRectangle);
    window.draw(textLabel);

    value.setString(std::to_string(score));
    value.setOrigin(value.getLocalBounds().left + value.getLocalBounds().width / 2.0f, value.getLocalBounds().top + value.getLocalBounds().height / 2.0f);
    value.setPosition(valueInnerRectangle.getPosition().x + valueInnerRectangle.getLocalBounds().left + valueInnerRectangle.getLocalBounds().width / 2.0f,
        valueInnerRectangle.getPosition().y + valueInnerRectangle.getLocalBounds().top + valueInnerRectangle.getLocalBounds().height / 2.0f);
    window.draw(value);
}

void ObserverScore::update(std::pair<std::string, int> updateData)
{
    score = updateData.second;
}

void ObserverScore::resetLockDelayRectangle()
{
    lockDelay.resetRectangle();
}

void ObserverScore::setLockDelayRectangle(float t, float currentValue)
{
    lockDelay.setRectangle(t, currentValue);
}

void ObserverScore::setLockDelayColor(sf::Color color)
{
    lockDelay.setColor(color);
}