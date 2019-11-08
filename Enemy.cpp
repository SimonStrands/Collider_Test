#include "Enemy.h"
#include <iostream>


Enemy::Enemy()
{
	interactive = true;
	radiousForInteractive = 200;
	name = "Penis";
	say = "You like spiders?";

	font.loadFromFile("C:/windows/fonts/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Red);

	this->texture.loadFromFile("Texture/Fireball.png"); 
	this->sprite.setTexture(this->texture);


}

Enemy::Enemy(float posX, float posY, sf::Texture tex, bool interactive, std::string name, std::string say)
{
	this->texture = tex;
	this->interactive = interactive;
	this->name = name;
	this->say = say;

	font.loadFromFile("C:/windows/fonts/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Red);

	this->sprite.setTexture(this->texture);



}

Enemy::Enemy(float posX, float posY, std::string tex, bool interactive, std::string name, std::string say)
{
	this->texture.loadFromFile(tex);
	this->interactive = interactive;
	this->name = name;
	this->say = say;

	font.loadFromFile("C:/windows/fonts/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Red);

	this->sprite.setTexture(this->texture);
}

void Enemy::interact(sf::RenderWindow &window, float playerPosX, float playerPosY)
{
	if (interactive == true && sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
		//std::cout << abs(this->posX - playerPosX) << std::endl;
		//if(abs(this->posX - playerPosX) < 100 && abs(this->posY - playerPosY) < 100)
		//this->text.setString(say);
		//this->text.setPosition(playerPosX - 200, 300 + playerPosY);
		//window.draw(this->text);
	}
}


void Enemy::drawEnemy(sf::RenderWindow& window, float playerPosX, float playerPosY)
{
	this->sprite.setScale(0.1f, 0.1f);
	//this->sprite.setPosition(this->posX, this->posY);
	window.draw(this->sprite);

	interact(window, playerPosX, playerPosY);
}
