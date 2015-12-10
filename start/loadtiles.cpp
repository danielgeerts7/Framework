/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/


#include "loadtiles.h"

LoadTiles::LoadTiles() : BasicEntity()
{
	gridwidth = 12;
	gridheight = 12;
	cellwidth = 64;
	cellheight = 64;
	this->position = Point2(0, 0);
	this->addGrid("assets/tiles_1.tga", 6, 6, gridwidth, gridheight, cellwidth, cellheight);

	int counter = 0;
	for (int x = 0; x < gridwidth; x++) {
		for (int y = 0; y < gridheight; y++) {
			this->spritebatch()[counter]->frame(rand() % 16);
			counter++;
		}
	}
}


LoadTiles::~LoadTiles()
{
}

void LoadTiles::LoadAndConvertTile()
{
}
