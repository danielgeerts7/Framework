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
		virtual ~SceneHighscore();

		virtual void update(float deltaTime);

	private:
		int tophighscores;
		Text* t;
		HighScoreList* h;
		bool loaded;

		Text* rankText;
		Text* titleNameText;
		Text* highscoreText;

		vector<pair <int, string> > highscoreList;
		vector<Text*> textsRanks;
		vector<Text*> textsnames;
		vector<Text*> textsHighscores;
};

#endif /* SCENEHIGHSCORE_H */

