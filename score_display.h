#pragma once
#include <SFML/Graphics.hpp>
#include "observer.h"
#include "score_manager.h"

class ScoreDisplay : public Observer 
{
private:
    int currentScore;
    sf::Font font;
    sf::Text scoreLabel;
    sf::Text scoreText;

public:
    ScoreDisplay();

    void update(int score) override;
    void draw(sf::RenderWindow& window);
};