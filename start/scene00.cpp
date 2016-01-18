/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "scene00.h"

Scene00::Scene00() : SuperScene()
{

	SuperScene::setState(START);

	// ###############################################################
	// Setting the variables
	// ###############################################################

	// Start Timer t
	t.start();

	mouseClickBulletDelay = 10;
	mouseClickBulletCounter = 0;

	playerReloadDelay = 100;
	playerReloadCounter = 0;

	enemieDelay = 10;
	enemieCounter = 0;

	countEnemiesDied = 0;

	score = 10;
	currentscore = 0;

	firstLetter = "a";
	secondLetter = "a";
	thirdLetter = "a";
	username = firstLetter + secondLetter + thirdLetter;
	username.resize(3);

	triggerWhenFinished = true;

	arrow = new BasicEntity();
	arrow->addSprite("assets/block.tga");
	arrow->scale = Point2(0.5, 0.5);

	enterUsername = new Text();
	enterUsername->position = Point2(0, 0);

	pressedReloadingForThePlayer = false;
	playerCanShoot = false;

	playerRaduis = 24;

	maxAmmoInMagazine = 32;
	currentAmmoInMagazine = maxAmmoInMagazine;

	currentAmmoInBag = maxAmmoInMagazine * 2;

	text[0]->message("Scene00: shoot the enemies before they shoot you!");

	background_entity = new LoadTiles();
	layers[0]->addChild(background_entity);

	player_entity = new Player();
	// cell 12 ; row 12
	player_entity->position = Point2(posTile(12), posTile(12));

	player_healthbar = new HealthBar();
	player_healthbar->position.x = player_entity->position.x;
	player_healthbar->position.y = player_entity->position.y - 60;
	
	player_health_text = new Text();
	player_health_text->scale = Point2(0.4, 0.4);
	layers[3]->addChild(player_health_text);

	for (int e = 0; e < 8; e++) {
		Enemie* enemie = new Enemie();
		enemies.push_back(enemie);

		layers[2]->addChild(enemies[e]);

		BasicEntity* gun_enemie = new BasicEntity();
		gun_enemie->addSprite("assets/gun.tga");
		gun_enemie->sprite()->color = YELLOW;
		gun_enemie->position = Point2(30, 25);

		guns_enemies.push_back(gun_enemie);
		enemies[e]->addChild(gun_enemie);

		HealthBar* healthbar_enemie = new HealthBar();
		healthbar_enemie->position.x = enemies[e]->position.x;
		healthbar_enemie->position.y = enemies[e]->position.y - 60;

		enemies_healthbars.push_back(healthbar_enemie);
		layers[2]->addChild(healthbar_enemie);
	}
	
	// cell 3,5,7 ; row 3
	enemies[0]->position = Point(posTile(3), posTile(3));
	enemies[1]->position = Point(posTile(5), posTile(3));
	enemies[2]->position = Point(posTile(7), posTile(3));
	// cell 3,7 ; row 5
	enemies[3]->position = Point(posTile(3), posTile(5));
	enemies[4]->position = Point(posTile(7), posTile(5));
	// cell 3,57 ; row 7
	enemies[5]->position = Point(posTile(3), posTile(7));
	enemies[6]->position = Point(posTile(5), posTile(7));
	enemies[7]->position = Point(posTile(7), posTile(7));

	gun_player_entity = new BasicEntity();
	gun_player_entity->addSprite("assets/gun.tga");
	gun_player_entity->sprite()->color = YELLOW;
	gun_player_entity->position = Point2(30, 25);
	
	// ammunition pickup
	int ammunition_pickup_amount = 3;
	for (int i = 0; i < ammunition_pickup_amount; i++) {
		Pickup* ammo = new Pickup("ammo");

		ammunitionpickups.push_back(ammo);
		layers[2]->addChild(ammunitionpickups[i]);
	}

	// cell 21 ; row 5,8,11
	ammunitionpickups[0]->position = Point2(posTile(21), posTile(5));
	ammunitionpickups[1]->position = Point2(posTile(21), posTile(8));
	ammunitionpickups[2]->position = Point2(posTile(21), posTile(11));

	// health pickup
	int health_pickup_amount = 2;
	for (int i = 0; i < health_pickup_amount; i++) {
		Pickup* health = new Pickup("health");

		healthpickups.push_back(health);
		layers[2]->addChild(healthpickups[i]);
	}
	//cell 19,23 ; row 8
	healthpickups[0]->position = Point2(posTile(19), posTile(8));
	healthpickups[1]->position = Point2(posTile(23), posTile(8));

	int amount = 17;

	for (int i = 0; i < amount; i++) {
		Block* b = new Block();
		blocks.push_back(b);

		layers[2]->addChild(blocks[i]);
	}
	// cell 10,11,13,14 ; row 9
	blocks[0]->position = Point2(posTile(10), posTile(9));
	blocks[1]->position = Point2(posTile(11), posTile(9));
	blocks[2]->position = Point2(posTile(13), posTile(9));
	blocks[3]->position = Point2(posTile(14), posTile(9));
	// cell 9,15 ; row 10
	blocks[4]->position = Point2(posTile(9), posTile(10));
	blocks[5]->position = Point2(posTile(15), posTile(10));
	// cell 8,16 ; row 11
	blocks[6]->position = Point2(posTile(8), posTile(11));
	blocks[7]->position = Point2(posTile(16), posTile(11));
	// cell 8,16 ; row 12
	blocks[8]->position = Point2(posTile(8), posTile(12));
	blocks[9]->position = Point2(posTile(16), posTile(12));
	// cell 9,15; row 13
	blocks[10]->position = Point2(posTile(9), posTile(13));
	blocks[11]->position = Point2(posTile(15), posTile(13));
	// cell 10,11,12,13,14 ; row 14
	blocks[12]->position = Point2(posTile(10), posTile(14));
	blocks[13]->position = Point2(posTile(11), posTile(14));
	blocks[14]->position = Point2(posTile(12), posTile(14));
	blocks[15]->position = Point2(posTile(13), posTile(14));
	blocks[16]->position = Point2(posTile(14), posTile(14));

	layers[2]->addChild(player_entity);
	layers[2]->addChild(player_healthbar);
	player_entity->addChild(gun_player_entity);
}


