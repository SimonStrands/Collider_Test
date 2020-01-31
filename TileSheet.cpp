#include "TileSheet.h"

void TileSheet::setTiles()
{
	this->tiles = new GameObject**[this->rows];
	for (int i = 0; i < this->rows; i++) {
		this->tiles[i] = new GameObject*[this->cols];
	}
	//fRow = forRow, fCol = forCol
	for (int fRow = 0; fRow < rows; fRow++) {
		for (int fCol = 0; fCol < cols; fCol++) {
			this->nrOfTiles++;
			tiles[fRow][fCol] = new GameObject(xPos + fRow * heigthPerTile, yPos + fCol * widthPerTile, "../Data/Texture/test.jpg", heigthPerTile, widthPerTile);
		}
	}
}

TileSheet::TileSheet(float xPos, float yPos, int ** map, int rows, int cols, float widthPerTile, float heigthPerTile)
{
	this->rows = rows;
	this->cols = cols;
	this->xPos = xPos;
	this->yPos = yPos;
	this->map = map;
	this->widthPerTile = widthPerTile;
	this->heigthPerTile = heigthPerTile;
	this->nrOfTiles = 0;
	this->setTiles();
}

TileSheet::~TileSheet()
{
	//IT DOESNT FUCKING SHOW UP IF I HAVE MEMORY LEAKS OR NOT
	
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			delete[] tiles[row][col];
		}
		delete[] tiles[row];
	}
	delete[] tiles;
}

int TileSheet::getNrOfTiles() const
{
	return this->nrOfTiles;
}

GameObject* TileSheet::getTile(int nr) const
{
	int x = 0;
	if (nr > rows) {
		x = nr % rows;
	}

	return tiles[1][1];
}

void TileSheet::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int row = 0; row < this->rows; row++) {
		for (int col = 0; col < this->cols; col++) {
			tiles[row][col]->changeWannaDraw(true);
			target.draw(*tiles[row][col]);
		}
	}
}
