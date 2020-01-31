#include "GameObject.h"



GameObject::GameObject(float xPos, float yPos, std::string spriteFile, float height, float width)
{
	this->wannaDraw = true;
	this->xPos = xPos;
	this->yPos = yPos;
	this->texture.loadFromFile(spriteFile);
	this->sprite.setTexture(texture);
	this->sprite.setPosition(xPos, yPos);
	this->type = "none";
	this->weight = 0;
	int temp = 0;
	if (height == -1) {
		this->height = sprite.getGlobalBounds().width;
	}
	else {
		this->height = height;
		temp++;
	}
	if (width == -1) {
		this->width = sprite.getGlobalBounds().height;
	}
	else {
		this->width = width;
		temp++;
	}
	if (temp >= 2) {
		setSizeOfSpritePX(width, height);
	}
	

}

GameObject::~GameObject()
{
}

void GameObject::addPosition(float xVel, float yVel)
{
	this->xPos += xVel;
	this->yPos += yVel;
	this->sprite.setPosition(xPos, yPos);

}

void GameObject::addPositionX(float Vel)
{
	this->xPos += Vel;
	this->sprite.setPosition(xPos, yPos);
}

void GameObject::addPositionY(float Vel)
{
	this->yPos += Vel;
	this->sprite.setPosition(xPos, yPos);
}

void GameObject::setPostion(float xPos, float yPos)
{
	this->xPos = xPos;
	this->yPos = yPos;
	this->sprite.setPosition(xPos, yPos);
}

void GameObject::setScaleOfSprite(float scale)
{
	this->sprite.setScale(scale,scale);
}

void GameObject::setSizeOfSpritePX(float width, float height)
{
	float scaleHeight;
	float scaleWidth;
	if (width != -1) {
		scaleWidth = width / sprite.getGlobalBounds().width;
	}
	else {
		scaleWidth = 1;
	}
	if (height != -1) {
		scaleHeight = height / sprite.getGlobalBounds().height;
	}
	else {
		scaleHeight = 1;
	}
	

	this->sprite.setScale(scaleWidth, scaleHeight);
}

void GameObject::changeWannaDraw(bool wannaDraw)
{
	this->wannaDraw = wannaDraw;
}

sf::FloatRect GameObject::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

float GameObject::getTop() const
{
	return sprite.getGlobalBounds().top;
}

float GameObject::getBot() const
{
	return sprite.getGlobalBounds().top + this->height;
}

float GameObject::getLeft() const
{
	return sprite.getGlobalBounds().left;
}

float GameObject::getRight() const
{
	return sprite.getGlobalBounds().left + width;
}

std::string GameObject::getType() const
{
	return this->type;
}

int GameObject::getWeight() const
{
	return this->weight;
}

void GameObject::changeWeight(int weight)
{
	this->weight = weight;
}

void GameObject::changeType(std::string type)
{
	this->type = type;
}

void GameObject::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(this->sprite);
}
