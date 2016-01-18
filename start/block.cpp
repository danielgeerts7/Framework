/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "block.h"


Block::Block() : BasicEntity()
{
	this->addSprite("assets/block.tga");
	this->sprite()->color = BLUE;
}


Block::~Block()
{
}


void Block::baiscEntityCollidWithBlock(BasicEntity* other, int thisRadius, int otherRadius)
{
	int thisLeft = this->position.x - thisRadius;
	int thisRight = this->position.x + thisRadius;
	int thisTop = this->position.y - thisRadius;
	int thisBottom = this->position.y + thisRadius;

	int otherLeft = other->position.x - otherRadius;
	int otherRight = other->position.x + otherRadius;
	int otherTop = other->position.y - otherRadius;
	int otherBottom = other->position.y + otherRadius;

	if (thisRight >= otherLeft && thisLeft <= otherRight && thisBottom >= otherTop && thisTop <= otherBottom) {
		//Checking this bottom side, and other top side
		if (this->position.y + thisRadius >= other->position.y - otherRadius && this->position.y + thisRadius - 1 <= other->position.y - otherRadius + 1) {
			other->position.y = this->position.y + (thisRadius + otherRadius + 1);
		}
		//Checking this top side, and other bottom side
		if (this->position.y - thisRadius <= other->position.y + otherRadius && this->position.y - thisRadius + 1 >= other->position.y + otherRadius - 1) {
			other->position.y = this->position.y - (thisRadius + otherRadius + 1);
		}
		//Checking this right side, and other left side
		if (this->position.x + thisRadius >= other->position.x - otherRadius && this->position.x + thisRadius - 1 <= other->position.x - otherRadius + 1) {
			other->position.x = this->position.x + (thisRadius + otherRadius + 1);
		}
		//Checking this left side, and other right side
		if (this->position.x - thisRadius <= other->position.x + otherRadius && this->position.x - thisRadius + 1 >= other->position.x + otherRadius - 1) {
			other->position.x = this->position.x - (thisRadius + otherRadius + 1);
		}

		this->sprite()->color = GREEN;

	}
	else {
		this->sprite()->color = BLUE;
	}
}