Scene00::~Scene00()
{
	int s = blocks.size();
	for (int i = 0; i<s; i++) {
		layers[2]->removeChild(blocks[i]);
		delete blocks[i];
		blocks[i] = NULL;
	}
	blocks.clear();

	int p_b = player_bullets.size();
	for (int j = 0; j<p_b; j++) {
		layers[1]->removeChild(player_bullets[j]);
		delete player_bullets[j];
		player_bullets[j] = NULL;
	}
	player_bullets.clear();

	int e_b = enemies_bullets.size();
	for (int l = 0; l<e_b; l++) {
		layers[1]->removeChild(enemies_bullets[l]);
		delete enemies_bullets[l];
		enemies_bullets[l] = NULL;
	}
	enemies_bullets.clear();

	int es = enemies.size();
	for (int k = 0; k < es; k++) {
		enemies[k]->removeChild(guns_enemies[k]);
		layers[2]->removeChild(enemies[k]);
		layers[2]->removeChild(enemies_healthbars[k]);
		delete guns_enemies[k];
		delete enemies[k];
		delete enemies_healthbars[k];
		guns_enemies[k] = NULL;
		enemies[k] = NULL;
		enemies_healthbars[k] = NULL;
	}
	enemies.clear();
	guns_enemies.clear();
	enemies_healthbars.clear();

	int pp = particles.size();
	for (int a = 0; a < pp; a++) {
		layers[3]->removeChild(particles[a]);
		delete particles[a];
		particles[a] = NULL;
	}
	particles.clear();

	// remove ammo pickups
	int ammopickupsize = ammunitionpickups.size();
	for (int i = 0; i < ammopickupsize; i++) {
		layers[2]->removeChild(ammunitionpickups[i]);
		delete ammunitionpickups[i];
		ammunitionpickups[i] = NULL;
	}
	ammunitionpickups.clear();

	// remove health pickups
	int healthpickupsize = healthpickups.size();
	for (int i = 0; i < healthpickupsize; i++) {
		layers[2]->removeChild(healthpickups[i]);
		delete healthpickups[i];
		healthpickups[i] = NULL;
	}
	healthpickups.clear();

	layers[0]->removeChild(background_entity);
	layers[2]->removeChild(player_entity);
	layers[2]->removeChild(player_healthbar);
	player_entity->removeChild(gun_player_entity);
	layers[3]->removeChild(player_health_text);
	delete background_entity;
	delete player_entity;
	delete player_healthbar;
	delete gun_player_entity;
	delete player_health_text;
	background_entity = NULL;
	player_entity = NULL;
	player_healthbar = NULL;
	gun_player_entity = NULL;
	player_health_text = NULL;
}

