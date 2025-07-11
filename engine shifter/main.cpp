#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "funtions.h"
#include <iostream>
#include <cmath>
#include <ctime>

int main()
{
#pragma region windows values
    int gameWidth = 512; //game width in pixel size
    int gameHeight = 288; //game height in pixel size
    std::string name = "Game 1"; //game name
    std::string icon_path = "C:/Users/axelc/source/repos/engine shifter/x64/Debug Dynamic/resources/temp_icon.png"; // change the window icon (full path)
    //if you want a camera use this
    int cameraWidth = gameWidth; //camera width in pixel size
    int cameraHeight = gameHeight; //camera height in pixel size
#pragma endregion
#pragma region DO NOT EDIT

    sf::RenderWindow window(sf::VideoMode(gameWidth, gameHeight) , name);

    sf::Image icon;
    if (!icon.loadFromFile(icon_path)) { std::cerr << "Failed to load image" << icon_path; }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::View camara(sf::FloatRect(0, 0, cameraWidth, cameraHeight));
#pragma endregion
#pragma region start_event
    sf::Texture red_tex;
    sf::Sprite red;
    if (!red_tex.loadFromFile("C:/Users/axelc/Downloads/red.png")) { std::cerr << "Failed to load texture 1"; }
    red.setTexture(red_tex);
    sf::Texture blue_tex;
    sf::Sprite blue;
    if (!blue_tex.loadFromFile("C:/Users/axelc/Downloads/blue.png")) { std::cerr << "Failed to load texture 2"; }
    blue.setTexture(blue_tex);
    red.setPosition(gameWidth / 2.0f, gameHeight / 2.0f);
    blue.setPosition(gameWidth / 2.0f + 120.0f, gameHeight / 2.0f);
    float speed = 0.1;
#pragma endregion
#pragma region DO NOT EDIT
    while (window.isOpen())
    {
        window.setView(camara);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
#pragma endregion
#pragma region update_event
        if (check_key_press('d')) { red.move(speed,0); }
        if (check_key_press('a')) { red.move(-speed, 0); }
        if (check_key_press('s')) { red.move(0, speed); }
        if (check_key_press('w')) { red.move(0, -speed); }

        if (check_key_press('l')) { blue.move(speed, 0); }
        if (check_key_press('j')) { blue.move(-speed, 0); }
        if (check_key_press('k')) { blue.move(0, speed); }
        if (check_key_press('i')) { blue.move(0, -speed); }
#pragma endregion
#pragma region DO NOT EDIT
        window.clear();
#pragma endregion
#pragma region draw_event
        sprite_draw(red, window);
        sprite_draw(blue, window);
#pragma endregion
#pragma region DO NOT EDIT
        window.display();
    }
    return 0;
#pragma endregion
}
