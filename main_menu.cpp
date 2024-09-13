#include <cmath>
#include <SFML/Window.hpp>

#include "game.h"
#include "state_main_menu.h"
#include "state_playing.h"

MainMenuState::MainMenuState() 
{
    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    mainMenuBackground.loadFromFile("Resources/Sprites/main_menu_background_2.png");
    mainMenuBackgroundSprite.setTexture(mainMenuBackground);
    mainMenuBackgroundSprite.setPosition(0, 0);

    tetrisLogo.loadFromFile("Resources/Sprites/tetris_logo.png");
    tetrisLogoSprite.setTexture(tetrisLogo);
    tetrisLogoSprite.setOrigin(250, 0);
    tetrisLogoSprite.setPosition(400, 100);

    startText.setFont(font);
    startText.setString("Press Enter to Start");
    startText.setCharacterSize(65);
    startTextBounds = startText.getLocalBounds();
    startText.setOrigin(startTextBounds.left + startTextBounds.width / 2.0f, startTextBounds.top + startTextBounds.height / 2.0f);
    startText.setPosition(400, 600);
}

void MainMenuState::handleInput(sf::RenderWindow& window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) 
    {
        //Game::getInstance().changeState(new PlayingState());
    }
}

void MainMenuState::update(float deltaTime)
{
    sf::Time elapsed = clock.getElapsedTime();
    float time = elapsed.asSeconds();
    float intensity = (std::sin(time * 2.0f) + 1.0f) / 2.0f * 255;
    sf::Color color(intensity, intensity, intensity);
    startText.setFillColor(color);
}

void MainMenuState::render(sf::RenderWindow& window)
{
    window.draw(mainMenuBackgroundSprite);
    window.draw(tetrisLogoSprite);
    window.draw(startText);
}