
#include "Tile.h"


Tile::Tile(string path)
{
	filePath = path;
	selected = false;
}

Tile::~Tile()
{

}

void Tile::select()
{
	selected = true;
}

void Tile::deselect()
{
	selected = false;
}


void Tile::toggleSelection()
{
	selected = (!selected);
}

bool Tile::isSelected()
{
	return selected;
}

string Tile::getFilePath()
{
	return filePath; 
}