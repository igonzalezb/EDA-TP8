#pragma once
#include "main.h"
#include <iostream>
#include <string>
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

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
//		GRAPHIC
//
////////////////////////////////////////////////////////////////////////////////////////////
class Graphic
{
	
public:

	Graphic();
	~Graphic();
#if IAM == COMPRESSOR
	//Cargo las imagenes como bitmaps en un arrrelgo, maximo 9
	void loadBitmaps(int i, const char *path);

	//Elimino los bitmaps del arreglo
	void removeBitmaps(unsigned int PageNumber, unsigned int ListSize);

	//Dibujo en pantalla un bitmap 
	void drawPng(unsigned int i, unsigned int j, unsigned int tileNumber, bool isSelected, unsigned int PageNumber);
#else
	//Dibujo en pantalla la imagen comprimida.
	void drawCompressed(unsigned int i, unsigned int j, unsigned int tileNumber, bool isSelected, unsigned int PageNumber, const char* name);
#endif
	//Screen que se muestra mientras se comprimen imagenes
	void compreScreen();

	//Borro todo el display y vuelvo a cargar el fondo
	void cleanScreen();

	//Devuelve un puntero al display
	ALLEGRO_DISPLAY * getDisplay();

	//Devuelve un puntero a la event queue
	ALLEGRO_EVENT_QUEUE * getEventQueue();

private:
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_BITMAP *logo = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	
	
	ALLEGRO_FONT *font = NULL;
	ALLEGRO_BITMAP *background = NULL;
#if IAM == COMPRESSOR
	ALLEGRO_BITMAP *tilesArray[TILES_MAX];
#endif
};
