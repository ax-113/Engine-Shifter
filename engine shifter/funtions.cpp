#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <string>
#include "funtions.h"

void randomize() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

void load_animation_spritesheet(sf::Sprite sprite, int frame_width, int frame_height) {
	sprite.setTextureRect({ {0,0},{frame_width,frame_height} });
	sprite.setOrigin({ sprite.getTextureRect().width / 2.0, sprite.getTextureRect().height / 2.0 });

}	 

void animation_draw(int amount_sprites_in_column, int row_to_draw, int frame_width, int frame_height, sf::Sprite sprite, float maxTime, sf::RenderWindow WINDOW, int timer, int temp_val) {
	timer += 0.1;
	if (timer >= maxTime) {
		temp_val += frame_width;
		if (temp_val >= row_to_draw * frame_width) {
			temp_val = 0;
		}
		else {
			sprite.setTextureRect({ {row_to_draw, amount_sprites_in_column},{frame_width, frame_height} });

		}
	}
	WINDOW.draw(sprite);
}