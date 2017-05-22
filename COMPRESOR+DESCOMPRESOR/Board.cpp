
#include "Board.h"


Board::Board(List<Tile> *Tiles)
{
	this->Tiles = Tiles;

	PageNumber = 0;
	PageMax = Tiles->getListSize() / TILES_MAX;
	if (Tiles->getListSize() % TILES_MAX >= 0)
		PageMax++;

	removeNonSquares();

	loadBitmaps();
	drawTiles();
}

void Board::nextPage() 
{
	if (PageNumber < PageMax)
	{
		PageNumber++;
		Tiles->moveToPos(TILES_MAX * PageNumber);
		graphics.removeBitmaps();
		loadBitmaps();
	}
	
}

void Board::previousPage() 
{
	if (PageNumber > 0)
	{
		PageNumber--;
		Tiles->moveToPos(PageNumber * TILES_MAX);
		graphics.removeBitmaps();
		loadBitmaps();
	}
	
}





void Board::keyDispacher(ALLEGRO_EVENT ev)
{
	switch (ev.keyboard.keycode) {
	case ALLEGRO_KEY_A:
		for (int i = (PageNumber * TILES_MAX); i < (TILES_MAX + (PageNumber * TILES_MAX)); i++) { selectTile(i); }
		break;
	case ALLEGRO_KEY_N:
		for (int i = (PageNumber * TILES_MAX); i < (TILES_MAX + (PageNumber * TILES_MAX)); i++) { deselectTile(i); }
		break;
	case ALLEGRO_KEY_RIGHT:
		nextPage();
		break;
	case ALLEGRO_KEY_LEFT:
		previousPage();
		break;
	case ALLEGRO_KEY_1:
		toggleTile(PageNumber * TILES_MAX);
		break;
	case ALLEGRO_KEY_2:
		toggleTile((PageNumber * TILES_MAX) + 1);
		break;
	case ALLEGRO_KEY_3:
		toggleTile((PageNumber * TILES_MAX) + 2);
		break;
	case ALLEGRO_KEY_4:
		toggleTile((PageNumber * TILES_MAX) + 3);
		break;
	case ALLEGRO_KEY_5:
		toggleTile((PageNumber * TILES_MAX) + 4);
		break;
	case ALLEGRO_KEY_6:
		toggleTile((PageNumber * TILES_MAX) + 5);
		break;
	case ALLEGRO_KEY_7:
		toggleTile((PageNumber * TILES_MAX) + 6);
		break;
	case ALLEGRO_KEY_8:
		toggleTile((PageNumber * TILES_MAX) + 7);
		break;
	case ALLEGRO_KEY_9:
		toggleTile((PageNumber * TILES_MAX) + 8);
		break;
	}

	drawTiles();

}


void Board::drawTiles()
{
	int tileNumber = 0;

	for (int j = 1; (j < 6) && (tileNumber < TILES_MAX); j++, j++, tileNumber++) {

		for (int i = 1; (i < 6) && (tileNumber < TILES_MAX); i++, i++, tileNumber++) {

			graphics.drawTiles(i, j, tileNumber, Tiles->getElement((PageNumber * TILES_MAX) + tileNumber).isSelected());

		}

		tileNumber--;
	}

	al_flip_display();
}


void Board::toggleTile(int TileNum)
{
	Tiles->getElement(TileNum).toggleSelection();
}

void Board::selectTile(int TileNum)
{
	Tiles->getElement(TileNum).isSelected = true;
}

void Board::deselectTile(int TileNum)
{
	Tiles->getElement(TileNum).isSelected = false;
}


void Board::loadBitmaps()
{
	for (unsigned int i = 0; i < TILES_MAX; i++)
	{
		string s = Tiles->getElement(i *PageNumber).getFilePath();
		const char *path = s.c_str();
		graphics.loadBitmaps(i, path);

	}
}


unsigned int Board::getPageNumber()
{
	return PageNumber;
}

void Board::removeNonSquares()
{
	for (int i = 0; i < Board::Tiles->getListSize(); i++)
	{
		ALLEGRO_BITMAP *image = NULL;
		string s = Tiles->getElement(i).getFilePath();
		const char *path = s.c_str();
		image = al_load_bitmap(path);
		if (!image)
			fprintf(stderr, "failed to check dimensions\n");
		if (al_get_bitmap_width(image) != al_get_bitmap_height(image))
			Tiles->removeElement(i);

		al_destroy_bitmap(image);
	}
}

Board::~Board()
{
}

//void Board::addTile(Tile element)
//{
//	Tiles.addElement(element);
//}