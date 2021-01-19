#include "Portal.h"

Portal::Portal(Texture& tex, Sprite spr, int pX, int pY)
{
	posX = pX;
	posY = pY;
	spr.setTexture(tex);
	spr.setTextureRect(IntRect(154, 42, 35, 35));
	spr.setPosition(pX, pY);
	sprite = spr;
}

void Portal::draw(RenderWindow& window)
{
	window.draw(sprite);
}