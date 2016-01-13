/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "scenecredits.h"


SceneCredits::SceneCredits() : SuperScene()
{
	SuperScene::setState(START);
	text[0]->message("CREDITS: here you can see who made this game!");
}


SceneCredits::~SceneCredits()
{
}

void SceneCredits::update(float deltaTime)
{
	// ###############################################################
	// Make SuperScene do what it needs to do (Escape key stops Scene)
	// ###############################################################
	SuperScene::update(deltaTime);
}