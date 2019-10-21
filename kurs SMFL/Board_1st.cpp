#include "Board_1st.h"



Board_1st::Board_1st()
{
}
/*
// Wall vector array
vector<Wall>::const_iterator iterWall;
vector<Wall> wallArray;

class Wall wall1;
wall1.rect.setPosition(100, 100);
//wallArray.push_back(wall1);

//Room properties
int roomSize = generateRandom(10) + 6;
int roomStartX = 0;
int roomStartY = 0;
int verticalDoorLocationLeft = 0;
int verticalDoorLocationRight = 0;
int horizontalDoorLocationUp = 0;
int horizontalDoorLocationDown = 0;

// Ground vector array
vector<Wall>::const_iterator iterGround;
vector<Wall> groundArray;

class Wall ground1;
ground1.sprite.setTexture(textureGround);


//Custom room
int roomSize = generateRandom(10) + 6;
int roomStart = 0;
int doorLocation = generateRandom(4);

enemy1.rect.setPosition((roomSize - 3) * 50 - 50, 3 * 50);
enemyArray.push_back(enemy1);

wall1.destructable = true; // Can be destroyed
wall1.rect.setFillColor(sf::Color::Yellow);
wall1.rect.setPosition((roomSize - 3) * 50 - 50, (roomSize - 3) * 50 - 50);
wallArray.push_back(wall1);

wall1.destructable = false; // Can't be destroyed
wall1.rect.setFillColor(sf::Color::White);

enemy1.rect.setPosition((roomSize - 3) * 50 - 50, 3 * 50);
enemyArray.push_back(enemy1);
enemy1.rect.setPosition((roomSize - 3) * 50 - 50, 3 * 50);
enemyArray.push_back(enemy1);
enemy1.rect.setPosition((roomSize - 3) * 50 - 50, 3 * 50);
enemyArray.push_back(enemy1);

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
wall1.rect.setPosition(50 * counter + roomStart, 0 + roomStart);
wallArray.push_back(wall1);
counter++;
}

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
wall1.rect.setPosition(50 * counter + roomStart, 50 * roomSize + roomStart);
wallArray.push_back(wall1);
counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize)
{
wall1.rect.setPosition(roomStart, 50 * counter + roomStart);
wallArray.push_back(wall1);
counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize + 1)
{
if (counter != doorLocation)
{
if (counter != doorLocation + 1)
{
wall1.rect.setPosition(50 * roomSize + roomStart, 50 * counter + roomStart);
wallArray.push_back(wall1);
}
}
counter++;
}
*/

