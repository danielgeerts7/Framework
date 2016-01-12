/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "highscore.h"


HighScore::HighScore()
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

	top10list[0] = 225;
	top10list[1] = 175;
	top10list[2] = 160;
	top10list[3] = 150;
	top10list[4] = 130;
	top10list[5] = 120;
	top10list[6] = 50;
	top10list[7] = 30;
	top10list[8] = 15;
	top10list[9] = 10;
}


HighScore::~HighScore()
{
}

void HighScore::setHighScore(int score) {
	this->highscore = score;
}

int HighScore::getHighScore() {
	return this->highscore;
}

void HighScore::addScore(int score) {
	this->highscore = this->highscore + score;
}

vector<int> HighScore::addCurrentHighScoreToList() {
	for (int i = 0; i < top10list.size(); i++) {
		if (this->highscore > top10list[i]) {
			if (top10list.size() <= 9) {
				top10list.push_back(this->highscore);
				sort(top10list.begin(), top10list.end());
			}
		}
	}
	return top10list;
}