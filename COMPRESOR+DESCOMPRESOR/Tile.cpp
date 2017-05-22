
#include "Tile.h"


Tile::Tile(string path)
{
	filePath = path;
	selected = false;
}

Tile::~Tile()
{

}


void Tile::toggleSelection()
{
	selected = (!selected);
}

bool Tile::isSelected()
{
	if (selected == true)
	{
		return true;
	}
	return false;
}

string Tile::getFilePath()
{
	return filePath; 
}

void Tile::draw (unsigned int x0, unsigned int y0) //funcion que dibuja con allegro UN TILE (una imagen)
{

}