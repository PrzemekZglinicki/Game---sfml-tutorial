#include<iostream>
#include<SFML/Graphics.hpp>

class Texture
{
public:
	Texture();

	sf::Texture texturePlayer;
	sf::Texture textureEnemy;
	sf::Texture textureFireball;
	sf::Texture texturePowerUp;
	sf::Texture textureBlood;
	//Texture of the coin
	sf::Texture textureCoin;
	//Texture of the coin
	sf::Texture textureCoin2;
	//Texture of the Wall
	sf::Texture textureWall;
	//Texture of the Crate
	sf::Texture textureCrate;
	sf::Texture textureGround;
	sf::Texture textureFood;
	sf::Texture texturePotion;
};