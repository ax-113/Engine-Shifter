#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>

void randomize();
void load_animation_spritesheet(sf::Sprite sprite, int frame_width, int frame_height);
void animation_draw(int amount_sprites_in_column, int row_to_draw, int frame_width, int frame_height, sf::Sprite sprite, float maxTime, sf::RenderWindow WINDOW, int timer, int temp_val);
void start_event(sf::RenderWindow& window);
void update_event(sf::RenderWindow& window);