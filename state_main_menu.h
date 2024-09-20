#pragma once
#include <SFML/Graphics.hpp>
#include "state.h"
#include "command.h"

class StateMainMenu : public State 
{
private:
    sf::Font font;
    sf::Text startText;
    sf::FloatRect startTextBounds;

    sf::Clock clock;

    sf::Texture mainMenuBackground;
    sf::Sprite mainMenuBackgroundSprite;

    sf::Texture tetrisLogo;
    sf::Sprite tetrisLogoSprite;

    CommandStartGame* commandStartGame;
    CommandExitGame* commandExitGame;

public:
    StateMainMenu(CommandExitGame* commandExitGame);

    void handleInput(sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};