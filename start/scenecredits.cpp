/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "scenecredits.h"


SceneCredits::SceneCredits() : SuperScene()
{
	SuperScene::setState(START);
	text[0]->message("CREDITS: here you can see who made this game!");

//adding dg logo line
	logo = new BasicEntity();
	logo->addLine("assets/dg_logo.line");
	logo->position = Point2(SWIDTH / 10 * 1, SHEIGHT / 10 * 9);
	logo->scale = Point2(1.5, -1.5);

	layers[1]->addChild(logo);
}


SceneCredits::~SceneCredits()
{
// remove dg logo line
	layers[1]->removeChild(logo);
	delete logo;
	logo = NULL;
}

void SceneCredits::update(float deltaTime)
{
	// ###############################################################
	// Make SuperScene do what it needs to do (Escape key stops Scene)
	// ###############################################################
	SuperScene::update(deltaTime);
}