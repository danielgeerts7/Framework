/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "scenemenu.h"


SceneMenu::SceneMenu() : SuperScene()
{
	text[0]->message("Menu scene: menu of this awesome game!");

	//Text: 'Start'
	textStart = new Text();
	//Button 'Start'
	btnStart = new Button(textStart, "Start");
	btnStart->position.y = 150;
	btnStart->scale = Point(3, 1);
	//Setting text to right pos in button 'Start'
	textStart->position.x = btnStart->position.x - 64;
	textStart->position.y = btnStart->position.y;
	//Adding text and button to the Scene Menu
	layers[1]->addChild(btnStart);
	layers[1]->addChild(textStart);

	//Text: 'Credits'
	textCredits = new Text();
	//Button: 'Credits'
	btnCredits = new Button(textCredits, "Credits");
	btnCredits->position.y = 300;
	btnCredits->scale = Point(4, 1);
	//Setting text to right pos in button 'Credits'
	textCredits->position.x = btnCredits->position.x - 96;
	textCredits->position.y = btnCredits->position.y;
	//Adding text and button to the Scene Menu
	layers[1]->addChild(btnCredits);
	layers[1]->addChild(textCredits);

	//Text: 'Highscore'
	textHighscore = new Text();
	//Button: 'Highscore'
	btnHighscore = new Button(textHighscore, "Highscore");
	btnHighscore->position.y = 450;
	btnHighscore->scale = Point(5, 1);
	//Setting text to right pos in button 'Highscore'
	textHighscore->position.x = btnHighscore->position.x - 128;
	textHighscore->position.y = btnHighscore->position.y;
	//Adding text and button to the Scene Menu
	layers[1]->addChild(btnHighscore);
	layers[1]->addChild(textHighscore);

	//Text: 'Quit'
	textQuit = new Text();
	//Button: 'Quit'
	btnQuit = new Button(textQuit, "Quit");
	btnQuit->position.y = 600;
	btnQuit->scale = Point(2.5, 1);
	//Setting text to right pos in button 'Quit'
	textQuit->position.x = btnQuit->position.x - 48;
	textQuit->position.y = btnQuit->position.y;
	//Adding text and button to the Scene Menu
	layers[1]->addChild(btnQuit);
	layers[1]->addChild(textQuit);
}


SceneMenu::~SceneMenu()
{
	//Removing text and button 'Start'
	layers[1]->removeChild(btnStart);
	layers[1]->removeChild(textStart);
	delete(btnStart);
	delete(textStart);

	//Removing text and button 'Credits'
	layers[1]->removeChild(btnCredits);
	layers[1]->removeChild(textCredits);
	delete(btnCredits);
	delete(textCredits);

	//Removing text and button 'Highscore'
	layers[1]->removeChild(btnHighscore);
	layers[1]->removeChild(textHighscore);
	delete(btnHighscore);
	delete(textHighscore);

	//Removing text and button 'Quit'
	layers[1]->removeChild(btnQuit);
	layers[1]->removeChild(textQuit);
	delete(btnQuit);
	delete(textQuit);
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
	// Checking if the mouse is over the button 'Start'
	// ###############################################################
	if (btnStart->checkIfMouseIsOverBtn(mousepos, btnStart->scale) == 1) {
		btnStart->sprite()->color = BLUE;
		if (input()->getMouseUp(0)) {
			SuperScene::stop();
			SuperScene::activescene = 1;
		}
	} else {
		btnStart->sprite()->color = GRAY;
	}

	// ###############################################################
	// Checking if the mouse is over the button 'Credits'
	// ###############################################################
	if (btnCredits->checkIfMouseIsOverBtn(mousepos, btnCredits->scale) == 1) {
		btnCredits->sprite()->color = BLUE;
		if (input()->getMouseUp(0)) {
			SuperScene::stop();
			SuperScene::activescene = 2;
		}
	} else {
		btnCredits->sprite()->color = GRAY;
	}

	// ###############################################################
	// Checking if the mouse is over the button 'Highscore'
	// ###############################################################
	if (btnHighscore->checkIfMouseIsOverBtn(mousepos, btnHighscore->scale) == 1) {
		btnHighscore->sprite()->color = BLUE;
		if (input()->getMouseUp(0)) {
			SuperScene::stop();
			SuperScene::activescene = 3;
		}
	}
	else {
		btnHighscore->sprite()->color = GRAY;
	}

	// ###############################################################
	// Checking if the mouse is over the button 'Quit'
	// ###############################################################
	if (btnQuit->checkIfMouseIsOverBtn(mousepos, btnQuit->scale) == 1) {
		btnQuit->sprite()->color = BLUE;
		if (input()->getMouseUp(0)) {
			SuperScene::stop();
			SuperScene::activescene = -1;
		}
	}
	else {
		btnQuit->sprite()->color = GRAY;
	}
}