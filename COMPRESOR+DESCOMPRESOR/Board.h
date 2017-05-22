#pragma once

#include "List.h"
#include "Tile.h"

class Board
{
private:
	List<Tile> Tiles;	//Creo una lista tiles, en la que cada nodo contiene un objeto Tile.
	unsigned int PageNumber;

public:
	Board();
	~Board();
	void addTile(Tile element);
	void nextPage();
	void previousPage();
	void draw(); //INAKI llama a los draw de cada tile
	void selectTile(int TileNum); //cambia el estado de las seleccionadas

};


//hacer un puntero de la primera imagen de las 9 que se muestran