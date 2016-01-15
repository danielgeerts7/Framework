/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "basicentity.h"
#include "pickup.h"

class Player : public BasicEntity
{
public:
	Player();
	~Player();
	virtual void update(float deltaTime);

	void playerCollidWithBlock(BasicEntity* objplayer, BasicEntity* objBlock, int blockHalfSize, int playerRadius);
	
	int getPlayerHealth();
	void addHealth(int h);

	int gettingHitByEnemieBullets(BasicEntity* b);

	bool player_pickup_item(Pickup* item);

private:
	int health;
};

#endif /* PLAYER_H */
