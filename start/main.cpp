/**
 * Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
 *
 * @brief Description of My Awesome Game.
 *
 * @file main.cpp
 *
 * @mainpage My Awesome Game
 *
 * @section intro Introduction
 *
 * Detailed description of My Awesome Game.
 *
 * There's even a second paragraph.
 */
#include <rt2d/core.h>

#include "scenemenu.h"
#include "scene00.h"

/// @brief main entry point
int main(void)
{
	// Core instance
	Core core;
	while (SuperScene::activescene >= 0 && SuperScene::activescene <= 1) {
		if (SuperScene::activescene == 0) {
			//Scene Menu
			SceneMenu* menu = new SceneMenu();
			while (menu->isRunning()) {
				core.run(menu);
				core.showFrameRate(5);
			}
			core.cleanup();
			delete menu;
		}
		if (SuperScene::activescene == 1) {
			//Scene00
			Scene00* scene00 = new Scene00();
			while (scene00->isRunning()) {
				core.run(scene00);
				core.showFrameRate(5);
			}
			core.cleanup();
			delete scene00;
		}
	}

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}
