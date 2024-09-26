#include "state_main_menu.h"

StateMainMenu::StateMainMenu(CommandExitGame* commandExitGame) : commandExitGame(commandExitGame)
{
    background.loadFromFile("Resources/Sprites/main_menu_background_2.png");
    backgroundSprite.setTexture(background);
    backgroundSprite.setPosition(0, 0);

    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    logo.loadFromFile("Resources/Sprites/tetris_logo.png");
    logoSprite.setTexture(logo);
    logoSprite.setOrigin(250, 0);
    logoSprite.setPosition(400, 100);

    text.setFont(font);
    text.setString("Press Enter to Start");
    text.setCharacterSize(65);
    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
    text.setPosition(400, 600);

    commandStartGame = new CommandStartGame();
}

StateMainMenu::~StateMainMenu()
{
    delete commandStartGame;
}

void StateMainMenu::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Enter)
        {
            commandStartGame->execute();
        }
        else if (event.key.code == sf::Keyboard::Escape)
        {
            commandExitGame->execute();
        }
    }
}

void StateMainMenu::update(float deltaTime)
{
    sf::Time elapsed = clock.getElapsedTime();
    float time = elapsed.asSeconds();
    float intensity = (std::sin(time * 2.0f) + 1.0f) / 2.0f * 255;
    sf::Color color(intensity, intensity, intensity);
    text.setFillColor(color);
}

void StateMainMenu::render(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    window.draw(logoSprite);
    window.draw(text);
}