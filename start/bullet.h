/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef BULLET_H
#define BULLET_H

#include "basicentity.h"
#include <rt2d/scene.h>
#include <vector>
#include <rt2d/input.h>
#include <rt2d/scene.h>

static class Bullet : public BasicEntity
{
public:
	Bullet();
	~Bullet();
	void setPositionAndRotation(BasicEntity* parent);

private:
	float velocity_x;
	float velocity_y;
	Vector2 velocity;

	virtual void update(float deltaTime);
};
#endif /* BULLET_H */
