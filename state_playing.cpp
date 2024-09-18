#include "state_playing.h"

PlayingState::PlayingState(CommandExitGame* commandExitGame, CommandEndGame* commandEndGame) : commandExitGame(commandExitGame) , commandEndGame(commandEndGame)
{
    tetrisGame.initialize();
}

void PlayingState::handleInput(sf::Event& event)
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

void PlayingState::update(float deltaTime)
{
    tetrisGame.update(deltaTime);

    if (tetrisGame.gameOver)
    {
        commandEndGame->execute();
    }
}

void PlayingState::render(sf::RenderWindow& window)
{
    tetrisGame.render(window);
}