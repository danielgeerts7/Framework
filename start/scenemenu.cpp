/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "scenemenu.h"


SceneMenu::SceneMenu() : SuperScene()
{
	text[0]->message("Menu scene: menu of this awesome game!");

	textStart = new Text();

	btnStart = new Button(textStart, "Start");
	btnStart->position.y = 150;
	btnStart->scale = Point(3, 1);

	textStart->position.x = btnStart->position.x - 64;
	textStart->position.y = btnStart->position.y;

	layers[1]->addChild(btnStart);
	layers[1]->addChild(textStart);
}


SceneMenu::~SceneMenu()
{
	layers[1]->removeChild(btnStart);
	layers[1]->removeChild(textStart);
	delete(btnStart);
	delete(textStart);
}

void SceneMenu::update(float deltaTime)
{
	// ###############################################################
	// Make SuperScene do what it needs to do (Escape key stops Scene)
	// ###############################################################
	SuperScene::update(deltaTime);

	// ###############################################################
	// Getting mouse position
	// ###############################################################
	mousePosX = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	mousePosY = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mousepos = Point2(mousePosX, mousePosY);

	// ###############################################################
	// Checking is the mouse if over the button
	// ###############################################################
	if (btnStart->checkIfMouseIsOverBtn(mousepos, btnStart->scale) == 1) {
		//TODO go to next scene
		btnStart->sprite()->color = BLUE;
	}
	else {
		btnStart->sprite()->color = GRAY;
	}
}