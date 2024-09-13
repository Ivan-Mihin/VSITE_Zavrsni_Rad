#include <SFML/Window.hpp>
#include "user_input.h"

void CommandMoveLeft::execute()
{
    tetromino.moveLeft();
}

void CommandMoveRight::execute()
{
    tetromino.moveRight();
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