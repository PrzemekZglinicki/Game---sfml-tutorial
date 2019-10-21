#include "projectille.h"

projectille::projectille()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Green);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}

void projectille::update()
{
	if (direction == 1)
	{
		rect.move(0, -movementSpeed); // up
		sprite.setTextureRect(sf::IntRect(counterAnimation*32, 3*32, 32, 32));
	}
	else if (direction == 2)
	{
		rect.move(0, movementSpeed); // Down
		sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 0, 32, 32));
	}
	else if (direction == 3)
	{
		rect.move(movementSpeed, 0); //Left
		sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 1 * 32, 32, 32));
	}
	else
	{
		rect.move(-movementSpeed, 0); //Right
		sprite.setTextureRect(sf::IntRect(counterAnimation * 32, 2 * 32, 32, 32));
	}

	counterLifeTime++;
	if (counterLifeTime >= LifeTime)
	{
		destroy = true;
	}

	counterAnimation++;
	if (counterAnimation >= 2)
	{
		counterAnimation = 0;
	}

	// Sprite set at rect
	sprite.setPosition(rect.getPosition());

}
