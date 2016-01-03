/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef SCENEMENU_H
#define SCENEMENU_H

#include "superscene.h"
#include "basicentity.h"
#include "button.h"

class SceneMenu: public SuperScene
{
public:
	SceneMenu();
	virtual ~SceneMenu();

	virtual void update(float deltaTime);

private:
	Button* btnStart;
	Button* btnCredits;
	Button* btnHighscore;
	Button* btnQuit;
	Text* textStart;

	int mousePosX;
	int mousePosY;
};

#endif /*SCENEMENU_H*/