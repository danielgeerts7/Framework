/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "loadtiles.h"

LoadTiles::LoadTiles() : BasicEntity()
{
	// ###############################################################
	// Setting variables
	// ###############################################################
	gridwidth = 25;
	gridheight = 15;
	cellwidth = 64;
	cellheight = 64;
	tileCounter = 0;
	this->position = Point2(32, 32);
	this->addGrid("assets/default_tile_grid.tga", 8, 1, gridwidth, gridheight, cellwidth, cellheight);

	// ###############################################################
	// Open the file 'assets/tiles_numbers.csv'
	// First, read the whole file with the .is_open() function
	// Second, read every line singly
	// Third, take every cell single
	// Fourth, with the function spritebatch() every tile set to the current cell 
	// ###############################################################
	string line, cell;
	ifstream myfile("assets/default_tile_grid.csv");

	//check if file is open
	if (myfile.is_open()) {
		// read each line into line
		while (getline(myfile, line))
		{
			cout << "Line contains: " << line << endl;
			// copy the line into lineSteam, so we can store them into a string delimited 
			stringstream  lineStream(line);
			while (getline(lineStream, cell, ','))
			{
				cout << "Words delimited by space: " << cell << endl;

				int result = 0;
				result = std::atoi(cell.c_str());

				this->spritebatch()[tileCounter]->frame(result);
				tileCounter++;

				ints.push_back(result);
			}
		}
	}
}


LoadTiles::~LoadTiles()
{
}
