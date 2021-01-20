#pragma once
#include "Object.h"

class Fruit : public Object
{
public:
	Fruit(Texture& tex, Sprite spr, int pX, int pY);
	void draw(RenderWindow& window);
};

class PowerUP : public Object
{
public:
	PowerUP(Texture& tex, Sprite spr, int pX, int pY);
	void draw(RenderWindow& window);
};
