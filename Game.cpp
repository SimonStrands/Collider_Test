#include "Game.h"
#include <iostream>

Game::Game()
	:tilemap(0,0,map,10,10,20,20),
	collision(),
	player(200,20)
{
	this->map = new int*[10];
	for (int i = 0; i < 10; i++) {
		this->map[i] = new int[10];
	}
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			map[x][y] = 3;
		}
	}

	this->font.loadFromFile("C:/windows/fonts/arial.ttf");
	text.setFont(font);
	this->text.setFillColor(sf::Color::Black);
	this->text.setPosition(20, 20);
	this->text.setCharacterSize(30);
	//set up collision
					//tiles                   //Player
	//int nrOfObjects = tilemap.getNrOfTiles() + 1;
	//allGameObj = new GameObject * [nrOfObjects];
	//for (int i = 0; i < tilemap.getNrOfTiles(); i++) {
	//	allGameObj[i] = tilemap.getTile(i);
	//}
	//allGameObj[nrOfObjects - 1] = player;
	//collision = new Collision(*allGameObj, nrOfObjects);


}

Game::~Game()
{
	for (int o = 0; o < 10; o++) {
		delete[] map[o];
	}
	delete[] map;
}

State Game::update(DeltaTime time)
{
	State state = State::NO_CHANGE;
	if (done == true) {
		state = State::EXIT;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		state = State::EXIT;
	}
	text.setString(std::to_string(time.dt()));

	player.update(time.dt());
	for (int i = 0; i < tilemap.getNrOfTiles() - 1; i++) {
		collision.CheckCollision(*tilemap.getTile(i), player);
	}
	

	return state;
}

void Game::render(sf::RenderWindow & window)
{
	window.clear(sf::Color::White);

	window.draw(this->tilemap);
	window.draw(this->text);
	window.draw(this->player);

	window.display();
}

void Game::handleEvents(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			this->done = true;
		}
	}
}
