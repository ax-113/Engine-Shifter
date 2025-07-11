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
	sprite.setOrigin({ sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f });
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
	sprite.setOrigin({ sprite.getTextureRect().width / 2.0f, sprite.getTextureRect().height / 2.0f });
	return sprite;
}

void tile_draw(sf::Sprite tilemap, sf::RenderWindow WINDOW, int tile_width, int tile_height, int row, int column)
{
	tilemap.setTextureRect({ {row * tile_width, column * tile_height},{tile_width, tile_height} });
	WINDOW.draw(tilemap);
}

std::unique_ptr<sf::Music> load_music(std::string& path) {
	auto music = std::make_unique<sf::Music>();
	if (!music->openFromFile(path)) { std::cerr << "Failed to load music: " << path; }
	return music;
}

void music_play(std::unique_ptr<sf::Music> music)
	{
		if (music->getStatus() != sf::SoundSource::Playing)
		{
			music->play();
		}
	}

bool check_key_down(char letter)
{
	if (letter >= 'a' && letter <= 'z')
		letter = letter - 'a' + 'A';

	if (letter >= 'A' && letter <= 'Z') {
		sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(sf::Keyboard::A + (letter - 'A'));
		return sf::Keyboard::isKeyPressed(key);
	}
	return false;
}

bool click_on_sprite(short button, sf::Sprite sprite, sf::RenderWindow WINDOW) 
{
	sf::Vector2i position = sf::Mouse::getPosition(WINDOW);
	sf::Mouse::Button temp;
	switch (button) {
	case (1):
		temp = sf::Mouse::Button::Left;
		break;
	case (2):
		temp = sf::Mouse::Button::Right;
		break;
	case (3):
		temp = sf::Mouse::Button::Middle;
		break;
	}
	if (sf::Mouse::isButtonPressed(temp) && position.x >= sprite.getPosition().x && position.x <= sprite.getPosition().x + sprite.getScale().x && position.y >= sprite.getPosition().y && position.y <= sprite.getPosition().y + sprite.getScale().y){
		return true;
	}

}

bool check_collision(sf::Sprite spr_1, sf::Sprite spr_2)
{
	int x1 = spr_1.getPosition().x;
	int x2 = spr_2.getPosition().x;
	int y1 = spr_1.getPosition().y;
	int y2 = spr_2.getPosition().y;
	int w1 = spr_1.getGlobalBounds().width;
	int w2 = spr_2.getGlobalBounds().width;
	int h1 = spr_1.getGlobalBounds().height;
	int h2 = spr_2.getGlobalBounds().height;

	// Check if boxes are NOT intersecting, and return the opposite
	return !(x1 + w1 < x2 ||     // Right edge of box 1 < left edge of box 2; OR
                 x1 > x2 + w2 ||     // Left edge of box 1 > right edge of box 2; OR
                 y1 + h1 < y2 ||     // Bottom of box 1 above top of box 2; OR
                 y1 > y2 + h2)       // Top of box 1 below bottom of box 2
}
