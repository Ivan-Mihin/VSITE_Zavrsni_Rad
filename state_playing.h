#pragma once
#include <SFML/Graphics.hpp>
#include "state.h"
#include "tetris.h"

class PlayingState : public State 
{
private:
    Tetris tetrisGame;

public:
    PlayingState();

    void handleInput(sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
};