#pragma once

#include "entity.h"
#include "Player.h"
#include "random.h"

class player;

class Enemy : public entity
{
public:
	Enemy();

	void update();

	void updateMovement();

	Enemy &createEnemy(int caseInt);

	bool getAlive()
	{
		return m_alive;
	}

	void setAlive(bool alive)
	{
		m_alive = alive;
	}

	int getHp()
	{
		return m_hp;
	}

	void setHp(int hp)
	{
		m_hp = hp;
	}

	void decreaseHP()
	{
		m_hp--;
	}

	void setAttackDamage(int attackDamage)
	{
		m_attackDamage = attackDamage;
	}

	int getAttackDamage()
	{
		return m_attackDamage;
	}

	int getDirection()
	{
		return direction;
	}

	void setDirection(int dir) { direction = dir; }

	int getMaxHp()
	{
		return m_maxhp;
	}

	void setMaxHp(int maxHp) { m_maxhp = maxHp; }

	bool getIsBlood() { return m_isBlood; }
	void setIsBlood(bool isBlood) {m_isBlood = isBlood;}

	int getBloodCounter() { return m_bloodCounter; }
	void setBloodCounter(int bloodCounter) { m_bloodCounter = bloodCounter; }
	int getBloodLifeTime() { return m_bloodLifeTime; }

	bool getAggroed() { return m_aggroed; }
	void setAggroed(bool aggroed) { m_aggroed = aggroed; }

	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveRight = true;
	bool canMoveLeft = true;

	int spriteX = 32;
	int spriteY = 32;
	int spriteXStart = 3 * 32;
	int spriteYStart = 0;

	bool isBoss = false;

private:
	int movementSpeed = 1;
	int movementLength = 100;
	int m_maxhp = 20;
	int m_hp = m_maxhp;
	int setMovement = 0;
	int counterWalking = 0;
	int m_attackDamage = 2;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	int counter = 0;
	bool m_alive = true;
	bool m_isBlood = false;
	int m_bloodCounter = 0;
	int m_bloodLifeTime = 400;
	int m_aggroed = false;
};