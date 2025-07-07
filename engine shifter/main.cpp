#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "funtions.h"
#include <iostream>
#include <cmath>
#include <ctime>


int main()
{
#pragma region CAN EDIT
    int gameWidth = 512;
    int gameHeight = 288;
    std::string name = "Juego 1";
    int cameraWidth = 288;
    int cameraHeight = 144;
#pragma endregion
#pragma region DO NOT EDIT

    sf::RenderWindow window(sf::VideoMode(cameraWidth, gameHeight) , name);

    sf::View camara(sf::FloatRect(0, 0, cameraWidth, cameraHeight));

    start_event(window);

    while (window.isOpen())
    {
        window.setView(camara);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        update_event(window);
        window.display();
    }
    return 0;
#pragma endregion
}
