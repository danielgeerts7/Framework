/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "player.h"


Player::Player() : BasicEntity()
{
	// ###############################################################
	// Setting the variables
	// ###############################################################
	this->addSprite("assets/player.tga");
	this->sprite()->color = GREEN;

	this->health = 100;
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
	if (this->health <= 0) {
		this->health = 0;
		this->sprite()->color = RED;
		this->alive = false;
	}
}

// ###############################################################
// Get player health
// ###############################################################
int Player::getPlayerHealth()
{
	return this->health;
}

// ###############################################################
// Set player health
// ###############################################################
void Player::addHealth(int h)
{
	this->health = this->health + h;
}

// ###############################################################
// Player pickup a item
// ###############################################################
bool Player::player_pickup_item(Pickup* p)
{
	int radius_player = 26;
	int raduis_pickup = 16;
	if (this->position.x + radius_player > p->position.x - raduis_pickup && 
		this->position.x - radius_player < p->position.x + raduis_pickup &&
		this->position.y + radius_player > p->position.y - raduis_pickup &&
		this->position.y - radius_player < p->position.y + raduis_pickup ) {
		return 1;
	}
	else {
		return 0;
	}
}

// ###############################################################
// Enemie bullets hit the player
// ###############################################################
int Player::gettingHitByEnemieBullets(BasicEntity* b)
{
	if (this->alive == true) {
		int radius = 24;
		if (b->position.x > this->position.x - radius &&
			b->position.x < this->position.x + radius &&
			b->position.y > this->position.y - radius &&
			b->position.y < this->position.y + radius) {
			this->health -= 5;
			return 1;
		}
	}
	else {
		return 0;
	}
}
