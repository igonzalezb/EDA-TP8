
#include "Board.h"


Board::Board() 
{
	PageNumber = 0;
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

}

void Board::previousPage() 
{
	PageNumber--;

	Tiles.moveToPos(9 * PageNumber);
}

void Board::draw(List<Tile> Tile) 
{


}

void Board::selectTile(int TileNum)
{
	Tiles.getElement(TileNum).isSelected==true;

}

