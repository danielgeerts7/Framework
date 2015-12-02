#pragma once

#include "Entity.h"
#include "basicentity.h"

class Player
{
public:
	Player();
	~Player();
	virtual void update(float deltaTime);

	void playerCollidWithBlock(BasicEntity* objPlayer, BasicEntity* objBlock, int blockHalfSize, int playerRadius);
};