/*
// Destructable boxes
wall1.destructable = true; // Can be destroyed
wall1.rect.setFillColor(sf::Color::Yellow);
wall1.rect.setPosition((roomSize - 3) * 50 - 50, (roomSize - 3) * 50 - 50);
wallArray.push_back(wall1);
wall1.destructable = false; // Can't be destroyed
wall1.rect.setFillColor(sf::Color::White);


//Custom room 1st
roomSize = 5;
roomStartX = 0;
roomStartY = 0;
verticalDoorLocationRight = 3;
verticalDoorLocationLeft = 100;
horizontalDoorLocationUp = 100;
horizontalDoorLocationDown = 100;
wall1.sprite.setScale(0.2, 0.2);
wall1.sprite.setTexture(textureWall);

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationUp)
	{
		if (counter != horizontalDoorLocationUp + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 0 + roomStartY);
			wallArray.push_back(wall1);
		}
	}

	counter++;
}

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationDown)
	{
		if (counter != horizontalDoorLocationDown + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
			wallArray.push_back(wall1);
		}
	}

	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize)
{
	if (counter != verticalDoorLocationLeft)
	{
		if (counter != verticalDoorLocationLeft + 1)
		{
			wall1.rect.setPosition(roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize + 1)
{
	if (counter != verticalDoorLocationRight)
	{
		if (counter != verticalDoorLocationRight + 1)
		{
			wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Lay Floor Tiles
counter = 0;
ground1.sprite.setTextureRect(sf::IntRect(430, 100, 50, 50));
while (counter <= roomSize)
{
	counter2 = 0;
	while (counter2 < roomSize)
	{
		ground1.sprite.setPosition(counter * 50 + roomStartX, counter2 * 50 + roomStartY);
		groundArray.push_back(ground1);

		counter2++;
	}
	counter++;
}

//Random Stuff in first Room
counter = 0;
while (counter < roomSize - 1)
{
	counter2 = 0;
	while (counter2 < roomSize - 1)
	{

		int tempRandom = generateRandom(10);
		if (tempRandom == 1)
		{
			// Destructable boxes
			wall1.destructable = true; // Can be destroyed
			wall1.sprite.setTexture(textureCrate);
			wall1.rect.setFillColor(sf::Color::Yellow);
			wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			wallArray.push_back(wall1);
			wall1.destructable = false; // Can't be destroyed
			wall1.rect.setFillColor(sf::Color::White);
		}

		if (tempRandom == 2)
		{
			enemy1.createEnemy(4);
			enemy1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			enemyArray.push_back(enemy1);
		}
		counter2++;
	}
	counter++;
}

//Custom room 2nd
roomSize = 10;
roomStartX = 5 * 50;
roomStartY = 0;
verticalDoorLocationRight = 3;
verticalDoorLocationLeft = 3;
horizontalDoorLocationUp = 4;
horizontalDoorLocationDown = 4;
wall1.sprite.setTexture(textureWall);

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationUp)
	{
		if (counter != horizontalDoorLocationUp + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 0 + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationDown)
	{
		if (counter != horizontalDoorLocationDown + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize)
{
	if (counter != verticalDoorLocationLeft)
	{
		if (counter != verticalDoorLocationLeft + 1)
		{
			wall1.rect.setPosition(roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize + 1)
{
	if (counter != verticalDoorLocationRight)
	{
		if (counter != verticalDoorLocationRight + 1)
		{
			wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Lay Floor Tiles
counter = 0;
ground1.sprite.setTextureRect(sf::IntRect(430, 100, 50, 50));
while (counter <= roomSize)
{
	counter2 = 0;
	while (counter2 < roomSize)
	{
		ground1.sprite.setPosition(counter * 50 + roomStartX, counter2 * 50 + roomStartY);
		groundArray.push_back(ground1);

		counter2++;
	}
	counter++;
}

//Random Stuff in 2nd Room
counter = 0;
while (counter < roomSize - 1)
{
	counter2 = 0;
	while (counter2 < roomSize - 1)
	{

		int tempRandom = generateRandom(10);
		if (tempRandom == 2)
		{
			// Destructable boxes
			wall1.destructable = true; // Can be destroyed
			wall1.sprite.setTexture(textureCrate);
			wall1.rect.setFillColor(sf::Color::Yellow);
			wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			wallArray.push_back(wall1);
			wall1.destructable = false; // Can't be destroyed
			wall1.rect.setFillColor(sf::Color::White);
		}

		if (tempRandom == 3)
		{
			int tempRandom2 = generateRandom(5);
			enemy1.createEnemy(tempRandom2);
			enemy1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			enemyArray.push_back(enemy1);
		}

		counter2++;
	}
	counter++;
}

//Custom room 3rd
roomSize = 6;
roomStartX = 5 * 50;
roomStartY = 10 * 50;
verticalDoorLocationRight = 100;
verticalDoorLocationLeft = 100;
horizontalDoorLocationUp = 4;
horizontalDoorLocationDown = 100;
wall1.sprite.setTexture(textureWall);

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationUp)
	{
		if (counter != horizontalDoorLocationUp + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 0 + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationDown)
	{
		if (counter != horizontalDoorLocationDown + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize)
{
	if (counter != verticalDoorLocationLeft)
	{
		if (counter != verticalDoorLocationLeft + 1)
		{
			wall1.rect.setPosition(roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize + 1)
{
	if (counter != verticalDoorLocationRight)
	{
		if (counter != verticalDoorLocationRight + 1)
		{
			wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Lay Floor Tiles
counter = 0;
ground1.sprite.setTextureRect(sf::IntRect(430, 100, 50, 50));
while (counter <= roomSize)
{
	counter2 = 0;
	while (counter2 < roomSize)
	{
		ground1.sprite.setPosition(counter * 50 + roomStartX, counter2 * 50 + roomStartY);
		groundArray.push_back(ground1);

		counter2++;
	}
	counter++;
}

//Random Stuff in 3th Room
counter = 0;
while (counter < roomSize - 1)
{
	counter2 = 0;
	while (counter2 < roomSize - 1)
	{

		int tempRandom = generateRandom(20);
		if (tempRandom == 1)
		{
			// Destructable boxes
			wall1.destructable = true; // Can be destroyed
			wall1.sprite.setTexture(textureCrate);
			wall1.rect.setFillColor(sf::Color::Yellow);
			wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			wallArray.push_back(wall1);
			wall1.destructable = false; // Can't be destroyed
			wall1.rect.setFillColor(sf::Color::White);
		}

		if (tempRandom == 2)
		{
			enemy1.createEnemy(2);
			enemy1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			enemyArray.push_back(enemy1);
		}

		if (tempRandom == 3)
		{
			enemy1.createEnemy(3);
			enemy1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			enemyArray.push_back(enemy1);
		}

		counter2++;
	}
	counter++;
}

//Custom room 4th
roomSize = 10;
roomStartX = 5 * 50;
roomStartY = -1 * (10 * 50);
verticalDoorLocationRight = 100;
verticalDoorLocationLeft = 100;
horizontalDoorLocationUp = 5;
horizontalDoorLocationDown = 5;
wall1.sprite.setTexture(textureWall);

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationUp)
	{
		if (counter != horizontalDoorLocationUp + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 0 + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationDown)
	{
		if (counter != horizontalDoorLocationDown + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize)
{
	if (counter != verticalDoorLocationLeft)
	{
		if (counter != verticalDoorLocationLeft + 1)
		{
			wall1.rect.setPosition(roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize + 1)
{
	if (counter != verticalDoorLocationRight)
	{
		if (counter != verticalDoorLocationRight + 1)
		{
			wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Lay Floor Tiles
counter = 0;
ground1.sprite.setTextureRect(sf::IntRect(430, 100, 50, 50));
while (counter <= roomSize)
{
	counter2 = 0;
	while (counter2 < roomSize)
	{
		ground1.sprite.setPosition(counter * 50 + roomStartX, counter2 * 50 + roomStartY);
		groundArray.push_back(ground1);

		counter2++;
	}
	counter++;
}

//Random Stuff in 4th Room
counter = 0;
while (counter < roomSize - 1)
{
	counter2 = 0;
	while (counter2 < roomSize - 1)
	{

		int tempRandom = generateRandom(20);
		if (tempRandom == 1)
		{
			// Destructable boxes
			wall1.destructable = true; // Can be destroyed
			wall1.sprite.setTexture(textureCrate);
			wall1.rect.setFillColor(sf::Color::Yellow);
			wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			wallArray.push_back(wall1);
			wall1.destructable = false; // Can't be destroyed
			wall1.rect.setFillColor(sf::Color::White);
		}

		if (tempRandom == 4)
		{
			enemy1.createEnemy(4);
			enemy1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			enemyArray.push_back(enemy1);
		}


		if (tempRandom == 5)
		{
			enemy1.createEnemy(5);
			enemy1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			enemyArray.push_back(enemy1);
		}


		counter2++;
	}
	counter++;
}

//Custom room 5th
roomSize = 15;
roomStartX = 5 * 50;
roomStartY = -1 * (25 * 50);
verticalDoorLocationRight = 100;
verticalDoorLocationLeft = 100;
horizontalDoorLocationUp = 100;
horizontalDoorLocationDown = 5;
wall1.sprite.setTexture(textureWall);

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationUp)
	{
		if (counter != horizontalDoorLocationUp + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 0 + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationDown)
	{
		if (counter != horizontalDoorLocationDown + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize)
{
	if (counter != verticalDoorLocationLeft)
	{
		if (counter != verticalDoorLocationLeft + 1)
		{
			wall1.rect.setPosition(roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize + 1)
{
	if (counter != verticalDoorLocationRight)
	{
		if (counter != verticalDoorLocationRight + 1)
		{
			wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Lay Floor Tiles
counter = 0;
ground1.sprite.setTextureRect(sf::IntRect(430, 100, 50, 50));
while (counter <= roomSize)
{
	counter2 = 0;
	while (counter2 < roomSize)
	{
		ground1.sprite.setPosition(10 * 50 + roomStartX, 10 * 50 + roomStartY);
		groundArray.push_back(ground1);

		counter2++;
	}
	counter++;
}

//Random Stuff in 5th Room
counter = 0;
while (counter < roomSize - 1)
{
	counter2 = 0;
	while (counter2 < roomSize - 1)
	{

		int tempRandom = generateRandom(11);

		if (tempRandom == 1 || tempRandom == 2)
		{
			// Destructable boxes
			wall1.destructable = true; // Can be destroyed
			wall1.sprite.setTexture(textureCrate);
			wall1.rect.setFillColor(sf::Color::Yellow);
			wall1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			wallArray.push_back(wall1);
			wall1.destructable = false; // Can't be destroyed
			wall1.rect.setFillColor(sf::Color::White);
		}

		if (tempRandom == 4)
		{
			enemy1.createEnemy(6);
			enemy1.rect.setPosition((counter * 50) + 50 + roomStartX, (counter2 * 50) + 50 + roomStartY);
			enemyArray.push_back(enemy1);
		}

		counter2++;
	}
	counter++;
}


//Boss enemy!!!!
class Enemy enemyBoss;
enemyBoss.sprite.setTexture(textureEnemy);
enemyBoss.createEnemy(5);
enemyBoss.setAttackDamage(8);
enemyBoss.setAggroed(true);
enemyBoss.isBoss = true;
enemyBoss.text.setFont(font);
enemyBoss.text.setCharacterSize(17);
enemyBoss.text.setColor(sf::Color::Red);
enemyBoss.setMaxHp(150);
enemyBoss.setHp(150);
enemyBoss.rect.setPosition((10 * 50) + 50 + roomStartX, (10 * 50) + 50 + roomStartY);
enemyBoss.sprite.setColor(sf::Color::Red);
enemyArray.push_back(enemyBoss);
enemyBoss.setAggroed(false);

//Custom room 6th - room item shop
roomSize = 8;
roomStartX = 15 * 50;
roomStartY = 0;
verticalDoorLocationRight = 100;
verticalDoorLocationLeft = 3;
horizontalDoorLocationUp = 100;
horizontalDoorLocationDown = 100;
wall1.sprite.setTexture(textureWall);

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationUp)
	{
		if (counter != horizontalDoorLocationUp + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 0 + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create horizontal wall
counter = 0;
while (counter < roomSize)
{
	if (counter != horizontalDoorLocationDown)
	{
		if (counter != horizontalDoorLocationDown + 1)
		{
			wall1.rect.setPosition(50 * counter + roomStartX, 50 * roomSize + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize)
{
	if (counter != verticalDoorLocationLeft)
	{
		if (counter != verticalDoorLocationLeft + 1)
		{
			wall1.rect.setPosition(roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Create vertical wall
counter = 0;
while (counter < roomSize + 1)
{
	if (counter != verticalDoorLocationRight)
	{
		if (counter != verticalDoorLocationRight + 1)
		{
			wall1.rect.setPosition(50 * roomSize + roomStartX, 50 * counter + roomStartY);
			wallArray.push_back(wall1);
		}
	}
	counter++;
}

//Lay Floor Tiles
counter = 0;
ground1.sprite.setTextureRect(sf::IntRect(120, 25, 50, 50));
while (counter <= roomSize)
{
	counter2 = 0;
	while (counter2 < roomSize)
	{
		ground1.sprite.setPosition(counter * 50 + roomStartX, counter2 * 50 + roomStartY);
		groundArray.push_back(ground1);

		counter2++;
	}
	counter++;
}

//Regular Power Up
pickUpCoin1.setCost(15);
pickUpCoin1.text.setString("Cost: " + to_string(pickUpCoin1.getCost()));
pickUpCoin1.setInShop(true);
pickUpCoin1.setIsCoin(false);
pickUpCoin1.setIsPowerUp(true);
pickUpCoin1.setIsNovaAttack(false);
pickUpCoin1.sprite.setTexture(texturePowerUp);
pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
pickUpCoin1.sprite.setTextureRect(sf::IntRect(34 * 3, 34 * 0, 32, 32));
pickUpCoin1.rect.setPosition((15 * 50) + (2 * 50), 4 * 50);
pickUpArray.push_back(pickUpCoin1);

//Nova Power Up
pickUpCoin1.setCost(20);
pickUpCoin1.text.setString("Cost: " + to_string(pickUpCoin1.getCost()));
pickUpCoin1.setInShop(true);
pickUpCoin1.setIsCoin(false);
pickUpCoin1.setIsPowerUp(false);
pickUpCoin1.setIsNovaAttack(true);
pickUpCoin1.sprite.setTexture(texturePowerUp);
pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
pickUpCoin1.sprite.setTextureRect(sf::IntRect(34 * 4, 34 * 0, 32, 32));
pickUpCoin1.rect.setPosition((15 * 50) + (4 * 50), 4 * 50);
pickUpArray.push_back(pickUpCoin1);

//HP Up Shield
pickUpCoin1.setCost(50);
pickUpCoin1.text.setString("Cost: " + to_string(pickUpCoin1.getCost()));
pickUpCoin1.setInShop(true);
pickUpCoin1.setIsCoin(false);
pickUpCoin1.setIsPowerUp(false);
pickUpCoin1.setIsNovaAttack(false);
pickUpCoin1.setIsHpShield(true);
pickUpCoin1.sprite.setTexture(texturePowerUp);
pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
pickUpCoin1.sprite.setTextureRect(sf::IntRect(34 * 10, 34 * 0, 32, 32));
pickUpCoin1.rect.setPosition((15 * 50) + (6 * 50), 4 * 50);
pickUpArray.push_back(pickUpCoin1);
pickUpCoin1.setIsHpShield(false);

//Food item
pickUpCoin1.setCost(10);
pickUpCoin1.text.setString("Cost: " + to_string(pickUpCoin1.getCost()));
pickUpCoin1.setInShop(true);
pickUpCoin1.setIsCoin(false);
pickUpCoin1.setIsPowerUp(false);
pickUpCoin1.setIsNovaAttack(false);
pickUpCoin1.setIsHpShield(false);
pickUpCoin1.setIsPotion(false);
pickUpCoin1.setIsFood(true);
pickUpCoin1.sprite.setTexture(textureFood);
pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
pickUpCoin1.sprite.setTextureRect(sf::IntRect(32 * 13, 34 * 0, 32, 32));
pickUpCoin1.rect.setPosition((15 * 50) + (3 * 50) + 10, 5 * 50 + 20);
pickUpArray.push_back(pickUpCoin1);
pickUpCoin1.setIsFood(false);
pickUpCoin1.setInShop(false);

//Potion item
pickUpCoin1.setCost(10);
pickUpCoin1.text.setString("Cost: " + to_string(pickUpCoin1.getCost()));
pickUpCoin1.setInShop(true);
pickUpCoin1.setIsCoin(false);
pickUpCoin1.setIsPowerUp(false);
pickUpCoin1.setIsNovaAttack(false);
pickUpCoin1.setIsHpShield(false);
pickUpCoin1.setIsPotion(true);
pickUpCoin1.setIsFood(false);
pickUpCoin1.sprite.setTexture(texturePotion);
pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
pickUpCoin1.sprite.setTextureRect(sf::IntRect(32 * 1, 32 * 3, 32, 32));
pickUpCoin1.rect.setPosition((15 * 50) + (5 * 50) + 15, 5 * 50 + 20);
pickUpArray.push_back(pickUpCoin1);
pickUpCoin1.setIsPotion(false);
pickUpCoin1.setInShop(false);*/