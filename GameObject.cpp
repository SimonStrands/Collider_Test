#include "GameObject.h"
#include "Animation.h"
#include <vector>

GameObject::GameObject() {
	collider = false;
	xPos = 0.0f;
	yPos = 0.0f;
	scales = 1.0f;
	sizeX = 32.0f;
	sizeY = 32.0f;
	offsetX = 0.0f;
	offsetY = 0.0f;
	rotation = 0;
	howMany = 1;
	weight = 50.0f;
	width = 64;
	height = 64;

	sf::RectangleShape rec;
	

}

void GameObject::rotate(int rotateion)
{

}


void GameObject::scale(float scales)
{
	//this->scale += scales;
}

void GameObject::setWidth(float width)
{
	this->width = width;
}

float GameObject::getWidth() const
{
	return this->width;
}

void GameObject::setHeight(float height)
{
	this->height = height;
}

float GameObject::getHeight() const
{
	return this->height;
}

float GameObject::getObjDown()const
{
	return yPos + height;
}

float GameObject::getObjUpper()const
{
	return yPos;
}

float GameObject::getObjLeft()const
{
	return xPos;
}

float GameObject::getObjRight()const
{
	return xPos + width;
}



float GameObject::getWeight()const
{
	return this->weight;
}

void GameObject::setWeight(float weight)
{
	this->weight = weight;
}

void GameObject::move(float x_Pos, float y_Pos)
{
	xPos = x_Pos;
	yPos = y_Pos;

}
void GameObject::addVelocity(float xVel, float yVel)
{
	velocity.x += xVel;
	velocity.y += yVel;
	xPos += velocity.x * 200;
	yPos += velocity.y * 200;
}
void GameObject::setVelocity(float xVel, float yVel)
{
	
	velocity.x = xVel;
	velocity.y = yVel;
	xPos += velocity.x * 200;
	yPos += velocity.y * 200;
	
}

sf::Vector2f GameObject::getVelocity() const
{
	return sf::Vector2f(velocity.x, velocity.y);
}

void GameObject::setTexture(sf::Texture& Tex, sf::RenderWindow& window) {
	sf::Sprite sprite(Tex);
	sprite.setPosition(xPos + offsetX, yPos + offsetY);
	sprite.scale(sizeX, sizeY);
	window.draw(sprite);
}

void GameObject::setAnimation(sf::Texture& Tex, sf::RenderWindow& window, double deltaTime)
{
	sf::Sprite sprite(Tex);
	sprite.setPosition(xPos, yPos);
	sprite.scale(sizeX, sizeY);
	this->anim.howMany = howMany;
	this->anim.scale = scales;
	this->anim.animate(window, Tex, deltaTime, 0.1, xPos, yPos, offsetX, offsetY);
}

void GameObject::writeWhereTheyAre(sf::RenderWindow &window)
{
	rec.setPosition(this->xPos, this->yPos);
	rec.setSize(sf::Vector2f(width, height));
	rec.setFillColor(sf::Color::Green);
	window.draw(this->rec);
}

sf::Vector2f GameObject::getPosition()
{
	return sf::Vector2f(xPos, yPos);
}

