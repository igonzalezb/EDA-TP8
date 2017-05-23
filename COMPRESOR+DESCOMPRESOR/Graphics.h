#pragma once
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

class Graphic
{
	
public:
	Graphic();
	~Graphic();
	void loadBitmaps(int i, const char *path);
	void drawTiles(int i, int j, int tileNumber, bool isSelected, int PageNUmber);
	void removeBitmaps(int i);
	void cleanScreen();
private:
	ALLEGRO_BITMAP *tilesArray[TILES_MAX];
	ALLEGRO_FONT *font = NULL;
	ALLEGRO_BITMAP *background = NULL;
};
