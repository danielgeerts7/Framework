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
}
