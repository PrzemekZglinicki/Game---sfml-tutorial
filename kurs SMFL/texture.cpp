#include "texture.h"

Texture::Texture()
{

	texturePlayer.loadFromFile("grafika/spriteWalk.png");

	textureEnemy.loadFromFile("grafika/spriteEnemy.png");

	textureFireball.loadFromFile("grafika/fireball.png");

	texturePowerUp.loadFromFile("grafika/weapons.png");
	
	if (!textureBlood.loadFromFile("grafika/blood.gif"))
	{
		return;
	}

	if (!textureCoin.loadFromFile("grafika/coin.png"))
	{
		return;
	}

	if (!textureCoin2.loadFromFile("grafika/coin4.png"))
	{
		return;
	}

	if (!textureWall.loadFromFile("grafika/Back_002.png"))
	{
		return;
	}

	if (!textureCrate.loadFromFile("grafika/Crate_001.png"))
	{
		return;
	}

	if (!textureGround.loadFromFile("grafika/tile.png"))
	{
		return;
	}

	if (!textureFood.loadFromFile("grafika/food.png"))
	{
		return;
	}

	if (!texturePotion.loadFromFile("grafika/potion.png"))
	{
		return;
	}
}