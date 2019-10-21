#include "Enemy.h"

Enemy::Enemy()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(200, 200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(spriteXStart, spriteYStart, spriteX, spriteY));
}


void Enemy::update()
{
	sprite.setPosition(rect.getPosition());
	text.setPosition(rect.getPosition().x - rect.getSize().x/2, rect.getPosition().y - rect.getSize().y/2 -5);

	if (m_isBlood == true)
	{
		m_bloodCounter++;

		if (m_bloodCounter >= m_bloodLifeTime)
		{
			m_alive = false;
		}
	}
}

void Enemy::updateMovement()
{
	//Move the sprit -> move up
	if (direction == 1)
	{
		if (canMoveUp == true)
		{
			rect.move(0, -movementSpeed);
			sprite.setTextureRect(sf::IntRect(spriteX * counterWalking + spriteXStart, spriteY * 3 + spriteYStart, spriteX, spriteY));
			canMoveUp = true;
			canMoveDown = true;
			canMoveRight = true;
			canMoveLeft = true;
		}
	}
	//Move the sprit -> move down
	else if (direction == 2)
	{
		if (canMoveDown == true)
		{
			rect.move(0, movementSpeed);
			sprite.setTextureRect(sf::IntRect(spriteX * counterWalking + spriteXStart, spriteY * 0 + spriteYStart, spriteX, spriteY));
			canMoveUp = true;
			canMoveDown = true;
			canMoveRight = true;
			canMoveLeft = true;
		}
	}
	//Move the sprit -> move left
	else if (direction == 3)
	{
		if (canMoveLeft == true)
		{
			rect.move(movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(spriteX * counterWalking + spriteXStart, spriteY*2 + spriteYStart, spriteX, spriteY));
			canMoveUp = true;
			canMoveDown = true;
			canMoveRight = true;
			canMoveLeft = true;
		}
	}
	//Move the sprit -> move right
	else if (direction == 4)
	{
		if (canMoveRight == true)
		{
			rect.move(-movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(spriteX * counterWalking + spriteXStart, spriteY * 1 + spriteYStart, spriteX, spriteY));
			canMoveUp = true;
			canMoveDown = true;
			canMoveRight = true;
			canMoveLeft = true;
		}
	}
	else
	{
		//Nothing happend
	}
	
	counterWalking++;
	if (counterWalking == 2)
	{
		counterWalking = 0;
	}

	int setMovement = generateRandom(1000);

	if (setMovement <= 500)
	{
		int movementLength = generateRandom(100) + 50;
	}
	
	if(m_aggroed == false)
	{
		counter++;
		if (counter >= movementLength)
		{
			counter = 0;
			direction = generateRandom(10);
		}
	}

}

Enemy &Enemy::createEnemy(int caseInt)
{
	int tempRandom = generateRandom(5);

	switch (caseInt)
	{
	case 1:
		// Normal goblin
		setMaxHp(15);
		setHp(15);
		m_attackDamage = 2;
		movementSpeed = 1;
		spriteXStart = 3 * 32;
		spriteYStart = 0;
		sprite.setTextureRect(sf::IntRect(spriteXStart, spriteYStart, spriteX, spriteY));
		break;
	case 2:
		//Armed goblin
		setMaxHp(30);
		setHp(30);
		m_attackDamage = 3;
		movementSpeed = 1;
		spriteXStart = 6 * 32;
		spriteYStart = 0;
		sprite.setTextureRect(sf::IntRect(spriteXStart, spriteYStart, spriteX, spriteY));
		break;
	case 3:
		//Armed Goblin2 enemy
		setMaxHp(25);
		setHp(25);
		m_attackDamage = 3;
		movementSpeed = 1;
		spriteXStart = 9 * 32;
		spriteYStart = 0;
		sprite.setTextureRect(sf::IntRect(spriteXStart, spriteYStart, spriteX, spriteY));
		break;
	case 4:
		//Robed Goblin enemy
		setMaxHp(30);
		setHp(30);
		m_attackDamage = 4;
		movementSpeed = 4;
		spriteXStart = 32 * 0;
		spriteYStart = 32 * 4;
		sprite.setTextureRect(sf::IntRect(spriteXStart, spriteYStart, spriteX, spriteY));
		break;
	case 5:
		//Leader of Goblins enemy
		setHp(40);
		setMaxHp(40);
		m_attackDamage = 4;
		movementSpeed = 2;
		spriteXStart = 3 * 32;
		spriteYStart = 4 * 32;
		sprite.setTextureRect(sf::IntRect(spriteXStart, spriteYStart, spriteX, spriteY));
		break;
	case 6:
		//Leader of Goblins enemy
		setMaxHp(20);
		setHp(20);
		m_attackDamage = 3;
		movementSpeed = 1;
		spriteXStart = 6 * 32;
		spriteYStart = 4 * 32;
		sprite.setTextureRect(sf::IntRect(spriteXStart, spriteYStart, spriteX, spriteY));
	break;
		default:
		break;
	}

	return *this;
}