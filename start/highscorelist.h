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

	void setHighScore(int score);
	int getHighScore();
	void addScore(int score);

	vector<int> getCurrentHighScoreToList();

private:
	int highscore;
	vector<int> top10list;
};

#endif /* HIGHSCORE_H */

