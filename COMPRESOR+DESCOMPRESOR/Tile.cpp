
#include "Tile.h"

// COMPLETAR FUNCIONES

Tile::Tile(string path)
{
	imagePath = path;
	selected = false;
}

Tile::~Tile()
{
	//DESTRUCTOR
}


void Tile::toggleSelection()
{
	selected != selected;
}

bool Tile::isSelected()
{
	return selected;
}

string Tile::getImagePath()
{
	return "prueba"; //sacar esto
}

void Tile::draw (unsigned int x0, unsigned int y0) //funcion que dibuja con allegro UN TILE (una imagen)
{

}