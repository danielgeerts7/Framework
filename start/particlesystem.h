/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "basicentity.h"
#include "bullet.h"
#include <rt2d/sprite.h>

using namespace std;
class ParticleSystem : public BasicEntity
{
public:
	ParticleSystem(RGBAColor color, string asset);
	~ParticleSystem();

	int speed;
	float lifespan;
	float angle;

	float velocity_x;
	float velocity_y;

	Vector2 acceleration;
	Vector2 velocity;

	Vector2 location;

	virtual void update(float deltaTime);

	void addParticleToParent(Bullet* fromBullet);
	bool isDead();

private:
	int maxParticles;
	int counter;
	int delay;
};

#endif /* PARTICLESYSTEM_H */
