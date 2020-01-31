#pragma once
#include "GameState.h"
#include "TileSheet.h"
#include "Player.h"
#include "Collision.h"

class Game : public GameState {
private:
	sf::Text text;
	sf::Font font;
	TileSheet tilemap;
	int **map;
	Player player;
	GameObject** allGameObj;
	Collision collision;
public:
	Game();
	virtual ~Game();
	State update(DeltaTime time);
	void render(sf::RenderWindow &window);
	void handleEvents(sf::RenderWindow & window);
};