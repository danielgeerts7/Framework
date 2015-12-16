/**
* This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
*
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


class Scene00: public SuperScene
{
	public:
		Scene00();
		virtual ~Scene00();

		virtual void update(float deltaTime);
	
	private:

		LoadTiles* background_entity;
		Player* player_entity;
		BasicEntity* gun_player_entity;

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
		std::vector<BasicEntity*> guns_enemies;
		std::vector<BasicEntity*> blocks;
		std::vector<BasicEntity*> player_bullets;
		std::vector<BasicEntity*> enemies_bullets;
		std::vector<BasicEntity*>::iterator iterator_player_bullets;
		std::vector<BasicEntity*>::iterator iterator_enemies_bullets;

		int maxAmmoInMagazine;
		int currentAmmoInMagazine;
		int currentAmmoInBag;
};

#endif /* SCENE00_H */ 
