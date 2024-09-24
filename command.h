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
    Tetromino* tetromino;

public:
    CommandMoveLeft(Tetromino* tetromino);
    void execute() override;
};

class CommandMoveRight : public Command 
{
private:
    Tetromino* tetromino;

public:
    CommandMoveRight(Tetromino* tetromino);
    void execute() override;
};

class CommandRotate : public Command
{
private:
    Tetromino* tetromino;

public:
    CommandRotate(Tetromino* tetromino);
    void execute() override;
};

class CommandStartGame : public Command
{
public:
    CommandStartGame(){}
    void execute() override;
};

class CommandEndGame : public Command
{
public:
    CommandEndGame() {}
    void execute() override;
};

class CommandExitGame : public Command
{
private:
    sf::RenderWindow* window;

public:
    CommandExitGame(sf::RenderWindow* window);
    void execute() override;
};