#pragma once

#include <boost/filesystem.hpp>
#include <fstream>
#include "paths.h"


#define PIXEL		4
#define THRESHOLD	50 //VER QUE NUMERO CONVIENE

using namespace std;

class Decompressor
{
private:
	 
	unsigned char* Img;
	Paths* Path;

public:
	Decompressor();

	bool decompressingFunction(char* filePath, unsigned int lado);
	bool quadTree(unsigned int x0, unsigned int y0, double lado, std::ifstream* vim);
};
