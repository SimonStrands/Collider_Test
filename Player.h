#pragma once
#include "Entitiy.h"

class Player:public Entity{
private:
	float speed;
	void move(double dt);
	void jump(double dt);
public:
	Player(float xPos, float yPos);
	void update(double dt);
};