#include <SFML/Window.hpp>
#include "game.h"
#include "state_game_over.h"
#include "state_playing.h"
#include "command.h"

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

void CommandRotate::execute()
{
    tetromino.rotate();
}

void CommandExitGame::execute()
{
    window->close();
}

void CommandStartGame::execute()
{
    Game::getInstance().changeState(new PlayingState(new CommandExitGame(&Game::getInstance().getWindow()), new CommandEndGame()));
}

void CommandEndGame::execute()
{
    Game::getInstance().changeState(new GameOverState(new CommandStartGame(), new CommandExitGame(&Game::getInstance().getWindow())));
}