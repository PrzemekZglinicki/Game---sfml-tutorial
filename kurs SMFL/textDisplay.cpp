#include "textDisplay.h"

#include "Player.h"

textDisplay::textDisplay()
{
	text.setColor(sf::Color::Red);
	text.setCharacterSize(30);
	//text.setPosition(0, 0);
	text.setString(myString);
}

void textDisplay::update()
{
	text.move(0, -movementSpeed);

	counter++;
	if (counter >= lifeTime)
	{
		destroy = true;
	}
}
