#include "Player.h"

void Player::move(double dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->addPositionX(speed * (float)dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->addPositionX(-(speed * (float)dt));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		jump(dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		//this->addPositionY(speed * dt);
	}
	this->addPositionY(-yVel * dt);
	if (!(yVel <= 0)) {
		yVel--;
	}
	else if(yVel < 0){
		yVel = 0;
	}
	
}

void Player::jump(double dt)
{
	if (this->grounded) {
		yVel = 10;
	}
}

Player::Player(float xPos, float yPos):
	Entity(xPos, yPos, "../Data/Texture/test.jpg", /*get lvl*/1, 0.3f, 2.0f)
{
	this->speed = 30;
	this->changeWeight(20);
}

void Player::update(double dt)
{
	move(dt);
	//gravityFunction(dt);
}
