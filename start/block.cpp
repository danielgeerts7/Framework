#include "Player.h"



Player::Player()
{
}

Player::~Player()
{
}

Player::PlayerCollidWithBlock(BasicEntity* objBlock, int blockHalfSize, int playerRadius)
{ 
	// ###############################################################
	// Player checks collision with block
	// ###############################################################
	int playerLeftRadius = this->position.x - playerRadius;
	int playerRightRadius = this->position.x + playerRadius;
	int playerTopRadius = this->position.y - playerRadius;
	int playerBottomRadius = this->position.y + playerRadius;


	int blockLeft = objBlock->position.x - blockHalfSize;
	int blockRight = objBlock->position.x + blockHalfSize;
	int blockTop = objBlock->position.y - blockHalfSize;
	int blockBottom = objBlock->position.y + blockHalfSize;


	//Checking player down
	if (playerRightRadius > blockLeft && playerLeftRadius < blockRight && playerBottomRadius > blockTop && playerTopRadius < blockBottom && this->position.y < objBlock->position.y) {
		this->position.y = objBlock->position.y - blockTop - playerBottomRadius;
	}
	/*
	//Checking player down
	if (playerRightRadius > blockLeft && playerLeftRadius < blockRight && playerBottomRadius > blockTop && playerTopRadius < blockBottom && this->position.y + playerBottomRadius + 0.5 < objBlock->position.y - blockTop - 0.5) {
	return 2;
	}*/


	//Checking player up
	if (playerRightRadius > blockLeft && playerLeftRadius < blockRight && playerBottomRadius > blockTop && playerTopRadius < blockBottom && this->position.y > objBlock->position.y) {
		this->position.y = objBlock->position.y + blockBottom + playerTopRadius;
	}
	/*
	//Checking player up
	if (playerRightRadius > blockLeft && playerLeftRadius < blockRight && playerBottomRadius > blockTop && playerTopRadius < blockBottom && this->position.y - playerTopRadius - 0.5 > objBlock->position.y + blockBottom + 0.5) {
	return 4;
	}
	*/


	//Checking player right
	if (playerRightRadius > blockLeft && playerLeftRadius < blockRight && playerBottomRadius > blockTop && playerTopRadius < blockBottom && this->position.x < objBlock->position.x) {
		this->position.x = objBlock->position.x + blockLeft + playerRightRadius;
	}
	/*
	//Checking player right
	if (playerRightRadius > blockLeft && playerLeftRadius < blockRight && playerBottomRadius > blockTop && playerTopRadius < blockBottom && this->position.x + playerRightRadius + 0.5 < objBlock->position.x - blockLeft - 0.5) {
	return 6;
	}
	*/

	//Checking player left
	if (playerRightRadius > blockLeft && playerLeftRadius < blockRight && playerBottomRadius > blockTop && playerTopRadius < blockBottom && this->position.x > objBlock->position.x) {
		this->position.x = objBlock->position.x - blockRight - playerLeftRadius;
	}
	/*
	//Checking player left
	if (playerRightRadius > blockLeft && playerLeftRadius < blockRight && playerBottomRadius > blockTop && playerTopRadius < blockBottom && this->position.x - playerLeftRadius - 0.5 > objBlock->position.x + blockRight + 0.5) {
	return 8;
	}
	*/
}