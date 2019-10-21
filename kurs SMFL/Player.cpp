#include "Player.h"

player::player()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(400,200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void player::update()
{
	sprite.setPosition(rect.getPosition());
}

void player::updateMovement()
{
	//Move the sprit -> move up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if(canMoveUp == true)
		{
			//cout << "The UP button is pressed" << endl;
			rect.move(0, -playerMovementSpeed);
			sprite.setTextureRect(sf::IntRect(counterWalking * PixSizeHeroX, PixSizeHeroY * 3, PixSizeHeroX, PixSizeHeroY));
			direction = 1;
			canMoveUp = true;
			canMoveDown = true;
			canMoveRight = true;
			canMoveLeft = true;
		}

	}

	//Move the sprit -> move down
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (canMoveDown == true)
		{
			//cout << "The DOWN button is pressed" << endl;
			rect.move(0, playerMovementSpeed);
			sprite.setTextureRect(sf::IntRect(counterWalking * PixSizeHeroX, PixSizeHeroY * 0, PixSizeHeroX, PixSizeHeroY));
			direction = 2;
			canMoveUp = true;
			canMoveDown = true;
			canMoveRight = true;
			canMoveLeft = true;
		}
	}

	//Move the sprit -> move right
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (canMoveLeft == true)
		{
			//cout << "The RIGHT button is pressed" << endl;
			rect.move(playerMovementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(counterWalking * PixSizeHeroX, PixSizeHeroY * 2, PixSizeHeroX, PixSizeHeroY));
			direction = 3;
			canMoveUp = true;
			canMoveDown = true;
			canMoveRight = true;
			canMoveLeft = true;
		}
	}

	//Move the sprit -> move left
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (canMoveRight == true)
		{
			//cout << "The LEFT button is pressed" << endl;
			rect.move(-playerMovementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(counterWalking * PixSizeHeroX, PixSizeHeroY * 1, PixSizeHeroX, PixSizeHeroY));
			direction = 4;
			canMoveUp = true;
			canMoveDown = true;
			canMoveRight = true;
			canMoveLeft = true;
		}
	}

	counterWalking++;
	if (counterWalking == 3)
	{
		counterWalking = 0;
	}

}