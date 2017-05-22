#pragma once

#include "Graphics.h"
#include "List.h"
#include "Tile.h"

class Board
{
	
public:
	Board(List<Tile> *Tiles);
	~Board();
	void nextPage();
	void previousPage();
	void loadBitmaps();
	void toggleTile(int TileNum); //cambia el estado de las seleccionadas
	void selectTile(int TileNum);
	void deselectTile(int TileNum);
	void removeNonSquares();
	void keyDispacher(ALLEGRO_EVENT ev);
	void drawTiles();
	void removeBitmaps();

private:
	List<Tile> *Tiles = NULL;	//Creo una lista tiles, en la que cada nodo contiene un objeto Tile.
	unsigned int PageNumber;
	unsigned int PageMax;
	Graphic graphics;
};


//hacer un puntero de la primera imagen de las 9 que se muestran