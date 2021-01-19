#include "Enemy.h"

Enemy::Enemy(string** map, int nr, Texture& tex, Sprite spr)
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (map[i][j] == "5")
			{
				posX = j - nr + 1;
				posY = i;
				startPosX = j - nr + 1;
				startPosY = i;
			}
		}
	}
	this->nr = nr;
	spr.setTexture(tex);
	spr.setTextureRect(IntRect(1 * nr - 76, 76, 35, 35));
	spr.setPosition(posX * 35, posY * 35);
	sprite = spr;
}

string Enemy::getBeforeMove()
{
	return beforeMove;
}

void Enemy::draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Enemy::moveUp(string** map)
{
	map[posY][posX] = before;
	posY--;
	map[posY][posX] = "5";
	before = afterUp;
	beforeMove = "Up";
}

void Enemy::moveDown(string** map)
{
	map[posY][posX] = before;
	posY++;
	map[posY][posX] = "5";
	before = afterDown;
	beforeMove = "Down";
}

void Enemy::moveLeft(string** map, int rightTelPosX, int rightTelPosY)
{
	map[posY][posX] = before;
	posX--;
	map[posY][posX] = "5";
	before = afterLeft;
	if (before == "7")
	{
		map[posY][posX] = before;
		posX = rightTelPosX;
		posY = rightTelPosY;
		map[posY][posX] = "5";
		before = "8";
	}
	beforeMove = "Left";
}

void Enemy::moveRight(string** map, int leftTelPosX, int leftTelPosY)
{
	map[posY][posX] = before;
	posX++;
	map[posY][posX] = "5";
	before = afterRight;
	if (before == "8")
	{
		map[posY][posX] = before;
		posX = leftTelPosX;
		posY = leftTelPosY;
		map[posY][posX] = "5";
		before = "7";
	}
	beforeMove = "Right";
}


