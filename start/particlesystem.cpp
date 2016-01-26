/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "particlesystem.h"


ParticleSystem::ParticleSystem(RGBAColor color, string asset, int spriteType, int spriteNumber) : BasicEntity ()
{
	lifespan = 255;
	type = spriteType;

	if (type == 0) {
		this->addSprite(asset);
		this->sprite()->color = color;

		counter = 0;
		delay = 600;
	} else if (type == 1) {
		this->addSprite(asset);
		this->sprite()->color = color;

		counter = 0;
		delay = 700;
	} else if (type == 2) {
		this->addSpriteSheet(asset, 1, 4);
		this->sprite()->color = color;
		float x = 0.25;
		float y = 1;
		this->sprite()->uvdim = Point2(x, y);
		this->sprite()->frame(spriteNumber);
		counter = 0;
		delay = 200;
	}
}


ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::addParticleToParentBullet(Bullet* fromBullet) {
	int scale = rand() % 1 + 3;
	this->scale = Point2(scale, scale);

	this->velocity_x = cos(fromBullet->rotation + rand() % 2 - 1) * 0;
	this->velocity_y = sin(fromBullet->rotation + rand() % 2 - 1) * 0;

	location = fromBullet->position;
	acceleration = Vector2(0, 0);
	velocity = Vector2(velocity_x, velocity_y);

	this->position.x = fromBullet->position.x;
	this->position.y = fromBullet->position.y;
	this->rotation = rand() % 360 / DEG_TO_RAD;

	whichParticle = 1;
}

void ParticleSystem::addParticleToParentEnemie(Enemie* fromEnemie) {
	this->scale = Point2(1, 1);
	this->velocity_x = cos(rand() % 360 / DEG_TO_RAD) * 0.2;
	this->velocity_y = sin(rand() % 360 / DEG_TO_RAD) * 0.2;

	location = fromEnemie->position;
	acceleration = Vector2(0, 0);
	velocity = Vector2(velocity_x, velocity_y);

	this->position.x = fromEnemie->position.x;
	this->position.y = fromEnemie->position.y;
	this->rotation = rand() % 360 / DEG_TO_RAD;
	whichParticle = 2;
}

void ParticleSystem::update(float deltaTime)
{
	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
	location.x += velocity.x;
	location.y += velocity.y;

	this->position.x = location.x;
	this->position.y = location.y;

	isDead();

	if (whichParticle == 1) {
		if (counter > delay) {
			lifespan -= 0.5;
		}
		else {
			counter++;
		}
	} else if (whichParticle == 2) {
		if (type == 1) {
			this->rotation += 0.02;
			if (counter > delay) {
				lifespan -= 0.5;
			}
			else {
				counter++;
			}
		} else if (type == 2) {
			this->rotation += 0.03;
			if (counter > delay) {
				lifespan -=	0.75;
			}
			else {
				counter++;
			}
		}
	}
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