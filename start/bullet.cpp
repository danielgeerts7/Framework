/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "bullet.h"


Bullet::Bullet() : BasicEntity()
{
	// ###############################################################
	// Setting the bullet's sprite and color
	// ###############################################################
	this->addSprite("assets/bullet.tga");
	this->sprite()->color = ORANGE;
}


Bullet::~Bullet()
{
}

void Bullet::setPositionAndRotation(BasicEntity* parent)
{
	// ###############################################################
	// This position is equals the 'parent' position
	// Calculate with Vector2 with rotation of the bullet, that direction go's into 'velocity'
	// ###############################################################
	this->position = parent->position;
	this->rotation = parent->rotation;
	velocity_x = cos(this->rotation)*1;
	velocity_y = sin(this->rotation)*1;
	velocity = Vector2(velocity_x, velocity_y);
}

void Bullet::update(float deltaTime)
{
	// ###############################################################
	// Update this position with the velocity, so the bullet always moves 'forward' from his rotation
	// ###############################################################
	this->position += velocity;
}
