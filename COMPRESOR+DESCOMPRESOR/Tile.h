#pragma once

#include <string>
//#include "stdint.h"

using namespace std;

class Tile
{
private:
	string imagePath; //guardar el path entero de una imagen
	bool selected;

public:
	Tile(string path); 
	~Tile();
	void toggleSelection();
	bool isSelected();
	string getImagePath();
	void draw(unsigned int x0, unsigned int y0); //funcion que dibuja con allegro UN TILE (una imagen)
};

