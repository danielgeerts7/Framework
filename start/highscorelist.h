/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <vector>
#include <algorithm>

using namespace std;
class HighScoreList
{
public:
	HighScoreList();
	~HighScoreList();

	void addScore(int score);
	vector<int> getHighScoreList();

private:
	vector<int> highscoreList;
};

#endif /* HIGHSCORE_H */

