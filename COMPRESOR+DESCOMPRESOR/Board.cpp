
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
}

void Board::previousPage()
{
	PageNumber--;
}

void Board::draw() //hago el draw de cada uno de los elementos de la lista
{

	for (int i = 0; i < Tiles.getListSize(); i++)
	{
		//Tiles.getElement(i).draw(x0;y0);
	}

}

void Board::selectTile(int TileNum)
{
	Tiles.getElement(TileNum).isSelected==true;

}

