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
	~Button();
};

#endif /*BUTTON_H*/
