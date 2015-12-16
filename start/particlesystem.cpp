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


	BasicEntity* b = new BasicEntity();
	b->addSprite("assets/singleparticle.tga");
	maxParticles = 15;
}


ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::addParticleToParent(Vector2 parent) {
	location = parent;
	acceleration = Vector2(0, 0);
	velocity = Vector2(0, 0);

	this->position.x = parent.x;
	this->position.y = parent.y;
	this->rotation = parent.getAngleDeg();

	for (int a = 0; a < maxParticles; a++) {
		
	}
}

void ParticleSystem::update(float deltaTime)
{
	velocity.cross(acceleration);
	location.cross(velocity);
	lifespan -= 2.0;
}