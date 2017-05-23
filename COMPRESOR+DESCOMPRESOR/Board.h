#pragma once

#include "Graphics.h"
#include "List.h"
#include "Tile.h"

class Board
{
	
public:
	Board(List<Tile> *Tiles);
	~Board();
	Graphic * getGraphics();
	void nextPage();
	void previousPage();
	void keyDispacher(ALLEGRO_EVENT ev);
	void removeNonSquares();
	void removeNonSelected();
	void toggleTile(int TileNum); //cambia el estado de las seleccionadas
	void drawTiles();
	void loadBitmaps();
	void startCompression();
	

private:
	List<Tile> *Tiles = NULL;	//Creo una lista tiles, en la que cada nodo contiene un objeto Tile.
	unsigned int PageNumber;
	unsigned int PageMax;
	Graphic *graphics;
};