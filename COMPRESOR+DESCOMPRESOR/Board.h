#pragma once

#include "List.h"
#include "Tile.h"

class Board
{
private:
	List<Tile> Tiles;	//Creo una lista tiles, en la que cada nodo contiene un objeto Tile.
	unsigned int PageNumber;
	ALLEGRO_BITMAP *talesArray[TALES_MAX];

public:
	Board();
	~Board();
	void addTile(Tile element);
	void nextPage();
	void previousPage();
	void draw(List<Tile> Tile); //INAKI llama a los draw de cada tile
	void selectTile(int TileNum); //cambia el estado de las seleccionadas

};


//hacer un puntero de la primera imagen de las 9 que se muestran