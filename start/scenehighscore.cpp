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

	/* RANKS */
	for (int i = 0; i < tophighscores; i++) {
		Text* tr = new Text();
		tr->scale = Point2(0.75, 0.75);
		tr->position.x = SWIDTH / 2 - 400;
		layers[1]->addChild(tr);
		textsRanks.push_back(tr);
	}

	/* NAMES */
	for (int i = 0; i < tophighscores; i++) {
		Text* tn = new Text();
		tn->scale = Point2(0.75, 0.75);
		tn->position.x = SWIDTH / 2 - 200;
		layers[1]->addChild(tn);
		textsnames.push_back(tn);
	}

	/* HIGHSCORES */
	for (int i = 0; i < tophighscores; i++) {
		Text* t = new Text();
		t->scale = Point2(0.75, 0.75);
		t->position.x = SWIDTH / 2 + 100;
		layers[1]->addChild(t);
		textsHighscores.push_back(t);
	}
	h = highscore;

	loaded = false;

	/* RANK */
	rankText = new Text();
	rankText->message("RANK");
	rankText->position.x = textsRanks[0]->position.x;
	rankText->position.y = 150;
	layers[1]->addChild(rankText);

	/* NAME */
	titleNameText = new Text();
	titleNameText->message("NAME");
	titleNameText->position.x = textsnames[0]->position.x;
	titleNameText->position.y = 150;
	layers[1]->addChild(titleNameText);

	/* HIGHSCORE */
	highscoreText = new Text();
	highscoreText->message("HIGHSCORE");
	highscoreText->position.x = textsHighscores[0]->position.x;
	highscoreText->position.y = 150;
	layers[1]->addChild(highscoreText);

//reset button
	resetText = new Text();
	resetBtn = new Button(resetText, "Reset list!");
	resetBtn->position = Point2(200, 800);
	resetBtn->scale = Point2(6, 1);
	resetText->position.x = resetBtn->position.x - 150;
	resetText->position.y = resetBtn->position.y;
	layers[1]->addChild(resetBtn);
	layers[1]->addChild(resetText);

//clear button
	clearText = new Text();
	clearBtn = new Button(clearText, "Clear list!");
	clearBtn->position = Point2(200, 900);
	clearBtn->scale = Point2(6, 1);
	clearText->position.x = clearBtn->position.x - 150;
	clearText->position.y = clearBtn->position.y;
	layers[1]->addChild(clearBtn);
	layers[1]->addChild(clearText);
}


SceneHighscore::~SceneHighscore()
{
	/* RANKS */
	for (int i = 0; i < textsRanks.size(); i++) {
		layers[1]->removeChild(textsRanks[i]);
		delete textsRanks[i];
		textsRanks[i] = NULL;
	}
	/* NAMES */
	for (int i = 0; i < textsnames.size(); i++) {
		layers[1]->removeChild(textsnames[i]);
		delete textsnames[i];
		textsnames[i] = NULL;
	}
	/* HIGHSCORES */
	for (int i = 0; i < textsHighscores.size(); i++) {
		layers[1]->removeChild(textsHighscores[i]);
		delete textsHighscores[i];
		textsHighscores[i] = NULL;
	}

	layers[1]->removeChild(rankText);
	layers[1]->removeChild(titleNameText);
	layers[1]->removeChild(highscoreText);
	delete rankText;
	delete titleNameText;
	delete highscoreText;
	rankText = NULL;
	titleNameText = NULL;
	highscoreText = NULL;

//remove text
	layers[1]->removeChild(resetText);
	layers[1]->removeChild(clearText);
	delete resetText;
	delete clearText;
	resetText = NULL;
	clearText = NULL;

//remove buttons
	layers[1]->removeChild(resetBtn);
	layers[1]->removeChild(clearBtn);
	delete resetBtn;
	delete clearBtn;
	resetBtn = NULL;
	clearBtn = NULL;
}

void SceneHighscore::update(float deltaTime)
{
	// ###############################################################
	// Make SuperScene do what it needs to do (Escape key stops Scene)
	// ###############################################################
	SuperScene::update(deltaTime);
	if (highscoreList != h->sortHighScoreList()) {
		highscoreList = h->sortHighScoreList();
		loaded = false;
	}

	if (!loaded) {
		int listsize = highscoreList.size();
		if (listsize >= 10) {
			listsize = 10;
		}

		for (int i = 0; i < listsize; i++) {
			/* RANKS */
			string RANK = " ";
			if (i < 9) {
				RANK.append(" ");
				RANK.append(to_string(i + 1));
			}
			else if (i == 9) {
				RANK.append(to_string(i + 1));
			}
			RANK.append(". ");
			textsRanks[i]->message(RANK);
			textsRanks[i]->position.y = 225 + (50 * i);

			/* NAMES */
			string NAME = "";
			NAME.append(highscoreList[i].second);
			textsnames[i]->message(NAME);
			textsnames[i]->position.y = 225 + (50 * i);

			/* HIGHSCORES */
			string HIGHSCORE = "";
			HIGHSCORE.append(to_string(highscoreList[i].first));
			textsHighscores[i]->message(HIGHSCORE);
			textsHighscores[i]->position.y = 225 + (50 * i);
		}
		loaded = true;
	}

	// ###############################################################
	// Getting mouse position
	// ###############################################################
	mousePosX = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	mousePosY = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mousepos = Point2(mousePosX, mousePosY);

	if (resetBtn->checkIfMouseIsOverBtn(mousepos, resetBtn->scale) == 1) {
		resetBtn->sprite()->color = BLUE;
		if (input()->getMouseUp(0)) {
			h->resetHighScoreList();
		}
	}
	else {
		resetBtn->sprite()->color = GRAY;
	}

	if (clearBtn->checkIfMouseIsOverBtn(mousepos, clearBtn->scale) == 1) {
		clearBtn->sprite()->color = BLUE;
		if (input()->getMouseUp(0)) {
			h->clearHighScoreList();

			int namesize = textsnames.size();
		}
	}
	else {
		clearBtn->sprite()->color = GRAY;
	}
}