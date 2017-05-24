
#include "Tile.h"


Tile::Tile(string path)
{
	filePath = path;
	selected = false;
	length = 0;
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

int Tile::getLength()
{
	return length;
}

void Tile::setLength(int length)
{
	this->length = length;
}
