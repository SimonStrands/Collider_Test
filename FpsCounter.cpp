#include "FpsCounter.h"
#include <string>
#include <iostream>

int FPS::CountFps(double deltaTime) {
	int fps;
	fps = 1 / deltaTime;
	return fps;
}
void FPS::PrintFps(int Fps, sf::RenderWindow& window, float xPos, float yPos) {
	font.loadFromFile("C:/windows/fonts/arial.ttf");
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Red);
	text.setPosition(xPos, yPos);
	text.setString(std::to_string(Fps));
	window.draw(text);
}