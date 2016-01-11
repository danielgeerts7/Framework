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
	}
}

void Player::playerCollidWithBlock(BasicEntity* objplayer, BasicEntity* objBlock, int blockHalfSize, int playerRadius)
{
	/*
	// ###############################################################
	// player checks collision with block
	// ###############################################################
	int playerLeftRadius = objplayer->position.x - playerRadius;
	int playerRightRadius = objplayer->position.x + playerRadius;
	int playerTopRadius = objplayer->position.y - playerRadius;
	int playerBottomRadius = objplayer->position.y + playerRadius;


	int blockLeft = objBlock->position.x - blockHalfSize;
	int blockRight = objBlock->position.x + blockHalfSize;
	int blockTop = objBlock->position.y - blockHalfSize;
	int blockBottom = objBlock->position.y + blockHalfSize;

	int i = 0;

	if (playerRightRadius > blockLeft && playerLeftRadius < blockRight && playerBottomRadius > blockTop && playerTopRadius < blockBottom) {
		//Checking player top, and block bottom
		if (objplayer->position.y + playerRadius -1 <= objBlock->position.y - blockHalfSize) {
			objplayer->position.y = objBlock->position.y - (blockHalfSize + playerRadius);
		}
		//Checking player bottom, and block top
		if (objplayer->position.y - playerRadius +1 >= objBlock->position.y + blockHalfSize) {
			objplayer->position.y = objBlock->position.y + (blockHalfSize + playerRadius);
		}
		//Checking player right, and block left
		if (objplayer->position.x + playerRadius -1 <= objBlock->position.x - blockHalfSize) {
			objplayer->position.x = objBlock->position.x - (blockHalfSize + playerRadius);
		}
		//Checking player left, and block right
		if  (objplayer->position.x - playerRadius +1 >= objBlock->position.x + blockHalfSize) {
			objplayer->position.x = objBlock->position.x + (blockHalfSize + playerRadius);
		}

		objBlock->sprite()->color = GREEN;
	}
	*/
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
void Player::setPlayerHealth(int h)
{
	this->health = h;
}

// ###############################################################
// Enemie bullets hit the player
// ###############################################################
int Player::gettingHitByEnemieBullets(BasicEntity* b)
{
	int radius = 24;
	if (b->position.x > this->position.x - radius &&
		b->position.x < this->position.x + radius &&
		b->position.y > this->position.y - radius &&
		b->position.y < this->position.y + radius) {
		this->health--;
		return 1;
	}
	else {
		return 0;
	}
}
