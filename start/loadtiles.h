/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef LOADTILES_H
#define LOADTILES_H

#include <fstream>
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
};

#endif /* LOADTILES_H */ 
