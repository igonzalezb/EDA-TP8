
#include "Board.h"


Board::Board(List<Tile> *Tiles)
{
	this->Tiles = Tiles;

	PageNumber = 0;
	PageMax = Tiles->getListSize() / 9;
	if (Tiles->getListSize() % 9 >= 0)
		PageMax++;

	removeNonSquares();

	loadBitmaps();
	graphics.drawTiles();
}

void Board::nextPage() 
{
	if (PageNumber < PageMax)
	{
		PageNumber++;
		Tiles->moveToPos(9 * PageNumber);
	}
	
}

void Board::previousPage() 
{
	if (PageNumber > 0)
	{
		PageNumber--;
		Tiles->moveToPos(9 * PageNumber);
	}
	
}



void Board::selectTile(int TileNum)
{
	Tiles->getElement(TileNum).isSelected==true;
}

void Board::keyDispacher(ALLEGRO_EVENT ev)
{
	switch (ev.keyboard.keycode) {
	case ALLEGRO_KEY_A:
		for (int i = 1; (i < TILES_MAX); i++) { selectTile(i * PageNumber); }
		break;
	case ALLEGRO_KEY_N:
		for (int j = 1; (j < 6); j++, j++) { for (int i = 1; (i < 6); i++, i++) { selectTile(i * PageNumber); } }
		break;
	case ALLEGRO_KEY_RIGHT:

		break;
	case ALLEGRO_KEY_LEFT:

		break;
	case ALLEGRO_KEY_1:
		selectTile(1, 1, true);
		break;
	case ALLEGRO_KEY_2:
		selectTile(1, 3, true);
		break;
	case ALLEGRO_KEY_3:
		selectTile(1, 5, true);
		break;
	case ALLEGRO_KEY_4:
		selectTile(3, 1, true);
		break;
	case ALLEGRO_KEY_5:
		selectTile(3, 3, true);
		break;
	case ALLEGRO_KEY_6:
		selectTile(3, 5, true);
		break;
	case ALLEGRO_KEY_7:
		selectTile(5, 1, true);
		break;
	case ALLEGRO_KEY_8:
		selectTile(5, 3, true);
		break;
	case ALLEGRO_KEY_9:
		selectTile(5, 5, true);
		break;
	}


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