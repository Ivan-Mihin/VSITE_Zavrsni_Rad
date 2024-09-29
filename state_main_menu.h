#pragma once
#include <SFML/Graphics.hpp>
#include "audio.h"
#include "command.h"
#include "state.h"

class StateMainMenu : public State 
{
private:
    sf::Texture background;
    sf::Sprite backgroundSprite;
    sf::Clock clock;
    sf::Font font;
    sf::Texture logo;
    sf::Sprite logoSprite;
    sf::Text text;
    AudioThemeSong audioThemeSong;

    CommandStartGame* commandStartGame;
    CommandExitGame* commandExitGame;

public:
    StateMainMenu(CommandExitGame* commandExitGame);
    ~StateMainMenu();

    void handleInput(sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};