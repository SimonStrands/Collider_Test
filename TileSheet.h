#pragma once
#include "GameObject.h"

class TileSheet : public sf::Drawable{
private:
	int rows;
	int cols;
	float xPos, yPos;
	int **map;
	GameObject ***tiles;
	void setTiles();
	float widthPerTile, heigthPerTile;
	int nrOfTiles;

public:
	TileSheet(float xPos, float yPos, int **map, int rows, int cols, float widthPerTile, float heigthPerTile);
	virtual ~TileSheet();
	int getNrOfTiles()const;
	GameObject *getTile(int nr)const;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};