/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "highscorelist.h"


HighScoreList::HighScoreList()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;
	int f = 60;
	int g = 70;
	int h = 80;
	int i = 90;
	int j = 100;

	string aa = "aaa";
	string bb = "bbb";
	string cc = "ccc";
	string dd = "ddd";
	string ee = "eee";
	string ff = "fff";
	string gg = "ggg";
	string hh = "hhh";
	string ii = "iii";
	string jj = "jjj";

	highscoreList.emplace_back(a, aa);
	highscoreList.emplace_back(b, bb);
	highscoreList.emplace_back(c, cc);
	highscoreList.emplace_back(d, dd);
	highscoreList.emplace_back(e, ee);
	highscoreList.emplace_back(f, ff);
	highscoreList.emplace_back(g, gg);
	highscoreList.emplace_back(h, hh);
	highscoreList.emplace_back(i, ii);
	highscoreList.emplace_back(j, jj);
}


HighScoreList::~HighScoreList()
{
}

void HighScoreList::addScore(int score, string name) {
	highscoreList.emplace_back(score, name);
	sort(highscoreList.begin(), highscoreList.end());
}

vector<pair <int, string> > HighScoreList::getHighScoreList() {
	return highscoreList;
}