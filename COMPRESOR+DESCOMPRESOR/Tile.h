#pragma once

#include <string>
//#include "stdint.h"

using namespace std;

class Tile
{
private:
	string filePath; //guardar el path entero de una imagen
	bool selected;
	//allegro_bitmap img;

public:
	Tile(string path); 
	~Tile();
	void toggleSelection();
	bool isSelected();
	string getFilePath();
	void draw(unsigned int x0, unsigned int y0); //funcion que dibuja con allegro UN TILE (una imagen)
};

