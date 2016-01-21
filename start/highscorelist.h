/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>	// std::sort

using namespace std;
class HighScoreList
{
public:
	HighScoreList();
	~HighScoreList();

	void addScore(int score, string name);
	vector<pair <int, string> > sortHighScoreList();

private:
	vector<int> tempHighscore;
	vector<string> tempName;
	vector<pair <int, string> > highscoreList;
};

#endif /* HIGHSCORE_H */

