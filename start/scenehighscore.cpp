/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "scenehighscore.h"


SceneHighscore::SceneHighscore(HighScoreList* highscore) : SuperScene()
{
	SuperScene::setState(START);

	tophighscores = 10;

	text[0]->message("HIGHSCORE: here you can see who is the best!");
	for (int i = 0; i < tophighscores; i++) {
		Text* t = new Text();
		t->scale = Point2(0.75, 0.75);
		t->position.x = SWIDTH / 2 - 100;
		layers[1]->addChild(t);
		texts.push_back(t);
	}
	h = highscore;

	loaded = false;
}


SceneHighscore::~SceneHighscore()
{
	for (int i = 0; i < tophighscores; i++) {
		layers[1]->removeChild(texts[i]);
		delete texts[i];
		texts[i] == NULL;
	}
}

void SceneHighscore::update(float deltaTime)
{
	// ###############################################################
	// Make SuperScene do what it needs to do (Escape key stops Scene)
	// ###############################################################
	SuperScene::update(deltaTime);
	if (highscoreList != h->getHighScoreList()) {
		highscoreList = h->getHighScoreList();
		loaded = false;
	}
	if (!loaded) {
		for (int i = 0; i < tophighscores; i++) {
			string hs = "";
			hs.append(to_string(i + 1));
			hs.append(". ");
			hs.append(to_string(highscoreList[i]));
			texts[i]->message(hs);
			texts[i]->position.y = 150 + (50 * i);
		}
		loaded = true;
	} 
}