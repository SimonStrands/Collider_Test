#pragma once
#include "GameObject.h"

class Collision {
private:
	//GameObject* gameobject;
	//int nrOfObjects;
	bool ifLeftSide(GameObject gameobj1, GameObject gameobj2);
	bool ifRightSide(GameObject gameobj1, GameObject gameobj2);
	bool ifTopSide(GameObject gameobj1, GameObject gameobj2);
	bool ifBotSide(GameObject gameobj1, GameObject gameobj2);
public:
	Collision();
	bool CheckCollision(GameObject &gameobj1, GameObject &gameobj2);
	void MoveObject(GameObject &gameobj1, GameObject &gameobj2);
};