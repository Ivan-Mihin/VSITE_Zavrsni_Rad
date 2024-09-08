#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(800, 800), "TETRIS!", Style::Close);

    while (window.isOpen())
    {
        sf::Event event;
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