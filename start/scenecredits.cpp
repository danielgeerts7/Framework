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

	numlines = 24;
	index = 0;

	// Create an Entity with a custom pivot point.
	consolecontainer = new BasicEntity();

	// txt is ~830px wide
	int left = (SWIDTH - 830) / 2;
	for (unsigned int i = 0; i < numlines; i++) {
		Text* line = new Text();
		line->scale = Point2(0.45f, 0.45f);
		line->position = Point2(left, 160 + i * 25);
		line->message("", WHITE);

		consoletext.push_back(line);
		consolecontainer->addChild(line);
	}
	filltext();

	layers[1]->addChild(consolecontainer);

	layers[1]->addChild(logo);
}


SceneCredits::~SceneCredits()
{
// remove dg logo line
	layers[1]->removeChild(logo);
	delete logo;
	logo = NULL;

	int ts = consoletext.size();
	for (int i = 0; i<ts; i++) {
		consolecontainer->removeChild(consoletext[i]);
		delete consoletext[i];
		consoletext[i] = NULL;
	}
	consoletext.clear();

	// deconstruct and delete the Tree
	layers[1]->removeChild(consolecontainer);

	delete consolecontainer;
}

void SceneCredits::update(float deltaTime)
{
	// ###############################################################
	// Make SuperScene do what it needs to do (Escape key stops Scene)
	// ###############################################################
	SuperScene::update(deltaTime);

	
	// ###############################################################
	// Load text once
	// ###############################################################
	static int first = 1;
	if (first) {
		updateconsoletext();
		first = 0;
	}
}


void SceneCredits::updateconsoletext()
{
	// ###############################################################
	// Fill consoletext with fulltext
	// ###############################################################
	unsigned int s = fulltext.size();
	int maxid = s - numlines;
	if (index > maxid) {
		index = maxid;
	}
	for (unsigned int i = 0; i < numlines; i++) {
		if (i == 0 || i == 16) {
			consoletext[i]->message(fulltext[index + i], ORANGE);
			consoletext[i]->scale = Point2(0.7f, 0.7f);
		} else {
			consoletext[i]->message(fulltext[index + i], WHITE);
		}
	}
}

void SceneCredits::filltext()
{
	fulltext.clear();
	std::ifstream infile("assets/howToPlay.txt");
	std::string line;
	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		fulltext.push_back(line);
	}
}