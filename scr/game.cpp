#include "game.h"

void loadingMap(string** map, string path)
{
	ifstream openfile(path, ios::in);
	if (openfile.is_open())
	{
		string line;
		int i = 0;
		while (getline(openfile, line))
		{
			for (int column = 0; column < line.length(); column++)
			{
				map[i][column] = line[column];
			}
			i++;
		}
	}
	else
	{
		stringstream errorMsg;
		errorMsg << "File open error (path: " << path << ")" << endl;
		throw invalid_argument(errorMsg.str());
	}
}

void checkIfTouchEnemy(Enemy en1, Enemy en2, Player pacMan, RenderWindow& window, int score)
{
	Event event;
	stringstream ss;
	ss << score;
	string scor;
	ss >> scor;

	vector <Text> texBox;
	Font font;
	if (!font.loadFromFile("sources/font.ttf"))
	{
		stringstream errorMsg;
		errorMsg << "File open error (path: sources/font.ttf)" << endl;
		throw invalid_argument(errorMsg.str());
	}
	Text text;
	text.setFont(font);
	text.setCharacterSize(73);
	text.setFillColor(Color::Yellow);
	text.setStyle(Text::Style::Bold);

	text.setPosition(15, 0);
	text.setString("Game Over!!!!");
	texBox.push_back(text);

	text.setCharacterSize(40);
	text.setPosition(10, 200);
	text.setString("Your Score: ");
	texBox.push_back(text);


	text.setPosition(10, 350);
	text.setString("Press escape to exit");
	texBox.push_back(text);

	text.setCharacterSize(35);
	text.setPosition(346, 206);
	text.setString(scor);
	texBox.push_back(text);


	if (pacMan.getAfter() == "5" || en1.before == "4" || en2.before == "4")
	{
		auto start = chrono::high_resolution_clock::now();
		this_thread::sleep_for(2000ms);
		auto end = chrono::high_resolution_clock::now();
		window.clear(Color::Black);
		for (int i = 0; i < texBox.size(); i++)
		{
			window.draw(texBox[i]);
		}
		window.display();
		while (true)
		{
			if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
			{
				window.close();
				break;
			}
		}
	}
}

void startScreen(RenderWindow& window)
{
	vector <Text> texBox;
	Font font;
	if (!font.loadFromFile("sources/font.ttf"))
	{
		stringstream errorMsg;
		errorMsg << "File open error (path: sources/font.ttf)" << endl;
		throw invalid_argument(errorMsg.str());
	}
	Text text;
	text.setFont(font);
	text.setCharacterSize(105);
	text.setFillColor(Color::Yellow);
	text.setStyle(Text::Style::Bold);

	text.setPosition(15, 0);
	text.setString("PAC MAN");
	texBox.push_back(text);

	text.setCharacterSize(40);
	text.setPosition(15, 300);
	text.setString("Press enter to start");
	texBox.push_back(text);

	text.setPosition(15, 400);
	text.setString("Press escape to exit");
	texBox.push_back(text);

	window.clear(Color::Black);
	for (int i = 0; i < texBox.size(); i++)
	{
		window.draw(texBox[i]);
	}
	window.display();

	while (true)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			window.close();
			break;
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
		{
			window.clear(Color::Black);
			break;
		}
	}
}

void win(RenderWindow& window, int score)
{
	stringstream ss;
	ss << score;
	string scor;
	ss >> scor;

	vector <Text> texBox;
	Font font;
	if (!font.loadFromFile("sources/font.ttf"))
	{
		stringstream errorMsg;
		errorMsg << "File open error (path: sources/font.ttf)" << endl;
		throw invalid_argument(errorMsg.str());
	}
	Text text;
	text.setFont(font);
	text.setCharacterSize(90);
	text.setFillColor(Color::Yellow);
	text.setStyle(Text::Style::Bold);

	text.setPosition(10, 0);
	text.setString("You Won!!!!");
	texBox.push_back(text);

	text.setCharacterSize(40);
	text.setPosition(10, 200);
	text.setString("Your Score: ");
	texBox.push_back(text);

	text.setPosition(10, 350);
	text.setString("Press escape to exit");
	texBox.push_back(text);

	text.setCharacterSize(35);
	text.setPosition(346, 206);
	text.setString(scor);
	texBox.push_back(text);

	window.clear(Color::Black);
	for (int i = 0; i < texBox.size(); i++)
	{
		window.draw(texBox[i]);
	}
	window.display();

	while (true)
	{
		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			window.close();
			break;
		}
	}
}

void checkIfPower(string** map, Enemy& en1, Enemy& en2, Player pacMan)
{
	if (pacMan.posX == en1.posX && pacMan.posY == en1.posY || en1.before == "4")
	{
		en1.posX = en1.startPosX;
		en1.posY = en1.startPosY;
		en1.before = "3";
		pacMan.before = "3";
	}
	if (pacMan.posX == en2.posX && pacMan.posY == en2.posY || en2.before == "4")
	{
		en2.posX = en2.startPosX;
		en2.posY = en2.startPosY;
		en2.before = "3";
		pacMan.before = "3";
	}
}

void game()
{
	int leftTeleportPos_X, leftTeleportPos_Y;
	int rightTeleportPos_X, rightTeleportPos_Y;

	int score = 0;
	int howMuchFruit = 0;
	float power = 0;
	//Loading map
	string** map = new string * [21];
	for (int i = 0; i < 21; i++)
	{
		map[i] = new string[19];
	}
	loadingMap(map, "sources/map.txt");

	//Loading Teleports
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 19; j++)
		{

			if (map[i][j] == "7")
			{
				leftTeleportPos_X = j;
				leftTeleportPos_Y = i;

			}
			if (map[i][j] == "8")
			{
				rightTeleportPos_X = j;
				rightTeleportPos_Y = i;

			}
			if (map[i][j] == "0")
			{
				howMuchFruit++;
			}
		}
	}

	//Creating window
	Board board;
	RenderWindow window(VideoMode(665, 735), "pacMan");
	window.setFramerateLimit(30);
	window.clear(Color::Black);

	startScreen(window);

	//Creating structures 
	Texture texture;
	Sprite object;
	if (!texture.loadFromFile("sources/textures.png"))
	{
		stringstream errorMsg;
		errorMsg << "File open error (path: sources/textures.png)" << endl;
		throw invalid_argument(errorMsg.str());
	}
	Player pacMan(map, texture, object);
	Enemy blue(map, 1, texture, object);
	Enemy pink(map, 2, texture, object);


	while (true)
	{
		pacMan.moveAndColision(map, score, power, leftTeleportPos_X, leftTeleportPos_Y, rightTeleportPos_X, rightTeleportPos_Y);

		if (power != 0)
		{
			checkIfPower(map, blue, pink, pacMan);
			power-= 0.5;
		}
		else
		{
			checkIfTouchEnemy(pink, blue, pacMan, window, score);
		}

		pink.moveAndColison(map, leftTeleportPos_X, leftTeleportPos_Y, rightTeleportPos_X, rightTeleportPos_Y);
		blue.moveAndColison(map, leftTeleportPos_X, leftTeleportPos_Y, rightTeleportPos_X, rightTeleportPos_Y);
		
		if (score / 10 == howMuchFruit)
		{
			win(window,score);
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			window.close();
			break;
		}

		board.generate(window, map, pacMan, pink, blue, power);

		window.display();

		auto start = chrono::high_resolution_clock::now();
		this_thread::sleep_for(400ms);
		auto end = chrono::high_resolution_clock::now();
		window.clear(Color::Black);
	}
}

