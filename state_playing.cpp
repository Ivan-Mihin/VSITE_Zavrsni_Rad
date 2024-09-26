#include "state_playing.h"

StatePlaying::StatePlaying(CommandExitGame* commandExitGame) : commandExitGame(commandExitGame)
{
    tetrisGame.initialize();

    commandEndGame = new CommandEndGame();
}

StatePlaying::~StatePlaying()
{
    delete commandEndGame;
}

void StatePlaying::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Escape)
        {
            commandExitGame->execute();
        }
    }

    tetrisGame.handleInput(event);
}

void StatePlaying::update(float deltaTime)
{
    tetrisGame.update(deltaTime);

    if (tetrisGame.gameOver)
    {
        commandEndGame->execute();
    }
}

void StatePlaying::render(sf::RenderWindow& window)
{
    tetrisGame.render(window);
}