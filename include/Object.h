#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

using namespace sf;
using namespace std;

class Object
{
public:
	virtual void draw(RenderWindow& window)
	{
		window.draw(sprite);
	}

	int posX = 0, posY = 0, startPosX = 0, startPosY = 0; 
	Sprite sprite;
};

