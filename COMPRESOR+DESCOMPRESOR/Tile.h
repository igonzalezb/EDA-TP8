#pragma once

#include <string>
//#include "stdint.h"

using namespace std;

class Tile
{
private:
	string filename;
	bool selected;

public:
	Tile(); 
	~Tile();
	void toggleSelection();
	bool isSelected();
	string getFilename();
	void draw(unsigned int x0, unsigned int y0); //funcion que dibuja con allegro UN TILE (una imagen)
}