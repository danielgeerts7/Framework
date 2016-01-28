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

	enemieSpawnDelay = 150;
	enemieSpawnCounter = 0;

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
	// cell 13 ; row 12
	player_entity->position = Point2(posTile(13), posTile(12));

	player_healthbar = new HealthBar();
	player_healthbar->position.x = player_entity->position.x;
	player_healthbar->position.y = player_entity->position.y - 60;

	player_health_text = new Text();
	player_health_text->scale = Point2(0.4, 0.4);
	layers[3]->addChild(player_health_text);

	Enemie* enemie = new Enemie();
	layers[2]->addChild(enemie);
	enemies.push_back(enemie);

	enemie->setCurrentWaypoint(0);
	enemie->setSpawnPoint(rand() % 3);
	enemieSpawnAddSpawnpoint(enemie, enemie->getSpawnPoint());

	BasicEntity* gun_enemie = new BasicEntity();
	gun_enemie->addSprite("assets/gun.tga");
	gun_enemie->sprite()->color = YELLOW;
	gun_enemie->position = Point2(30, 25);

	guns_enemies.push_back(gun_enemie);
	enemie->addChild(gun_enemie);

	HealthBar* healthbar_enemie = new HealthBar();
	healthbar_enemie->position.x = enemie->position.x;
	healthbar_enemie->position.y = enemie->position.y - 60;

	enemies_healthbars.push_back(healthbar_enemie);
	layers[2]->addChild(healthbar_enemie);

	gun_player_entity = new BasicEntity();
	gun_player_entity->addSprite("assets/gun.tga");
	gun_player_entity->sprite()->color = YELLOW;
	gun_player_entity->position = Point2(30, 25);
	
	// ammunition pickup
	int ammunition_pickup_amount = 4;
	for (int i = 0; i < ammunition_pickup_amount; i++) {
		Pickup* ammo = new Pickup("ammo");

		ammunitionpickups.push_back(ammo);
		layers[2]->addChild(ammunitionpickups[i]);
	}

	// cell 3,9,18,23 ; row 2,14
	ammunitionpickups[0]->position = Point2(posTile(3), posTile(2));
	ammunitionpickups[1]->position = Point2(posTile(9), posTile(14));
	ammunitionpickups[2]->position = Point2(posTile(18), posTile(2));
	ammunitionpickups[3]->position = Point2(posTile(23), posTile(14));

	// health pickup
	int health_pickup_amount = 4;
	for (int i = 0; i < health_pickup_amount; i++) {
		Pickup* health = new Pickup("health");

		healthpickups.push_back(health);
		layers[2]->addChild(healthpickups[i]);
	}
	//cell 3,8,17,23 ; row 2,14
	healthpickups[0]->position = Point2(posTile(3), posTile(14));
	healthpickups[1]->position = Point2(posTile(8), posTile(2));
	healthpickups[2]->position = Point2(posTile(17), posTile(14));
	healthpickups[3]->position = Point2(posTile(23), posTile(2));

	int amount = 23;

	for (int i = 0; i < amount; i++) {
		Block* b = new Block();
		blocks.push_back(b);

		layers[2]->addChild(blocks[i]);
	}
	// cell 10,11,15,16 ; row 9
	blocks[0]->position = Point2(posTile(10), posTile(9));
	blocks[1]->position = Point2(posTile(11), posTile(9));
	blocks[2]->position = Point2(posTile(15), posTile(9));
	blocks[3]->position = Point2(posTile(16), posTile(9));
	// cell 9,10,16,17 ; row 10
	blocks[4]->position = Point2(posTile(9), posTile(10));
	blocks[5]->position = Point2(posTile(10), posTile(10));
	blocks[6]->position = Point2(posTile(16), posTile(10));
	blocks[7]->position = Point2(posTile(17), posTile(10));
	// cell 9,17 ; row 11
	blocks[8]->position = Point2(posTile(9), posTile(11));
	blocks[9]->position = Point2(posTile(17), posTile(11));
	// cell 9,17 ; row 12
	blocks[10]->position = Point2(posTile(9), posTile(12));
	blocks[11]->position = Point2(posTile(17), posTile(12));
	// cell 9,10,16,17 ; row 13
	blocks[12]->position = Point2(posTile(9), posTile(13));
	blocks[13]->position = Point2(posTile(10), posTile(13));
	blocks[14]->position = Point2(posTile(16), posTile(13));
	blocks[15]->position = Point2(posTile(17), posTile(13));
	// cell 10,11,12,13,14,15,16 ; row 14
	blocks[16]->position = Point2(posTile(10), posTile(14));
	blocks[17]->position = Point2(posTile(11), posTile(14));
	blocks[18]->position = Point2(posTile(12), posTile(14));
	blocks[19]->position = Point2(posTile(13), posTile(14));
	blocks[20]->position = Point2(posTile(14), posTile(14));
	blocks[21]->position = Point2(posTile(15), posTile(14));
	blocks[22]->position = Point2(posTile(16), posTile(14));

	layers[2]->addChild(player_entity);
	layers[2]->addChild(player_healthbar);
	player_entity->addChild(gun_player_entity);
}


