/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "particlesystem.h"


ParticleSystem::ParticleSystem() : BasicEntity ()
{
	speed = 1;
	lifespan = 255;

	this->addSprite("assets/singleparticle.tga");
	this->sprite()->color = RED;
}


ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::addParticleToParent(BasicEntity* toParent, BasicEntity* fromBullet) {
	this->velocity_x = cos(fromBullet->rotation + rand() % 2 - 1) * .5;
	this->velocity_y = sin(fromBullet->rotation + rand() % 2 - 1) * .5;

	location = fromBullet->position;
	acceleration = Vector2(0,0);
	velocity = Vector2(velocity_x , velocity_y );

	this->position.x = fromBullet->position.x;
	this->position.y = fromBullet->position.y;
	this->rotation = angle;

	for (int a = 0; a < maxParticles; a++) {
		
	}
}

void ParticleSystem::update(float deltaTime)
{
	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
	location.x += velocity.x;
	location.y += velocity.y;
	lifespan -= 1;

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