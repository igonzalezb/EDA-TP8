#pragma once
#include "main.h"
#if IAM == DECOMPRESSOR
#include <boost/filesystem.hpp>
#include <fstream>
#include "paths.h"


#define PIXEL		4
#define THRESHOLD	100 //VER QUE NUMERO CONVIENE

using namespace std;

class Decompressor
{
private:
	 
	unsigned char* Img;
	Paths* Path;
	unsigned int imgW;
public:
	Decompressor();

	bool decompressingFunction(const char* filePath);
	bool quadTree(unsigned int x0, unsigned int y0, double lado, std::ifstream* vim);
};

#endif