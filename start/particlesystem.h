/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "basicentity.h"
#include "bullet.h"
#include "enemie.h"
#include <rt2d/sprite.h>

using namespace std;
class ParticleSystem : public BasicEntity
{
public:
	ParticleSystem(RGBAColor color, string asset, int spriteType, int spriteNumber);
	~ParticleSystem();

	float speed;
	float lifespan;

	float velocity_x;
	float velocity_y;

	Vector2 acceleration;
	Vector2 velocity;

	Vector2 location;

	virtual void update(float deltaTime);

	void addParticleToParentBullet(Bullet* fromBullet);
	void addParticleToParentEnemie(Enemie* fromEnemie);
	bool isDead();

private:
	int maxParticles;
	int counter;
	int delay;

// 0 = nothing, 1 = Bullet, 2 = Enemie
	int whichParticle;

	int type;
};

#endif /* PARTICLESYSTEM_H */
