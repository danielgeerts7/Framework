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
	location = toParent->position;
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);

	this->position.x = toParent->position.x;
	this->position.y = toParent->position.y;
	this->rotation = toParent->rotation;

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
	
	if (lifespan <= 0) {
		lifespan = 0;
	} else {
		this->sprite()->color.a = lifespan;
	}
}