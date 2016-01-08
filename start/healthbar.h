/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include "basicentity.h"
#include "player.h"
#include "enemie.h"

class HealthBar : public BasicEntity
{
public:
	HealthBar(BasicEntity* parent);
	HealthBar(Player* parent);
	HealthBar(Enemie* parent);
	virtual ~HealthBar();

	virtual void update(float deltaTime);

private:
	BasicEntity* b;
	Player* p;
	Enemie* e;

	bool boolBasicEntity;
	bool boolPlayer;
	bool boolEnemie;
};

#endif /*HEALTHBAR_H*/