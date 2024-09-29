#include "state_game_over.h"

StateGameOver::StateGameOver(CommandExitGame* commandExitGame) : commandExitGame(commandExitGame)
{
    audioThemeSong.getSfxTetrisThemeSong().setLoop(true);
    audioThemeSong.getSfxTetrisThemeSong().setVolume(15);
    audioThemeSong.getSfxTetrisThemeSong().play();

    background.loadFromFile("Resources/Sprites/main_menu_background_2.png");
    backgroundSprite.setTexture(background);
    backgroundSprite.setPosition(0, 0);

    font.loadFromFile("Resources/Fonts/BaiJamjuree-Regular.ttf");

    logo.loadFromFile("Resources/Sprites/game_over_logo.png");
    logoSprite.setTexture(logo);
    logoSprite.setOrigin(250, 0);
    logoSprite.setPosition(400, 100);

    text.setFont(font);
    text.setString("Press Enter to Restart");
    text.setCharacterSize(65);
    text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2.0f, text.getLocalBounds().top + text.getLocalBounds().height / 2.0f);
    text.setPosition(400, 600);

    commandStartGame = new CommandStartGame();
}

StateGameOver::~StateGameOver()
{
    delete commandStartGame;
}

void StateGameOver::handleInput(sf::Event& event)
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

void StateGameOver::update(float deltaTime)
{
    sf::Time elapsed = clock.getElapsedTime();
    float time = elapsed.asSeconds();
    float intensity = (std::sin(time * 2.0f) + 1.0f) / 2.0f * 255;
    sf::Color color(intensity, intensity, intensity);
    text.setFillColor(color);
}

void StateGameOver::render(sf::RenderWindow& window)
{
    window.draw(backgroundSprite);
    window.draw(logoSprite);
    window.draw(text);
}