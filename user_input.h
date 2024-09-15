#pragma once
#include <SFML/Graphics.hpp>
#include "tetromino.h"

class Command 
{
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

class CommandMoveLeft : public Command 
{
private:
    Tetromino& tetromino;

public:
    CommandMoveLeft(Tetromino* t) : tetromino(*t) {}
    void execute() override;
};

class CommandMoveRight : public Command 
{
private:
    Tetromino& tetromino;

public:
    CommandMoveRight(Tetromino* t) : tetromino(*t) {}
    void execute() override;
};

class CommandStartGame : public Command
{
public:
    CommandStartGame(){}
    void execute() override;
};

class CommandExitGame : public Command
{
private:
    sf::RenderWindow* window;

public:
    CommandExitGame(sf::RenderWindow* window) : window(window) {}
    void execute() override;
};

class InputHandler 
{
private:
    Command* moveLeft;
    Command* moveRight;

public:
    InputHandler(Command* ml, Command* mr) : moveLeft(ml), moveRight(mr) {}

    void handleInput(sf::Event& event);
};