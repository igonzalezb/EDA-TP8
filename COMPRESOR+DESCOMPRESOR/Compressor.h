#pragma once

#include <boost/filesystem.hpp>
#include "lodepng.h"
#include <string>

enum { COMPONENTE_R, COMPONENTE_G, COMPONENTE_B }componentesRGB;

class Compressor
{
private:
	unsigned char* Img;
	unsigned int imgWidth;
	unsigned int imgHeight;
	

public:
	//void decode(char* path); //Descompresor tiene que tener encode
	void decode(char* path);

	void quadTree(unsigned char* image, unsigned int x0, unsigned int y0,
		unsigned int xf, unsigned int yf, FILE* fp);
	unsigned int max(unsigned int, unsigned int);
	unsigned int min(unsigned int, unsigned int);
};

