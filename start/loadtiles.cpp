/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/


#include "loadtiles.h"
using namespace std;

LoadTiles::LoadTiles() : BasicEntity()
{
	/*
	IN 'assets/tiles_2.cvs' :::::::
	Needs to work:
	0,1,2,3,4,5
	6,7,8,9,10,11
	12,13,14,15,16,17
	18,19,20,21,22,23
	24,25,26,27,28,29
	30,31,32,33,34,35

	Works now:
	30,24,18,12,6,0
	31,25,19,13,7,1
	32,26,20,14,8,2
	33,27,21,15,9,3
	34,28,22,16,10,4
	35,29,23,17,11,5

	OR THERE IS SOMETHING WRONG WITH THE 'ADDGRID' OR ELSE WITH THE IFSTREAM FILE CHECKER
	*/
	
	gridwidth = 6;
	gridheight = 6;
	cellwidth = 64;
	cellheight = 64;
	tileCounter = 0;
	this->position = Point2(0, 0);
	this->addGrid("assets/tiles_1.tga", 6, 6, gridwidth, gridheight, cellwidth, cellheight);
	
	string line, cell;
	ifstream myfile("assets/tiles_2.csv");
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
