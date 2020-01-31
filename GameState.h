#pragma once
#include <SFML/Graphics.hpp>
#include "DeltaTime.h"
enum class State { MENU, NO_CHANGE, EXIT, GAME, GAME_OVER, NEW_START, HIGHSCORE_LIST, CREDITS };

class GameState {
protected:
	sf::RenderWindow window;
	bool done;
public:
	GameState();
	virtual ~GameState();
	virtual State update(DeltaTime time) = 0;
	virtual void render(sf::RenderWindow &window) = 0;
	virtual void handleEvents(sf::RenderWindow & window) = 0;
};