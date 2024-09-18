#include "score_display.h"

ScoreDisplay::ScoreDisplay() : currentScore(0) 
{
    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);
    scoreText.setString("Score: 0");
}

void ScoreDisplay::update(int score)
{
    currentScore = score;
    scoreText.setString("Score: " + std::to_string(currentScore));
}

void ScoreDisplay::draw(sf::RenderWindow& window) 
{
    window.draw(scoreText);
}