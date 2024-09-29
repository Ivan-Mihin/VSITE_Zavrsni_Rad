#include "observer_difficulty.h"

ObserverDifficulty::ObserverDifficulty(ManagerDifficulty& manager) : managerDifficulty(manager)
{
    scoreDifficulty = 1;
    timeDifficulty = 1;
    isScoreDifficultyIncreased = false;
    isTimeDifficultyIncreased = false;
    score = 0;

    // Draw
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
    textLabel2InnerRectangle.setFillColor(innerRectangleColor );

    textLabel3InnerRectangle.setPosition(outerRectangle.getPosition().x + 10, outerRectangle.getPosition().y + 10 + textLabel1InnerRectangle.getSize().y + textLabel2InnerRectangle.getSize().y);
    textLabel3InnerRectangle.setSize(sf::Vector2f(150, 50));
    textLabel3InnerRectangle.setFillColor(innerRectangleColor);

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
    textLabel2.setString("Increased");
    textLabel2.setOrigin(textLabel2.getLocalBounds().left + textLabel2.getLocalBounds().width / 2.0f,
        textLabel2.getLocalBounds().top + textLabel2.getLocalBounds().height / 2.0f);
    textLabel2.setPosition(textLabel2InnerRectangle.getPosition().x + textLabel2InnerRectangle.getLocalBounds().left + textLabel2InnerRectangle.getLocalBounds().width / 2.0f,
        textLabel2InnerRectangle.getPosition().y + textLabel2InnerRectangle.getLocalBounds().top + textLabel2InnerRectangle.getLocalBounds().height / 2.0f);

    textLabel3.setFont(font);
    textLabel3.setCharacterSize(30);
    textLabel3.setFillColor(sf::Color::White);
    textLabel3.setString("Reached");
    textLabel3.setOrigin(textLabel3.getLocalBounds().left + textLabel3.getLocalBounds().width / 2.0f,
        textLabel3.getLocalBounds().top + textLabel3.getLocalBounds().height / 2.0f);
    textLabel3.setPosition(textLabel3InnerRectangle.getPosition().x + textLabel3InnerRectangle.getLocalBounds().left + textLabel3InnerRectangle.getLocalBounds().width / 2.0f,
        textLabel3InnerRectangle.getPosition().y + textLabel3InnerRectangle.getLocalBounds().top + textLabel3InnerRectangle.getLocalBounds().height / 2.0f);

    lockDelayRectangleStartX = textLabel1InnerRectangle.getPosition().x;
    lockDelayRectangleStartY = textLabel1InnerRectangle.getPosition().y;
    lockDelayRectangleEndX = outerRectangle.getPosition().x;
    lockDelayRectangleEndY = outerRectangle.getPosition().y;
    lockDelayRectangle.setPosition(sf::Vector2f(lockDelayRectangleStartX, lockDelayRectangleStartY));
    lockDelayRectangle.setSize(sf::Vector2f(textLabel1InnerRectangle.getLocalBounds().width, textLabel1InnerRectangle.getLocalBounds().height + textLabel2InnerRectangle.getLocalBounds().height));
}

