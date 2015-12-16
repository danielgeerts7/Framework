#include "enemie.h"



Enemie::Enemie() : BasicEntity ()
{
	this->addSprite("assets/player.tga");
	this->sprite()->color = PINK;

	this->fieldOfView = 192;
	this->health = 100;
	this->checkIfPlayerIsInFieldOfView = false;
}


Enemie::~Enemie()
{
}

void Enemie::update(float deltatime) {
	if (this->health <= 0) {
		this->health = 0;
		this->sprite()->color = RED;
	}
}

// ###############################################################
// All enemies rotation to the player_entity
// ###############################################################
void Enemie::checkForPlayerIfWalkingInFieldOfView(Player* p)
{
	this->radius = 32;

	if (p->position.x - radius < this->position.x + fieldOfView && p->position.x + radius > this->position.x - fieldOfView && p->position.y + radius > this->position.y - fieldOfView && p->position.y - radius < this->position.y + fieldOfView) {
		Point2 mousepos1 = Point2(p->position.x, p->position.y);
		Vector2 delta1 = Vector2(this->position, mousepos1);
		float angle1 = delta1.getAngle();
		this->rotation = angle1;

		this->checkIfPlayerIsInFieldOfView = true;
	} else {
		this->rotation = 0;
		this->checkIfPlayerIsInFieldOfView = false;
	}
}

// ###############################################################
// Get enemie health
// ###############################################################
int Enemie::getEnemieHealth()
{
	int h = health;
	return h;
}

// ###############################################################
// Set enemie health
// ###############################################################
void Enemie::setEnemieHealth(int h)
{
	this->health = h;
}

int Enemie::gettingHitByPlayerBullets(BasicEntity* b)
{
	int i = 0;
	int radius = 26;
	if (b->position.x > this->position.x - radius &&
		b->position.x < this->position.x + radius &&
		b->position.y > this->position.y - radius &&
		b->position.y < this->position.y + radius) {
		this->health -= 5;
		i = 1;
	} else {
		i = 0;
	}
	return i;
}