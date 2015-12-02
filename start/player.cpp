#include "Player.h"


Player::Player()
{
}

Player::~Player()
{
}

void Player::update(float deltaTime)
{
}

void Player::playerCollidWithBlock(BasicEntity* objPlayer, BasicEntity* objBlock, int blockHalfSize, int playerRadius)
{
	/*
	// ###############################################################
	// Player checks collision with block
	// ###############################################################
	int playerLeftRadius = objPlayer->position.x - playerRadius;
	int playerRightRadius = objPlayer->position.x + playerRadius;
	int playerTopRadius = objPlayer->position.y - playerRadius;
	int playerBottomRadius = objPlayer->position.y + playerRadius;


	int blockLeft = objBlock->position.x - blockHalfSize;
	int blockRight = objBlock->position.x + blockHalfSize;
	int blockTop = objBlock->position.y - blockHalfSize;
	int blockBottom = objBlock->position.y + blockHalfSize;

	int i = 0;

	if (playerRightRadius > blockLeft && playerLeftRadius < blockRight && playerBottomRadius > blockTop && playerTopRadius < blockBottom) {
		//Checking player top, and block bottom
		if (objPlayer->position.y + playerRadius -1 <= objBlock->position.y - blockHalfSize) {
			objPlayer->position.y = objBlock->position.y - (blockHalfSize + playerRadius);
		}
		//Checking player bottom, and block top
		if (objPlayer->position.y - playerRadius +1 >= objBlock->position.y + blockHalfSize) {
			objPlayer->position.y = objBlock->position.y + (blockHalfSize + playerRadius);
		}
		//Checking player right, and block left
		if (objPlayer->position.x + playerRadius -1 <= objBlock->position.x - blockHalfSize) {
			objPlayer->position.x = objBlock->position.x - (blockHalfSize + playerRadius);
		}
		//Checking player left, and block right
		if  (objPlayer->position.x - playerRadius +1 >= objBlock->position.x + blockHalfSize) {
			objPlayer->position.x = objBlock->position.x + (blockHalfSize + playerRadius);
		}

		objBlock->sprite()->color = GREEN;
	}
	*/
}