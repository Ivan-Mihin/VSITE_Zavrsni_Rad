#include <SFML/Window.hpp>
#include "game.h"
#include "state_playing.h"
#include "user_input.h"

void CommandMoveLeft::execute()
{
    tetromino.moveLeft();
}

void CommandMoveRight::execute()
{
    tetromino.moveRight();
}

void CommandExitGame::execute()
{
    window->close();
}

void CommandStartGame::execute()
{
    Game::getInstance().changeState(new PlayingState());
}

void InputHandler::handleInput(sf::Event& event) 
{
    if (event.type == sf::Event::KeyPressed) 
    {
        switch (event.key.code) 
        {
        case sf::Keyboard::Left:
        {
            moveLeft->execute();
            break;
        }
        case sf::Keyboard::Right:
        {
            moveRight->execute();
            break;
        }
        default:
            break;
        }
    }
}