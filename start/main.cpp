/**
 * Copyright 2015 Your Name <you@yourhost.com>
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

	Scene00* scene00 = new Scene00();
	while (scene00->isRunning()) {
		core.run(scene00);
		core.showFrameRate(5);
	}

	delete scene00;

	/*
	// Scene01
	MyScene* myscene = new MyScene(); // create Scene on the heap
	while(myscene->isRunning()) { // check status of Scene every frame
		core.run(myscene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
	}
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete myscene; // delete Scene and everything in it from the heap to make space for next Scene

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.
	*/
	return 0;
}
