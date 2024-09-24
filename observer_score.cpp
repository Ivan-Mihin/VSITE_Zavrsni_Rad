#include "observer_score.h"

ObserverScore::ObserverScore()
{
    score = 0;

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

    scoreTextLabel.setFont(font);
    scoreTextLabel.setCharacterSize(30);
    scoreTextLabel.setFillColor(sf::Color::White);
    scoreTextLabel.setString("Score");
    scoreTextLabel.setOrigin(scoreTextLabel.getLocalBounds().left + scoreTextLabel.getLocalBounds().width / 2.0f,
        scoreTextLabel.getLocalBounds().top + scoreTextLabel.getLocalBounds().height / 2.0f);
    scoreTextLabel.setPosition(textLabelInnerRectangle.getPosition().x + textLabelInnerRectangle.getLocalBounds().left + textLabelInnerRectangle.getLocalBounds().width / 2.0f,
        textLabelInnerRectangle.getPosition().y + textLabelInnerRectangle.getLocalBounds().top + textLabelInnerRectangle.getLocalBounds().height / 2.0f);

    scoreValue.setFont(font);
    scoreValue.setCharacterSize(30);
    scoreValue.setFillColor(sf::Color::White);
    scoreValue.setString("0");
    scoreValue.setOrigin(scoreValue.getLocalBounds().left + scoreValue.getLocalBounds().width / 2.0f,
        scoreValue.getLocalBounds().top + scoreValue.getLocalBounds().height / 2.0f);
    scoreValue.setPosition(valueInnerRectangle.getPosition().x + valueInnerRectangle.getLocalBounds().left + valueInnerRectangle.getLocalBounds().width / 2.0f,
        valueInnerRectangle.getPosition().y + valueInnerRectangle.getLocalBounds().top + valueInnerRectangle.getLocalBounds().height / 2.0f);

    lockDelayRectangleStartX = textLabelInnerRectangle.getPosition().x;
    lockDelayRectangleStartY = textLabelInnerRectangle.getPosition().y;
    lockDelayRectangleEndX = outerRectangle.getPosition().x;
    lockDelayRectangleEndY = outerRectangle.getPosition().y;
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(textLabelInnerRectangle.getLocalBounds().width, textLabelInnerRectangle.getLocalBounds().height + valueInnerRectangle.getLocalBounds().height));
}

void ObserverScore::setColor(sf::Color color)
{
    lockDelayRectangle.setFillColor(color);
}

void ObserverScore::setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue)
{
    float currentLockDelayScoreRectangleSizeX = lockDelayRectangleStartX + t * (lockDelayRectangleEndX - lockDelayRectangleStartX);
    float currentLockDelayScoreRectangleSizeY = lockDelayRectangleStartY + t * (lockDelayRectangleEndY - lockDelayRectangleStartY);

    lockDelayRectangle.setSize(sf::Vector2f(textLabelInnerRectangle.getLocalBounds().width + currentLockDelaySizeIncreaseValue,
        textLabelInnerRectangle.getLocalBounds().height + valueInnerRectangle.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
    lockDelayRectangle.setPosition(currentLockDelayScoreRectangleSizeX, currentLockDelayScoreRectangleSizeY);
}

void ObserverScore::resetLockDelayRectangle()
{
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(textLabelInnerRectangle.getLocalBounds().width, textLabelInnerRectangle.getLocalBounds().height + valueInnerRectangle.getLocalBounds().height));
}

void ObserverScore::update(int score)
{
    this->score = score;
    scoreValue.setString(std::to_string(this->score));
    scoreValue.setOrigin(scoreValue.getLocalBounds().left + scoreValue.getLocalBounds().width / 2.0f,
        scoreValue.getLocalBounds().top + scoreValue.getLocalBounds().height / 2.0f);
    scoreValue.setPosition(valueInnerRectangle.getPosition().x + valueInnerRectangle.getLocalBounds().left + valueInnerRectangle.getLocalBounds().width / 2.0f,
        valueInnerRectangle.getPosition().y + valueInnerRectangle.getLocalBounds().top + valueInnerRectangle.getLocalBounds().height / 2.0f);
}

void ObserverScore::draw(sf::RenderWindow& window)
{
    window.draw(outerRectangle);
    window.draw(lockDelayRectangle);
    window.draw(textLabelInnerRectangle);
    window.draw(valueInnerRectangle);
    window.draw(scoreTextLabel);
    window.draw(scoreValue);
}