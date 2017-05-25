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
	unsigned char* Img;
	Paths* Path;
	unsigned int imgW;
	int threshold;

public:
	Compressor();
	bool compressingFunction(const char* filePath, unsigned int lado, int threshold);
	void quadTree(unsigned int x0, unsigned int y0, double lado, std::ofstream* vim);
};

#endif
