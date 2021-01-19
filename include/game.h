#pragma once

#include <iostream>
#include <fstream>
#include <sstream> 

#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Enemy.h"
#include "Board.h"


using namespace sf;
using namespace std;

void loadingMap(string** map, string path);

void checkIfTouchEnemy(Enemy en1, Enemy en2, Player pacMan, RenderWindow& window, int score);
void startScreen(RenderWindow& window);
void win(RenderWindow& window, int score);
void checkIfPower(string** map, Enemy& en1, Enemy& en2, Player pacMan);

void game();
