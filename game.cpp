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

State* Game::getCurrentState()
{
    return states.top();
}

sf::RenderWindow& Game::getWindow()
{
    return window;
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

void Game::popState()
{
    if (!states.empty())
    {
        delete states.top();
        states.pop();
    }
}

void Game::pushState(State* newState) 
{
    states.push(newState);
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

            getCurrentState()->handleInput(event);
        }

        getCurrentState()->update(deltaTime);

        window.clear();
        getCurrentState()->render(window);
        window.display();
    }
}