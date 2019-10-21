#pragma once

#include "entity.h"


class projectille : public entity
{
public:
	int movementSpeed = 8;
	int attackDamage = 2;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	bool destroy = false;
	int counterLifeTime = 0;
	int counterAnimation = 0;
	int LifeTime = 150;
	bool enemyProjectile = false;

	projectille();

	void update();

	//void updateMovement();
};

