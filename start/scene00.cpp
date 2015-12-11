/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
* - Copyright 2015 Rik Teerling <rik@onandoffables.com>
*     - Initial commit
* - Copyright 2015 Your Name <you@yourhost.com>
*     - What you did
*/

#include "scene00.h"

Scene00::Scene00() : SuperScene()
{
	// Start Timer t
	t.start();

	delay = 10;
	counter = 0;

	MaxAmmo = 25;
	MaxMags = 6;

	CurrentAmmo = MaxAmmo;
	CurrentMags = MaxMags;

	text[0]->message("Scene00: shoot the enemies before they shoot you!");

	background_entity = new LoadTiles();
	layers[0]->addChild(background_entity);
	//background_entity->LoadAndConvertTile;

	player_entity = new Player();
	player_entity->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	player_entity->addSprite("assets/player.tga");
	player_entity->sprite()->color = GREEN;

	for (int e = 0; e < 5; e++) {
		BasicEntity* enemie = new BasicEntity();
		enemie->addSprite("assets/player.tga");

		enemie->sprite()->color = MAGENTA;

		enemies.push_back(enemie);

		layers[2]->addChild(enemies[e]);

		
		BasicEntity* gun_enemie = new BasicEntity();
		gun_enemie->addSprite("assets/gun.tga");
		gun_enemie->sprite()->color = YELLOW;
		gun_enemie->position = Point2(30, 25);

		guns_enemies.push_back(gun_enemie);

		enemies[e]->addChild(gun_enemie);
	}
	
	enemies[0]->position = Point(100, 100);
	enemies[1]->position = Point(700, 600);
	enemies[2]->position = Point(750, 100);
	enemies[3]->position = Point(400, 400);
	enemies[4]->position = Point(200, 650);

	gun_player_entity = new BasicEntity();
	gun_player_entity->addSprite("assets/gun.tga");
	gun_player_entity->sprite()->color = YELLOW;
	gun_player_entity->position = Point2(30, 25);
	
	int amount = 10;

	for (int i = 0; i<amount; i++) {
		BasicEntity* b = new BasicEntity();
		b->addSprite("assets/block.tga");

		b->sprite()->color = BLUE;
		b->position.x = 250;
		b->position.y = rand() % 300 + 150;
		blocks.push_back(b);

		layers[2]->addChild(blocks[i]);
	}

	layers[2]->addChild(player_entity);
	player_entity->addChild(gun_player_entity);
}


Scene00::~Scene00()
{

	int s = blocks.size();
	for (int i = 0; i<s; i++) {
		layers[2]->removeChild(blocks[i]);
		delete blocks[i];
	}
	blocks.clear();

	int p_b = player_bullets.size();
	for (int j = 0; j<p_b; j++) {
		layers[1]->removeChild(player_bullets[j]);
		delete player_bullets[j];
	}
	player_bullets.clear();

	int es = enemies.size();
	for (int k = 0; k < es; k++) {
		enemies[k]->removeChild(guns_enemies[k]);
		layers[1]->removeChild(enemies[k]);
		delete guns_enemies[k];
		delete enemies[k];
	}
	enemies.clear();

	layers[2]->removeChild(player_entity);
	player_entity->removeChild(gun_player_entity);
	

	layers[0]->removeChild(background_entity);
	delete background_entity;
	delete player_entity;
	delete gun_player_entity;
}

void Scene00::update(float deltaTime)
{
	// ###############################################################
	// Make SuperScene do what it needs to do (Escape key stops Scene)
	// ###############################################################
	SuperScene::update(deltaTime);

	Vector2 playerRight = Vector2(1, 0);
	Vector2 playerUp = Vector2(0, 1);

	// ###############################################################
	// Move player_entity to and from the mouse
	// ###############################################################
	float speed = 150.0f; // 150 units / second

	// Move up
	if (input()->getKey(GLFW_KEY_W)) {
		player_entity->position -= playerUp * deltaTime * speed;
	}
	// Move down
	if (input()->getKey(GLFW_KEY_S)) {
		player_entity->position += playerUp * deltaTime * speed;
	}
	// move left
	if (input()->getKey(GLFW_KEY_A)) {
		player_entity->position -= playerRight * deltaTime * speed;
	}
	// move right
	if (input()->getKey(GLFW_KEY_D)) {
		player_entity->position += playerRight * deltaTime * speed;
	}

	//camera()->position.x = player_entity->position.x;
	//camera()->position.y = player_entity->position.y;

	// ###############################################################
	// Rotate player_entity to the position of the mouse
	// ###############################################################
	Point2 mousepos = Point2(input()->getMouseX(), input()->getMouseY());
	Vector2 delta = Vector2(player_entity->position, mousepos);
	float angle = delta.getAngle();
	player_entity->rotation = angle;
	

	for (int a = 0; a < enemies.size(); a++) {
		Point2 mousepos1 = Point2(player_entity->position.x, player_entity->position.y);
		Vector2 delta1 = Vector2(enemies[a]->position, mousepos1);
		float angle1 = delta1.getAngle();
		enemies[a]->rotation = angle1;
	}

	for (int i = 0; i < blocks.size(); i++) {
		player_entity->playerCollidWithBlock(player_entity, blocks[i], 32, 27);
	}
	
	counter += 0.5;

	if (counter >= delay) {
		counter = delay;
	}
	
	if (input()->getMouse(GLFW_MOUSE_BUTTON_1) && counter >= delay) {
		Bullet* b = new Bullet();
		b->setPositionAndRotation(player_entity);
		layers[1]->addChild(b);
		player_bullets.push_back(b);

		counter = 0;
		CurrentAmmo--;
	}

	std::string AmmoLeftToUseText = "Ammo: ";
	AmmoLeftToUseText.append(std::to_string(CurrentAmmo));
	AmmoLeftToUseText.append("/");
	AmmoLeftToUseText.append(std::to_string(CurrentMags));
	text[4]->message(AmmoLeftToUseText);

	std::string playerHealthToText = "Health: ";
	playerHealthToText.append(std::to_string(player_entity->getCurrentHealth()));
	playerHealthToText.append("/");
	playerHealthToText.append(std::to_string(player_entity->getMaxHealth()));
	text[5]->message(playerHealthToText);

	int playerRaduis = 24;

	if (player_entity->position.x < 0 + playerRaduis) {
		player_entity->position.x = 0 + playerRaduis;
	}
	if (player_entity->position.x > 800 - playerRaduis) {
		player_entity->position.x = 800 - playerRaduis;
	}
	if (player_entity->position.y < 0 + playerRaduis) {
		player_entity->position.y = 0 + playerRaduis;
	}
	if (player_entity->position.y > 720 - playerRaduis) {
		player_entity->position.y = 720 - playerRaduis;
	}
}