void Enemy::moveAndColison(string** map, int leftTelPosX, int leftTelPosY, int rightTelPosX, int rightTelPosY)
{
	srand(time(NULL));
	afterUp = map[posY - 1][posX];
	afterDown = map[posY + 1][posX];
	afterLeft = map[posY][posX - 1];
	afterRight = map[posY][posX + 1];

	int pomLeft = 0, pomRight = 0, pomUp = 0, pomDown = 0, pomRand;

	if (afterLeft != "1" && afterLeft != "5")
	{
		pomLeft++;
		direction++;
	}
	if (afterRight != "1" && afterRight != "5")
	{
		pomRight++;
		direction++;
	}
	if (afterUp != "1" && afterUp != "5")
	{
		pomUp++;
		direction++;
	}
	if (afterDown != "1" && afterDown != "5")
	{
		pomDown++;
		direction++;
	}

	//Dor
	if (afterUp == "6")
	{
		moveUp(map);
		goto next;
	}
	if (before == "6")
	{
		moveUp(map);
		goto next;
	}
	if (afterDown == "6") direction--;

	//Moving
	if (direction == 0) goto next;
	else if (direction == 1)
	{
		if (afterLeft != "1" && afterLeft != "5")
		{
			moveLeft(map, rightTelPosX, rightTelPosY);
			goto next;
		}
		if (afterRight != "1" && afterRight != "5")
		{
			moveRight(map, leftTelPosX, leftTelPosY);
			goto next;
		}
		if (afterUp != "1" && afterUp != "5")
		{
			moveUp(map);
			goto next;
		}
		if (afterDown != "1" && afterDown != "5")
		{
			moveDown(map);
			goto next;
		}
	}
	else if (direction == 2)
	{
		if (pomLeft == 1 && pomRight == 1 && beforeMove == "Right") 
		{
			moveRight(map, leftTelPosX, leftTelPosY);
			goto next;
		}
		if (pomLeft == 1 && pomRight == 1 && beforeMove == "Left") 
		{
			moveLeft(map, rightTelPosX, rightTelPosY);
			goto next;
		}
		if (pomUp == 1 && pomDown == 1 && beforeMove == "Down") 
		{
			moveDown(map);
			goto next;
		}
		if (pomUp == 1 && pomDown == 1 && beforeMove == "Up") 
		{
			moveUp(map);
			goto next;
		}
		if (pomLeft == 1 && pomRight == 1 && beforeMove == "Up")
		{
			pomRand = rand() % 2 + 1;
			if (pomRand == 1) 
			{
				moveLeft(map, rightTelPosX, rightTelPosY);
				goto next;
			}
			if (pomRand == 2)
			{
				moveRight(map, leftTelPosX, leftTelPosY);
				goto next;
			}
		}
		
		if (pomLeft == 1 && pomDown == 1)
		{
			pomRand = rand() % 2 + 1;
			if (pomRand == 1) 
			{
				moveLeft(map, rightTelPosX, rightTelPosY);
				goto next;
			}
			if (pomRand == 2) 
			{
				moveDown(map);
				goto next;
			}
		}
		
		if (pomRight == 1 && pomDown == 1)
		{
			pomRand = rand() % 2 + 1;
			if (pomRand == 1)
			{
				moveRight(map, leftTelPosX, leftTelPosY);
				goto next;
			}
			if (pomRand == 2) 
			{
				moveDown(map);
				goto next;
			}
		}
		if (pomLeft == 1 && pomUp == 1)
		{
			pomRand = rand() % 2 + 1;
			if (pomRand == 1) 
			{
				moveLeft(map, rightTelPosX, rightTelPosY);
				goto next;
			}
			if (pomRand == 2) 
			{
				moveUp(map);
				goto next;
			}
		}
		if (pomRight == 1 && pomUp == 1)
		{
			pomRand = rand() % 2 + 1;
			if (pomRand == 1)
			{
				moveRight(map, leftTelPosX, leftTelPosY);
				goto next;
			}
			if (pomRand == 2)
			{
				moveUp(map);
				goto next;
			}
		}
	}
	else if (direction == 3)
	{
		if (pomLeft == 1 && pomUp == 1 && pomRight == 1)
		{
			pomRand = rand() % 3 + 1;
			if(pomRand == 1) 
			{
				moveLeft(map, rightTelPosX, rightTelPosY);
				goto next;
			}
			if(pomRand == 2) 
			{
				moveUp(map);
				goto next;
			}
			if(pomRand == 3) 
			{
				moveRight(map, leftTelPosX, leftTelPosY);
				goto next;
			}
		}
		if (pomUp == 1 && pomRight == 1 && pomDown == 1)
		{
			pomRand = rand() % 3 + 1;
			if (pomRand == 1)
			{
				moveUp(map);
				goto next;
			}
			if (pomRand == 2) 
			{
				moveRight(map, leftTelPosX, leftTelPosY);
				goto next;
			}
			if (pomRand == 3) 
			{
				moveDown(map);
				goto next;
			}
		}
		if (pomRight == 1 && pomDown == 1 && pomLeft == 1)
		{
			pomRand = rand() % 3 + 1;
			if (pomRand == 1) 
			{
				moveRight(map, leftTelPosX, leftTelPosY);
				goto next;
			}
			if (pomRand == 2)
			{
				moveDown(map);
				goto next;
			}
			if (pomRand == 3) 
			{
				moveLeft(map, rightTelPosX, rightTelPosY);
				goto next;
			}
		}
		if (pomDown == 1 && pomLeft == 1 && pomUp == 1)
		{
			pomRand = rand() % 3 + 1;
			if (pomRand == 1) 
			{
				moveDown(map);
				goto next;
			}
			if (pomRand == 2) 
			{
				moveLeft(map, rightTelPosX, rightTelPosY);
				goto next;
			}
			if (pomRand == 3)
			{
				moveUp(map);
				goto next;
			}
		}
	}
	else 
	{
		pomRand = rand() % 4 + 1;
		if (pomRand == 1) 
		{
			moveLeft(map, rightTelPosX, rightTelPosY);
			goto next;
		}
		if (pomRand == 2) 
		{
			moveRight(map, leftTelPosX, leftTelPosY);
			goto next;
		}
		if (pomRand == 3) 
		{
			moveUp(map);
			goto next;
		}
		if (pomRand == 4)
		{
			moveDown(map);
			goto next;
		}
	}
next:
	direction = 0;
}