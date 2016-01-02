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
	gridwidth = 3;
	gridheight = 3;
	cellwidth = 64;
	cellheight = 64;
	tileCounter = 0;
	this->position = Point2(50, 150);
	this->addGrid("assets/tiles_numbers.tga", 3, 3, gridwidth, gridheight, cellwidth, cellheight);

	// ###############################################################
	// Open the file 'assets/tiles_numbers.csv'
	// First, read the whole file with the .is_open() function
	// Second, read every line singly
	// Third, take every cell single
	// Fourth, with the function spritebatch() every tile set to the current cell 
	// ###############################################################
	string line, cell;
	ifstream myfile("assets/tiles_numbers.csv");
	// try to open the file, else if you cannot throw exception
	try
	{
		myfile.is_open();

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
	// display the exception thrown
	catch (ifstream::failure e) {
		cout << "Exception opening/reading file: " << e.what();
	}
}


LoadTiles::~LoadTiles()
{
}

void LoadTiles::LoadAndConvertTile()
{
}
