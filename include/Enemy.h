#pragma once

#include "Object.h"

#include <time.h>

class Enemy : public Object
{
public:
	Enemy(string** map, int nr, Texture& tex, Sprite spr);

	string getBeforeMove();
	void moveAndColison(string** map, int leftTelPosX, int leftTelPosY, int rightTelPosX, int rightTelPosY);
	void draw(RenderWindow& window);

	string before = "3";
private:
	int nr;
	int direction = 0;
	string beforeMove;
	string afterLeft, afterUp, afterRight, afterDown;

	void moveUp(string** map);
	void moveDown(string** map);
	void moveLeft(string** map, int rightTelPosX, int rightTelPosY);
	void moveRight(string** map, int leftTelPosX, int leftTelPosY);
};

