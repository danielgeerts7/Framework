/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef BLOCK_H
#define BLOCK_H

#include "basicentity.h"

class Block : public BasicEntity
{
	public:
		Block();
		~Block();
		void baiscEntityCollidWithBlock(BasicEntity * other, int thisRadius, int otherRadius);
};

#endif /* BLOCK_H */