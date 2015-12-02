#pragma once

#include "basicentity.h"
#include <rt2d/scene.h>
#include <vector>

class Bullet : public BasicEntity
{
public:
	Bullet(BasicEntity* user, std::vector<BasicEntity*> bullets);
	~Bullet();
};

