#pragma once

#include "Object.h"

class Portal : public Object
{
public:
	Portal(Texture& tex, Sprite spr, int pX, int pY);
	void draw(RenderWindow& window);
};
