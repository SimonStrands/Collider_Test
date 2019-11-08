#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "GameObject.h"
#include <cstdlib>

class Enemy : public GameObject{
private:
	bool interactive;
	float radiousForInteractive;
	std::string name;
	std::string say;
	sf::Font font;
	sf::Text text;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	Enemy();
	Enemy(float posX, float posY, sf::Texture tex, bool interactive = false, std::string name = "", std::string say = "");
	Enemy(float posX, float posY, std::string tex, bool interactive = false, std::string name = "", std::string say = "");
	void interact(sf::RenderWindow& window, float playerPosX, float playerPosY);
	void drawEnemy(sf::RenderWindow& window, float playerPosX, float playerPosY);
};
