#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include "funtions.h"

void randomize() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

sf::Sprite load_animation_spritesheet(std::string path, int frame_width, int frame_height) {
	sf::Texture texture;
	if (!texture.loadFromFile(path)) { std::cerr << "Failed to load texture" << path; }
	sf::Sprite sprite(texture);
	sprite.setTextureRect({ {0,0},{frame_width,frame_height} });
	sprite.setOrigin({ sprite.getTextureRect().width / 2.0, sprite.getTextureRect().height / 2.0 });
	return sprite;
}	 

void animation_draw(int amount_sprites_in_column, int row_to_draw, int frame_width, int frame_height, sf::Sprite sprite, float maxTime, sf::RenderWindow WINDOW, int timer, int temp_val) {
	timer += 0.1;
	if (timer >= maxTime) {
		temp_val += frame_width;
		if (temp_val >= row_to_draw * frame_width) {
			temp_val = 0;
		}
		else {
			sprite.setTextureRect({ {row_to_draw * frame_width, amount_sprites_in_column * frame_height},{frame_width, frame_height} });

		}
	}
	WINDOW.draw(sprite);
}

sf::Sprite load_sprite(std::string path)
{
	sf::Texture texture;
	if (!texture.loadFromFile(path)) { std::cerr << "Failed to load texture" << path; }
	sf::Sprite sprite(texture);
	return sprite;
}

void sprite_draw(sf::Sprite sprite, sf::RenderWindow WINDOW)
{
	WINDOW.draw(sprite);
}

sf::Sprite load_tileset(std::string path, int tile_width, int tile_height)
{
	sf::Texture texture;
	if (!texture.loadFromFile(path)) { std::cerr << "Failed to load texture" << path; }
	sf::Sprite sprite(texture);
	sprite.setTextureRect({ {0,0},{tile_width,tile_height} });
	sprite.setOrigin({ sprite.getTextureRect().width / 2.0, sprite.getTextureRect().height / 2.0 });
	return sprite;
}

void tile_draw(sf::Sprite tilemap, sf::RenderWindow WINDOW, int tile_width, int tile_height, int row, int column)
{
	tilemap.setTextureRect({ {row * tile_width, column * tile_height},{tile_width, tile_height} });
	WINDOW.draw(tilemap);
}