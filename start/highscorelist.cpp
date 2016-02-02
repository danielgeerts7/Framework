/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "highscorelist.h"


HighScoreList::HighScoreList()
{
	string line, cell;
	ifstream myfile("assets/highscore_list.csv");

	//check if file is open
	if (myfile.is_open()) {
		while (getline(myfile, line))
		{
			cout << "highscore line: " << line << endl;
			stringstream  lineStream(line);
			while (getline(lineStream, cell, ','))
			{
				int a = atoi(cell.c_str());

				if (a == 0) {
					cell.resize(3);
					tempName.emplace_back(cell);
				} else {
					tempHighscore.emplace_back(a);
				}
			}
		}
		myfile.close();
	} else {
		// if file cannot be found make a new file
		std::ofstream outfile("assets/highscore_list.csv");

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

		// filling the new file
		int listSize = highscoreList.size();
		for (int i = 0; i < listSize; i++) {
			outfile << highscoreList[i].first << "," << highscoreList[i].second << std::endl;
		}
		outfile.close();
	}

	int tempSizeHighscore = tempHighscore.size();
	int tempSizeName = tempName.size();
	if (tempSizeHighscore == tempSizeName) {
		for (int i = 0; i < tempSizeHighscore; i++) {
			highscoreList.emplace_back(tempHighscore[i], tempName[i]);
		}
	}
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

	std::ofstream outfile("assets/highscore_list.csv");

	//check if file is open
	if (outfile.is_open()) {

		string Result;

		stringstream convert;
		convert << score;
		Result = convert.str();

		int listSize = highscoreList.size();

		for (int i = 0; i < listSize; i++) {
			outfile << highscoreList[i].first << "," << highscoreList[i].second << std::endl;
		}
		outfile.close();
	}
}

vector<pair <int, string> > HighScoreList::sortHighScoreList() {
	sort(highscoreList.begin(), highscoreList.end(), compare);
	return highscoreList;
}

void HighScoreList::resetHighScoreList() {
	//TODO reset the highscorelist to the default HighScoreList (Delete and fill Vector)
}

void HighScoreList::clearHighScoreList() {
	//TODO clear the whole Highscorelist and clear the scene
}