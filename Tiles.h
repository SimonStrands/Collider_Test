#pragma once
#include <SFML/Graphics.hpp>


void layTileMap(sf::RenderWindow& window, sf::Texture spritesheet, int mapIndex, float startPosX, float startPosY, float width, float height, float offsetX, float offsetY, float scale, int nbrOfSpriteInRow, int firstOffsetX = 0, int firstOffsetY = 0);


	/*int map, sf::Texture spritesheet, int offsetX, int offsetY, int width, int height, int firstOffsetX, int firstOffsetY*/