#include "Animation.h"
#include <fstream>
#include <iostream>

Animation::Animation() {
	liveHowMany = 0;
	totTime = 0;
	scale = 1;
	howMany = 32;
	width = 32;
	height = 32;

}
Animation::~Animation() {}
void Animation::animate(sf::RenderWindow& window, sf::Texture Tex, float deltaTime, float timeBetween, float posX, float posY,  float offsetX, float offsetY )
{
	sf::Sprite sprite(Tex);

	totTime += deltaTime;
		if (totTime >= timeBetween) {
			liveHowMany++;
			totTime = 0;
		}
	if (liveHowMany > howMany) {
		liveHowMany = 0;
	}
	sprite.setTextureRect(sf::IntRect(offsetX + (liveHowMany * width), offsetY , width, height));
	sprite.scale(scale, scale);
	sprite.setPosition((float)posX, (float)posY);

	window.draw(sprite);
}