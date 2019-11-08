#pragma once
#include <SFML/Graphics.hpp>

class Animation {
private:
	double totTime;
public:
	int liveHowMany, howMany;
	
	float scale, width, height;
	Animation();
	~Animation();
	void animate(sf::RenderWindow& window, sf::Texture Tex, float deltaTime, float timeBetween, float posX = 0.0f, float posY = 0.0f, float offsetX = 0.0f, float offsetY = 0.0f);
};


