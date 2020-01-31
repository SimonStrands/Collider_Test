#pragma once
#include <SFML/Graphics.hpp>

class GameObject : public sf::Drawable {
private:
	float xPos, yPos;
	float width, height;
	bool wannaDraw;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string type;
	int weight;
public:
	GameObject(float xPos, float yPos, std::string spriteFile, float height = -1, float width = -1);
	virtual ~GameObject();
	void addPosition(float xVel, float yVel);
	void addPositionX(float Vel);
	void addPositionY(float Vel);
	void setPostion(float xPos, float yPos);
	void setScaleOfSprite(float scale);
	void setSizeOfSpritePX(float width, float height);
	void changeWannaDraw(bool wannaDraw);
	sf::FloatRect getBounds()const;
	float getTop()const;
	float getBot()const;
	float getLeft()const;
	float getRight()const;
	std::string getType()const;
	int getWeight()const;
	void changeWeight(int weight);
	void changeType(std::string type);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};