#pragma once

#include "List.h"
#include "Tile.h"

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

#define SCREEN_W	1000
#define SCREEN_H	600
#define TILES_MAX	9
#define TILES_W		230.0
#define TILES_H		120.0


Board b; (aca adentro List Tiles)
path p;
b.Tiles



class Board
{
private:
	List<Tile> Tiles;	//Creo una lista tiles, en la que cada nodo contiene un objeto Tile.
	unsigned int PageNumber;
	ALLEGRO_BITMAP *tilesArray[TILES_MAX];
	ALLEGRO_FONT *font = NULL;

public:
	Board();
	~Board();
	void addTile(Tile element);
	void nextPage();
	void previousPage();
	void drawTales(); //INAKI llama a los draw de cada tile
	void selectTile(int TileNum); //cambia el estado de las seleccionadas
	void loadBitmaps();
	void removeBitmaps();
};


//hacer un puntero de la primera imagen de las 9 que se muestran