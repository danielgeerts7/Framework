/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef SCENE00_H
#define SCENE00_H

#include <vector>
#include <rt2d/timer.h>
#include "player.h"
#include "superscene.h"
#include "basicentity.h"
#include "bullet.h"
#include "loadtiles.h"
#include "enemie.h"
#include "particlesystem.h"
#include "healthbar.h"
#include "highscorelist.h"
#include "pickup.h"
#include "block.h"

class Scene00: public SuperScene
{
	public:
		Scene00();
		virtual ~Scene00();

		virtual void update(float deltaTime);

		int getscore();
		string getname();
	
	private:

		int posTile(int rowOrCell);

		LoadTiles* background_entity;
		Player* player_entity;
		BasicEntity* gun_player_entity;

		HealthBar* player_healthbar;
		Text* player_health_text;

		Timer t;
		int mouseClickBulletDelay;
		float mouseClickBulletCounter;

		int playerReloadDelay;
		float playerReloadCounter;

		int enemieDelay;
		float enemieCounter;

		bool pressedReloadingForThePlayer;
		bool playerCanShoot;

		int playerRaduis;

		ParticleSystem* p;

		std::vector<ParticleSystem*> particles;
		std::vector<Enemie*> enemies;
		std::vector<Enemie*> deadEnemies;
		std::vector<BasicEntity*> guns_enemies;
		std::vector<Block*> blocks;
		std::vector<BasicEntity*> player_bullets;
		std::vector<BasicEntity*> enemies_bullets;

		std::vector<HealthBar*> enemies_healthbars;

		int maxAmmoInMagazine;
		int currentAmmoInMagazine;
		int currentAmmoInBag;

		int countEnemiesDied;

		int score;
		int currentscore;

		vector<Pickup*> ammunitionpickups;
		vector<Pickup*> healthpickups;

		string firstLetter;
		string secondLetter;
		string thirdLetter;
		string username;
		Text* enterUsername;

		BasicEntity* arrow;

		bool triggerWhenFinished;

		bool numberone = false;
		bool numbertwo = false;
		bool numberthree = false;
		bool pressed = false;
};

#endif /* SCENE00_H */ 
