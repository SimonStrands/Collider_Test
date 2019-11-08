#include "Collider.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Maps.h"

sf::Vector2f getDistance(GameObject gameobj1, GameObject gameobj2)
{
	
	float xDist = abs(gameobj1.getObjLeft() - gameobj2.getObjLeft());

	float yDist = abs(gameobj1.getObjUpper() - gameobj2.getObjUpper());
	
	return sf::Vector2f(xDist,yDist);
}

bool checkCollider(GameObject gameobj1, GameObject gameobj2)
{
	{
		bool theReturn = false;
		if ((gameobj1.getObjLeft() < gameobj2.getObjLeft() && gameobj2.getObjLeft() < gameobj1.getObjRight() || gameobj1.getObjLeft() < gameobj2.getObjRight() && gameobj1.getObjLeft() > gameobj2.getObjLeft()) &&
			(gameobj1.getObjDown() > gameobj2.getObjDown() && gameobj1.getObjUpper() < gameobj2.getObjDown() || gameobj2.getObjDown() > gameobj1.getObjDown() && gameobj2.getObjUpper() < gameobj1.getObjDown()))
		{
			theReturn = true;
		}
		return theReturn;
	}
}

void collider(GameObject& gameobj1, GameObject& gameobj2)
{
	//here don't do anything
	if (gameobj1.getWeight() == gameobj2.getWeight()) {

	}
	else {
		//here move the object that has less weight 
		//need delta time
		
		if (gameobj1.getWeight() > gameobj2.getWeight()) {
			while (checkCollider(gameobj1, gameobj2)) {
				//Gameobj 1
				//left
				if (gameobj1.getObjLeft() < gameobj2.getObjLeft() && ifLeftSide(gameobj1, gameobj2)) {
					gameobj2.setVelocity(0.0002,0);
				}
				//right
				if (gameobj1.getObjRight() > gameobj2.getObjRight() && ifRightSide(gameobj1, gameobj2)) {
					gameobj2.setVelocity(-0.0002, 0);
				}
				//under
				if (gameobj1.getObjDown() > gameobj2.getObjDown() && ifDownSide(gameobj1, gameobj2)) {
					gameobj2.setVelocity(0, -0.0002);
				}
				//upper
				if (gameobj1.getObjUpper() < gameobj2.getObjUpper() && ifUpperSide(gameobj1, gameobj2)) {
					gameobj2.setVelocity(0, 0.0002);
				}
			}
		}
		else {
			while (checkCollider(gameobj1, gameobj2)) {
				//left
				if (gameobj1.getObjLeft() < gameobj2.getObjLeft() && ifLeftSide(gameobj1, gameobj2)) {
					gameobj1.setVelocity(-0.0002, 0);
				}
				//right
				if (gameobj1.getObjRight() > gameobj2.getObjRight() && ifRightSide(gameobj1, gameobj2)) {
					gameobj1.setVelocity(0.0002, 0);
				}
				//under
				if (gameobj1.getObjDown() > gameobj2.getObjDown() && ifDownSide(gameobj1, gameobj2)) {
					gameobj1.setVelocity(0, 0.0002);
				}
				//upper
				if (gameobj1.getObjUpper() < gameobj2.getObjUpper() && ifUpperSide(gameobj1, gameobj2)) {
					gameobj1.setVelocity(0, -0.0002);
				}
			}
			
		}


	}


}


void TileCollider(sf::RenderWindow& window, GameObject &Player ,int mapIndex, int startPosX, int startPosY, int width, int height, float scale, int offsetX, int offsetY, int weight)
{
	//Get map
	int** map = nullptr;
	map = getMapTile(mapIndex, 20, 20);

	GameObject* wall = nullptr;
	//See how many gameobj we need
	int counter = 0;
	for (int i = 0; i < 20; i++) {
		for (int x = 0; x < 20; x++) {
			if (map[x][i] != 0) {
				counter++;
			}
		}
	}

	
	//create gameobj
	wall = new GameObject[counter];
	int othercounter = counter;
	counter = 0;
	//Set gameobj:s to the right width, height and position and start a collider on them all with gameobj player
	for (int i = 0; i < 20; i++) {
		for (int x = 0; x < 20; x++) {

			if (map[x][i] != 0) {
				wall[counter].setHeight(height * scale);
				wall[counter].setWidth(width * scale);
				wall[counter].move(i * width * scale + startPosX, x * height * scale + startPosY);
				wall[counter].setWeight(weight);
				wall[counter].name = "wall";
				collider(Player, wall[counter]);
				

				counter++;
			}
			

		}

	}
	//delete map
	for (int h = 0; h < 20; h++)
	{
		delete[] map[h];
	}
	delete[] map;

	//delte all gameobj:s
	delete[] wall;
	

}



//maybe dist in parameter list
// add + (gameobj1.getHeight() - gameobj2.getHeight()) && !(ifUpperSide(gameobj1, gameobj2)) to Left and Right 
// and you can change the y size of gameobject but not x size
// 

bool ifLeftSide(GameObject gameobj1, GameObject gameobj2)
{
	sf::Vector2f dist = getDistance(gameobj1, gameobj2);
	bool theReturn = false;
	
	if (gameobj1.getObjLeft() < gameobj2.getObjLeft() && 
		!(gameobj1.getObjUpper() > gameobj2.getObjUpper() + gameobj2.getHeight()) &&
		!(gameobj1.getObjDown() < gameobj2.getObjUpper()) && 
		dist.x  > dist.y)
	{
		theReturn = true;
	}
	return theReturn;
}

bool ifRightSide(GameObject gameobj1, GameObject gameobj2)
{
	sf::Vector2f dist = getDistance(gameobj1, gameobj2);
	bool theReturn = false;

	if (gameobj1.getObjRight() > gameobj2.getObjRight() &&
		!(gameobj1.getObjUpper() > gameobj2.getObjUpper() + gameobj2.getHeight()) &&
		!(gameobj1.getObjDown() < gameobj2.getObjUpper()) && 
		dist.x > dist.y)
	{
		theReturn = true;
	}
	return theReturn;
}

bool ifUpperSide(GameObject gameobj1, GameObject gameobj2)
{
	sf::Vector2f dist = getDistance(gameobj1, gameobj2);
	bool theReturn = false;

	if (gameobj1.getObjUpper() < gameobj2.getObjUpper() && 
		!(gameobj1.getObjLeft() > gameobj2.getObjRight()) &&
		!(gameobj1.getObjRight() < gameobj2.getObjLeft()) && 
		dist.x < dist.y)
	{
		theReturn = true;
	}
	return theReturn;
}

bool ifDownSide(GameObject gameobj1, GameObject gameobj2)
{
	sf::Vector2f dist = getDistance(gameobj1, gameobj2);
	bool theReturn = false;

	if (gameobj1.getObjDown() > gameobj2.getObjDown() &&
		!(gameobj1.getObjLeft() > gameobj2.getObjRight()) &&
		!(gameobj1.getObjRight() < gameobj2.getObjLeft()) &&
		dist.x < dist.y)
	{
		theReturn = true;
	}
	return theReturn;
}


