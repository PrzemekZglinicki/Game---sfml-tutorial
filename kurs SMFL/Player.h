#pragma once

#include "entity.h"

class player : public entity
{
private:
	int PixSizeHeroX = 32;
	int PixSizeHeroY = 32;

public:
	int playerMovementSpeed = 4;
	int counterWalking = 0;
	int attackDamage = 2;
	bool powerUpLevel = false;
	bool novaAttack = false;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveRight = true;
	bool canMoveLeft = true;
	int HP = 25;
	int maxHP = 10;
	int gil = 0;

	player();
	
	void update();

	sf::Vector2f MYFgetPosition()
	{
		return this->rect.getPosition();
	}

	void updateMovement();

	friend class Enemy;
};