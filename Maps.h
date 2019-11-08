#pragma once



class Maps {

public:
	
	Maps();
	int getMapIndex(int mapIndex);
private:
	
};


int** getMap(int mapIndex, unsigned height, unsigned width);
int** getMapTile(int mapIndex, unsigned height, unsigned width);

