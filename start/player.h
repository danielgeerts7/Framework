/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "basicentity.h"

class Player : public BasicEntity
{
public:
	Player();
	~Player();
	virtual void update(float deltaTime);

	void playerCollidWithBlock(BasicEntity* objplayer, BasicEntity* objBlock, int blockHalfSize, int playerRadius);
};

#endif /* PLAYER_H */
