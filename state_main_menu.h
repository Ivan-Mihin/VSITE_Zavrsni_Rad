#pragma once

#include <SFML/Graphics.hpp>

#include "state.h"
#include "state_playing.h"

using namespace sf;

class MainMenuState : public State 
{
private:
    Font font;
    Text startText;
    FloatRect startTextBounds;
    Clock clock;
    Texture mainMenuBackground;
    Texture tetrisLogo;
    Sprite mainMenuBackgroundSprite;
    Sprite tetrisLogoSprite;

public:
    MainMenuState();

    void handleInput(RenderWindow& window) override;
    void update(float deltaTime) override;
    void render(RenderWindow& window) override;
};