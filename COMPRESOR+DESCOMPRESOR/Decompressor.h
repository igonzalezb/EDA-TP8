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
	Decompressor();

	bool decompressingFunction(const char* filePath);
	bool quadTree(unsigned int x0, unsigned int y0, double lado, std::ifstream* vim);
};

#endif