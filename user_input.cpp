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

void CommandMoveDown::execute()
{
    tetromino.moveDown();
}

void CommandExitGame::execute()
{
    window->close();
}

void CommandStartGame::execute()
{
    Game::getInstance().changeState(new PlayingState());
}