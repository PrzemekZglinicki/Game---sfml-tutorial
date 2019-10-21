#pragma once

#include "entity.h"

class textDisplay : public entity
{
public:
/*
sf::Font font;

	if (!font.loadFromFile("sansation.ttf"))
	{
		cout << "BLAD BLAD BLAD!!!" << endl;
		return EXIT_FAILURE;
	}
	sf::Text text("Zombiehoooo", font, 25);
*/
	string myString = "Default";
	textDisplay();
	void update();
	int movementSpeed = 2;
	int counter = 0;
	bool destroy = false;
	int lifeTime = 100;

};