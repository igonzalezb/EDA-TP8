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



private:

	string filePath;
	bool selected;

};

