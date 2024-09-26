#pragma once
#include <SFML/Graphics.hpp>
#include "command.h"
#include "state.h"

class StateGameOver : public State 
{
private:
    sf::Texture background;
    sf::Sprite backgroundSprite;
    sf::Clock clock;
    sf::Font font;
    sf::Texture logo;
    sf::Sprite logoSprite;
    sf::Text text;

    CommandStartGame* commandStartGame;
    CommandExitGame* commandExitGame;

public:
    StateGameOver(CommandExitGame* commandExitGame);
    ~StateGameOver();

    void handleInput(sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};