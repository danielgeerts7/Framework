/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "highscorelist.h"


HighScoreList::HighScoreList()
{
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	int i;
	int j;

	highscoreList.push_back(a);
	highscoreList.push_back(b);
	highscoreList.push_back(c);
	highscoreList.push_back(d);
	highscoreList.push_back(e);
	highscoreList.push_back(f);
	highscoreList.push_back(g);
	highscoreList.push_back(h);
	highscoreList.push_back(i);
	highscoreList.push_back(j);

	highscoreList[0] = 1;
	highscoreList[1] = 2;
	highscoreList[2] = 3;
	highscoreList[3] = 4;
	highscoreList[4] = 5;
	highscoreList[5] = 6;
	highscoreList[6] = 7;
	highscoreList[7] = 8;
	highscoreList[8] = 9;
	highscoreList[9] = 10;
}


HighScoreList::~HighScoreList()
{
}

void HighScoreList::addScore(int score) {
	highscoreList.push_back(score);
	sort(highscoreList.begin(), highscoreList.end());
}

vector<int> HighScoreList::getHighScoreList() {
	return highscoreList;
}