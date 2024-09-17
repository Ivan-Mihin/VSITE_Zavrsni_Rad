#pragma once
#include <SFML/Graphics.hpp>
#include "command.h"
#include "state.h"
#include "tetris.h"

class PlayingState : public State 
{
private:
    Tetris tetrisGame;
    CommandExitGame* commandExitGame;
    CommandEndGame* commandEndGame;

public:
    PlayingState(CommandExitGame* commandExitGame, CommandEndGame* commandEndgame);

    void handleInput(sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};