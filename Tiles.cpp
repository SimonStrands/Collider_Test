#include "Tiles.h"
#include <iostream>
#include <time.h>
#include "Maps.h"

//int map1[20][20] = {
//	{1,0,0,0,1,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1},
//	{1,0,1,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1,1,1},
//	{1,0,0,0,1,0,0,1,1,0,1,0,0,1,0,1,1,0,1,1},
//	{1,0,1,1,1,0,1,1,1,0,1,1,0,1,0,1,1,1,0,1},
//	{1,0,1,1,1,0,0,0,1,0,1,1,0,1,0,1,0,0,0,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//};

void layTileMap(sf::RenderWindow& window, sf::Texture spritesheet, int mapIndex, float startPosX, float startPosY, float width, float height, float offsetX, float offsetY, float scale, int nbrOfSpriteInRow, int firstOffsetX, int firstOffsetY)
{
	
	//set what the sprite is
	sf::Sprite backGround(spritesheet);
	backGround.setScale(scale, scale);
	int** map = nullptr;
	map = getMap(mapIndex, 20, 20);

	bool once = true;
	
	for (int i = 0; i < 19; i++) {
		for (int x = 0; x < 19; x++) {

			if (once == true) { once = false; }
			else { firstOffsetX = 0; firstOffsetY = 0; }
			
			if (map[x][i] != 0) {
				backGround.setTextureRect(sf::IntRect(firstOffsetX + offsetX + (map[x][i] + -1) * width, firstOffsetY + offsetY, width, height));
				backGround.setPosition(offsetX + width * scale * i, offsetY + height * scale * x);
				window.draw(backGround);
			}
			

		}

	}
	for (int h = 0; h < 20; h++)
	{
		delete [] map[h];
	}
	delete[] map;

}
