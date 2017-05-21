#pragma once

#include "List.h"
#include "Tile.h"

class Board
{
private:
	List<Tile> tiles;	//Creo una lista tiles, en la que cada nodo contiene un objeto Tile.
	unsigned int PageNumber;

public:
	Board();
	~Board();
	void addTile();
	void nextPage();
	void previousPage();
	void draw();
	void selectTile(unsigned int filename);
	List<Tile> getTiles(); //ver si tiene que devolver List<Tile> o un List<Tile>*
};


//hacer un puntero de la primera imagen de las 9 que se muestran