/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "healthbar.h"


HealthBar::HealthBar(BasicEntity* parent) : BasicEntity()
{
	this->b = parent;
	this->addSprite("assets/healthbar.tga");
	this->scale = Point2(2, 0.2);
	this->boolBasicEntity = true;
	this->boolPlayer = false;
	this->boolEnemie = false;
}

HealthBar::HealthBar(Player* parent) : BasicEntity()
{
	this->p = parent;
	this->addSprite("assets/healthbar.tga");
	this->scale = Point2(2, 0.2);
	this->boolBasicEntity = false;
	this->boolPlayer = true;
	this->boolEnemie = false;
}

HealthBar::HealthBar(Enemie* parent) : BasicEntity()
{
	this->e = parent;
	this->addSprite("assets/healthbar.tga");
	this->scale = Point2(2, 0.2);
	this->boolBasicEntity = false;
	this->boolPlayer = false;
	this->boolEnemie = true;
}


HealthBar::~HealthBar()
{
}

void HealthBar::update(float deltaTime)
{
	if (!(this->b == NULL) && boolBasicEntity) {
		this->position.x = b->position.x;
		this->position.y = b->position.y - 75;
	}
	if (!(this->p == NULL) && boolPlayer) {
		this->position.x = p->position.x;
		this->position.y = p->position.y - 75;
	}
	if (!(this->e == NULL) && boolEnemie) {
		this->position.x = e->position.x;
		this->position.y = e->position.y - 75;
	}
}
