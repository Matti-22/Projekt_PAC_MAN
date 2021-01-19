#include "Fruit.h"

Fruit::Fruit(Texture& tex, Sprite spr, int pX, int pY)
{
	posX = pX;
	posY = pY;
	spr.setTexture(tex);
	spr.setTextureRect(IntRect(40, 42, 35, 35));
	spr.setPosition(pX, pY);
	sprite = spr;
}

void Fruit::draw(RenderWindow& window)
{
	window.draw(sprite);
}

PowerUP::PowerUP(Texture& tex, Sprite spr, int pX, int pY)
{
	posX = pX;
	posY = pY;
	spr.setTexture(tex);
	spr.setTextureRect(IntRect(78, 42, 35, 35));
	spr.setPosition(pX, pY);
	sprite = spr;
}

void PowerUP::draw(RenderWindow& window)
{
	window.draw(sprite);
}