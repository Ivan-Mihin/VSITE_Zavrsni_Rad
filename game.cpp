#include "game.h"
#include "state_main_menu.h"

Game::Game() : window(VideoMode(800, 800), "Tetris!")
{
    changeState(new MainMenuState());
}

Game* Game::instance = nullptr;

Game& Game::getInstance() 
{
    if (instance == nullptr) 
    {
        instance = new Game();
    }

    return *instance;
}

void Game::run()
{
    Clock clock;

    while (window.isOpen()) 
    {
        Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == Event::Closed) 
            {
                window.close();
            }
        }

        currentState()->handleInput(window);
        currentState()->update(deltaTime);

        window.clear();
        currentState()->render(window);
        window.display();
    }
}

void Game::changeState(State* newState) 
{
    if (!states.empty()) 
    {
        delete states.top();
        states.pop();
    }

    states.push(newState);
}

void Game::pushState(State* newState) 
{
    states.push(newState);
}

void Game::popState() 
{
    if (!states.empty()) 
    {
        delete states.top();
        states.pop();
    }
}

State* Game::currentState() 
{
    return states.top();
}

RenderWindow& Game::getWindow()
{ 
    return window; 
}