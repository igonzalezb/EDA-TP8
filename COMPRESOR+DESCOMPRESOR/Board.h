#pragma once

#include "main.h"
#include "Graphics.h"
#include "List.h"
#include "Tile.h"

class Board
{
	
public:
	Board(List<Tile> *Tiles);
	~Board();
	Graphic * getGraphics();
	List<Tile> *getTiles();
	void nextPage();
	void previousPage();
	bool keyDispacher(ALLEGRO_EVENT ev);
	
	void removeNonSelected();
	void toggleTile(int TileNum); //cambia el estado de las seleccionadas
	void drawTiles();
	void startCompression();

#if IAM == COMPRESSOR
	void loadBitmaps();
	void removeNonSquares();
	
#endif
	
	

private:
	List<Tile> *Tiles = NULL;	//Creo una lista tiles, en la que cada nodo contiene un objeto Tile.
	unsigned int PageNumber;
	unsigned int PageMax;
	Graphic *graphics;
};