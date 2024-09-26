#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include "state.h"
#include "command.h"

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
    ~Game();

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static void destroy();
    static Game& getInstance();

    State* getCurrentState();
    sf::RenderWindow& getWindow();

    void changeState(State* newState);
    void popState();
    void pushState(State* newState);
    void run();
};