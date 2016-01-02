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
	~SceneMenu();

private:
	Button* btnStart;
	Button* btnCredits;
	Button* btnHighscore;
	Button* btnQuit;
	Text* textStart;
};

#endif /*SCENEMENU_H*/