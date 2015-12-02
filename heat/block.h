#pragma once

#include "Entity.h"
#include "basicentity.h"

class Player : public Entity
{
public:
	Player();
	~Player();
	void PlayerCollidWithBlock(BasicEntity* objBlock, int blockHalfSize, int playerRadius);
};

