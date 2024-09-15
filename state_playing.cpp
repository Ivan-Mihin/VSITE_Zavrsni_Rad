    #include "state_playing.h"

PlayingState::PlayingState()
{
    tetrisGame.initialize();
}

void PlayingState::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Enter)
        {
            //Game::getInstance().changeState(new PausedState());
        }
    }

    tetrisGame.handleInput(event);
}

void PlayingState::update(float deltaTime)
{
    tetrisGame.update(deltaTime);
}

void PlayingState::render(sf::RenderWindow& window)
{
    tetrisGame.render(window);
}