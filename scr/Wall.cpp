#include "Wall.h"

Wall::Wall(Texture& tex, Sprite spr, int pX, int pY)
{
	posX = pX;
	posY = pY;
	spr.setTexture(tex);
	spr.setTextureRect(IntRect(2, 42, 35, 35));
	spr.setPosition(pX, pY);
	sprite = spr;
}

void Wall::draw(RenderWindow& window)
{
	window.draw(sprite);
}

Empty::Empty(Texture& tex, Sprite spr, int pX, int pY)
{
	posX = pX;
	posY = pY;
	spr.setTexture(tex);
	spr.setTextureRect(IntRect(120, 40, 35, 35));
	spr.setPosition(pX, pY);
	sprite = spr;
}

void Empty::draw(RenderWindow& window)
{
	window.draw(sprite);
}

Door::Door(Texture& tex, Sprite spr, int pX, int pY)
{
	posX = pX;
	posY = pY;
	spr.setTexture(tex);
	spr.setTextureRect(IntRect(154, 4, 35, 35));
	spr.setPosition(pX, pY);
	sprite = spr;
}

void Door::draw(RenderWindow& window)
{
	window.draw(sprite);
}