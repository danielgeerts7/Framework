/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef ENEMIE_H
#define ENEMIE_H

#include "basicentity.h"
#include "player.h"

class Enemie : public BasicEntity
{
public:
	Enemie();
	~Enemie();

	void checkForPlayerIfWalkingInFieldOfView(Player* p);

private:
	int fieldOfView;

	int radius;
};

#endif /* ENEMIE_H */