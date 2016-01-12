/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <vector>
#include <algorithm>

using namespace std;
class HighScore
{
public:
	HighScore();
	~HighScore();

	void setHighScore(int score);
	int getHighScore();
	void addScore(int score);

	vector<int> addCurrentHighScoreToList();

private:
	int highscore;
	vector<int> top10list;
};

#endif /* HIGHSCORE_H */

