#include <SFML/Window.hpp>
#include "game.h"
#include "state_game_over.h"
#include "state_playing.h"
#include "command.h"

CommandMoveLeft::CommandMoveLeft(Tetromino* tetromino)
{
    this->tetromino = tetromino;
}

void CommandMoveLeft::execute()
{
    tetromino->moveLeft();
}

CommandMoveRight::CommandMoveRight(Tetromino* tetromino)
{
    this->tetromino = tetromino;
}

void CommandMoveRight::execute()
{
    tetromino->moveRight();
}

CommandRotate::CommandRotate(Tetromino* tetromino)
{
    this->tetromino = tetromino;
}

void CommandRotate::execute()
{
    tetromino->rotate();
}

void CommandStartGame::execute()
{
    Game::getInstance().changeState(new StatePlaying(new CommandExitGame(&Game::getInstance().getWindow())));
}

void CommandEndGame::execute()
{
    Game::getInstance().changeState(new StateGameOver(new CommandExitGame(&Game::getInstance().getWindow())));
}

CommandExitGame::CommandExitGame(sf::RenderWindow* window)
{
    this->window = window;
}

void CommandExitGame::execute()
{
    window->close();
}