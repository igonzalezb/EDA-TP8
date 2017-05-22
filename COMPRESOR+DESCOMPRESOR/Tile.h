#pragma once

#include <string>
//#include "stdint.h"

using namespace std;

class Tile
{
public:

	Tile(string path); 
	~Tile();

	void toggleSelection();
	bool isSelected();
	string getFilePath();

	void draw(unsigned int x0, unsigned int y0);  //INAKI


private:

	string filePath;
	bool selected;

};

