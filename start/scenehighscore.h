/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef SCENEHIGHSCORE_H
#define SCENEHIGHSCORE_H

#include "superscene.h"
#include "highscorelist.h"

class SceneHighscore: public SuperScene
{
public:
	SceneHighscore(HighScoreList* highscore);
	~SceneHighscore();

private:
	Text* t;

	HighScoreList* highscorelist;
	vector<int> v;
};

#endif /*SCENEHIGHSCORE_H*/

