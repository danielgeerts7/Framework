/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef LOADTILES_H
#define LOADTILES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstddef>
#include "basicentity.h"

class LoadTiles : public BasicEntity
{
public:
	LoadTiles();
	virtual ~LoadTiles();

	void LoadAndConvertTile();

private:
	int gridwidth;
	int gridheight;
	int cellwidth;
	int cellheight;

	int tileCounter;

	std::vector<int> ints;
};

#endif /* LOADTILES_H */ 
