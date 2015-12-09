#include "bullet.h"



Bullet::Bullet() : BasicEntity()
{
	this->addSprite("assets/bullet.tga");
	this->sprite()->color = ORANGE;
}


Bullet::~Bullet()
{
}

void Bullet::setPositionAndRotation(BasicEntity* parent)
{
	this->position = parent->position;
	this->rotation = parent->rotation;
	velocity_x = cos(this->rotation)*1;
	velocity_y = sin(this->rotation)*1;
	velocity = Vector2(velocity_x, velocity_y);
}

void Bullet::update(float deltaTime)
{
	this->position += velocity;
}
