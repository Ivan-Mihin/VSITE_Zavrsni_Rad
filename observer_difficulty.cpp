#include "observer_difficulty.h"

ObserverDifficulty::ObserverDifficulty(ManagerDifficulty& manager) : managerDifficulty(manager)
{
    difficulty = 1;
    score = 0;

    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    innerRectangleColor.r = 25;
    innerRectangleColor.g = 25;
    innerRectangleColor.b = 25;

    outerRectangle.setPosition(20, 375);
    outerRectangle.setSize(sf::Vector2f(170, 120));
    outerRectangle.setFillColor(sf::Color::Black);

    textLabel1InnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10);
    textLabel1InnerRectangle.setSize(sf::Vector2f(150, 50));
    textLabel1InnerRectangle.setFillColor(innerRectangleColor);

    textLabel2InnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10 + textLabel1InnerRectangle.getSize().y);
    textLabel2InnerRectangle.setSize(sf::Vector2f(150, 50));
    textLabel2InnerRectangle.setFillColor(innerRectangleColor);

    textLabel1.setFont(font);
    textLabel1.setCharacterSize(30);
    textLabel1.setFillColor(sf::Color::White);
    textLabel1.setString("Difficulty");
    textLabel1.setOrigin(textLabel1.getLocalBounds().left + textLabel1.getLocalBounds().width / 2.0f,
        textLabel1.getLocalBounds().top + textLabel1.getLocalBounds().height / 2.0f);
    textLabel1.setPosition(textLabel1InnerRectangle.getPosition().x + textLabel1InnerRectangle.getLocalBounds().left + textLabel1InnerRectangle.getLocalBounds().width / 2.0f,
        textLabel1InnerRectangle.getPosition().y + textLabel1InnerRectangle.getLocalBounds().top + textLabel1InnerRectangle.getLocalBounds().height / 2.0f);

    textLabel2.setFont(font);
    textLabel2.setCharacterSize(30);
    textLabel2.setFillColor(sf::Color::White);
    textLabel2.setString("Increase");
    textLabel2.setOrigin(textLabel2.getLocalBounds().left + textLabel2.getLocalBounds().width / 2.0f,
        textLabel2.getLocalBounds().top + textLabel2.getLocalBounds().height / 2.0f);
    textLabel2.setPosition(textLabel2InnerRectangle.getPosition().x + textLabel2InnerRectangle.getLocalBounds().left + textLabel2InnerRectangle.getLocalBounds().width / 2.0f,
        textLabel2InnerRectangle.getPosition().y + textLabel2InnerRectangle.getLocalBounds().top + textLabel2InnerRectangle.getLocalBounds().height / 2.0f);

    lockDelayRectangleStartX = textLabel1InnerRectangle.getPosition().x;
    lockDelayRectangleStartY = textLabel1InnerRectangle.getPosition().y;
    lockDelayRectangleEndX = outerRectangle.getPosition().x;
    lockDelayRectangleEndY = outerRectangle.getPosition().y;
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(textLabel1InnerRectangle.getLocalBounds().width, textLabel1InnerRectangle.getLocalBounds().height + textLabel2InnerRectangle.getLocalBounds().height));

    duration = 3.0f;
    didDifficultyIncrease = false;
}

void ObserverDifficulty::draw(sf::RenderWindow& window)
{
    if (clock.getElapsedTime().asSeconds() <= duration && didDifficultyIncrease)
    {
        window.draw(outerRectangle);
        window.draw(lockDelayRectangle);
        window.draw(textLabel1InnerRectangle);
        window.draw(textLabel2InnerRectangle);
        window.draw(textLabel1);
        window.draw(textLabel2);
    }
    else
    {
        didDifficultyIncrease = false;
    }
}

void ObserverDifficulty::resetLockDelayRectangle()
{
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(textLabel1InnerRectangle.getLocalBounds().width, textLabel1InnerRectangle.getLocalBounds().height + textLabel2InnerRectangle.getLocalBounds().height));
}

void ObserverDifficulty::setLockDelayColor(sf::Color color)
{
    lockDelayRectangle.setFillColor(color);
}

void ObserverDifficulty::setLockDelayRectangle(float t, float currentLockDelaySizeIncreaseValue)
{
    float currentLockDelayRectangleSizeX = lockDelayRectangleStartX + t * (lockDelayRectangleEndX - lockDelayRectangleStartX);
    float currentLockDelayRectangleSizeY = lockDelayRectangleStartY + t * (lockDelayRectangleEndY - lockDelayRectangleStartY);

    lockDelayRectangle.setSize(sf::Vector2f(textLabel1InnerRectangle.getLocalBounds().width + currentLockDelaySizeIncreaseValue,
        textLabel1InnerRectangle.getLocalBounds().height + textLabel2InnerRectangle.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
    lockDelayRectangle.setPosition(currentLockDelayRectangleSizeX, currentLockDelayRectangleSizeY);
}

void ObserverDifficulty::update(std::pair<std::string, int> updateData)
{
    if (updateData.first == "difficulty")
    {
        this->difficulty = updateData.second;
    }
    else if (updateData.first == "score")
    {
        score = updateData.second;
        const int SCORE_THRESHOLDS[] = { 300, 700, 1200, 1800, 2500 };
        const int MAX_DIFFICULTY_LEVEL = sizeof(SCORE_THRESHOLDS) / sizeof(SCORE_THRESHOLDS[0]);

        if (difficulty <= MAX_DIFFICULTY_LEVEL && score >= SCORE_THRESHOLDS[difficulty - 1])
        {
            managerDifficulty.increaseDifficulty();

            didDifficultyIncrease = true;
            clock.restart();
        }
    }
}