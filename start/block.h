#pragma once

#include "Entity.h"
#include <demo/basicentity.h>

class Player : public Entity
{
public:
	Player();
	~Player();
	PlayerCollidWithBlock(BasicEntity* objBlock, int blockHalfSize, int playerRadius);
};

