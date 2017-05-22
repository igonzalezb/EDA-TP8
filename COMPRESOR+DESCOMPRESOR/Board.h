#pragma once

#include "Graphics.h"
#include "List.h"
#include "Tile.h"


class Board
{
	
public:
	Board(List<Tile> *Tiles);
	~Board();
	//void addTile(Tile element);
	void nextPage();
	void previousPage();
	void loadBitmaps();
	void selectTile(int TileNum); //cambia el estado de las seleccionadas
	void removeNonSquares();
	unsigned int getPageNumber();
	void keyDispacher(ALLEGRO_EVENT ev);

private:
	List<Tile> *Tiles;	//Creo una lista tiles, en la que cada nodo contiene un objeto Tile.
	unsigned int PageNumber;
	unsigned int PageMax;
	Graphic graphics;
};


//hacer un puntero de la primera imagen de las 9 que se muestran