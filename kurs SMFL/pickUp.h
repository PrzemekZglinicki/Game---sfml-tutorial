#pragma once

#include "entity.h"

class pickup : public entity
{
private:
	bool m_isCoin = false;
	bool m_isPowerUp = false;
	bool m_isNovaAttack = false;
	bool m_inShop = false;
	bool m_isHpShield = false;
	bool m_destroy = false;
	bool m_isFood = false;
	bool m_isPotion = false;
	int m_coinValue = 5;
	int m_cost = 10;

public:
	pickup();
	
	void update();

	int getCoinValue() { return m_coinValue; }
	void setCoinValue(int coinValue) { m_coinValue = coinValue; }

	bool getDestroy() { return m_destroy;}
	void setDestroy(bool destroy) { m_destroy = destroy; }
	
	bool getIsCoin() { return m_isCoin; }
	void setIsCoin(bool isCoin) { m_isCoin = isCoin; }

	bool getIsPowerUp() { return m_isPowerUp; }
	void setIsPowerUp(bool isPowerUp) { m_isPowerUp = isPowerUp; }

	bool getIsNovaAttack() { return m_isNovaAttack; }
	void setIsNovaAttack(bool isNovaAttack) { m_isNovaAttack = isNovaAttack; }

	bool getIsHpShield() { return m_isHpShield; }
	void setIsHpShield(bool isHpShield) { m_isHpShield = isHpShield; }

	bool getInShop() { return m_inShop; }
	void setInShop(bool inShop) { m_inShop = inShop; }

	bool getIsPotion() { return m_isPotion; }
	void setIsPotion(bool isPotion) { m_isPotion = isPotion; }

	bool getIsFood() { return m_isFood; }
	void setIsFood(bool isFood) { m_isFood = isFood; }

	int getCost() { return m_cost; }
	void setCost(int cost) { m_cost = cost; }
};