#pragma once
#include "main.h"

#if IAM == COMPRESSOR
#include <boost/filesystem.hpp>
#include <fstream>
#include "paths.h"


#define PIXEL		4

using namespace std;

class Compressor
{
private:
	unsigned char* Img; // arreglo donde se guarda lo que devuelve la funcion lodepng_decode32_file
	Paths* Path;
	unsigned int imgW;	//alto inicial de la imagen
	int threshold;		//esta entre 0 y 100 % donde 0 significa 0 y 100 significa 3 * 255

public:

	//Constructor de la clase
	Compressor(); 


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Recibe: un path .png, el tamano de un lado de la imagen y el threshold
	//Devuelve: un bool que determina si realizo la operacion correctamente
	//Decodifica la imagen con la funcion lodepng_decode32_file() que completa el arreglo Img.
	//Crea una extension .mvi con el path que le llego, abre el .mvi en modo escritura. 
	//El .mvi es donde queda la imagen comprimida luego de llamar a quadTree() 
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool compressingFunction(const char* filePath, unsigned int lado, int threshold);



	//////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Recibe: el tamano del lado y el x0 e y0 donde empieza el cuadrante que se esta procesando actualemente
	// y un puntero al .mvi donde se va a guardar la imagen comprimida
	//Devuelve: nada
	//Comprime una imagen utilizando el algoritmo quad tree.
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	void quadTree(unsigned int x0, unsigned int y0, double lado, std::ofstream* vim);
};

#endif
