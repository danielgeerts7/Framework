/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "highscorelist.h"


HighScoreList::HighScoreList()
{
	highscore = 0;
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

	top10list.push_back(a);
	top10list.push_back(b);
	top10list.push_back(c);
	top10list.push_back(d);
	top10list.push_back(e);
	top10list.push_back(f);
	top10list.push_back(g);
	top10list.push_back(h);
	top10list.push_back(i);
	top10list.push_back(j);

	top10list[0] = 420;
	top10list[1] = 1337;
	top10list[2] = 12;
	top10list[3] = 42;
	top10list[4] = 130;
	top10list[5] = 83;
	top10list[6] = 5;
	top10list[7] = 32310;
	top10list[8] = 150;
	top10list[9] = 10000;
}


HighScoreList::~HighScoreList()
{
}

void HighScoreList::setHighScore(int score) {
	this->highscore = score;
}

int HighScoreList::getHighScore() {
	return this->highscore;
}

void HighScoreList::addScore(int score) {
	this->highscore = this->highscore + score;
}

vector<int> HighScoreList::getCurrentHighScoreToList() {
	top10list.push_back(this->highscore);
	sort(top10list.begin(), top10list.end());
	return top10list;
}