/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef BUTTON_H
#define BUTTON_H

#include "basicentity.h"
#include <rt2d/text.h>
using namespace std;

class Button : public BasicEntity
{
public:
	Button(Text* t, string s);
	virtual ~Button();

	int checkIfMouseIsOverBtn(Point2 mousepos, Vector2 scale);

private:
	int resolution;
};

#endif /*BUTTON_H*/
