#include "Collision.h"
#include <iostream>

bool Collision::ifLeftSide(GameObject gameobj1, GameObject gameobj2)
{
	bool theReturn = false;

	if (gameobj1.getBounds().left < gameobj2.getBounds().left &&
		!(gameobj1.getBounds().top > gameobj2.getBounds().top + gameobj2.getBounds().height) &&
		!(gameobj1.getBounds().top + gameobj1.getBounds().height < gameobj2.getBounds().top))
	{
		theReturn = true;
	}
	return theReturn;
}

bool Collision::ifRightSide(GameObject gameobj1, GameObject gameobj2)
{
	bool theReturn = false;

	if (gameobj1.getBounds().left + gameobj1.getBounds().width < gameobj2.getBounds().left + gameobj2.getBounds().width &&
		!(gameobj1.getBounds().top > gameobj2.getBounds().top + gameobj2.getBounds().height) &&
		!(gameobj1.getBounds().top + gameobj1.getBounds().height < gameobj2.getBounds().top))
	{
		theReturn = true;
	}
	return theReturn;
}

bool Collision::ifTopSide(GameObject gameobj1, GameObject gameobj2)
{
	bool theReturn = false;

	if (gameobj1.getBounds().top < gameobj2.getBounds().top &&
		!(gameobj1.getBounds().left > gameobj2.getBounds().left + gameobj2.getBounds().width) &&
		!(gameobj1.getBounds().left + gameobj1.getBounds().width < gameobj2.getBounds().left))
	{
		theReturn = true;
	}
	return theReturn;
}

bool Collision::ifBotSide(GameObject gameobj1, GameObject gameobj2)
{
	bool theReturn = false;
	if (gameobj1.getBounds().top + gameobj1.getBounds().height < gameobj2.getBounds().top + gameobj2.getBounds().height &&
		!(gameobj1.getBounds().left > gameobj2.getBounds().left + gameobj2.getBounds().width) &&
		!(gameobj1.getBounds().left + gameobj1.getBounds().width < gameobj2.getBounds().left))
	{
		theReturn = true;
	}
	return theReturn;
}

Collision::Collision()
{
	
}

bool Collision::CheckCollision(GameObject &gameobj1, GameObject &gameobj2)
{
	bool theReturn = false;
			if (gameobj1.getBounds().intersects(gameobj2.getBounds())) {
				theReturn = true;
				//std::cout << "hit" << std::endl;
				//gameobj1.addPositionX(0.1);
				MoveObject(gameobj1, gameobj2);
			}
	return theReturn;
}

void Collision::MoveObject(GameObject &gameobj1, GameObject &gameobj2)
{
	if (gameobj1.getWeight() < gameobj2.getWeight()) {
		//to Left

		if ( gameobj1.getBounds().left < gameobj2.getBounds().left && ifLeftSide(gameobj1, gameobj2) ) {
			gameobj1.addPositionX(-0.1);
			std::cout << "left" << std::endl;
			if (gameobj1.getBounds().intersects(gameobj2.getBounds())) {
				//MoveObject(gameobj1, gameobj2);
				
			}
		}
		if (gameobj1.getBounds().left + gameobj1.getBounds().width < gameobj2.getBounds().left + gameobj2.getBounds().width && ifRightSide(gameobj1, gameobj2)) {
			gameobj1.addPositionX(0.1);
			std::cout << "right" << std::endl;
			if (gameobj1.getBounds().intersects(gameobj2.getBounds())) {
				//MoveObject(gameobj1, gameobj2);
			}
		}
		if (gameobj1.getBounds().top < gameobj2.getBounds().top && ifTopSide(gameobj1, gameobj2)) {
			gameobj1.addPositionY(-0.1);
			std::cout << "top" << std::endl;
			if (gameobj1.getBounds().intersects(gameobj2.getBounds())) {
				//MoveObject(gameobj1, gameobj2);
			}
		}
		if (gameobj1.getBounds().top + gameobj1.getBounds().height < gameobj2.getBounds().top + gameobj2.getBounds().height && ifBotSide(gameobj1, gameobj2)) {
			gameobj1.addPositionY(0.1);
			std::cout << "bot" << std::endl;
			if (gameobj1.getBounds().intersects(gameobj2.getBounds())) {
				//MoveObject(gameobj1, gameobj2);
			}
		}
	}
	else {

	}
}

