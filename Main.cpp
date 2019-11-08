#include <SFML/Graphics.hpp>
#include <iostream>//for debugging
#include <SFML/Window/Cursor.hpp>
#include <ctime>
#include <chrono>
#include "Tiles.h"
#include "FpsCounter.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Collider.h"


using namespace sf;

const int WINDOW_WIDTH = 820;
const int WINDOW_HEIGHT = 800;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	FPS fps;
	GameObject Player;
	Enemy paul;
	
	//Wrong coursor
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");
	sf::View camera(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(820.0f, 800.0f));

	sf::Cursor cursor;
	if (cursor.loadFromSystem(sf::Cursor::Cross))
		window.setMouseCursor(cursor);

	sf::Event event;
	Texture Sheet, anim;
	Sheet.loadFromFile("Texture/Texture.png");
	anim.loadFromFile("Texture/animation_test2.png");
	
	paul.setHeight(64);
	paul.setWidth(200);

	int x = 0;
	int y = 0;
	double totTime = 0;
	double deltaTime = 0;
	bool Player_moves = false;
	bool change = false;

	Player.xPos = -100;
	Player.yPos = -100;
	Player.scales = 2.0f;
	Player.setWeight(60);
	Player.name = "Player";

	paul.move(-200, -200);

	
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		auto t_start = std::chrono::high_resolution_clock::now();
		////Keyboard////

		float speed = 2;
		Player_moves = false;
		//check for double keys if then halfspeed
		//////////////////
		int keyCounter = 0;
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			keyCounter++;
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			keyCounter++;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			keyCounter++;
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			keyCounter++;
		}
		if (keyCounter >= 2){
			speed /= 2;
		}
		////////////////////
		if (Keyboard::isKeyPressed(Keyboard::W)) {
			Player.addVelocity(0, -speed * (float)deltaTime);
			Player_moves = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			Player.addVelocity(speed * (float)deltaTime, 0);
			Player_moves = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			Player.addVelocity(0, speed * (float)deltaTime);
			Player_moves = true;
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			Player.addVelocity(-speed * (float)deltaTime, 0);
			Player_moves = true;
		}
		

		

		////draw////
		window.clear(Color::White);
		collider(Player, paul);
		
		Player.setVelocity(0, 0);
		window.setView(camera);
		camera.setCenter(Player.getPosition());
		
		
		
		

		//lay a Tilemap
		
		layTileMap(window, Sheet, 1, 100, 100,32,32,0,0,2,3);
		TileCollider(window, Player, 1);

		Player.writeWhereTheyAre(window);
		paul.writeWhereTheyAre(window);

		if (Player_moves) {
			Player.offsetY = 0;
			Player.howMany = 3;
			Player.setAnimation(anim, window, deltaTime);
		}
		else {
			Player.howMany = 0;
			Player.offsetY = 32;
			Player.setAnimation(anim, window, deltaTime);
		}
		
		
		
		
		fps.PrintFps(fps.CountFps(deltaTime), window, Player.xPos + WINDOW_WIDTH/3 + 75, Player.yPos - WINDOW_HEIGHT / 3 - 100);
		window.display();
		

		//End check for time and make it real milliseconds
		auto t_end = std::chrono::high_resolution_clock::now();
		deltaTime = (std::chrono::duration<double, std::milli>(t_end - t_start).count())/1000;
		 
	}
	return 0;
}