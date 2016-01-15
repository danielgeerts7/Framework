/**
* - Copyright 2015 Daniel Geerts <daniel.geerts@live.nl>
*     - Initial commit
*/

#include "pickup.h"

Pickup::Pickup(string pickup) : BasicEntity()
{
	item = pickup;
	if (item == "ammo") {
		this->addSprite("assets/extraammo.tga");
	} else if (item == "health") {
		this->addSprite("assets/extrahealth.tga");
	} else {
		cout << "pickup.cpp the string doenst match" << endl;
	}
}

Pickup::~Pickup()
{
}

string Pickup::getItem() {
	return item;
}