void ObserverDifficulty::draw(sf::RenderWindow& window)
{
    if (clockForDrawing.getElapsedTime().asSeconds() <= duration && (isScoreDifficultyIncreased || isTimeDifficultyIncreased))
    {
        window.draw(outerRectangle);
        window.draw(lockDelayRectangle);
        window.draw(textLabel1InnerRectangle);
        window.draw(textLabel2InnerRectangle);
        window.draw(textLabel3InnerRectangle);

        if (static_cast<int>(clockForDrawing.getElapsedTime().asSeconds()) != 2 && static_cast<int>(clockForDrawing.getElapsedTime().asSeconds()) != 3)
        {
            textLabel1.setString("Difficulty");
            textLabel1.setOrigin(textLabel1.getLocalBounds().left + textLabel1.getLocalBounds().width / 2.0f,
                textLabel1.getLocalBounds().top + textLabel1.getLocalBounds().height / 2.0f);
            textLabel1.setPosition(textLabel1InnerRectangle.getPosition().x + textLabel1InnerRectangle.getLocalBounds().left + textLabel1InnerRectangle.getLocalBounds().width / 2.0f,
                textLabel2InnerRectangle.getPosition().y);
            setTextColor(&textLabel1);
            window.draw(textLabel1);

            textLabel2.setString("Increased");
            textLabel2.setOrigin(textLabel2.getLocalBounds().left + textLabel2.getLocalBounds().width / 2.0f,
                textLabel2.getLocalBounds().top + textLabel2.getLocalBounds().height / 2.0f);
            textLabel2.setPosition(textLabel2InnerRectangle.getPosition().x + textLabel2InnerRectangle.getLocalBounds().left + textLabel2InnerRectangle.getLocalBounds().width / 2.0f,
                textLabel3InnerRectangle.getPosition().y);
            setTextColor(&textLabel2);
            window.draw(textLabel2);
        }
        else
        {
            if (isScoreDifficultyIncreased)
            {
                textLabel1.setString("Score");
            }
            else if (isTimeDifficultyIncreased)
            {
                textLabel1.setString("Time");
            }

            textLabel1.setOrigin(textLabel1.getLocalBounds().left + textLabel1.getLocalBounds().width / 2.0f,
                textLabel1.getLocalBounds().top + textLabel1.getLocalBounds().height / 2.0f);
            textLabel1.setPosition(textLabel1InnerRectangle.getPosition().x + textLabel1InnerRectangle.getLocalBounds().left + textLabel1InnerRectangle.getLocalBounds().width / 2.0f,
                textLabel1InnerRectangle.getPosition().y + textLabel1InnerRectangle.getLocalBounds().top + textLabel1InnerRectangle.getLocalBounds().height / 2.0f);
            setTextColor(&textLabel1);
            window.draw(textLabel1);

            textLabel2.setString("Threshold");
            textLabel2.setOrigin(textLabel2.getLocalBounds().left + textLabel2.getLocalBounds().width / 2.0f,
                textLabel2.getLocalBounds().top + textLabel2.getLocalBounds().height / 2.0f);
            textLabel2.setPosition(textLabel2InnerRectangle.getPosition().x + textLabel2InnerRectangle.getLocalBounds().left + textLabel2InnerRectangle.getLocalBounds().width / 2.0f,
                textLabel2InnerRectangle.getPosition().y + textLabel2InnerRectangle.getLocalBounds().top + textLabel2InnerRectangle.getLocalBounds().height / 2.0f);
            setTextColor(&textLabel2);
            window.draw(textLabel2);

            textLabel3.setString("Reached");
            textLabel3.setOrigin(textLabel3.getLocalBounds().left + textLabel3.getLocalBounds().width / 2.0f,
                textLabel3.getLocalBounds().top + textLabel3.getLocalBounds().height / 2.0f);
            textLabel3.setPosition(textLabel3InnerRectangle.getPosition().x + textLabel3InnerRectangle.getLocalBounds().left + textLabel3InnerRectangle.getLocalBounds().width / 2.0f,
                textLabel3InnerRectangle.getPosition().y + textLabel3InnerRectangle.getLocalBounds().top + textLabel3InnerRectangle.getLocalBounds().height / 2.0f);
            setTextColor(&textLabel3);
            window.draw(textLabel3);
        }
    }
    else
    {
        isScoreDifficultyIncreased = false;
        isTimeDifficultyIncreased = false;
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

void ObserverDifficulty::setTextColor(sf::Text* text)
{
    float elapsedTime = clockForChangingColor.getElapsedTime().asSeconds();

    if (elapsedTime >= 2.0f)
    {
        clockForChangingColor.restart();
        elapsedTime = 0.0f;
    }

    float intensity = (std::sin((elapsedTime * 3.141592f) - 3.141592f / 2.0f) + 1.0f) / 2.0f * 230.0f + 25.0f;
    sf::Color color(intensity, intensity, intensity);
    text->setFillColor(color);
}

void ObserverDifficulty::update(std::pair<std::string, int> updateData)
{
    if (updateData.first == "difficulty-score")
    {
        if (updateData.second <= MAX_SCORE_DIFFICULTY_LEVEL)
        {
            scoreDifficulty = updateData.second;
        }
    }
    else if (updateData.first == "difficulty-time")
    {
        if (updateData.second <= MAX_TIME_DIFFICULTY_LEVEL)
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
        isScoreDifficultyIncreased = true;
        clockForDrawing.restart();
        clockForChangingColor.restart();
    }
}

void ObserverDifficulty::updateDifficultyBasedOnTime(float timeValue)
{
    const int TIME_THRESHOLDS[] = { 60, 120, 180, 240, 300 };

    if (timeDifficulty < MAX_TIME_DIFFICULTY_LEVEL && static_cast<int>(timeValue) >= TIME_THRESHOLDS[timeDifficulty - 1])
    {
        managerDifficulty.increaseTimeDifficulty();
        isTimeDifficultyIncreased = true;
        clockForDrawing.restart();
        clockForChangingColor.restart();
    }
}