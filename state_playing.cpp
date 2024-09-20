#include "state_playing.h"

StatePlaying::StatePlaying(CommandExitGame* commandExitGame) : commandExitGame(commandExitGame)
{
    commandEndGame = new CommandEndGame();

    tetrisGame.initialize();
}

void StatePlaying::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Enter)
        {
            //Game::getInstance().changeState(new PausedState());
        }
        else if (event.key.code == sf::Keyboard::Escape)
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