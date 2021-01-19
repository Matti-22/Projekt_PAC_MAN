#include "Board.h"

void Board::generate(RenderWindow& window, string** map, Player player, Enemy en1, Enemy en2, float& power)
{
	Sprite object;
	vector <Object> board;
	Texture objecTex;
	if (!objecTex.loadFromFile("sources/textures.png"))
	{
		stringstream errorMsg;
		errorMsg << "File open error (path: sources/textures.png)" << endl;
		throw invalid_argument(errorMsg.str());
	}
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (map[j][i] == "0")
			{
				Fruit f(objecTex, object, i * 35, j * 35);
				board.push_back(f);
			}

			if (map[j][i] == "1")
			{
				Wall w(objecTex, object, i * 35, j * 35);
				board.push_back(w);
			}

			if (map[j][i] == "2")
			{
				PowerUP p(objecTex, object, i * 35, j * 35);
				board.push_back(p);
			}

			if (map[j][i] == "3")
			{
				Empty e(objecTex, object, i * 35, j * 35);
				board.push_back(e);
			}

			if (map[j][i] == "4")
			{
				player.sprite.setPosition(i * 35, j * 35);
				board.push_back(player);
			}

			if (map[j][i] == "5")
			{
				if (power != 0)
				{
					if (i == en1.posX && j == en1.posY)
					{
						en1.sprite.setPosition(i * 35, j * 35);
						en1.sprite.setTextureRect(IntRect(115, 76, 35, 35));
						board.push_back(en1);
					}
					if (i == en2.posX && j == en2.posY)
					{
						en2.sprite.setPosition(i * 35, j * 35);
						en2.sprite.setTextureRect(IntRect(115, 76, 35, 35));
						board.push_back(en2);
					}
				}
				else
				{
					if (i == en1.posX && j == en1.posY)
					{
						en1.sprite.setPosition(i * 35, j * 35);
						en1.sprite.setTextureRect(IntRect(77, 76, 35, 35));
						board.push_back(en1);
					}
					if (i == en2.posX && j == en2.posY)
					{
						en2.sprite.setPosition(i * 35, j * 35);
						en2.sprite.setTextureRect(IntRect(1, 76, 35, 35));
						board.push_back(en2);
					}
				}
			}

			if (map[j][i] == "6")
			{
				Door d(objecTex, object, i * 35, j * 35);
				board.push_back(d);
			}

			if (map[j][i] == "7")
			{
				Portal porL(objecTex, object, i * 35, j * 35);
				board.push_back(porL);
			}

			if (map[j][i] == "8")
			{
				Portal porP(objecTex, object, i * 35, j * 35);
				board.push_back(porP);
			}
	
		}
	}
	objectMap = board;
	for (int i = 0; i < board.size(); i++)
	{
		board[i].draw(window);
	}
	board.clear();
}

