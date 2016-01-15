/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#ifndef PICKUP_H
#define PICKUP_H

#include "basicentity.h";

using namespace std;
class Pickup : public BasicEntity
{
	public:
		Pickup(string pickup);
		~Pickup();

		string getItem();

	private:
		string item;
};

#endif /* PICKUP_H */