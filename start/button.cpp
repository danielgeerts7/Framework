/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "button.h"

Button::Button(Text* t, string s) : BasicEntity()
{
	this->position.x = SWIDTH / 2;
	this->addSprite("assets/block.tga");
	this->sprite()->color = GRAY;

	t->message(s);
}


Button::~Button()
{
}
