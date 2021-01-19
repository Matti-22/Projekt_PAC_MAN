#pragma once
#include "Object.h"


class Wall : public Object
{
public:
	Wall(Texture& tex, Sprite spr, int pX, int pY);
	void draw(RenderWindow& window);
};

class Empty : public Object
{
public: 
	Empty(Texture& tex,Sprite spr, int pX, int pY);
	void draw(RenderWindow& window);
};

class Door : public Object
{
public:
	Door(Texture& tex, Sprite spr, int pX, int pY);
	void draw(RenderWindow& window);
};