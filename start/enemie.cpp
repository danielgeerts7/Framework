#include "enemie.h"



Enemie::Enemie() : BasicEntity ()
{
	this->addSprite("assets/player.tga");
	this->sprite()->color = MAGENTA;

	fieldOfView = 192;

	health = 100;
}


Enemie::~Enemie()
{
}

// ###############################################################
// All enemies rotation to the player_entity
// ###############################################################
void Enemie::checkForPlayerIfWalkingInFieldOfView(Player* p)
{
	radius = 32;

	if (p->position.x - radius < this->position.x + fieldOfView && p->position.x + radius > this->position.x - fieldOfView && p->position.y + radius > this->position.y - fieldOfView && p->position.y - radius < this->position.y + fieldOfView) {
		Point2 mousepos1 = Point2(p->position.x, p->position.y);
		Vector2 delta1 = Vector2(this->position, mousepos1);
		float angle1 = delta1.getAngle();
		this->rotation = angle1;
	} else {
		this->rotation = 0;
	}
}

int Enemie::getEnemieHealth()
{
	return health;
}

void Enemie::setEnemieHealth(int h)
{
	health = h;
}