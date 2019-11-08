#pragma once
#include <SFML/Graphics.hpp>
class FPS {
private:
	sf::Text text;
	sf::Font font;
	
public:
	int CountFps(double deltaTime);
	void PrintFps(int Fps, sf::RenderWindow& window, float xPos = 100.0f, float yPos = 100.0f);


};

