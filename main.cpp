#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "tetromino.h"

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(800, 800), "TETRIS!", Style::Close);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}