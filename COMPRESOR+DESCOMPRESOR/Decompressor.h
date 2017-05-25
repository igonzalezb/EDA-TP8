#pragma once
#include "main.h"
#if IAM == DECOMPRESSOR
#include <boost/filesystem.hpp>
#include <fstream>
#include "paths.h"

#define NEW_SIZE	1024
#define PIXEL		4

using namespace std;

class Decompressor
{
private:
	 
	unsigned char* Img; 
	Paths* Path;
	unsigned int imgW;
public:
	//Constructor de la clase
	Decompressor();

	//////////////////////////////////////////////////////////////////////////////////////////////////////
	//Recibe: un path .mvi 
	//Devuelve: un bool para determinar si la operacion se realizo correctamente
	//realiza la funcion inversa a compressingFunction()
	//crea una extension (new).png con el path .mvi que le llega del archivo que se quiere descomprimir
	//abre el .mvi en modo lectura yrealiza la funcion quadTree y luego a la funcion lodepng_encode32_file 
	//y asi crea un archivo de tipo (new).png con la imagen descomprimida, de tamano lado*lado*PIXEL
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	bool decompressingFunction(const char* filePath);


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Recibe: el tamano del lado y el x0 e y0 donde empieza el cuadrante que se esta procesando actualemente
	// y un puntero al .mvi de donde voy a leer la informacion
	//Devuelve: un bool que determina si la operacion fue realizada correctamente.
	//quaadTree va geteando del .mvi, si se encuentra un 1 es porque el cuadrante se dividio en 4 y hace la recurcividad
	//si encuentra un 0, el cuadrante no se dividio y guarda los valores RGBA de los pixel del cuadrante en el arreglo Img.
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool quadTree(unsigned int x0, unsigned int y0, double lado, std::ifstream* vim);
};

#endif