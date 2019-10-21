#pragma once

#include "entity.h"
class Wall : public entity
{
public:
	bool destructable = false;
	int hp = 50;
	bool destroy = false;
	Wall();

	void update();
};

