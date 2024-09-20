#include "game.h"
#include "state_main_menu.h"

Game::Game() : window(sf::VideoMode(800, 800), "Tetris!") , commandExitGame(new CommandExitGame(&window))
{
    commandStartGame = new CommandStartGame();
    changeState(new StateMainMenu(commandExitGame));
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
    sf::Clock clock;

    while (window.isOpen()) 
    {
        sf::Time elapsed = clock.restart();
        float deltaTime = elapsed.asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) 
        {
            if (event.type == sf::Event::Closed) 
            {
                window.close();
            }

            currentState()->handleInput(event);
        }

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

sf::RenderWindow& Game::getWindow()
{ 
    return window; 
}