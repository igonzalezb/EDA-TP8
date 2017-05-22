
#include "Board.h"


Board::Board() 
{
	PageNumber = 0;
	loadBitmaps();
}

Board::~Board()
{
	
}

void Board::addTile(Tile element)
{
	Tiles.addElement(element);
}

void Board::nextPage() 
{
	PageNumber++;
	Tiles.moveToPos(9*PageNumber);
	removeBitmaps();
	loadBitmaps();
}

void Board::previousPage() 
{
	PageNumber--;
	Tiles.moveToPos(9 * PageNumber);
	removeBitmaps();
	loadBitmaps();
}

void Board::loadBitmaps()
{
	for (unsigned int i = 0; i < TILES_MAX; i++)
	{
		string s = Tiles.getElement(i*PageNumber).getFilePath();
		const char *path = s.c_str();
		tilesArray[i] = al_load_bitmap(path);
		if (!tilesArray[i])
		{
			fprintf(stderr, "failed to create tale\n");
			for (i--; i >= 0; i--)
				al_destroy_bitmap(tilesArray[i]);
		}

	}
}

void Board::removeBitmaps()
{
	for (unsigned int i = 0; i < TILES_MAX; i++) {
		al_destroy_bitmap(tilesArray[i]);
	}
}

void Board::drawTales()
{
	int tileNumber = 0;

	for (int j = 1; (j < 6) && (tileNumber < TILES_MAX); j++, j++, tileNumber++) {

		for (int i = 1; (i < 6) && (tileNumber < TILES_MAX); i++, i++, tileNumber++) {

			al_draw_scaled_bitmap(tilesArray[tileNumber], 0.0, 0.0,
				al_get_bitmap_width(tilesArray[tileNumber]), al_get_bitmap_height(tilesArray[tileNumber]),
				((SCREEN_W / 6) * (i)) - (TILES_W / 2),
				((SCREEN_H / 6) * (j)) - (TILES_H / 2),
				TILES_W, TILES_H, 0);
			al_draw_textf(font, al_map_rgb(0, 0, 0), ((SCREEN_W / 6) * (i)), ((SCREEN_H / 6) * (j)) + (TILES_H / 2), ALLEGRO_ALIGN_CENTRE, "%d", tileNumber + 1);
		}

		tileNumber--;
	}

	al_flip_display();

}

void Board::selectTile(int TileNum)
{
	Tiles.getElement(TileNum).isSelected==true;

}

