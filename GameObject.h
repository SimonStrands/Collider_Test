#pragma once
#include "Animation.h"
#include "Tiles.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>


//change from public to private
class GameObject{
private:
	Animation anim;
	float weight;
public:
	sf::Vector2f velocity;
	float xPos, yPos;
	float scales;
	float sizeX, sizeY;
	float offsetX, offsetY;
	int howMany;
	float width, height;
	std::string name;
	
	sf::RectangleShape rec;

	int rotation;
	bool collider;

	GameObject();

	void rotate(int rotation);
	void scale(float scales);

	void setWidth(float width);
	float getWidth() const;
	void setHeight(float height);
	float getHeight() const;

	float getObjDown() const;
	float getObjUpper() const;
	float getObjLeft() const;
	float getObjRight() const;

	float getWeight() const;
	void setWeight(float weight);

	void move(float x_Pos, float y_Pos);
	void addVelocity(float xVel, float yVel);
	void setVelocity(float xVel, float yVel);
	sf::Vector2f getVelocity() const;

	void setTexture(sf::Texture& Tex, sf::RenderWindow& window);
	void setAnimation(sf::Texture& Tex, sf::RenderWindow& window, double deltaTime);
	void writeWhereTheyAre(sf::RenderWindow &window);
	sf::Vector2f getPosition();


};