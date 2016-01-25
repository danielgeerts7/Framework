/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "particlesystem.h"


ParticleSystem::ParticleSystem(RGBAColor color, string asset) : BasicEntity ()
{
	lifespan = 255;

	this->scale = Point2(rand() % 1 + 3, rand() % 1 + 3);
	this->addSprite(asset);
	this->sprite()->color = color;

	counter = 0;
	delay = 300;
}


ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::addParticleToParent(Bullet* fromBullet) {
	this->velocity_x = cos(fromBullet->rotation + rand() % 2 - 1) * 0;
	this->velocity_y = sin(fromBullet->rotation + rand() % 2 - 1) * 0;

	location = fromBullet->position;
	acceleration = Vector2(0, 0);
	velocity = Vector2(velocity_x, velocity_y);

	this->position.x = fromBullet->position.x;
	this->position.y = fromBullet->position.y;
	this->rotation = angle;
}

void ParticleSystem::update(float deltaTime)
{
	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
	location.x += velocity.x;
	location.y += velocity.y;

	if (counter > delay) {
		lifespan -= 2.5;
	} else {
		counter++;
	}

	this->position.x = location.x;
	this->position.y = location.y;

	isDead();
}

bool ParticleSystem::isDead() {
	if (lifespan <= 0) {
		lifespan = 0;
		return true;
	}
	else {
		this->sprite()->color.a = lifespan;
		return false;
	}

	if (((this->position.x < SWIDTH - SWIDTH) ||
		(this->position.x > SWIDTH) ||
		(this->position.y < SHEIGHT - SHEIGHT) ||
		(this->position.y > SHEIGHT))) {
		return true;
	}
}