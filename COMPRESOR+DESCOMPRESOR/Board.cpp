
#include "Board.h"

Board::Board(List<Tile> *Tiles)
{
	this->Tiles = Tiles;
	PageNumber = 0;

	graphics = new Graphic();

#if IAM == COMPRESSOR
	removeNonSquares();
	loadBitmaps();
#endif

	
	PageMax = Tiles->getListSize() / TILES_MAX;
	PageMax--;

	if (Tiles->getListSize() % TILES_MAX >= 0)
		PageMax++;
	drawTiles();
}

void Board::nextPage() 
{
	if (PageNumber < PageMax)
	{
		PageNumber++;
		Tiles->moveToPos(TILES_MAX * PageNumber);
		
#if IAM == COMPRESSOR
		graphics->removeBitmaps(PageNumber, Tiles->getListSize());
		loadBitmaps();
#endif
	}
	
}

void Board::previousPage() 
{
	if (PageNumber > 0)
	{
		PageNumber--;
		Tiles->moveToPos(PageNumber * TILES_MAX);
#if IAM == COMPRESSOR
		graphics->removeBitmaps(PageNumber, Tiles->getListSize());
		loadBitmaps();
#endif
	}
	
}

bool Board::keyDispacher(ALLEGRO_EVENT ev)
{
	switch (ev.keyboard.keycode) {
	
	case ALLEGRO_KEY_ESCAPE:
#if IAM == COMPRESSOR
		graphics->cleanScreen();
		graphics->removeBitmaps(PageNumber, Tiles->getListSize());
#endif
		return true;
	case ALLEGRO_KEY_A:
		for (unsigned int i = 0; i <  Tiles->getListSize(); i++) { Tiles->getElement(i).select(); }
		break;
	case ALLEGRO_KEY_N:
		for (unsigned int i = 0; i <  Tiles->getListSize(); i++) { Tiles->getElement(i).deselect(); }
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
	return false;

}

void Board::drawTiles()
{
	graphics->cleanScreen();

	unsigned int tileNumber = 0;

	for (unsigned int j = 1; (j < 6) && (tileNumber < TILES_MAX) && (((PageNumber * TILES_MAX) + tileNumber) < Tiles->getListSize()); j++, j++, tileNumber++) {

		for (unsigned int i = 1; (i < 6) && (tileNumber < TILES_MAX) && (((PageNumber * TILES_MAX) + tileNumber) < Tiles->getListSize()); i++, i++, tileNumber++) {
#if IAM == COMPRESSOR
			graphics->drawPng(i, j, tileNumber, Tiles->getElement((PageNumber * TILES_MAX) + tileNumber).isSelected(), PageNumber);
#else
			graphics->drawCompressed(i, j, tileNumber, 
				Tiles->getElement((PageNumber * TILES_MAX) + tileNumber).isSelected(), 
				PageNumber, Tiles->getElement((PageNumber * TILES_MAX) + tileNumber).getFilePath().c_str());
#endif
		}

		tileNumber--;
	}

	al_flip_display();
}

void Board::toggleTile(int TileNum)
{
	if(TileNum < Tiles->getListSize())
		Tiles->getElement(TileNum).toggleSelection();
}

#if IAM == COMPRESSOR
void Board::loadBitmaps()
{
	for (unsigned int i = 0; (i < TILES_MAX) && (((PageNumber * TILES_MAX) + i) < Tiles->getListSize()); i++)
	{
		graphics->loadBitmaps(i, Tiles->getElement((PageNumber * TILES_MAX) + i).getFilePath().c_str());

	}
}

void Board::removeNonSquares()
{
	for (int i = 0; i < Tiles->getListSize(); i++)
	{
		ALLEGRO_BITMAP *image = NULL;

		image = al_load_bitmap(Tiles->getElement(i).getFilePath().c_str());
		if (!image)
			fprintf(stderr, "failed to check dimensions\n");
		else if (!((al_get_bitmap_width(image) == al_get_bitmap_height(image)) && ((al_get_bitmap_width(image)&(al_get_bitmap_width(image) - 1)) == 0)))
		{
			Tiles->removeElement(i);
			i--;
		}
			
		else {
			Tiles->getElement(i).setLength(al_get_bitmap_width(image));
		}
		al_destroy_bitmap(image);
	}
}

#endif


void Board::startCompression()
{
	graphics->compreScreen();
#if IAM == COMPRESSOR
	graphics->removeBitmaps(PageNumber, Tiles->getListSize());
#endif
	removeNonSelected();
}

Graphic * Board::getGraphics()
{
	return graphics;
}

List<Tile>* Board::getTiles()
{
	return Tiles;
}

void Board::removeNonSelected()
{
	for (int i = 0; i < Tiles->getListSize(); i++)
	{
		if (!Tiles->getElement(i).isSelected()) {
			Tiles->removeElement(i);
			i--;
		}
	}
}

Board::~Board()
{
	graphics->cleanScreen();
	delete graphics;
}