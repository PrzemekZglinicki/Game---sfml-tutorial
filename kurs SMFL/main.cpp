#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<cmath>
#include<iostream>
#include "Player.h"
#include "entity.h"
#include "projectille.h"
#include "Enemy.h"
#include "random.h"
#include "textDisplay.h"
#include "pickUp.h"
#include "Wall.h"
#include "texture.h"

using namespace std;

int main()
{
	srand(time(NULL));
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;

	//create the main window
	sf::RenderWindow  window(sf::VideoMode(1000, 800, 32), "Gierama"); //, sf::Style::Fullscreen ->Flaga trybu pe³noekranowego
	window.setFramerateLimit(500);

	//View
	sf::View view1(sf::FloatRect(200, 200, 320, 200));
	view1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	view1.setCenter(sf::Vector2f(view1.getSize().x/2, view1.getSize().y/2));
	window.setView(view1);

	// Load a music to play
	sf::Music music;
	if (!music.openFromFile("sound/music.ogg"))
	{return EXIT_FAILURE;}

	//Sounds effects Shot
	sf::SoundBuffer bufferShot;
	if (!bufferShot.loadFromFile("sound/shot.ogg"))
	{return EXIT_FAILURE;}
	sf::Sound soundShot;
	soundShot.setBuffer(bufferShot);
	
	//Sounds effects Collision
	sf::SoundBuffer bufferCollision;
	if (!bufferCollision.loadFromFile("sound/collision.ogg"))
	{return EXIT_FAILURE;}
	sf::Sound soundCollision;
	soundCollision.setBuffer(bufferCollision);

	//Sound effects - player gets demage
	sf::SoundBuffer bufferPlayerDemage;
	if (!bufferPlayerDemage.loadFromFile("sound/playerhit.ogg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundPlayerDemage;
	soundPlayerDemage.setBuffer(bufferPlayerDemage);

	//Sound effects - pickup items
	/*
	sf::SoundBuffer bufferPickUpItems;
	if (!bufferPickUpItems.loadFromFile("sound/nice_music.ogg"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundPickUpItems;
	soundPickUpItems.setBuffer(bufferPickUpItems);
	*/

	//Sound effects - pickup items
	sf::SoundBuffer bufferPickUpCoin;
	if (!bufferPickUpCoin.loadFromFile("sound/coin.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundPickUpCoin;
	soundPickUpCoin.setBuffer(bufferPickUpCoin);

	//Set font for text display
	sf::Font font;

	if (!font.loadFromFile("font/pixel.ttf"))
	{
		cout << "BLAD BLAD BLAD!!!" << endl;
		return EXIT_FAILURE;
	}

	// Set position of the window
	window.setTitle("Gierma");
	//set size of the window
	window.setSize(sf::Vector2u(1000, 800));
	
	// set the icon
	sf::Image icon;
	icon.loadFromFile("grafika/icon.jpg");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	Texture texture;

	// create a player
	class player Player1;
	// Set the texture of the player
	
	Player1.sprite.setTexture(texture.texturePlayer);

	//Projectile Vector Array
	vector<projectille>::const_iterator iter;
	vector<projectille> projectilleArray;
	//Projectille object
	class projectille projectille1;
	projectille1.sprite.setTexture(texture.textureFireball);

	//Enemy Vector Array
	vector<Enemy>::const_iterator iterEnemyArray;
	vector<Enemy> enemyArray;
	//Enemy object
	class Enemy enemy1;
	enemy1.sprite.setTexture(texture.textureEnemy);
	enemy1.text.setFont(font);
	enemy1.text.setCharacterSize(15);
	enemy1.text.setColor(sf::Color::Red);
	//enemy1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	enemy1.rect.setPosition(200, 200);
	enemyArray.push_back(enemy1);

	//Blood Vector Array
	vector<Enemy>::const_iterator iterBlood;
	vector<Enemy> bloodArray;

	//Blood object 1
	class Enemy blood1;
	blood1.setIsBlood(true);
	blood1.sprite.setTexture(texture.textureBlood);
	blood1.sprite.setTextureRect(sf::IntRect(32*5, 0, 32, 32));
	blood1.rect.setPosition(300, 300);

	//PickUp Vector Array
	vector<pickup>::const_iterator iterCoin;
	vector<pickup> pickUpArray;

	//Add coin to pickUpArray
	class pickup pickUpCoin1;
	pickUpCoin1.sprite.setTexture(texture.textureCoin);
	pickUpCoin1.text.setFont(font);
	pickUpCoin1.text.setCharacterSize(15);
	pickUpCoin1.text.setColor(sf::Color::Green);
	pickUpCoin1.rect.setPosition(300, 300);
	pickUpCoin1.sprite.setScale(sf::Vector2f(0.2, 0.2));
	pickUpCoin1.sprite.setTextureRect(sf::IntRect(40, 40, 200, 300));


	//Text Vector Array
	vector<textDisplay>::const_iterator iterText;
	vector<textDisplay> textDisplayArray;
	//Projectille object

	//Training text
	sf::Text text("Gil: ", font, 25);
	text.setColor(sf::Color::Red);
	text.setCharacterSize(25);
	text.setPosition(0, 0);

	//Player HP text
	sf::Text textHP("HP: ", font, 25);
	textHP.setColor(sf::Color::Red);
	textHP.setCharacterSize(25);
	textHP.setPosition(0, 0);

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
	ground1.sprite.setTexture(texture.textureGround);

	/*
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
	*/

	//Custom room 1st
	roomSize = 5;
	roomStartX = 0;
	roomStartY = 0;
	verticalDoorLocationRight = 3;
	verticalDoorLocationLeft = 100;
	horizontalDoorLocationUp = 100;
	horizontalDoorLocationDown = 100;
	wall1.sprite.setScale(0.2,0.2);
	wall1.sprite.setTexture(texture.textureWall);

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
				wall1.sprite.setTexture(texture.textureCrate);
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
	wall1.sprite.setTexture(texture.textureWall);

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
				wall1.sprite.setTexture(texture.textureCrate);
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
	wall1.sprite.setTexture(texture.textureWall);

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
				wall1.sprite.setTexture(texture.textureCrate);
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
	wall1.sprite.setTexture(texture.textureWall);

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
				wall1.sprite.setTexture(texture.textureCrate);
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
	wall1.sprite.setTexture(texture.textureWall);

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
				wall1.sprite.setTexture(texture.textureCrate);
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
	enemyBoss.sprite.setTexture(texture.textureEnemy);
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
	wall1.sprite.setTexture(texture.textureWall);

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
	pickUpCoin1.sprite.setTexture(texture.texturePowerUp);
	pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
	pickUpCoin1.sprite.setTextureRect(sf::IntRect(34*3, 34*0, 32, 32));
	pickUpCoin1.rect.setPosition((15*50) + (2*50), 4*50);
	pickUpArray.push_back(pickUpCoin1);

	//Nova Power Up
	pickUpCoin1.setCost(20);
	pickUpCoin1.text.setString("Cost: " + to_string(pickUpCoin1.getCost()));
	pickUpCoin1.setInShop(true);
	pickUpCoin1.setIsCoin(false);
	pickUpCoin1.setIsPowerUp(false);
	pickUpCoin1.setIsNovaAttack(true);
	pickUpCoin1.sprite.setTexture(texture.texturePowerUp);
	pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
	pickUpCoin1.sprite.setTextureRect(sf::IntRect(34*4, 34*0, 32, 32));
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
	pickUpCoin1.sprite.setTexture(texture.texturePowerUp);
	pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
	pickUpCoin1.sprite.setTextureRect(sf::IntRect(34*10, 34*0, 32, 32));
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
	pickUpCoin1.sprite.setTexture(texture.textureFood);
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
	pickUpCoin1.sprite.setTexture(texture.texturePotion);
	pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
	pickUpCoin1.sprite.setTextureRect(sf::IntRect(32 * 1, 32 * 3, 32, 32));
	pickUpCoin1.rect.setPosition((15 * 50) + (5 * 50) + 15, 5 * 50 + 20);
	pickUpArray.push_back(pickUpCoin1);
	pickUpCoin1.setIsPotion(false);
	pickUpCoin1.setInShop(false);

	//Set the music
	//music.play();
	//music.setVolume(10);
	//music.setLoop(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// close window: button x
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			// Set the Icon
			sf::Image icon;
			//if(!icon.loadFromFile(resourcePath() + ))

			// close window: button escape
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}

			// close window: press middle button on the mouse
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle)
			{
				window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//cout << "The MOUSE LEFT is pressed" << endl;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				//cout << "The MOUSE RIGHT is pressed" << endl;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				//cout << "The KEY Q is pressed" << endl;
			}
		}

		window.clear(sf::Color::Black);

		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time elapsed3 = clock3.getElapsedTime();

		//Enemy collides with Wall
		counter = 0;
		for (iterEnemyArray = enemyArray.begin(); iterEnemyArray != enemyArray.end(); iterEnemyArray++)
		{
			counter2 = 0;
			for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++)
			{

				if (enemyArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
				{
					// Hit the wall
					if (enemyArray[counter].getDirection() == 1) //Up
					{
						enemyArray[counter].canMoveUp = false;
						enemyArray[counter].rect.move(0, 1);
					}
					else if (enemyArray[counter].getDirection() == 2) //Down
					{
						enemyArray[counter].canMoveDown = false;
						enemyArray[counter].rect.move(0, -1);
					}
					else if (enemyArray[counter].getDirection() == 3) //Left
					{
						enemyArray[counter].canMoveLeft = false;
						enemyArray[counter].rect.move(-1, 0);
					}
					else if (enemyArray[counter].getDirection() == 4) //Right
					{
						enemyArray[counter].canMoveRight = false;
						enemyArray[counter].rect.move(1, 0);
					}
				}

				counter2++;
			}

			counter++;
		}

		//Player collides with Wall
		counter = 0;
		for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++)
		{
			if (Player1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
			{
				// Hit the wall
				if (Player1.direction == 1) //Up
				{
					Player1.canMoveUp = false;
					Player1.rect.move(0, 1);
				}
				else if (Player1.direction == 2) //Down
				{
					Player1.canMoveDown = false;
					Player1.rect.move(0,-1);
				}
				else if (Player1.direction == 3) //Left
				{
					Player1.canMoveLeft = false;
					Player1.rect.move(-1, 0);
				}
				else if (Player1.direction == 4) //Right
				{
					Player1.canMoveRight = false;
					Player1.rect.move(1, 0);
				}
			}
			counter++;
		}

		//Player collides with pickUp items
		counter = 0;
		for (iterCoin = pickUpArray.begin(); iterCoin != pickUpArray.end(); iterCoin++)
		{
			if (Player1.rect.getGlobalBounds().intersects(pickUpArray[counter].rect.getGlobalBounds()))
			{
				if (pickUpArray[counter].getIsCoin() == true)
				{
					soundPickUpCoin.play();
					Player1.gil += pickUpArray[counter].getCoinValue();
					class textDisplay textDisplay1;
					textDisplay1.text.setFont(font);

					textDisplay1.text.setString(to_string(pickUpArray[counter].getCoinValue()));
					textDisplay1.text.setPosition(pickUpArray[counter].rect.getPosition().x - pickUpArray[counter].rect.getSize().x / 2, pickUpArray[counter].rect.getPosition().y - pickUpArray[counter].rect.getSize().y / 2);
					textDisplayArray.push_back(textDisplay1);
					pickUpArray[counter].setDestroy(true);
				}

				if (pickUpArray[counter].getInShop() == true)
				{
					if (Player1.gil >= pickUpArray[counter].getCost())
					{
						Player1.gil -= pickUpArray[counter].getCost();

						if (pickUpArray[counter].getIsPowerUp() == true)
						{
							soundPickUpCoin.play();
							Player1.powerUpLevel = true;
							Player1.novaAttack = false;
							pickUpArray[counter].setDestroy(true);
						}

						if (pickUpArray[counter].getIsNovaAttack() == true)
						{
							soundPickUpCoin.play();
							Player1.powerUpLevel = false;
							Player1.novaAttack = true;
							pickUpArray[counter].setDestroy(true);
						}

						if (pickUpArray[counter].getIsHpShield() == true)
						{
							soundPickUpCoin.play();
							Player1.HP += 10;
							Player1.maxHP += 10;
							pickUpArray[counter].setDestroy(true);
						}

						if (pickUpArray[counter].getIsFood() == true)
						{
							soundPickUpCoin.play();
							Player1.HP += 5;
							pickUpArray[counter].setDestroy(true);
						}

						if (pickUpArray[counter].getIsPotion() == true)
						{
							soundPickUpCoin.play();
							Player1.HP += 5;
							Player1.maxHP += 5;
							pickUpArray[counter].setDestroy(true);
						}
					}
				}
				if (pickUpArray[counter].getInShop() == false)
				{
					if (pickUpArray[counter].getIsPowerUp() == true)
					{
						soundPickUpCoin.play();
						Player1.powerUpLevel = true;
						Player1.novaAttack = false;
						pickUpArray[counter].setDestroy(true);
					}

					if (pickUpArray[counter].getIsNovaAttack() == true)
					{
						soundPickUpCoin.play();
						Player1.powerUpLevel = false;
						Player1.novaAttack = true;
						pickUpArray[counter].setDestroy(true);
					}

					if (pickUpArray[counter].getIsFood() == true)
					{
						soundPickUpCoin.play();
						Player1.HP += 5;
						pickUpArray[counter].setDestroy(true);
					}

					if (pickUpArray[counter].getIsPotion() == true)
					{
						soundPickUpCoin.play();
						Player1.HP += 5;
						Player1.maxHP += 5;
						pickUpArray[counter].setDestroy(true);
					}
				}
			}
			counter++;
		}

		//Projectile colides with walls
		counter = 0;
		for (iter = projectilleArray.begin(); iter != projectilleArray.end(); iter++)
		{
			counter2 = 0;
			for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++)
			{
				if (projectilleArray[counter].rect.getGlobalBounds().intersects(wallArray[counter2].rect.getGlobalBounds()))
				{
					soundCollision.play();
					projectilleArray[counter].destroy = true;

					if (wallArray[counter2].destructable == true)
					{
						wallArray[counter2].hp -= Player1.attackDamage;

						if (wallArray[counter2].hp <= 0)
						{
							wallArray[counter2].destroy = true;
						}
					}

				}
				counter2++;
			}
			counter++;
		}

		counter = 0;
		for (iterEnemyArray = enemyArray.begin(); iterEnemyArray != enemyArray.end(); iterEnemyArray++)
		{
			if (enemyArray[counter].getAggroed() == true)
			{
				if (elapsed3.asSeconds() >= 1)
				{
					clock3.restart();

					int tempRand = generateRandom(3);
					
					if (tempRand == 1) //Enemy fires Projectile at chases player
					{
						projectille1.attackDamage = enemyArray[counter].getAttackDamage();
						// Player to Right
						if ((Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
						{
							soundShot.play();
							projectille1.enemyProjectile = true;
							projectille1.direction = 4;
							projectille1.rect.setPosition((enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x / 2 - projectille1.rect.getSize().x / 2),
								(enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y / 2 - projectille1.rect.getSize().y / 2));
							projectilleArray.push_back(projectille1);
							projectille1.enemyProjectile = false;

							enemyArray[counter].setDirection(3);
						}

						// Player to Left
						if ((Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x) && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
						{
							soundShot.play();
							projectille1.enemyProjectile = true;
							projectille1.direction = 3;
							projectille1.rect.setPosition((enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x / 2 - projectille1.rect.getSize().x / 2),
								(enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y / 2 - projectille1.rect.getSize().y / 2));
							projectilleArray.push_back(projectille1);
							projectille1.enemyProjectile = false;

							enemyArray[counter].setDirection(4);
						}

						// Player to Top
						if ((Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
						{
							soundShot.play();
							projectille1.enemyProjectile = true;
							projectille1.direction = 1;
							projectille1.rect.setPosition((enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x / 2 - projectille1.rect.getSize().x / 2),
								(enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y / 2 - projectille1.rect.getSize().y / 2));
							projectilleArray.push_back(projectille1);
							projectille1.enemyProjectile = false;

							enemyArray[counter].setDirection(1);
						}

						// Player to Bottom
						if ((Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x) && (abs(Player1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40))
						{
							soundShot.play();
							projectille1.enemyProjectile = true;
							projectille1.direction = 2;
							projectille1.rect.setPosition((enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x / 2 - projectille1.rect.getSize().x / 2),
								(enemyArray[counter].rect.getPosition().y + enemyArray[counter].rect.getSize().y / 2 - projectille1.rect.getSize().y / 2));
							projectilleArray.push_back(projectille1);
							projectille1.enemyProjectile = false;

							enemyArray[counter].setDirection(2);
						}
					}
					else if (tempRand == 2) // Enemy Chases the player
					{
						if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].setDirection(1);
						}
						else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].setDirection(2);
						}
						else if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].setDirection(4);
						}
						else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].setDirection(3);
						}
					}
					else //Enemy Chases Player
					{
						if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].setDirection(4);
						}
						else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].setDirection(3);
						}
						else if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].setDirection(1);
						}
						else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].setDirection(2);
						}
					}
				}
			}

			counter++;
		}

		//Enemy Projectile colides with player
		counter = 0;
		for (iter = projectilleArray.begin(); iter != projectilleArray.end(); iter++)
		{
			if (projectilleArray[counter].enemyProjectile == true)
			{
				if (projectilleArray[counter].rect.getGlobalBounds().intersects(Player1.rect.getGlobalBounds()))
				{
					soundCollision.play();
					projectilleArray[counter].destroy = true;
					Player1.HP -= projectilleArray[counter].attackDamage;

					//Text display
					class textDisplay textDisplay1;
					textDisplay1.text.setFont(font);
					textDisplay1.text.setString(to_string(projectilleArray[counter].attackDamage));
					textDisplay1.text.setPosition(Player1.rect.getPosition().x - Player1.rect.getSize().x / 2, Player1.rect.getPosition().y - Player1.rect.getSize().y / 2);
					textDisplayArray.push_back(textDisplay1);
				}
			}
			counter++;
		}

		//Projectile colides with enemies
		counter = 0;
		for (iter = projectilleArray.begin(); iter != projectilleArray.end(); iter++)
		{
			if (projectilleArray[counter].enemyProjectile == false)
			{
				counter2 = 0;
				for (iterEnemyArray = enemyArray.begin(); iterEnemyArray != enemyArray.end(); iterEnemyArray++)
				{
					if (projectilleArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
					{
						soundCollision.play();

						projectilleArray[counter].destroy = true;
						//cout << "Collision" << endl;

						//Text display
						class textDisplay textDisplay1;
						textDisplay1.text.setFont(font);
						textDisplay1.text.setString(to_string(Player1.attackDamage));
						textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x - enemyArray[counter2].rect.getSize().x / 2, enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y / 2);
						textDisplayArray.push_back(textDisplay1);

						enemyArray[counter2].setHp(enemyArray[counter2].getHp() - Player1.attackDamage);
						if (enemyArray[counter2].getHp() <= 0)
						{
							enemyArray[counter2].setAlive(false);
						}

						//Aggro
						enemyArray[counter2].setAggroed(true);
					}

					counter2++;
				}
			}
			counter++;
		}

		//Enemy colides with player (Player takes damages)		
		if (elapsed2.asSeconds() >= 0.5)
		{
			clock2.restart();
			counter = 0;
			for (iterEnemyArray = enemyArray.begin(); iterEnemyArray != enemyArray.end(); iterEnemyArray++)
			{
				if (Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
				{
					soundPlayerDemage.play();

					//Text display
					class textDisplay textDisplay1;
					textDisplay1.text.setFont(font);
					textDisplay1.text.setString(to_string(enemyArray[counter].getAttackDamage()));
					textDisplay1.text.setPosition(Player1.rect.getPosition().x - Player1.rect.getSize().x / 2, Player1.rect.getPosition().y - Player1.rect.getSize().y / 2);
					textDisplayArray.push_back(textDisplay1);
					
					Player1.HP -= enemyArray[counter].getAttackDamage();
					Player1.powerUpLevel = false;
					Player1.novaAttack = false;
				}
			    counter++;
			}
		}

		//cout << "Player hp: " << Player1.HP << endl;
		
		//Delete pickUp Items
		counter = 0;
		for (iterCoin = pickUpArray.begin(); iterCoin != pickUpArray.end(); iterCoin++)
		{
			if (pickUpArray[counter].getDestroy() == true)
			{
				pickUpArray.erase(iterCoin);
				break;
			}
			counter++;
		}

		//Delete wall
		counter = 0;
		for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++)
		{
			if (wallArray[counter].destroy == true)
			{
				int tempRand = generateRandom(15);
				//Drop Coin
				if (tempRand >= 1 && tempRand <= 3)
				{
					pickUpCoin1.setIsCoin(true);
					pickUpCoin1.setIsPowerUp(false);
					pickUpCoin1.setIsNovaAttack(false);
					pickUpCoin1.sprite.setTexture(texture.textureCoin);
					pickUpCoin1.setCoinValue(10);
					pickUpCoin1.sprite.setScale(sf::Vector2f(0.2, 0.2));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(40, 40, 200, 300));
					pickUpCoin1.rect.setPosition(wallArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUpCoin1);
				}
				//Drop Multiple Coin
				else if (tempRand >= 8)
				{
					pickUpCoin1.setIsCoin(true);
					pickUpCoin1.setIsPowerUp(false);
					pickUpCoin1.setIsNovaAttack(false);
					pickUpCoin1.sprite.setTexture(texture.textureCoin);
					pickUpCoin1.setCoinValue(10);
					pickUpCoin1.sprite.setScale(sf::Vector2f(0.2, 0.2));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(40, 40, 200, 300));

					pickUpCoin1.rect.setPosition(wallArray[counter].rect.getPosition().x - 5, wallArray[counter].rect.getPosition().y);
					pickUpArray.push_back(pickUpCoin1);

					pickUpCoin1.rect.setPosition(wallArray[counter].rect.getPosition().x, wallArray[counter].rect.getPosition().y + 5);
					pickUpArray.push_back(pickUpCoin1);

					pickUpCoin1.rect.setPosition(wallArray[counter].rect.getPosition().x + 5, wallArray[counter].rect.getPosition().y);
					pickUpArray.push_back(pickUpCoin1);
				}

				//Drop PowerUp
				if (tempRand > 1 && tempRand <= 4)
				{
					pickUpCoin1.setIsCoin(false);
					pickUpCoin1.setIsPowerUp(true);
					pickUpCoin1.setIsNovaAttack(false);
					pickUpCoin1.sprite.setTexture(texture.texturePowerUp);
					pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(34*3, 34*0, 32, 32));
					pickUpCoin1.rect.setPosition(wallArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUpCoin1);
				}
				//Drop Nova PowerUp
				else if (tempRand > 6 && tempRand <= 8)
				{
					pickUpCoin1.setIsCoin(false);
					pickUpCoin1.setIsPowerUp(false);
					pickUpCoin1.setIsNovaAttack(true);
					pickUpCoin1.sprite.setTexture(texture.texturePowerUp);
					pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(34*4, 34*0, 32, 32));
					pickUpCoin1.rect.setPosition(wallArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUpCoin1);
				}

				if (tempRand == 10)
				{
					//Food item
					pickUpCoin1.setIsFood(true);
					pickUpCoin1.sprite.setTexture(texture.textureFood);
					pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(32 * 13, 34 * 0, 32, 32));
					pickUpCoin1.rect.setPosition(wallArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUpCoin1);
					pickUpCoin1.setIsFood(false);
				}
				else if (tempRand == 12)
				{
					//Potion item
					pickUpCoin1.setIsPotion(true);
					pickUpCoin1.sprite.setTexture(texture.texturePotion);
					pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(32 * 1, 32 * 3, 32, 32));
					pickUpCoin1.rect.setPosition(wallArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUpCoin1);
					pickUpCoin1.setIsPotion(false);
				}



				wallArray.erase(iterWall);
				break;
			}
			counter++;
		}

		//Delete dead enemies
		counter = 0;
		for (iterEnemyArray = enemyArray.begin(); iterEnemyArray != enemyArray.end(); iterEnemyArray++)
		{
			if (enemyArray[counter].getAlive() == false)
			{
				int tempRand = generateRandom(10);
				//Drop Coin
				if (tempRand >= 1 && tempRand <= 3)
				{
					pickUpCoin1.setIsCoin(true);
					pickUpCoin1.setIsPowerUp(false);
					pickUpCoin1.setIsNovaAttack(false);
					pickUpCoin1.sprite.setTexture(texture.textureCoin2);
					pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
					pickUpCoin1.rect.setPosition(enemyArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUpCoin1);
				}
				//Drop PowerUp
				else if (tempRand == 4)
				{
					pickUpCoin1.setIsCoin(false);
					pickUpCoin1.setIsPowerUp(true);
					pickUpCoin1.setIsNovaAttack(false);
					pickUpCoin1.sprite.setTexture(texture.texturePowerUp);
					pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(34*3, 34*0, 32, 32));
					pickUpCoin1.rect.setPosition(enemyArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUpCoin1);
				}

				//Drop Nova PowerUp
				else if (tempRand == 5)
				{
					pickUpCoin1.setIsCoin(false);
					pickUpCoin1.setIsPowerUp(false);
					pickUpCoin1.setIsNovaAttack(true);
					pickUpCoin1.sprite.setTexture(texture.texturePowerUp);
					pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(34*4, 34*0, 32, 32));
					pickUpCoin1.rect.setPosition(enemyArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUpCoin1);
				}

				else if (tempRand == 6)
				{
					//Food item
					pickUpCoin1.setIsFood(true);
					pickUpCoin1.sprite.setTexture(texture.textureFood);
					pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(32 * 13, 34 * 0, 32, 32));
					pickUpCoin1.rect.setPosition(enemyArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUpCoin1);
					pickUpCoin1.setIsFood(false);
				}
				else if (tempRand == 6)
				{
					//Potion item
					pickUpCoin1.setIsPotion(true);
					pickUpCoin1.sprite.setTexture(texture.texturePotion);
					pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(32 * 1, 32 * 3, 32, 32));
					pickUpCoin1.rect.setPosition(enemyArray[counter].rect.getPosition());
					pickUpArray.push_back(pickUpCoin1);
					pickUpCoin1.setIsPotion(false);
				}
				// Killed the boss
				if (enemyArray[counter].isBoss == true)
				{
					pickUpCoin1.setIsCoin(true);
					pickUpCoin1.setIsPowerUp(false);
					pickUpCoin1.setIsNovaAttack(false);
					pickUpCoin1.sprite.setTexture(texture.textureCoin2);
					pickUpCoin1.sprite.setScale(sf::Vector2f(1, 1));
					pickUpCoin1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

					counter3 = 0;
					while (counter3 <= 3)
					{
						pickUpCoin1.rect.setPosition(enemyArray[counter].rect.getPosition().x - generateRandom(30), enemyArray[counter].rect.getPosition().y - generateRandom(30));
						pickUpArray.push_back(pickUpCoin1);

						pickUpCoin1.rect.setPosition(enemyArray[counter].rect.getPosition().x + generateRandom(30), enemyArray[counter].rect.getPosition().y + generateRandom(30));
						pickUpArray.push_back(pickUpCoin1);

						pickUpCoin1.rect.setPosition(enemyArray[counter].rect.getPosition().x - generateRandom(30), enemyArray[counter].rect.getPosition().y + generateRandom(30));
						pickUpArray.push_back(pickUpCoin1);

						pickUpCoin1.rect.setPosition(enemyArray[counter].rect.getPosition().x + generateRandom(30), enemyArray[counter].rect.getPosition().y - generateRandom(30));
						pickUpArray.push_back(pickUpCoin1);

						counter3++;
					}
				}

				//Blood after enemy
				blood1.rect.setPosition(enemyArray[counter].rect.getPosition().x, enemyArray[counter].rect.getPosition().y);
				bloodArray.push_back(blood1);

				enemyArray.erase(iterEnemyArray);
				break;
			}
			counter++;
		}

		//Delete used projectile
		counter = 0;
		for (iter = projectilleArray.begin(); iter != projectilleArray.end(); iter++)
		{
			if (projectilleArray[counter].destroy == true)
			{
				projectilleArray.erase(iter);
				break;
			}
			counter++;
		}

		//Delete text
		counter = 0;
		for (iterText = textDisplayArray.begin(); iterText != textDisplayArray.end(); iterText++)
		{
			if (textDisplayArray[counter].destroy == true)
			{
				textDisplayArray.erase(iterText);
				break;
			}
		}


		//Delete Blood after enemy
		counter = 0;
		for (iterBlood = bloodArray.begin(); iterBlood != bloodArray.end(); iterBlood++)
		{
			if (!bloodArray[counter].getAlive())
			{
				bloodArray.erase(iterBlood);
				break;
			}

			counter++;
		}

		//Swapn the enemies
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
		{
			enemy1.rect.setPosition(generateRandom(window.getSize().x), generateRandom(window.getSize().y));
			enemyArray.push_back(enemy1);
		}

		//Fires Missle (by the space)
		if (elapsed1.asSeconds() >= 0.1)
		{
			clock.restart();
			//Fires Missle (by the space)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				soundShot.play();

				if (Player1.powerUpLevel == true) // PowerUp attack
				{
					projectille1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - projectille1.rect.getSize().x / 2 - generateRandom(50),
						Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectille1.rect.getSize().y / 2 - generateRandom(50));
					projectille1.direction = Player1.direction;
					projectilleArray.push_back(projectille1);

					projectille1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - projectille1.rect.getSize().x / 2,
						Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectille1.rect.getSize().y / 2);
					projectille1.direction = Player1.direction;
					projectilleArray.push_back(projectille1);

					projectille1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - projectille1.rect.getSize().x / 2 + generateRandom(50),
						Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectille1.rect.getSize().y / 2 + generateRandom(50));
					projectille1.direction = Player1.direction;
					projectilleArray.push_back(projectille1);
				}
				else if (Player1.novaAttack == true)
				{
					projectille1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - projectille1.rect.getSize().x / 2,
						Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectille1.rect.getSize().y / 2);
					projectille1.direction = 1;
					projectilleArray.push_back(projectille1);

					projectille1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - projectille1.rect.getSize().x / 2,
						Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectille1.rect.getSize().y / 2);
					projectille1.direction = 2;
					projectilleArray.push_back(projectille1);

					projectille1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - projectille1.rect.getSize().x / 2,
						Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectille1.rect.getSize().y / 2);
					projectille1.direction = 3;
					projectilleArray.push_back(projectille1);

					projectille1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - projectille1.rect.getSize().x / 2,
						Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectille1.rect.getSize().y / 2);
					projectille1.direction = 4;
					projectilleArray.push_back(projectille1);
				}
				else // Normal attack
				{
					projectille1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - projectille1.rect.getSize().x / 2,
						Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - projectille1.rect.getSize().y / 2);
					projectille1.direction = Player1.direction;
					projectilleArray.push_back(projectille1);
				}
			}
		}

		/*
		//Draw Ground
		counter = 0;
		for (iterGround = groundArray.begin(); iterGround != groundArray.end(); iterGround++)
		{
			//groundArray[counter].update();

			//window.draw(groundArray[counter].rect);
			window.draw(groundArray[counter].sprite);
			counter++;
		}
		*/

		//Draw Wall
		counter = 0;
		for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++)
		{
			wallArray[counter].update();

			window.draw(wallArray[counter].sprite);
			counter++;
		}

		//Draw Blood after enemy
		counter = 0;
		for (iterBlood = bloodArray.begin(); iterBlood != bloodArray.end(); iterBlood++)
		{
			bloodArray[counter].update();
			window.draw(bloodArray[counter].sprite);

			counter++;
		}

		//Draw pickUp Items
		counter = 0;
		for (iterCoin = pickUpArray.begin(); iterCoin != pickUpArray.end(); iterCoin++)
		{
			if (pickUpArray[counter].getInShop() == true)
			{
				window.draw(pickUpArray[counter].text);
			}

			pickUpArray[counter].update(); //Update pickup item
			window.draw(pickUpArray[counter].sprite);
			counter++;
		}

		//Draw projectilles
		counter = 0;
		for (iter = projectilleArray.begin(); iter != projectilleArray.end(); iter++)
		{
			projectilleArray[counter].update(); //Update Projectille
			window.draw(projectilleArray[counter].sprite);
			counter++;
		}

		//Draw Enemies
		counter = 0;
		for (iterEnemyArray = enemyArray.begin(); iterEnemyArray != enemyArray.end(); iterEnemyArray++)
		{
			enemyArray[counter].text.setString("HP " + to_string(enemyArray[counter].getHp()) + "/" + to_string(enemyArray[counter].getMaxHp()));
			window.draw(enemyArray[counter].text);

			enemyArray[counter].update(); //Update Enemies
			enemyArray[counter].updateMovement();
			window.draw(enemyArray[counter].sprite);
			counter++;
		}

		//cout << Player1.rect.getPosition().x << ", " << Player1.rect.getPosition().y << endl;

		//Draw HP Player text hp
		textHP.setString("Hp: " + to_string(Player1.HP) + "/" + to_string(Player1.maxHP));
		window.draw(textHP);
		textHP.setPosition(Player1.rect.getPosition().x - window.getSize().x / 2, Player1.rect.getPosition().y - window.getSize().y / 2);

		//Draw gil information
		text.setString("Gil: " + to_string(Player1.gil));
		window.draw(text);
		text.setPosition(Player1.rect.getPosition().x - window.getSize().x / 2, Player1.rect.getPosition().y - window.getSize().y / 2 + 25);

		//Draw Player
		window.draw(Player1.sprite);

		//Draw Text Displayer
		counter = 0;
		for (iterText = textDisplayArray.begin(); iterText != textDisplayArray.end(); iterText++)
		{
			textDisplayArray[counter].update();
			window.draw(textDisplayArray[counter].text);

			counter++;
		}

		// Update Player
		Player1.update();

		// Player View
		window.setView(view1);
		view1.setCenter(Player1.rect.getPosition());

		//Move the player
		Player1.updateMovement();

		window.display();
	}

	system("pasue");
	return 0;
}