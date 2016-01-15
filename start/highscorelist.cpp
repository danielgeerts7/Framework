/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "highscorelist.h"


HighScoreList::HighScoreList()
{
	int a = 60;
	int b = 50;
	int c = 10;
	int d = 20;
	int e = 80;
	int f = 70;
	int g = 100;
	int h = 30;
	int i = 40;
	int j = 90;

	string aa = "aaa";
	string bb = "aaa";
	string cc = "aaa";
	string dd = "aaa";
	string ee = "aaa";
	string ff = "aaa";
	string gg = "aaa";
	string hh = "aaa";
	string ii = "aaa";
	string jj = "aaa";

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

bool compare(const pair<int, string>&i, const pair<int, string>&j)
{
	return i.first > j.first;
}

void HighScoreList::addScore(int score, string name) {
	highscoreList.emplace_back(score, name);
	sort(highscoreList.begin(), highscoreList.end(), compare);
}

vector<pair <int, string> > HighScoreList::sortHighScoreList() {
	sort(highscoreList.begin(), highscoreList.end(), compare);
	return highscoreList;
}