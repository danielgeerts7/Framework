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

#include "myscene.h"
#include "scene00.h"

/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;

	//Scene00
	Scene00* scene00 = new Scene00();
	while (scene00->isRunning()) {
		core.run(scene00);
		core.showFrameRate(5);
	}
	core.cleanup();
	delete scene00;

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}
