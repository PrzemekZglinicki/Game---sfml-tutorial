#include "pickUp.h"

pickup::pickup()
{
	rect.setSize(sf::Vector2f(36,36));
	rect.setFillColor(sf::Color::Yellow);
	//sprite.setScale(sf::Vector2f(0.2, 0.2));
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
}


void pickup::update()
{
	sprite.setPosition(rect.getPosition());
	text.setPosition(rect.getPosition().x - rect.getSize().x/2, rect.getPosition().y - 32);
}