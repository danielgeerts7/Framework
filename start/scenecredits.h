/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef SCENECREDITS_H
#define SCENECREDITS_H

#include "superscene.h"
#include <deque>
#include <fstream>
#include <sstream>

using namespace std;
class SceneCredits: public SuperScene
{
	public:
		SceneCredits();
		virtual ~SceneCredits();

		virtual void update(float deltaTime);

	private:
		BasicEntity* logo;

		BasicEntity* consolecontainer;
		vector<Text*> consoletext;
		deque<string> fulltext;
		unsigned int numlines;
		Timer t;

		void filltext();
		void updateconsoletext();
		int index;
};

#endif /* SCENECREDITS_H */

