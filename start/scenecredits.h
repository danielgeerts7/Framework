/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef SCENECREDITS_H
#define SCENECREDITS_H

#include "superscene.h"

class SceneCredits: public SuperScene
{
	public:
		SceneCredits();
		virtual ~SceneCredits();

		virtual void update(float deltaTime);

	private:
		BasicEntity* logo;
};

#endif /* SCENECREDITS_H */

