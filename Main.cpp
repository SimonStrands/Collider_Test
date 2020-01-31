#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
#include <ctime>
#include <crtdbg.h>




int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned int)time(0));
	sf::RenderWindow window(sf::VideoMode(800, 600), "Title");
	
	DeltaTime time;
	State currentState = State::NO_CHANGE;
	GameState* gameState = new Game();

	while (currentState != State::EXIT) {
		if (currentState != State::NO_CHANGE) {
	
		}
		else {
			time.restartClock();
			gameState->handleEvents(window);
			currentState = gameState->update(time);
			gameState->render(window);
		}
	}
	
	delete gameState;
	//getchar();
	return 0;
}