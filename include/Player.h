#pragma once
#include "Object.h"
#include "Enemy.h"

#include <chrono>
#include <thread>

using namespace sf;
using namespace std;

class Player : public Object
{
public:
	Player(string** map, Texture& tex, Sprite spr);
	void moveAndColision(string **map, int& score, float& power, int leftTelPosX, int leftTelPosY, int rightTelPosX, int rightTelPosY);
	void draw(RenderWindow& window);
	string getAfter();
	string before = "3";
private:
	string after;

};

