#pragma once

#include <SFML/Graphics.hpp>
#include <stack>
#include "State.h"

using namespace sf;
using namespace std;

class Game 
{
private:
    Game();

    static Game* instance;
    stack<State*> states;
    RenderWindow window;

public:
    static Game& getInstance();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    void run();
    void changeState(State* newState);
    void pushState(State* newState);
    void popState();
    State* currentState();
    RenderWindow& getWindow();
};