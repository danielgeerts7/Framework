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
#include "scenehighscore.h"
#include "scenecredits.h"
#include "highscorelist.h"

/// @brief main entry point
int main(void)
{
	// Core instance
	Core core;

	// making a highscorelist
	HighScoreList* highscore = new HighScoreList();

	// setting scene
	SceneMenu* scenemenu = new SceneMenu();
	Scene00* scene00 = new Scene00();
	SceneHighscore* scenehighscore = new SceneHighscore(highscore);
	SceneCredits* scenecredits = new SceneCredits();

	// Create all scenes on the heap and keep a list
	std::vector<SuperScene*> scenes;
	scenes.push_back(scenemenu);
	scenes.push_back(scene00);
	scenes.push_back(scenehighscore);
	scenes.push_back(scenecredits);
	int s = scenes.size();

	// start running with the first Scene
	SuperScene* scene = scenes[0];
	int scenecounter = 0;
	int running = 1;
	bool canAddScoreToTheList = false;

	while (running && core.exitApp() == 0) {
		scenecounter = scene->activescene;
		SuperScene::state state = scene->getState();
		if (scenecounter >= 0 && scenecounter <= 3) {
			if (scene00->getState() == SuperScene::state::START && scene00->isRunning() && !canAddScoreToTheList)
			{
				canAddScoreToTheList = true;
			}
			if ((scene00->getState() == SuperScene::state::WIN || scene00->getState() == SuperScene::state::LOSE) && !scene00->isRunning() && canAddScoreToTheList)
			{
				int newscore = scene00->getscore();
				string newname = scene00->getname();
				highscore->addScore(newscore, newname);
				canAddScoreToTheList = false;
			}
			if (scenemenu->getState() == SuperScene::state::START && scenemenu->isRunning())
			{
				highscore->sortHighScoreList();
			}

			scene = scenes[scenecounter];
			core.run(scene); // update and render the current scene
			core.showFrameRate(5); // show framerate in output every n seconds
			
			//if (glfwWindowShouldClose(core.getRenderer().window()) == 1) { running = 0; }
		}
		if (!scene->isRunning() && scenecounter == -1) {
			running = 0; // check status of Scene every frame
		}
	}

	// delete all scenes
	for (int i = 0; i < s; i++) {
		delete scenes[i];
		scenes[i] = NULL;
	}
	scenes.clear();

	/*
	while (SuperScene::activescene >= 0 && SuperScene::activescene <= 3) {
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
		if (SuperScene::activescene == 2) {
			//CREDITS SCENE
			SceneCredits* credits = new SceneCredits();
			while (credits->isRunning()) {
				core.run(credits);
				core.showFrameRate(5);
			}
			core.cleanup();
			delete credits;
		}
		if (SuperScene::activescene == 3) {
			//HIGHSCORE SCENE
			SceneHighscore* highscore = new SceneHighscore();
			while (highscore->isRunning()) {
				core.run(highscore);
				core.showFrameRate(5);
			}
			core.cleanup();
			delete highscore;
		}
	}
	*/
	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}