void Scene00::update(float deltaTime)
{
	// ###############################################################
	// Make SuperScene do what it needs to do (Escape key stops Scene)
	// ###############################################################
	SuperScene::update(deltaTime);

	// ###############################################################
	// Moving the player_entity
	// ###############################################################
	float speed = 150.0f; // 150 units / second

	Vector2 playerRight = Vector2(1, 0);
	Vector2 playerUp = Vector2(0, 1);

	if (player_entity->alive) {
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
	}

	// ###############################################################
	// Camera follow the player_entity
	// ###############################################################
	//camera()->position.x = player_entity->position.x;
	//camera()->position.y = player_entity->position.y;

	// ###############################################################
	// Rotate player_entity to the position of the mouse
	// ###############################################################
	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mousepos = Point2(mousex, mousey);
	Vector2 delta = Vector2(player_entity->position, mousepos);
	float angle = delta.getAngle();
	player_entity->rotation = angle;

	// ###############################################################
	// Updating the enemieCounter and checking if the enemieCounter is greater then the enemieDelay
	// ###############################################################
	enemieCounter += 0.5;
	if (enemieCounter >= enemieDelay) {
		enemieCounter = enemieDelay;
	}

	// ###############################################################
	// Giving the new Bullet(s)* b the rotation of the enemies[a]
	// ###############################################################
	int enemiesSize = enemies.size();
	for (int a = 0; a < enemiesSize; a++) {
		if (enemies[a]->alive && player_entity->alive) {
			enemies[a]->checkForPlayerIfWalkingInFieldOfView(player_entity);
			if (enemies[a]->checkIfPlayerIsInFieldOfView && enemieCounter >= enemieDelay) {
				Bullet* b = new Bullet();
				b->setPositionAndRotation(enemies[a]);
				layers[1]->addChild(b);
				enemies_bullets.push_back(b);

				enemieCounter = 0;
			}
		}
	}
	enemiesSize = NULL;

	// ###############################################################
	// Player gets hit by the enemies bullets
	// ###############################################################
	vector<Bullet*>::iterator toremoveEB = enemies_bullets.begin();
	if (player_entity->alive) {
		while (toremoveEB != enemies_bullets.end()) {
			if (player_entity->gettingHitByEnemieBullets((*toremoveEB)) == 1 && player_entity->getPlayerHealth() > 0 && (*toremoveEB) > 0) {
				layers[1]->removeChild((*toremoveEB));
				delete (*toremoveEB);
				toremoveEB = enemies_bullets.erase(toremoveEB);
			}
			else {
				++toremoveEB;
			}
		}
	}

	// ###############################################################
	// Check which Enemy gets hit by the player bullets
	// ###############################################################
	int player_bullets_size = player_bullets.size();
	for (int pb = 0; pb < player_bullets_size; pb++) {
		for (int ee = 0; ee < enemies.size(); ee++) {
			if (enemies[ee]->gettingHitByPlayerBullets(player_bullets[pb]) == 1 && enemies[ee]->alive && player_entity->alive && player_bullets.size() >= 0) {
				player_bullets[pb]->alive = false;

				p = new ParticleSystem();
				p->addParticleToParent(enemies[ee], player_bullets[pb]);
				layers[3]->addChild(p);
				particles.push_back(p);
			}
		}
	}
	player_bullets_size = NULL;

	// ###############################################################
	// Remove all bullets that hit a Enemie
	// ###############################################################
	vector<Bullet*>::iterator toremovePB = player_bullets.begin();
	while (toremovePB != player_bullets.end()) {
		if (!(*toremovePB)->alive) {
			layers[1]->removeChild((*toremovePB));
			delete (*toremovePB);
			toremovePB = player_bullets.erase(toremovePB);
		}
		else {
			++toremovePB;
		}
	}

	// ###############################################################
	// Deleting particles when isDead() is true
	// ###############################################################
	vector<ParticleSystem*>::iterator toremovePart = particles.begin();
	while (toremovePart != particles.end()) {
		if ((*toremovePart)->isDead()) {
			layers[3]->removeChild((*toremovePart));
			delete (*toremovePart);
			toremovePart = particles.erase(toremovePart);
		}
		else {
			++toremovePart;
		}
	}
	string pp = "particles: ";
	pp.append(to_string(particles.size()));
	text[12]->message(pp);

	// ###############################################################
	// Checking if the enemie_bullets go out of the stage, then remove them
	// ###############################################################
	vector<Bullet*>::iterator toremoveEB2 = enemies_bullets.begin();
	while (toremoveEB2 != enemies_bullets.end()) {
		if ((((*toremoveEB2)->position.x < SWIDTH - SWIDTH) ||
			((*toremoveEB2)->position.x > SWIDTH) ||
			((*toremoveEB2)->position.y < SHEIGHT - SHEIGHT) ||
			((*toremoveEB2)->position.y > SHEIGHT)) &&
			(*toremoveEB2) > 0) {

			layers[1]->removeChild((*toremoveEB2));
			delete (*toremoveEB2);
			toremoveEB2 = enemies_bullets.erase(toremoveEB2);
		}
		else {
			++toremoveEB2;
		}
	}

	// ###############################################################
	// Checking if the player_bullets go out of the stage, then remove them
	// ###############################################################
	vector<Bullet*>::iterator toremove2 = player_bullets.begin();
	if (player_bullets.size() > 0) {
		while (toremove2 != player_bullets.end()) {
			if ((*toremove2)->position.x < SWIDTH - SWIDTH ||
				(*toremove2)->position.x > SWIDTH ||
				(*toremove2)->position.y < SHEIGHT - SHEIGHT ||
				(*toremove2)->position.y > SHEIGHT) {

				layers[1]->removeChild((*toremove2));
				delete (*toremove2);
				toremove2 = player_bullets.erase(toremove2);
			}
			else {
				++toremove2;
			}
		}
	}

	// ###############################################################
	// Calling the playerCollidWithBlock function to every block that is on stage
	// But that function doens't do anything yet
	// ###############################################################
	int blocks_size = blocks.size();
	for (int i = 0; i < blocks_size; i++) {
		blocks[i]->baiscEntityCollidWithBlock(player_entity, 32, 24);
	}
	blocks_size = NULL;

	// ###############################################################
	// Updating mouseClickBulletCounter and checking if the mouseClickBulletCounter is greater then the mouseClickBulletDelay
	// ###############################################################
	mouseClickBulletCounter += 0.5;
	if (mouseClickBulletCounter >= mouseClickBulletDelay) {
		mouseClickBulletCounter = mouseClickBulletDelay;
	}

	// ###############################################################
	// Creating Bullet* on the position of the player_entity when left mouse button is clicked
	// ###############################################################
	if (input()->getMouse(GLFW_MOUSE_BUTTON_1) && mouseClickBulletCounter >= mouseClickBulletDelay && currentAmmoInMagazine > 0 && playerCanShoot && player_entity->alive) {
		Bullet* b = new Bullet();
		b->setPositionAndRotation(player_entity);
		layers[1]->addChild(b);
		player_bullets.push_back(b);

		mouseClickBulletCounter = 0;
		currentAmmoInMagazine--;
		playerCanShoot = false;
	}

	// ###############################################################
	// When R pressed and currentAmmoInBag is greater then 0
	// Then, pressedReloadingForThePlayer is true
	// ###############################################################
	if (input()->getKeyDown(GLFW_KEY_R) && currentAmmoInBag > 0 && player_entity->alive) {
		pressedReloadingForThePlayer = true;
	}

	// ###############################################################
	// When pressedReloadingForThePlayer is true
	// playerCanShoot is false, because in the reloading time the player can't shoot
	// Then the counter gets activated and while the counter is going that is the time that the player can shoot
	// Then the player reloads and after that he can shoot again.
	// ###############################################################
	if (pressedReloadingForThePlayer) {
		playerCanShoot = false;
		playerReloadCounter += 0.5;
		if (playerReloadCounter >= playerReloadDelay) {
			playerReloadCounter = playerReloadDelay;

			int checkIfCanCarry = currentAmmoInMagazine + currentAmmoInBag;

			if (checkIfCanCarry > 32) {
				currentAmmoInBag -= maxAmmoInMagazine - currentAmmoInMagazine;
				currentAmmoInMagazine = maxAmmoInMagazine;
			}
			else if (checkIfCanCarry > 0) {
				currentAmmoInMagazine += currentAmmoInBag;
				currentAmmoInBag -= currentAmmoInBag;
			}
			playerReloadCounter = 0;
			pressedReloadingForThePlayer = false;
		}
	}
	else if (!pressedReloadingForThePlayer) {
		playerCanShoot = true;
	}

	// ###############################################################
	// When the ammo in magazine equals or less than 0 then it stays 0
	// ###############################################################
	if (currentAmmoInMagazine <= 0) {
		currentAmmoInMagazine = 0;
	}
	// ###############################################################
	// When the ammo in youre bag equals or less than 0 then it stays 0
	// ###############################################################
	if (currentAmmoInBag <= 0) {
		currentAmmoInBag = 0;
	}
	// ###############################################################
	// When the ammo in magazine equals to 0 and the ammo in your bag equals to 0
	// Then you get a message that youre out of ammo,
	// ###############################################################
	if (currentAmmoInMagazine == 0 && currentAmmoInBag == 0) {
		text[7]->message("You're out of ammo, find a ammunition box to continuing shooting");
	}

	// ###############################################################
	// Setting healthbar to current position of the player
	// ###############################################################
	player_healthbar->position.x = player_entity->position.x;
	player_healthbar->position.y = player_entity->position.y - 65;

	// ###############################################################
	// Setting scale of healthbar to current health of the player
	// ###############################################################
	player_healthbar->scale.x = (float)player_entity->getPlayerHealth() / 100;

	if ((player_entity->getPlayerHealth() <= 100) && (player_entity->getPlayerHealth() >= 76)) {
		player_healthbar->sprite()->color = GREEN;
	}
	if ((player_entity->getPlayerHealth() <= 75) && (player_entity->getPlayerHealth() >= 51)) {
		player_healthbar->sprite()->color = YELLOW;
	}
	if ((player_entity->getPlayerHealth() <= 50) && (player_entity->getPlayerHealth() >= 26)) {
		player_healthbar->sprite()->color = ORANGE;
	}
	if ((player_entity->getPlayerHealth() <= 25) && (player_entity->getPlayerHealth() >= 0)) {
		player_healthbar->sprite()->color = RED;
	}

	// ###############################################################
	// Setting text to the player healthbar
	// ###############################################################
	string health_string = to_string(player_entity->getPlayerHealth());

	player_health_text->message(health_string);

	if (player_entity->getPlayerHealth() <= 100 || player_entity->getPlayerHealth() > 100) {
		player_health_text->position.x = player_healthbar->position.x -14;
	}
	if (player_entity->getPlayerHealth() <= 99) {
		player_health_text->position.x = player_healthbar->position.x - 7;
	}
	if (player_entity->getPlayerHealth() == 0) {
		player_health_text->position.x = player_healthbar->position.x;
	}
	player_health_text->position.y = player_healthbar->position.y + 15;

	// ###############################################################
	// Setting healthbar to current position of the enemies
	// ###############################################################
	int enemie_size = enemies.size();
	for (int i = 0; i < enemie_size; i++) {
		enemies_healthbars[i]->position.x = enemies[i]->position.x;
		enemies_healthbars[i]->position.y = enemies[i]->position.y - 65;

		// ###############################################################
		// Setting scale of healthbar to current health of the player
		// ###############################################################
		enemies_healthbars[i]->scale.x = (float)enemies[i]->getEnemieHealth() / 100;

		if ((enemies[i]->getEnemieHealth() <= 100) && (enemies[i]->getEnemieHealth() >= 76)) {
			enemies_healthbars[i]->sprite()->color = GREEN;
		}
		if ((enemies[i]->getEnemieHealth() <= 75) && (enemies[i]->getEnemieHealth() >= 51)) {
			enemies_healthbars[i]->sprite()->color = YELLOW;
		}
		if ((enemies[i]->getEnemieHealth() <= 50) && (enemies[i]->getEnemieHealth() >= 26)) {
			enemies_healthbars[i]->sprite()->color = ORANGE;
		}
		if ((enemies[i]->getEnemieHealth() <= 25) && (enemies[i]->getEnemieHealth() >= 0)) {
			enemies_healthbars[i]->sprite()->color = RED;
		}
	}
	enemie_size = NULL;

	// ###############################################################
	// Adding highscore when player kills a enemie
	// ###############################################################
	vector<Enemie*>::iterator toremoveEnemies = enemies.begin();
	while (toremoveEnemies != enemies.end()) {
		if ((*toremoveEnemies)->alive == false && countEnemiesDied <= deadEnemies.size()) {
			currentscore += score;
			countEnemiesDied++;
			deadEnemies.push_back((*toremoveEnemies));
			toremoveEnemies = enemies.erase(toremoveEnemies);
		}
		else {
			++toremoveEnemies;
		}
	}

	// ###############################################################
	// Check when player pick up ammunition
	// ###############################################################
	vector<Pickup*>::iterator playerPickupsAmmunition_it = ammunitionpickups.begin();
	while (playerPickupsAmmunition_it != ammunitionpickups.end()) {
		if (player_entity->player_pickup_item(*playerPickupsAmmunition_it) == 1 &&
			(*playerPickupsAmmunition_it)->getItem() == "ammo") {

			currentAmmoInBag += maxAmmoInMagazine;

			layers[2]->removeChild((*playerPickupsAmmunition_it));
			delete (*playerPickupsAmmunition_it);
			playerPickupsAmmunition_it = ammunitionpickups.erase(playerPickupsAmmunition_it);
		}
		else {
			++playerPickupsAmmunition_it;
		}
	}

	
	// ###############################################################
	// Check when player pick up health
	// ###############################################################
	vector<Pickup*>::iterator playerPickupsHealth_it = healthpickups.begin();
	while (playerPickupsHealth_it != healthpickups.end()) {
		if (player_entity->player_pickup_item(*playerPickupsHealth_it) == 1 &&
			(*playerPickupsHealth_it)->getItem() == "health") {

			player_entity->addHealth(25);

			layers[2]->removeChild((*playerPickupsHealth_it));
			delete (*playerPickupsHealth_it);
			playerPickupsHealth_it = healthpickups.erase(playerPickupsHealth_it);
		}
		else {
			++playerPickupsHealth_it;
		}
	}

	// ###############################################################
	// Checking if the player's bullets hit a "collision" block
	// ###############################################################
	int blocksSize = blocks.size();
	int bulletListP = player_bullets.size();
	for (int i = 0; i < blocksSize; i++) {
		for (int j = 0; j < player_bullets.size(); j++) {
			if (player_bullets[j]->position.x < blocks[i]->position.x - 32 &&
				player_bullets[j]->position.x > blocks[i]->position.x + 32 &&
				player_bullets[j]->position.y < blocks[i]->position.y - 32 &&
				player_bullets[j]->position.y > blocks[i]->position.y + 32) {
				player_bullets[j]->alive = false;
			}
		}
	}

	// ###############################################################
	// Checking if the player's bullets hit a "collision" block
	// ###############################################################
	vector<Bullet*>::iterator bulletP = player_bullets.begin();
	while (bulletP != player_bullets.end()) {
		if ((*bulletP)->alive) {
			layers[2]->removeChild((*bulletP));
			delete (*bulletP);
			bulletP = player_bullets.erase(bulletP);
		}
		else {
			++bulletP;
		}
	}

	// ###############################################################
	// Setting state when WIN of LOSE
	// ###############################################################
	if (enemies.size() <= 0) {
		SuperScene::setState(WIN);
	}
	if (player_entity->getPlayerHealth() <= 0) {
		SuperScene::setState(LOSE);
	}

	if (SuperScene::getState() == WIN || SuperScene::getState() == LOSE) {
		if (triggerWhenFinished) {
			enterUsername->position.x = camera()->position.x;
			enterUsername->position.y = camera()->position.y;
			enterUsername->message(username);
			layers[4]->addChild(enterUsername);

			arrow->position.y = enterUsername->position.y + 40;
			layers[4]->addChild(arrow);

			numberone = true;
			numbertwo = false;
			numberthree = false;

			triggerWhenFinished = false;
		}

		if (numberone) {
			arrow->position.x = enterUsername->position.x;
		}
		if (numbertwo) {
			arrow->position.x = enterUsername->position.x + 32;
		}
		if (numberthree) {
			arrow->position.x = enterUsername->position.x + 64;
		}

		if (input()->getKey(GLFW_KEY_LEFT) && !pressed) {
			if (numberone && !pressed) {
				numberone = false;
				numbertwo = false;
				numberthree = true;

				pressed = true;
			}
			if (numbertwo && !pressed) {
				numberone = true;
				numbertwo = false;
				numberthree = false;

				pressed = true;
			}
			if (numberthree && !pressed) {
				numberone = false;
				numbertwo = true;
				numberthree = false;

				pressed = true;
			}
		}

		if (input()->getKeyUp(GLFW_KEY_LEFT) && pressed) {
			pressed = false;
		}

		if (input()->getKey(GLFW_KEY_RIGHT) && !pressed) {
			if (numberone && !pressed) {
				numberone = false;
				numbertwo = true;
				numberthree = false;

				pressed = true;
			}
			if (numbertwo && !pressed) {
				numberone = false;
				numbertwo = false;
				numberthree = true;

				pressed = true;
			}
			if (numberthree && !pressed) {
				numberone = true;
				numbertwo = false;
				numberthree = false;

				pressed = true;
			}
		}

		if (input()->getKeyUp(GLFW_KEY_RIGHT) && pressed) {
			pressed = false;
		}

		if (input()->getKey(GLFW_KEY_UP) && !pressed) {
			if (numberone && !pressed) {
				if (firstLetter == "a" && !pressed) {
					firstLetter = "b";
					pressed = true;
				}
				if (firstLetter == "b" && !pressed) {
					firstLetter = "c";
					pressed = true;
				}
				if (firstLetter == "c" && !pressed) {
					firstLetter = "d";
					pressed = true;
				}
				if (firstLetter == "d" && !pressed) {
					firstLetter = "e";
					pressed = true;
				}
				if (firstLetter == "e" && !pressed) {
					firstLetter = "f";
					pressed = true;
				}
				if (firstLetter == "f" && !pressed) {
					firstLetter = "g";
					pressed = true;
				}
				if (firstLetter == "g" && !pressed) {
					firstLetter = "h";
					pressed = true;
				}
				if (firstLetter == "h" && !pressed) {
					firstLetter = "i";
					pressed = true;
				}
				if (firstLetter == "i" && !pressed) {
					firstLetter = "j";
					pressed = true;
				}
				if (firstLetter == "j" && !pressed) {
					firstLetter = "k";
					pressed = true;
				}
				if (firstLetter == "k" && !pressed) {
					firstLetter = "l";
					pressed = true;
				}
				if (firstLetter == "l" && !pressed) {
					firstLetter = "m";
					pressed = true;
				}
				if (firstLetter == "m" && !pressed) {
					firstLetter = "n";
					pressed = true;
				}
				if (firstLetter == "n" && !pressed) {
					firstLetter = "o";
					pressed = true;
				}
				if (firstLetter == "o" && !pressed) {
					firstLetter = "p";
					pressed = true;
				}
				if (firstLetter == "p" && !pressed) {
					firstLetter = "q";
					pressed = true;
				}
				if (firstLetter == "q" && !pressed) {
					firstLetter = "r";
					pressed = true;
				}
				if (firstLetter == "r" && !pressed) {
					firstLetter = "s";
					pressed = true;
				}
				if (firstLetter == "s" && !pressed) {
					firstLetter = "t";
					pressed = true;
				}
				if (firstLetter == "t" && !pressed) {
					firstLetter = "u";
					pressed = true;
				}
				if (firstLetter == "u" && !pressed) {
					firstLetter = "v";
					pressed = true;
				}
				if (firstLetter == "v" && !pressed) {
					firstLetter = "w";
					pressed = true;
				}
				if (firstLetter == "w" && !pressed) {
					firstLetter = "x";
					pressed = true;
				}
				if (firstLetter == "x" && !pressed) {
					firstLetter = "y";
					pressed = true;
				}
				if (firstLetter == "y" && !pressed) {
					firstLetter = "z";
					pressed = true;
				}
				if (firstLetter == "z" && !pressed) {
					firstLetter = "a";
					pressed = true;
				}
			}
			if (numbertwo && !pressed) {
				if (secondLetter == "a" && !pressed) {
					secondLetter = "b";
					pressed = true;
				}
				if (secondLetter == "b" && !pressed) {
					secondLetter = "c";
					pressed = true;
				}
				if (secondLetter == "c" && !pressed) {
					secondLetter = "d";
					pressed = true;
				}
				if (secondLetter == "d" && !pressed) {
					secondLetter = "e";
					pressed = true;
				}
				if (secondLetter == "e" && !pressed) {
					secondLetter = "f";
					pressed = true;
				}
				if (secondLetter == "f" && !pressed) {
					secondLetter = "g";
					pressed = true;
				}
				if (secondLetter == "g" && !pressed) {
					secondLetter = "h";
					pressed = true;
				}
				if (secondLetter == "h" && !pressed) {
					secondLetter = "i";
					pressed = true;
				}
				if (secondLetter == "i" && !pressed) {
					secondLetter = "j";
					pressed = true;
				}
				if (secondLetter == "j" && !pressed) {
					secondLetter = "k";
					pressed = true;
				}
				if (secondLetter == "k" && !pressed) {
					secondLetter = "l";
					pressed = true;
				}
				if (secondLetter == "l" && !pressed) {
					secondLetter = "m";
					pressed = true;
				}
				if (secondLetter == "m" && !pressed) {
					secondLetter = "n";
					pressed = true;
				}
				if (secondLetter == "n" && !pressed) {
					secondLetter = "o";
					pressed = true;
				}
				if (secondLetter == "o" && !pressed) {
					secondLetter = "p";
					pressed = true;
				}
				if (secondLetter == "p" && !pressed) {
					secondLetter = "q";
					pressed = true;
				}
				if (secondLetter == "q" && !pressed) {
					secondLetter = "r";
					pressed = true;
				}
				if (secondLetter == "r" && !pressed) {
					secondLetter = "s";
					pressed = true;
				}
				if (secondLetter == "s" && !pressed) {
					secondLetter = "t";
					pressed = true;
				}
				if (secondLetter == "t" && !pressed) {
					secondLetter = "u";
					pressed = true;
				}
				if (secondLetter == "u" && !pressed) {
					secondLetter = "v";
					pressed = true;
				}
				if (secondLetter == "v" && !pressed) {
					secondLetter = "w";
					pressed = true;
				}
				if (secondLetter == "w" && !pressed) {
					secondLetter = "x";
					pressed = true;
				}
				if (secondLetter == "x" && !pressed) {
					secondLetter = "y";
					pressed = true;
				}
				if (secondLetter == "y" && !pressed) {
					secondLetter = "z";
					pressed = true;
				}
				if (secondLetter == "z" && !pressed) {
					secondLetter = "a";
					pressed = true;
				}
			}
			if (numberthree && !pressed) {
				if (thirdLetter == "a" && !pressed) {
					thirdLetter = "b";
					pressed = true;
				}
				if (thirdLetter == "b" && !pressed) {
					thirdLetter = "c";
					pressed = true;
				}
				if (thirdLetter == "c" && !pressed) {
					thirdLetter = "d";
					pressed = true;
				}
				if (thirdLetter == "d" && !pressed) {
					thirdLetter = "e";
					pressed = true;
				}
				if (thirdLetter == "e" && !pressed) {
					thirdLetter = "f";
					pressed = true;
				}
				if (thirdLetter == "f" && !pressed) {
					thirdLetter = "g";
					pressed = true;
				}
				if (thirdLetter == "g" && !pressed) {
					thirdLetter = "h";
					pressed = true;
				}
				if (thirdLetter == "h" && !pressed) {
					thirdLetter = "i";
					pressed = true;
				}
				if (thirdLetter == "i" && !pressed) {
					thirdLetter = "j";
					pressed = true;
				}
				if (thirdLetter == "j" && !pressed) {
					thirdLetter = "k";
					pressed = true;
				}
				if (thirdLetter == "k" && !pressed) {
					thirdLetter = "l";
					pressed = true;
				}
				if (thirdLetter == "l" && !pressed) {
					thirdLetter = "m";
					pressed = true;
				}
				if (thirdLetter == "m" && !pressed) {
					thirdLetter = "n";
					pressed = true;
				}
				if (thirdLetter == "n" && !pressed) {
					thirdLetter = "o";
					pressed = true;
				}
				if (thirdLetter == "o" && !pressed) {
					thirdLetter = "p";
					pressed = true;
				}
				if (thirdLetter == "p" && !pressed) {
					thirdLetter = "q";
					pressed = true;
				}
				if (thirdLetter == "q" && !pressed) {
					thirdLetter = "r";
					pressed = true;
				}
				if (thirdLetter == "r" && !pressed) {
					thirdLetter = "s";
					pressed = true;
				}
				if (thirdLetter == "s" && !pressed) {
					thirdLetter = "t";
					pressed = true;
				}
				if (thirdLetter == "t" && !pressed) {
					thirdLetter = "u";
					pressed = true;
				}
				if (thirdLetter == "u" && !pressed) {
					thirdLetter = "v";
					pressed = true;
				}
				if (thirdLetter == "v" && !pressed) {
					thirdLetter = "w";
					pressed = true;
				}
				if (thirdLetter == "w" && !pressed) {
					thirdLetter = "x";
					pressed = true;
				}
				if (thirdLetter == "x" && !pressed) {
					thirdLetter = "y";
					pressed = true;
				}
				if (thirdLetter == "y" && !pressed) {
					thirdLetter = "z";
					pressed = true;
				}
				if (thirdLetter == "z" && !pressed) {
					thirdLetter = "a";
					pressed = true;
				}
			}
		}

		if (input()->getKeyUp(GLFW_KEY_UP) && pressed) {
			pressed = false;
		}


		if (input()->getKey(GLFW_KEY_DOWN) && !pressed) {
			if (numberone && !pressed) {
				if (firstLetter == "b" && !pressed) {
					firstLetter = "a";
					pressed = true;
				}
				if (firstLetter == "c" && !pressed) {
					firstLetter = "b";
					pressed = true;
				}
				if (firstLetter == "d" && !pressed) {
					firstLetter = "c";
					pressed = true;
				}
				if (firstLetter == "e" && !pressed) {
					firstLetter = "d";
					pressed = true;
				}
				if (firstLetter == "f" && !pressed) {
					firstLetter = "e";
					pressed = true;
				}
				if (firstLetter == "g" && !pressed) {
					firstLetter = "f";
					pressed = true;
				}
				if (firstLetter == "h" && !pressed) {
					firstLetter = "g";
					pressed = true;
				}
				if (firstLetter == "i" && !pressed) {
					firstLetter = "h";
					pressed = true;
				}
				if (firstLetter == "j" && !pressed) {
					firstLetter = "i";
					pressed = true;
				}
				if (firstLetter == "k" && !pressed) {
					firstLetter = "j";
					pressed = true;
				}
				if (firstLetter == "l" && !pressed) {
					firstLetter = "k";
					pressed = true;
				}
				if (firstLetter == "m" && !pressed) {
					firstLetter = "l";
					pressed = true;
				}
				if (firstLetter == "n" && !pressed) {
					firstLetter = "m";
					pressed = true;
				}
				if (firstLetter == "o" && !pressed) {
					firstLetter = "n";
					pressed = true;
				}
				if (firstLetter == "p" && !pressed) {
					firstLetter = "o";
					pressed = true;
				}
				if (firstLetter == "q" && !pressed) {
					firstLetter = "p";
					pressed = true;
				}
				if (firstLetter == "r" && !pressed) {
					firstLetter = "q";
					pressed = true;
				}
				if (firstLetter == "s" && !pressed) {
					firstLetter = "r";
					pressed = true;
				}
				if (firstLetter == "t" && !pressed) {
					firstLetter = "s";
					pressed = true;
				}
				if (firstLetter == "u" && !pressed) {
					firstLetter = "t";
					pressed = true;
				}
				if (firstLetter == "v" && !pressed) {
					firstLetter = "u";
					pressed = true;
				}
				if (firstLetter == "w" && !pressed) {
					firstLetter = "v";
					pressed = true;
				}
				if (firstLetter == "x" && !pressed) {
					firstLetter = "w";
					pressed = true;
				}
				if (firstLetter == "y" && !pressed) {
					firstLetter = "x";
					pressed = true;
				}
				if (firstLetter == "z" && !pressed) {
					firstLetter = "y";
					pressed = true;
				}
				if (firstLetter == "a" && !pressed) {
					firstLetter = "z";
					pressed = true;
				}
			}
			if (numbertwo && !pressed) {
				if (secondLetter == "b" && !pressed) {
					secondLetter = "a";
					pressed = true;
				}
				if (secondLetter == "c" && !pressed) {
					secondLetter = "b";
					pressed = true;
				}
				if (secondLetter == "d" && !pressed) {
					secondLetter = "c";
					pressed = true;
				}
				if (secondLetter == "e" && !pressed) {
					secondLetter = "d";
					pressed = true;
				}
				if (secondLetter == "f" && !pressed) {
					secondLetter = "e";
					pressed = true;
				}
				if (secondLetter == "g" && !pressed) {
					secondLetter = "f";
					pressed = true;
				}
				if (secondLetter == "h" && !pressed) {
					secondLetter = "g";
					pressed = true;
				}
				if (secondLetter == "i" && !pressed) {
					secondLetter = "h";
					pressed = true;
				}
				if (secondLetter == "j" && !pressed) {
					secondLetter = "i";
					pressed = true;
				}
				if (secondLetter == "k" && !pressed) {
					secondLetter = "j";
					pressed = true;
				}
				if (secondLetter == "l" && !pressed) {
					secondLetter = "k";
					pressed = true;
				}
				if (secondLetter == "m" && !pressed) {
					secondLetter = "l";
					pressed = true;
				}
				if (secondLetter == "n" && !pressed) {
					secondLetter = "m";
					pressed = true;
				}
				if (secondLetter == "o" && !pressed) {
					secondLetter = "n";
					pressed = true;
				}
				if (secondLetter == "p" && !pressed) {
					secondLetter = "o";
					pressed = true;
				}
				if (secondLetter == "q" && !pressed) {
					secondLetter = "p";
					pressed = true;
				}
				if (secondLetter == "r" && !pressed) {
					secondLetter = "q";
					pressed = true;
				}
				if (secondLetter == "s" && !pressed) {
					secondLetter = "r";
					pressed = true;
				}
				if (secondLetter == "t" && !pressed) {
					secondLetter = "s";
					pressed = true;
				}
				if (secondLetter == "u" && !pressed) {
					secondLetter = "t";
					pressed = true;
				}
				if (secondLetter == "v" && !pressed) {
					secondLetter = "u";
					pressed = true;
				}
				if (secondLetter == "w" && !pressed) {
					secondLetter = "v";
					pressed = true;
				}
				if (secondLetter == "x" && !pressed) {
					secondLetter = "w";
					pressed = true;
				}
				if (secondLetter == "y" && !pressed) {
					secondLetter = "x";
					pressed = true;
				}
				if (secondLetter == "z" && !pressed) {
					secondLetter = "y";
					pressed = true;
				}
				if (secondLetter == "a" && !pressed) {
					secondLetter = "z";
					pressed = true;
				}
			}
			if (numberthree && !pressed) {
				if (thirdLetter == "b" && !pressed) {
					thirdLetter = "a";
					pressed = true;
				}
				if (thirdLetter == "c" && !pressed) {
					thirdLetter = "b";
					pressed = true;
				}
				if (thirdLetter == "d" && !pressed) {
					thirdLetter = "c";
					pressed = true;
				}
				if (thirdLetter == "e" && !pressed) {
					thirdLetter = "d";
					pressed = true;
				}
				if (thirdLetter == "f" && !pressed) {
					thirdLetter = "e";
					pressed = true;
				}
				if (thirdLetter == "g" && !pressed) {
					thirdLetter = "f";
					pressed = true;
				}
				if (thirdLetter == "h" && !pressed) {
					thirdLetter = "g";
					pressed = true;
				}
				if (thirdLetter == "i" && !pressed) {
					thirdLetter = "h";
					pressed = true;
				}
				if (thirdLetter == "j" && !pressed) {
					thirdLetter = "i";
					pressed = true;
				}
				if (thirdLetter == "k" && !pressed) {
					thirdLetter = "j";
					pressed = true;
				}
				if (thirdLetter == "l" && !pressed) {
					thirdLetter = "k";
					pressed = true;
				}
				if (thirdLetter == "m" && !pressed) {
					thirdLetter = "l";
					pressed = true;
				}
				if (thirdLetter == "n" && !pressed) {
					thirdLetter = "m";
					pressed = true;
				}
				if (thirdLetter == "o" && !pressed) {
					thirdLetter = "n";
					pressed = true;
				}
				if (thirdLetter == "p" && !pressed) {
					thirdLetter = "o";
					pressed = true;
				}
				if (thirdLetter == "q" && !pressed) {
					thirdLetter = "p";
					pressed = true;
				}
				if (thirdLetter == "r" && !pressed) {
					thirdLetter = "q";
					pressed = true;
				}
				if (thirdLetter == "s" && !pressed) {
					thirdLetter = "r";
					pressed = true;
				}
				if (thirdLetter == "t" && !pressed) {
					thirdLetter = "s";
					pressed = true;
				}
				if (thirdLetter == "u" && !pressed) {
					thirdLetter = "t";
					pressed = true;
				}
				if (thirdLetter == "v" && !pressed) {
					thirdLetter = "u";
					pressed = true;
				}
				if (thirdLetter == "w" && !pressed) {
					thirdLetter = "v";
					pressed = true;
				}
				if (thirdLetter == "x" && !pressed) {
					thirdLetter = "w";
					pressed = true;
				}
				if (thirdLetter == "y" && !pressed) {
					thirdLetter = "x";
					pressed = true;
				}
				if (thirdLetter == "z" && !pressed) {
					thirdLetter = "y";
					pressed = true;
				}
				if (thirdLetter == "a" && !pressed) {
					thirdLetter = "z";
					pressed = true;
				}
			}
		}

		if (input()->getKeyUp(GLFW_KEY_DOWN) && pressed) {
			pressed = false;
		}
		layers[4]->removeChild(enterUsername);
		username = firstLetter + secondLetter + thirdLetter;
		enterUsername->message(username);
		layers[4]->addChild(enterUsername);
	}

	// ###############################################################
	// Logging current score
	// ###############################################################
	string currentscorestr = to_string(currentscore);
	text[6]->message("Score: " + currentscorestr);

	// ###############################################################
	// Logging current ammo and current mags
	// ###############################################################
	string AmmoLeftToUseText = "Ammo: ";
	AmmoLeftToUseText.append(to_string(currentAmmoInMagazine));
	AmmoLeftToUseText.append("/");
	AmmoLeftToUseText.append(to_string(currentAmmoInBag));
	text[4]->message(AmmoLeftToUseText);

	// ###############################################################
	// Logging current health and max health
	// ###############################################################
	string playerHealthToText = "Health: ";
	playerHealthToText.append(to_string(player_entity->getPlayerHealth()));
	playerHealthToText.append("/");
	playerHealthToText.append("100");
	text[5]->message(playerHealthToText);

	// ###############################################################
	// Setting the borders for the player_entity
	// ###############################################################
	if (player_entity->position.x < 0 + playerRaduis + 64) {
		player_entity->position.x = 0 + playerRaduis + 64;
	}
	if (player_entity->position.x > SWIDTH - playerRaduis - 64) {
		player_entity->position.x = SWIDTH - playerRaduis - 64;
	}
	if (player_entity->position.y < 0 + playerRaduis + 64) {
		player_entity->position.y = 0 + playerRaduis + 64;
	}
	if (player_entity->position.y > SHEIGHT - playerRaduis - 64) {
		player_entity->position.y = SHEIGHT - playerRaduis - 64;
	}
}

int Scene00::getscore() {
	return this->currentscore;
}

string Scene00::getname() {
	return this->username;
}

int Scene00::posTile(int rowOrCell) {
	int i = 64 * rowOrCell - 32;
	return i;
}