Scene00::~Scene00()
{
// remove blocks
	int s = blocks.size();
	for (int i = 0; i<s; i++) {
		layers[2]->removeChild(blocks[i]);
		delete blocks[i];
		blocks[i] = NULL;
	}
	blocks.clear();

// remove player bullets
	int p_b = player_bullets.size();
	for (int j = 0; j<p_b; j++) {
		layers[1]->removeChild(player_bullets[j]);
		delete player_bullets[j];
		player_bullets[j] = NULL;
	}
	player_bullets.clear();

// remove enemies bullets
	int e_b = enemies_bullets.size();
	for (int l = 0; l<e_b; l++) {
		layers[1]->removeChild(enemies_bullets[l]);
		delete enemies_bullets[l];
		enemies_bullets[l] = NULL;
	}
	enemies_bullets.clear();

// remove enemies, guns_enemies, enemies_healthbars
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

// remove enemiesparticles
	int ep = enemiesparticles.size();
	for (int a = 0; a < ep; a++) {
		layers[1]->removeChild(enemiesparticles[a]);
		delete enemiesparticles[a];
		enemiesparticles[a] = NULL;
	}
	enemiesparticles.clear();

	// remove playerparticles
	int pp = playerparticles.size();
	for (int a = 0; a < pp; a++) {
		layers[1]->removeChild(playerparticles[a]);
		delete playerparticles[a];
		playerparticles[a] = NULL;
	}
	playerparticles.clear();

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

// removing the rest
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
			if (enemies[a]->getIfPlayerInField() && enemieCounter >= enemieDelay) {
				Bullet* b = new Bullet();
				b->setPositionAndRotation(enemies[a]);
				layers[1]->addChild(b);
				enemies_bullets.push_back(b);
			}
		}
	}
	enemiesSize = 0;

	// Setting the counter to 0 for a bullet shooting delay
	if (enemieCounter >= enemieDelay) {
		enemieCounter = 0;
	}

	// 
	enemieSpawnCounter += 0.5;
	if (enemieSpawnCounter >= enemieSpawnDelay) {
		enemieSpawnCounter = enemieSpawnDelay;
	}
	// ###############################################################
	// Spawning new enemies when counter is greater or equal delay
	// ###############################################################
	if (enemieSpawnCounter >= enemieSpawnDelay && player_entity->alive) {
		Enemie* enemie = new Enemie();
		layers[2]->addChild(enemie);
		enemies.push_back(enemie);

		enemie->setCurrentWaypoint(0);
		enemie->setSpawnPoint(rand() % 3);
		enemieSpawnAddSpawnpoint(enemie, enemie->getSpawnPoint());

		BasicEntity* gun_enemie = new BasicEntity();
		gun_enemie->addSprite("assets/gun.tga");
		gun_enemie->sprite()->color = YELLOW;
		gun_enemie->position = Point2(30, 25);

		guns_enemies.push_back(gun_enemie);
		enemie->addChild(gun_enemie);

		HealthBar* healthbar_enemie = new HealthBar();
		healthbar_enemie->position.x = enemie->position.x;
		healthbar_enemie->position.y = enemie->position.y - 60;

		enemies_healthbars.push_back(healthbar_enemie);
		layers[2]->addChild(healthbar_enemie);

		enemieSpawnCounter = 0;
	}

	// ###############################################################
	// All enemies walk to 'waypoints' and then to the player
	// ###############################################################
	int enemiesSizeForWaypoints = enemies.size();
	
	for (int i = 0; i < enemiesSizeForWaypoints; i++) {
		if (enemies[i]->getSpawnPoint() == 0) {
			if (enemies[i]->getCurrentWaypoint() == 0 && enemies[i]->getNewWaypoint() == 0) {
				Point2 newPosition0 = Point2(posTile(rand() % 3 + 5), posTile(rand() % 3 + 4));
				enemies[i]->setNewPosition(newPosition0);
				enemies[i]->setNewWaypoint(1);
			}
			if (enemies[i]->getCurrentWaypoint() == 1 && enemies[i]->getNewWaypoint() == 1) {
				Point2 newPosition1 = Point2(posTile(rand() % 3 + 12), posTile(rand() % 3 + 6));
				enemies[i]->setNewPosition(newPosition1);
				enemies[i]->setNewWaypoint(2);
			}

			if (enemies[i]->position.x < enemies[i]->getNewPosition().x + 5 &&
				enemies[i]->position.x > enemies[i]->getNewPosition().x - 5 &&
				enemies[i]->position.y < enemies[i]->getNewPosition().y + 5 &&
				enemies[i]->position.y > enemies[i]->getNewPosition().y - 5 &&
				enemies[i]->getCurrentWaypoint() < 2) {
				int a = enemies[i]->getCurrentWaypoint() + 1;
				enemies[i]->setCurrentWaypoint(a);
			}
			if (enemies[i]->getCurrentWaypoint() < 2 && enemies[i]->checkIfPlayerIsInFieldOfView == false) {
				Point2 newpos = Point2(enemies[i]->getNewPosition().x, enemies[i]->getNewPosition().y);
				Vector2 delta1 = Vector2(enemies[i]->position, newpos);
				float angle1 = delta1.getAngle();
				enemies[i]->rotation = angle1;

				float velocity_x = cos(enemies[i]->rotation) * 1;
				float velocity_y = sin(enemies[i]->rotation) * 1;
				Vector2 velocity = Vector2(velocity_x, velocity_y);

				enemies[i]->position += velocity;
			} else {
				Point2 newpos = Point2(player_entity->position.x, player_entity->position.y);
				Vector2 delta1 = Vector2(enemies[i]->position, newpos);
				float angle1 = delta1.getAngle();
				enemies[i]->rotation = angle1;

				float velocity_x = cos(enemies[i]->rotation) * 1;
				float velocity_y = sin(enemies[i]->rotation) * 1;
				Vector2 velocity = Vector2(velocity_x, velocity_y);

				enemies[i]->position += velocity;
			}
		}
		if (enemies[i]->getSpawnPoint() == 1) {
			if (enemies[i]->getCurrentWaypoint() == 0 && enemies[i]->getNewWaypoint() == 0) {
				Point2 newPosition0 = Point2(posTile(rand() % 3 + 19), posTile(rand() % 3 + 4));
				enemies[i]->setNewPosition(newPosition0);
				enemies[i]->setNewWaypoint(1);
			}
			if (enemies[i]->getCurrentWaypoint() == 1 && enemies[i]->getNewWaypoint() == 1) {
				Point2 newPosition1 = Point2(posTile(rand() % 3 + 12), posTile(rand() % 3 + 6));
				enemies[i]->setNewPosition(newPosition1);
				enemies[i]->setNewWaypoint(2);
			}

			if (enemies[i]->position.x < enemies[i]->getNewPosition().x + 5 &&
				enemies[i]->position.x > enemies[i]->getNewPosition().x - 5 &&
				enemies[i]->position.y < enemies[i]->getNewPosition().y + 5 &&
				enemies[i]->position.y > enemies[i]->getNewPosition().y - 5 &&
				enemies[i]->getCurrentWaypoint() < 2) {
				int a = enemies[i]->getCurrentWaypoint() + 1;
				enemies[i]->setCurrentWaypoint(a);
			}
			if (enemies[i]->getCurrentWaypoint() < 2 && enemies[i]->checkIfPlayerIsInFieldOfView == false) {
				Point2 newpos = Point2(enemies[i]->getNewPosition().x, enemies[i]->getNewPosition().y);
				Vector2 delta1 = Vector2(enemies[i]->position, newpos);
				float angle1 = delta1.getAngle();
				enemies[i]->rotation = angle1;

				float velocity_x = cos(enemies[i]->rotation) * 1;
				float velocity_y = sin(enemies[i]->rotation) * 1;
				Vector2 velocity = Vector2(velocity_x, velocity_y);

				enemies[i]->position += velocity;
			}
			else {
				Point2 newpos = Point2(player_entity->position.x, player_entity->position.y);
				Vector2 delta1 = Vector2(enemies[i]->position, newpos);
				float angle1 = delta1.getAngle();
				enemies[i]->rotation = angle1;

				float velocity_x = cos(enemies[i]->rotation) * 1;
				float velocity_y = sin(enemies[i]->rotation) * 1;
				Vector2 velocity = Vector2(velocity_x, velocity_y);

				enemies[i]->position += velocity;
			}
		}
		if (enemies[i]->getSpawnPoint() == 2) {
			if (enemies[i]->getCurrentWaypoint() == 0 && enemies[i]->getNewWaypoint() == 0) {
				Point2 newPosition0 = Point2(posTile(rand() % 3 + 6), posTile(rand() % 3 + 6));
				enemies[i]->setNewPosition(newPosition0);
				enemies[i]->setNewWaypoint(1);
			}
			if (enemies[i]->getCurrentWaypoint() == 1 && enemies[i]->getNewWaypoint() == 1) {
				Point2 newPosition1 = Point2(posTile(rand() % 3 + 12), posTile(rand() % 3 + 6));
				enemies[i]->setNewPosition(newPosition1);
				enemies[i]->setNewWaypoint(2);
			}

			if (enemies[i]->position.x < enemies[i]->getNewPosition().x + 5 &&
				enemies[i]->position.x > enemies[i]->getNewPosition().x - 5 &&
				enemies[i]->position.y < enemies[i]->getNewPosition().y + 5 &&
				enemies[i]->position.y > enemies[i]->getNewPosition().y - 5 &&
				enemies[i]->getCurrentWaypoint() < 2) {
				int a = enemies[i]->getCurrentWaypoint() + 1;
				enemies[i]->setCurrentWaypoint(a);
			}
			if (enemies[i]->getCurrentWaypoint() < 2 && enemies[i]->checkIfPlayerIsInFieldOfView == false) {
				Point2 newpos = Point2(enemies[i]->getNewPosition().x, enemies[i]->getNewPosition().y);
				Vector2 delta1 = Vector2(enemies[i]->position, newpos);
				float angle1 = delta1.getAngle();
				enemies[i]->rotation = angle1;

				float velocity_x = cos(enemies[i]->rotation) * 1;
				float velocity_y = sin(enemies[i]->rotation) * 1;
				Vector2 velocity = Vector2(velocity_x, velocity_y);

				enemies[i]->position += velocity;
			}
			else {
				Point2 newpos = Point2(player_entity->position.x, player_entity->position.y);
				Vector2 delta1 = Vector2(enemies[i]->position, newpos);
				float angle1 = delta1.getAngle();
				enemies[i]->rotation = angle1;

				float velocity_x = cos(enemies[i]->rotation) * 1;
				float velocity_y = sin(enemies[i]->rotation) * 1;
				Vector2 velocity = Vector2(velocity_x, velocity_y);

				enemies[i]->position += velocity;
			}
		}
		if (enemies[i]->getSpawnPoint() == 3) {
			if (enemies[i]->getCurrentWaypoint() == 0 && enemies[i]->getNewWaypoint() == 0) {
				Point2 newPosition0 = Point2(posTile(rand() % 3 + 19), posTile(rand() % 3 + 6));
				enemies[i]->setNewPosition(newPosition0);
				enemies[i]->setNewWaypoint(1);
			}
			if (enemies[i]->getCurrentWaypoint() == 1 && enemies[i]->getNewWaypoint() == 1) {
				Point2 newPosition1 = Point2(posTile(rand() % 3 + 12), posTile(rand() % 3 + 6));
				enemies[i]->setNewPosition(newPosition1);
				enemies[i]->setNewWaypoint(2);
			}

			if (enemies[i]->position.x < enemies[i]->getNewPosition().x + 5 &&
				enemies[i]->position.x > enemies[i]->getNewPosition().x - 5 &&
				enemies[i]->position.y < enemies[i]->getNewPosition().y + 5 &&
				enemies[i]->position.y > enemies[i]->getNewPosition().y - 5 &&
				enemies[i]->getCurrentWaypoint() < 2) {
				int a = enemies[i]->getCurrentWaypoint() + 1;
				enemies[i]->setCurrentWaypoint(a);
			}
			if (enemies[i]->getCurrentWaypoint() < 2 && enemies[i]->checkIfPlayerIsInFieldOfView == false) {
				Point2 newpos = Point2(enemies[i]->getNewPosition().x, enemies[i]->getNewPosition().y);
				Vector2 delta1 = Vector2(enemies[i]->position, newpos);
				float angle1 = delta1.getAngle();
				enemies[i]->rotation = angle1;

				float velocity_x = cos(enemies[i]->rotation) * 1;
				float velocity_y = sin(enemies[i]->rotation) * 1;
				Vector2 velocity = Vector2(velocity_x, velocity_y);

				enemies[i]->position += velocity;
			}
			else {
				Point2 newpos = Point2(player_entity->position.x, player_entity->position.y);
				Vector2 delta1 = Vector2(enemies[i]->position, newpos);
				float angle1 = delta1.getAngle();
				enemies[i]->rotation = angle1;

				float velocity_x = cos(enemies[i]->rotation) * 1;
				float velocity_y = sin(enemies[i]->rotation) * 1;
				Vector2 velocity = Vector2(velocity_x, velocity_y);

				enemies[i]->position += velocity;
			}
		}
	}
	enemiesSizeForWaypoints = 0;
	

	// ###############################################################
	// Player gets hit by the enemies bullets
	// ###############################################################
	vector<Bullet*>::iterator toremoveEB = enemies_bullets.begin();
	if (player_entity->alive) {
		while (toremoveEB != enemies_bullets.end()) {
			if (player_entity->gettingHitByEnemieBullets((*toremoveEB)) == 1 && player_entity->getPlayerHealth() > 0 && (*toremoveEB) > 0) {
				
				ParticleSystem* p = new ParticleSystem(RED, "assets/singleparticle.tga", 0, 0);
				p->addParticleToParentBullet((*toremoveEB));
				layers[1]->addChild(p);
				playerparticles.push_back(p);

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

				ParticleSystem* p = new ParticleSystem(RED, "assets/singleparticle.tga", 0, 0);
				p->addParticleToParentBullet(player_bullets[pb]);
				layers[1]->addChild(p);
				enemiesparticles.push_back(p);
			}
		}
	}
	player_bullets_size = 0;

	// ###############################################################
	// Remove all bullets that hit a Enemie
	// ###############################################################
	vector<Bullet*>::iterator toremovePB = player_bullets.begin();
	while (toremovePB != player_bullets.end()) {
		if ((*toremovePB)->alive == false) {
			layers[1]->removeChild((*toremovePB));
			delete (*toremovePB);
			toremovePB = player_bullets.erase(toremovePB);
		}
		else {
			++toremovePB;
		}
	}

	// ###############################################################
	// Deleting enemies particles when isDead() is true
	// ###############################################################
	vector<ParticleSystem*>::iterator toremovePart = enemiesparticles.begin();
	while (toremovePart != enemiesparticles.end()) {
		if ((*toremovePart)->isDead()) {
			layers[1]->removeChild((*toremovePart));
			delete (*toremovePart);
			toremovePart = enemiesparticles.erase(toremovePart);
		}
		else {
			++toremovePart;
		}
	}

	// ###############################################################
	// Deleting player particles when isDead() is true
	// ###############################################################
	vector<ParticleSystem*>::iterator toremovePartplayer = playerparticles.begin();
	while (toremovePartplayer != playerparticles.end()) {
		if ((*toremovePartplayer)->isDead()) {
			layers[1]->removeChild((*toremovePartplayer));
			delete (*toremovePartplayer);
			toremovePartplayer = playerparticles.erase(toremovePartplayer);
		}
		else {
			++toremovePartplayer;
		}
	}

	string pp = "Allparticles: ";
	pp.append(to_string(enemiesparticles.size() + playerparticles.size()));
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
	int enemies_size = enemies.size();
	for (int i = 0; i < blocks_size; i++) {
		blocks[i]->baiscEntityCollidWithBlock(player_entity, 32, 24);
		for (int j = 0; j < enemies_size; j++) {
			blocks[i]->baiscEntityCollidWithBlock(enemies[j], 32, 24);
		}
	}
	blocks_size = 0;

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
	} else {
		text[7]->message("");
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
		if (enemies[i]->getEnemieHealth() <= 0) {
			enemies_healthbars[i]->alive = false;
			enemies[i]->alive = false;
		}

		if (player_entity->alive == false) {
			enemies_healthbars[i]->alive = false;
			enemies[i]->alive = false;
		}
	}
	enemie_size = 0;

	// ###############################################################
	// Removing the healthbar when the health of the enemie is 0 or lower
	// ###############################################################
	vector<HealthBar*>::iterator toremoveHealthbarsEnemies = enemies_healthbars.begin();
	while (toremoveHealthbarsEnemies != enemies_healthbars.end()) {
		if ((*toremoveHealthbarsEnemies)->alive == false) {
			layers[2]->removeChild(*toremoveHealthbarsEnemies);
			delete (*toremoveHealthbarsEnemies);
			toremoveHealthbarsEnemies = enemies_healthbars.erase(toremoveHealthbarsEnemies);
		}
		else {
			++toremoveHealthbarsEnemies;
		}
	}

	// ###############################################################
	// Adding highscore when player kills a enemie
	// ###############################################################
	vector<Enemie*>::iterator toremoveEnemies = enemies.begin();
	while (toremoveEnemies != enemies.end()) {
		if ((*toremoveEnemies)->alive == false && countEnemiesDied <= deadEnemies.size()) {
			if (player_entity->alive) {
				currentscore += score;
				countEnemiesDied++;
				deadEnemies.push_back((*toremoveEnemies));

				ParticleSystem* p = new ParticleSystem(YELLOW, "assets/gun.tga", 1, 0);
				p->addParticleToParentEnemie((*toremoveEnemies));
				layers[1]->addChild(p);
				enemiesparticles.push_back(p);

				int i = 0;
				while (i < 3) {
					ParticleSystem* pgun = new ParticleSystem(PINK, "assets/player_sprite_booty_parts.tga", 2, i);
					pgun->addParticleToParentEnemie((*toremoveEnemies));
					layers[1]->addChild(pgun);
					enemiesparticles.push_back(pgun);
					i++;
				}
			}
			layers[2]->removeChild(*toremoveEnemies);
			delete (*toremoveEnemies);
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
		for (int j = 0; j < bulletListP; j++) {
			if (player_bullets[j]->position.x < blocks[i]->position.x + 32 &&
				player_bullets[j]->position.x > blocks[i]->position.x - 32 &&
				player_bullets[j]->position.y < blocks[i]->position.y + 32 &&
				player_bullets[j]->position.y > blocks[i]->position.y - 32) {
				player_bullets[j]->alive = false;
			}
		}
	}
	blocksSize = 0;
	bulletListP = 0;

	// ###############################################################
	// Deleting player bullets when bullets are !alive
	// ###############################################################
	vector<Bullet*>::iterator bulletP = player_bullets.begin();
	while (bulletP != player_bullets.end()) {
		if ((*bulletP)->alive == false) {
			layers[1]->removeChild((*bulletP));
			delete (*bulletP);
			bulletP = player_bullets.erase(bulletP);
		}
		else {
			++bulletP;
		}
	}

	// ###############################################################
	// Checking if the player's bullets hit a "collision" block
	// ###############################################################
	int blocksSizeEnemies = blocks.size();
	int bulletListE = enemies_bullets.size();
	for (int i = 0; i < blocksSizeEnemies; i++) {
		for (int j = 0; j < bulletListE; j++) {
			if (enemies_bullets[j]->position.x < blocks[i]->position.x + 32 &&
				enemies_bullets[j]->position.x > blocks[i]->position.x - 32 &&
				enemies_bullets[j]->position.y < blocks[i]->position.y + 32 &&
				enemies_bullets[j]->position.y > blocks[i]->position.y - 32) {
				enemies_bullets[j]->alive = false;
			}
		}
	}
	blocksSizeEnemies = 0;
	bulletListE = 0;

	// ###############################################################
	// Deleting bullets when bullets are !alive
	// ###############################################################
	vector<Bullet*>::iterator bulletE = enemies_bullets.begin();
	while (bulletE != enemies_bullets.end()) {
		if ((*bulletE)->alive == false) {
			layers[1]->removeChild((*bulletE));
			delete (*bulletE);
			bulletE = enemies_bullets.erase(bulletE);
		}
		else {
			++bulletE;
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

	// ###############################################################
	// When WIN or LOSE, enter username
	// ###############################################################
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

		if (input()->getKey(GLFW_KEY_ENTER)) {
			this->stop();
			SuperScene::activescene = 0;
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

// Getting current score of the current game
int Scene00::getscore() {
	return this->currentscore;
}

// Getting the username which the player enters when WIN or LOSE
string Scene00::getname() {
	return this->username;
}

// Calculates int (x or y) when input 'rowOrCell' tile number
int Scene00::posTile(int rowOrCell) {
	int i = 64 * rowOrCell - 32;
	return i;
}

void Scene00::enemieSpawnAddSpawnpoint(Enemie* e, int spawnPointNumber) {
	if (spawnPointNumber == 0) {
		// cell 3 row 4
		e->position = Point(posTile(3), posTile(4));
	}
	if (spawnPointNumber == 1) {
		// cell 23, row 4
		e->position = Point(posTile(23), posTile(4));
	}
	if (spawnPointNumber == 2) {
		// cel 4, row 10
		e->position = Point(posTile(4), posTile(10));
	}
	if (spawnPointNumber == 3) {
		// cell 22, row 10
		e->position = Point(posTile(22), posTile(10));
	}
}