#pragma once

#include "main.h"
#include "Graphics.h"
#include "List.h"
#include "Tile.h"

class Board
{
	
public:
	

	//	Constructor de la clase que recibe un puntero a una lista
	Board(List<Tile> *Tiles);
	

	//	Devuelve el objeto graphics
	Graphic * getGraphics();


	//	Devuelve un puntero a la Lista
	List<Tile> *getTiles();


	//	Cambia de Pagina
	void nextPage();
	void previousPage();


	//	Dispacher de eventos de teclado
	bool keyDispacher(ALLEGRO_EVENT ev);
	

	//	Elimina de la lista los archivos que no fueron seleccionados
	void removeNonSelected();


	//	Cambia el estado de las seleccionadas
	void toggleTile(int TileNum); 

	//	Dibuja en pantalla nueve imagenes de la pagina actua
	void drawTiles();


	//	Cambia la pantalla y elimina bitmaps que no se necesitan. 
	//	Llamar antes de la compression
	void startCompression();


	//	Destructor de Board
	~Board();
#if IAM == COMPRESSOR

	//	Crea nueve bitmaps en un arreglo que luego son mostrados en el display
	void loadBitmaps();


	//	Elimina de la lista las imagenes que no son cuadras y su tamaño no es una potencia de 2
	void removeNonSquares();
	
#endif
	
	

private:
	List<Tile> *Tiles = NULL;	//Creo una lista tiles, en la que cada nodo contiene un objeto Tile.
	unsigned int PageNumber;
	unsigned int PageMax;
	Graphic *graphics;
};