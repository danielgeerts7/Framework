#pragma once

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

