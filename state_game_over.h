#pragma once
#include <SFML/Graphics.hpp>
#include "state.h"
#include "game.h"

class GameOverState : public State 
{
private:
    sf::Font font;
    sf::Text gameOverText;
    sf::FloatRect gameOverTextBounds;

    sf::Clock clock;

    sf::Texture gameOverBackground;
    sf::Sprite gameOverBackgroundSprite;

    sf::Texture gameOverLogo;
    sf::Sprite gameOverLogoSprite;

    CommandStartGame* commandStartGame;
    CommandExitGame* commandExitGame;

public:
    GameOverState(CommandStartGame* commandStartGame, CommandExitGame* commandExitGame);

    void handleInput(sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};