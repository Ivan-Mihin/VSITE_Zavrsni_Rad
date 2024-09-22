#include "state_game_over.h"

StateGameOver::StateGameOver(CommandExitGame* commandExitGame) : commandExitGame(commandExitGame)
{
    commandStartGame = new CommandStartGame();

    font.loadFromFile("../../Resources/Fonts/BaiJamjuree-Regular.ttf");

    gameOverBackground.loadFromFile("../../Resources/Sprites/main_menu_background_2.png");
    gameOverBackgroundSprite.setTexture(gameOverBackground);
    gameOverBackgroundSprite.setPosition(0, 0);

    gameOverLogo.loadFromFile("../../Resources/Sprites/game_over_logo.png");
    gameOverLogoSprite.setTexture(gameOverLogo);
    gameOverLogoSprite.setOrigin(250, 0);
    gameOverLogoSprite.setPosition(400, 100);

    gameOverText.setFont(font);
    gameOverText.setString("Press Enter to Restart");
    gameOverText.setCharacterSize(65);
    gameOverTextBounds = gameOverText.getLocalBounds();
    gameOverText.setOrigin(gameOverTextBounds.left + gameOverTextBounds.width / 2.0f, gameOverTextBounds.top + gameOverTextBounds.height / 2.0f);
    gameOverText.setPosition(400, 600);
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
    gameOverText.setFillColor(color);
}

void StateGameOver::render(sf::RenderWindow& window)
{
    window.draw(gameOverBackgroundSprite);
    window.draw(gameOverLogoSprite);
    window.draw(gameOverText);
}