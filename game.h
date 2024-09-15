#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include "state.h"
#include "user_input.h"

class Game 
{
private:
    Game();

    static Game* instance;
    std::stack<State*> states;
    sf::RenderWindow window;
    CommandStartGame* commandStartGame;
    CommandExitGame* commandExitGame;

public:
    static Game& getInstance();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void run();
    void changeState(State* newState);
    void pushState(State* newState);
    void popState();
    State* currentState();
    sf::RenderWindow& getWindow();
};