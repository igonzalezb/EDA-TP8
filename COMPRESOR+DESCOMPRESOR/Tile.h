#pragma once

#include <string>

using namespace std;
typedef unsigned int uint;
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
	void draw(uint x0, uint y0); //funcion que dibuja con allegro UN TILE (una imagen)
};