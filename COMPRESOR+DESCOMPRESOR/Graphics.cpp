#include "Graphics.h"


Graphic::Graphic()
{
	font = al_load_ttf_font("resources\\font.ttf", 25, 0);
	if (!font) {
		fprintf(stderr, "failed to create font!\n");
	}

	background = al_load_bitmap("resources\\background.png");
	if (!background) {
		fprintf(stderr, "failed to create background!\n");
	}

	al_clear_to_color(al_map_rgb(0.0, 0.0, 0.0));

	al_draw_scaled_bitmap(background, 0.0, 0.0,
		al_get_bitmap_width(background), al_get_bitmap_height(background),
		0.0, 0.0, SCREEN_W, SCREEN_H, 0);

}



void Graphic::loadBitmaps(int i, const char *path)
{
	tilesArray[i] = al_load_bitmap(path);
	if (!tilesArray[i])
	{
		fprintf(stderr, "failed to create tale\n");
		tilesArray[i] = NULL; //??????
	}
}


void Graphic::drawTiles(unsigned int i, unsigned int j, unsigned int tileNumber, bool isSelected, unsigned int PageNumber)
{
	al_draw_scaled_bitmap(tilesArray[tileNumber], 0.0, 0.0,
		al_get_bitmap_width(tilesArray[tileNumber]), al_get_bitmap_height(tilesArray[tileNumber]),
		((SCREEN_W / 6) * (i)) - (TILES_W / 2),
		((SCREEN_H / 6) * (j)) - (TILES_H / 2),
		TILES_W, TILES_H, 0);
	if (isSelected)
		al_draw_rectangle(((SCREEN_W / 6) * (i)) - (TILES_W / 2), ((SCREEN_H / 6) * (j)) - (TILES_H / 2),
		((SCREEN_W / 6) * (i)) - (TILES_W / 2) + TILES_W, ((SCREEN_H / 6) * (j)) - (TILES_H / 2) + TILES_H,
			al_map_rgb(0.0, 255.0, 0.0), 5.0);
	else
		al_draw_rectangle(((SCREEN_W / 6) * (i)) - (TILES_W / 2), ((SCREEN_H / 6) * (j)) - (TILES_H / 2),
		((SCREEN_W / 6) * (i)) - (TILES_W / 2) + TILES_W, ((SCREEN_H / 6) * (j)) - (TILES_H / 2) + TILES_H,
			al_map_rgb(0.0, 0.0, 0.0), 5.0);
	al_draw_textf(font, al_map_rgb(0, 0, 0), ((SCREEN_W / 6) * (i)), ((SCREEN_H / 6) * (j)) + (TILES_H / 2), ALLEGRO_ALIGN_CENTRE, "%d", tileNumber + 1);
	al_draw_textf(font, al_map_rgb(0, 0, 0), SCREEN_W -30, SCREEN_H-35, ALLEGRO_ALIGN_CENTRE, "%d", PageNumber);
}


void Graphic::removeBitmaps(unsigned int PageNumber, unsigned int ListSize)
{	
	for (unsigned int i = 0; (i < TILES_MAX) && (((PageNumber * TILES_MAX) + i) < ListSize); i++)
		al_destroy_bitmap(tilesArray[i]);
}

void Graphic::cleanScreen()
{
	al_clear_to_color(al_map_rgb(0.0, 0.0, 0.0));

	al_draw_scaled_bitmap(background, 0.0, 0.0,
		al_get_bitmap_width(background), al_get_bitmap_height(background),
		0.0, 0.0, SCREEN_W, SCREEN_H, 0);
}

Graphic::~Graphic()
{
	al_destroy_font(font);
	al_destroy_bitmap(background);
}