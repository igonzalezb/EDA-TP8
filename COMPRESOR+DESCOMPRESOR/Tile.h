#pragma once

#include <string>
//#include "stdint.h"

using namespace std;

class Tile
{
public:
	Tile() { ; }
	Tile(string path); 
	~Tile();
	void select();
	void deselect();
	void toggleSelection();
	bool isSelected();
	string getFilePath();



private:
	string filePath;
	bool selected;

};

