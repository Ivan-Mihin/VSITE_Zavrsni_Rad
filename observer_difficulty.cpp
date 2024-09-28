#include "observer_difficulty.h"

ObserverDifficulty::ObserverDifficulty(ManagerDifficulty& manager) : managerDifficulty(manager)
{
    scoreDifficulty = 1;
    timeDifficulty = 1;
    score = 0;

    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    innerRectangleColor.r = 25;
    innerRectangleColor.g = 25;
    innerRectangleColor.b = 25;

    outerRectangle.setPosition(20, 375);
    outerRectangle.setSize(sf::Vector2f(170, 170));
    outerRectangle.setFillColor(sf::Color::Black);

    textLabel1InnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10);
    textLabel1InnerRectangle.setSize(sf::Vector2f(150, 50));
    textLabel1InnerRectangle.setFillColor(innerRectangleColor);

    textLabel2InnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10 + textLabel1InnerRectangle.getSize().y);
    textLabel2InnerRectangle.setSize(sf::Vector2f(150, 50));
    textLabel2InnerRectangle.setFillColor(sf::Color::Red);

    textLabel3InnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10 + textLabel1InnerRectangle.getSize().y + textLabel2InnerRectangle.getSize().y);
    textLabel3InnerRectangle.setSize(sf::Vector2f(150, 50));
    textLabel3InnerRectangle.setFillColor(innerRectangleColor);

    textLabel1.setFont(font);
    textLabel1.setCharacterSize(30);
    textLabel1.setFillColor(sf::Color::White);
    textLabel1.setString("Score");
    textLabel1.setOrigin(textLabel1.getLocalBounds().left + textLabel1.getLocalBounds().width / 2.0f,
        textLabel1.getLocalBounds().top + textLabel1.getLocalBounds().height / 2.0f);
    textLabel1.setPosition(textLabel1InnerRectangle.getPosition().x + textLabel1InnerRectangle.getLocalBounds().left + textLabel1InnerRectangle.getLocalBounds().width / 2.0f,
        textLabel1InnerRectangle.getPosition().y + textLabel1InnerRectangle.getLocalBounds().top + textLabel1InnerRectangle.getLocalBounds().height / 2.0f);

    textLabel2.setFont(font);
    textLabel2.setCharacterSize(30);
    textLabel2.setFillColor(sf::Color::White);
    textLabel2.setString("Threshold");
    textLabel2.setOrigin(textLabel2.getLocalBounds().left + textLabel2.getLocalBounds().width / 2.0f,
        textLabel2.getLocalBounds().top + textLabel2.getLocalBounds().height / 2.0f);
    textLabel2.setPosition(textLabel2InnerRectangle.getPosition().x + textLabel2InnerRectangle.getLocalBounds().left + textLabel2InnerRectangle.getLocalBounds().width / 2.0f,
        textLabel2InnerRectangle.getPosition().y + textLabel2InnerRectangle.getLocalBounds().top + textLabel2InnerRectangle.getLocalBounds().height / 2.0f);

    textLabel3.setFont(font);
    textLabel3.setCharacterSize(30);
    textLabel3.setFillColor(sf::Color::White);
    textLabel3.setString("Reached");
    textLabel3.setOrigin(textLabel3.getLocalBounds().left + textLabel3.getLocalBounds().width / 2.0f,
        textLabel3.getLocalBounds().top + textLabel3.getLocalBounds().height / 2.0f + 5);
    textLabel3.setPosition(textLabel3InnerRectangle.getPosition().x + textLabel3InnerRectangle.getLocalBounds().left + textLabel3InnerRectangle.getLocalBounds().width / 2.0f,
        textLabel3InnerRectangle.getPosition().y + textLabel3InnerRectangle.getLocalBounds().top + textLabel3InnerRectangle.getLocalBounds().height / 2.0f);

    lockDelayRectangleStartX = textLabel1InnerRectangle.getPosition().x;
    lockDelayRectangleStartY = textLabel1InnerRectangle.getPosition().y;
    lockDelayRectangleEndX = outerRectangle.getPosition().x;
    lockDelayRectangleEndY = outerRectangle.getPosition().y;
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(textLabel1InnerRectangle.getLocalBounds().width, textLabel1InnerRectangle.getLocalBounds().height + textLabel2InnerRectangle.getLocalBounds().height));

    duration = 2.0f;
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
        window.draw(textLabel3InnerRectangle);
        window.draw(textLabel1);
        window.draw(textLabel2);
        window.draw(textLabel3);
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
        textLabel1InnerRectangle.getLocalBounds().height + textLabel2InnerRectangle.getLocalBounds().height + textLabel3InnerRectangle.getLocalBounds().height + currentLockDelaySizeIncreaseValue));
    lockDelayRectangle.setPosition(currentLockDelayRectangleSizeX, currentLockDelayRectangleSizeY);
}

void ObserverDifficulty::update(std::pair<std::string, int> updateData)
{
    if (updateData.first == "difficulty-score")
    {
        if (updateData.second <= 6)
        {
            scoreDifficulty = updateData.second;
        }
    }
    else if (updateData.first == "difficulty-time")
    {
        if (updateData.second <= 6)
        {
            timeDifficulty = updateData.second;
        }
    }  
    else if (updateData.first == "score")
    {
        score = updateData.second;
        updateDifficultyBasedOnScore();
    }
}

void ObserverDifficulty::updateDifficultyBasedOnScore()
{
    const int SCORE_THRESHOLDS[] = { 3000, 7000, 12000, 18000, 25000 };

    if (scoreDifficulty < MAX_SCORE_DIFFICULTY_LEVEL && score >= SCORE_THRESHOLDS[scoreDifficulty - 1])
    {
        managerDifficulty.increaseScoreDifficulty();
        didDifficultyIncrease = true;
        clock.restart();
    }
}

void ObserverDifficulty::updateDifficultyBasedOnTime(float timeValue)
{
    const int TIME_THRESHOLDS[] = { 60, 120, 180, 240, 300 };

    if (timeDifficulty < MAX_TIME_DIFFICULTY_LEVEL && static_cast<int>(timeValue) >= TIME_THRESHOLDS[timeDifficulty - 1])
    {
        managerDifficulty.increaseTimeDifficulty();
        didDifficultyIncrease = true;
        clock.restart();
    }
}