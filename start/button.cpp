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
	
	resolution = 64;
}


Button::~Button()
{
}

int Button::checkIfMouseIsOverBtn(Point2 mousepos, Vector2 scale)
{
	int mousex = mousepos.x;
	int mousey = mousepos.y;

	int radiusWidth = (scale.x * resolution) / 2;
	int radiusHeight = (scale.y * resolution) / 2;

	if (mousex < this->position.x + radiusWidth &&
		mousex > this->position.x - radiusWidth &&
		mousey < this->position.y + radiusHeight &&
		mousey > this->position.y - radiusHeight) {
		return 1;
	} else {
		return 0;
	}
}
