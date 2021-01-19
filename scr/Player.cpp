#include "Player.h"

Player::Player(string** map, Texture& tex, Sprite spr)
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (map[i][j] == "4")
			{

				posX = j;
				posY = i;
				startPosX = j;
				startPosY = i;

			}
		}
	}
	spr.setTexture(tex);
	spr.setTextureRect(IntRect(3, 4, 35, 35));
	spr.setPosition(posX * 35, posY * 35);
	sprite = spr;
}

void Player::draw(RenderWindow& window)
{
	window.draw(sprite);
}

void Player::moveAndColision(string** map, int& score, float& power, int leftTelPosX, int leftTelPosY, int rightTelPosX, int rightTelPosY)
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Up))
	{
		after = map[posY - 1][posX];
		if (after == "1" || after == "6")
		{
			goto noMove;
		}
		map[posY][posX] = before;
		posY--;
		map[posY][posX] = "4";
		if (after == "0")
		{
			before = "3";
			score += 10;
		}
		else if (after == "2")
		{
			power = 10;
			before = "3";
		}
		else
		{
			before = after;
		}
		sprite.setTextureRect(IntRect(40, 4, 35, 35));

	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Down))
	{
		after = map[posY + 1][posX];
		if (after == "1" || after == "6")
		{
			goto noMove;
		}
		map[posY][posX] = before;
		posY++;
		map[posY][posX] = "4";
		if (after == "0")
		{
			before = "3";
			score += 10;
		}
		else if (after == "2")
		{
			power = 10;
			before = "3";
		}
		else
		{
			before = after;
		}
		sprite.setTextureRect(IntRect(116, 4, 35, 35));
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left))
	{
		after = map[posY][posX - 1];
		if (after == "1" || after == "6")
		{
			goto noMove;
		}
		map[posY][posX] = before;
		posX--;
		map[posY][posX] = "4";
		if (after == "0")
		{
			before = "3";
			score += 10;
		}
		else if (after == "2")
		{
			power = 10;
			before = "3";
		}
		else
		{
			before = after;
		}
		if (before == "7")
		{
			map[posY][posX] = before;
			posX = rightTelPosX;
			posY = rightTelPosY;
			map[posY][posX] = "4";
			before = "8";
		}
		sprite.setTextureRect(IntRect(3, 4, 35, 35));
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Right))
	{
		after = map[posY][posX + 1];
		if (after == "1" || after == "6")
		{
			goto noMove;
		}
		map[posY][posX] = before;
		posX++;
		map[posY][posX] = "4";
		if (after == "0")
		{
			before = "3";
			score += 10;
		}
		else if (after == "2")
		{
			power = 10;
			before = "3";
		}
		else
		{
			before = after;
		}
		if (before == "8")
		{
			map[posY][posX] = before;
			posX = leftTelPosX;
			posY = leftTelPosY;
			map[posY][posX] = "4";
			before = "7";
		}
		sprite.setTextureRect(IntRect(79, 4, 35, 35));
	}
noMove:
	cout;
}

string Player::getAfter()
{
	return after;
}