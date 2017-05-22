
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