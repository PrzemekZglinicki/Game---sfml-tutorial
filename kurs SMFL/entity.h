
#ifndef __InstallingSFML__entity__
#define __InstallingSFML__entity__

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <deque>
#include <list>
#include <vector>

using namespace std;

class entity
{
private:


public:
	// Physical Object
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;

	/*
	bool active = false;
	bool deleteIt = false;

	int x = 0;
	int y = 0;
	*/

};

#endif /* defined(__InstallingSFML__entity__) */
