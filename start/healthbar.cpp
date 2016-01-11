/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "healthbar.h"


HealthBar::HealthBar() : BasicEntity()
{
	this->addSprite("assets/block.tga");
	this->scale = Point2(1, 0.1);
	this->sprite()->color = GREEN;
}

HealthBar::~HealthBar()
{
}
