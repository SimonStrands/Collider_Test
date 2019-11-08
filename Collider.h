#pragma once
#include "GameObject.h"

//Get distance between two gameObjects (upper right corner) 
sf::Vector2f getDistance(GameObject gameobj1, GameObject gameobj2);

//Check if two gameObjects have collided with eachother
bool checkCollider(GameObject gameobj1, GameObject gameobj2);

//Try to move the gameObject with the least amount with weight
void collider(GameObject &gameobj1, GameObject &gameobj2);

//create gameobj with with a map and makes a collider with it
void TileCollider(sf::RenderWindow& window, GameObject& Player, int mapIndex, int startPosX = 0, int startPosY = 0, int width = 32, int height = 32, float scale = 2, int offsetX = 0, int offsetY = 0, int weight = 500);

//Try to see if gameobj1 is to the left of gameobj2 (doesn't work if they aren't the same size in x)
bool ifLeftSide(GameObject gameobj1, GameObject gameobj2);
bool ifRightSide(GameObject gameobj1, GameObject gameobj2);//to the Right
bool ifUpperSide(GameObject gameobj1, GameObject gameobj2);//if gameobj1 is over gameobj2
bool ifDownSide(GameObject gameobj1, GameObject gameobj2);//if gameobj1 is under gameobj2