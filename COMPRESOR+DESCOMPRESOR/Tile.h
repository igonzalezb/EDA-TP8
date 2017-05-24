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
	int getLength();
	void setLength(int length);


private:
	string filePath;
	bool selected;
	int length;

};

