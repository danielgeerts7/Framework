/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "scenehighscore.h"


SceneHighscore::SceneHighscore(HighScoreList* highscore) : SuperScene()
{
	this->highscorelist = highscore;

	text[0]->message("HIGHSCORE: here you can see who is the best!");
	t = new Text();

	v = highscorelist->getCurrentHighScoreToList();

	for (int i = 0; i < 10; i++) {
		string hs = "";
		hs.append(to_string(i+1));
		hs.append(". ");
		hs.append(to_string(v[i]));
		text[5+i]->message(hs);
	}
}


SceneHighscore::~SceneHighscore()
{
}
