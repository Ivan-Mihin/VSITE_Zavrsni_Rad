#include "score_display.h"

ScoreDisplay::ScoreDisplay() : currentScore(0) 
{
    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    scoreLabel.setFont(font);
    scoreLabel.setCharacterSize(30);
    scoreLabel.setFillColor(sf::Color::White);
    scoreLabel.setString("Score");
    scoreLabel.setOrigin(scoreLabel.getLocalBounds().left + scoreLabel.getLocalBounds().width / 2.0f,
                         scoreLabel.getLocalBounds().top + scoreLabel.getLocalBounds().height / 2.0f);
    scoreLabel.setPosition(105, 45);

    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setString("0");
    scoreText.setOrigin(scoreText.getLocalBounds().left + scoreText.getLocalBounds().width / 2.0f, 
                        scoreText.getLocalBounds().top + scoreText.getLocalBounds().height / 2.0f);
    scoreText.setPosition(105, 75);
}

void ScoreDisplay::update(int score)
{
    currentScore = score;
    scoreText.setString(std::to_string(currentScore));
    scoreText.setOrigin(scoreText.getLocalBounds().left + scoreText.getLocalBounds().width / 2.0f,
        scoreText.getLocalBounds().top + scoreText.getLocalBounds().height / 2.0f);
    scoreText.setPosition(105, 75);
}

void ScoreDisplay::draw(sf::RenderWindow& window) 
{
    window.draw(scoreLabel);
    window.draw(scoreText);
}