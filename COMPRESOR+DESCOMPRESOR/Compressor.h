#pragma once
#include "main.h"

#if IAM == COMPRESSOR
#include <boost/filesystem.hpp>
#include <fstream>
#include "paths.h"


#define PIXEL		4
//#define THRESHOLD	0 //VER QUE NUMERO CONVIENE

using namespace std;

class Compressor
{
private:
	unsigned char* Img;
	Paths* Path;
	unsigned int imgW;
	int threshold;

public:
	Compressor();

	//void decode(char* path); //Descompresor tiene que tener encode
	bool compressingFunction(const char* filePath, unsigned int lado, int threshold);
	void quadTree(unsigned int x0, unsigned int y0, double lado, std::ofstream* vim);
};

#endif
