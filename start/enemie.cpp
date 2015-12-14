#include "enemie.h"



Enemie::Enemie() : BasicEntity ()
{
	this->addSprite("assets/player.tga");
	this->sprite()->color = MAGENTA;
}


Enemie::~Enemie()
{
}
