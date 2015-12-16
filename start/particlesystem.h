/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "basicentity.h"
#include <rt2d\sprite.h>

class ParticleSystem : public BasicEntity
{
public:
	ParticleSystem();
	~ParticleSystem();

	int speed;
	float lifespan;

	Vector2 acceleration;
	Vector2 velocity;

	Vector2 location;

	virtual void update(float deltaTime);

	void addParticleToParent(Vector2 parent);

private:
	int maxParticles;
};

#endif /* PARTICLESYSTEM_H */
