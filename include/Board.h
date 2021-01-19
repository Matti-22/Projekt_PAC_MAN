#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream> 

#include "Object.h"
#include "Wall.h"
#include "Player.h"
#include "Fruit.h"
#include "Portal.h"
#include "Enemy.h"

using namespace sf;
using namespace std;

class Board
{
public:
	void generate(RenderWindow& window, string** map, Player player, Enemy en1, Enemy en2, float& power);
private:
	vector <Object> objectMap;
};

