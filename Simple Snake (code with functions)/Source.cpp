#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

int MainMenu();
int DifMenu();
void Game(int pause);

int main()
{
	setlocale(0, "");
	srand(time(NULL));

	while (MainMenu()) {};

	//char _; cin >> _;
	return 0;
}

int MainMenu()
{
	int userInput;

	system("cls");

	cout << "\t Çìåéêà\n\n";
	cout << "[1] Èãðàòü\n";
	cout << "[0] Âûõîä\n\n";
	cout << "Ââîä: _\b";
	cin >> userInput;

	switch (userInput)
	{
	case 1:
		while (DifMenu()) {};
		return 1;
	case 0:
		return 0;
	default:

		system("cls");
		cout << "\t\x1b[91mÍÅÂÅÐÍÛÉ ÂÂÎÄ\x1b[0m";
		Sleep(700);
		return 1;
	}
}

int DifMenu()
{
	int userInput;

	system("cls");

	cout << "\t Âûáîð Ñëîæíîñòè\n\n";
	cout << "[1] Ëåãêî\n";
	cout << "[2] Íîðìàëüíî\n";
	cout << "[3] Ñëîæíî\n\n";
	cout << "[0] Âûõîä\n\n";
	cout << "Ââîä: _\b";
	cin >> userInput;

	switch (userInput)
	{
	case 1: Game(2000);
		return 0;
	case 2: Game(1000);
		return 0;
	case 3: Game(700);
		return 0;
	case 0:
		return 0;
	default:

		system("cls");
		cout << "\t\x1b[91mÍÅÂÅÐÍÛÉ ÂÂÎÄ\x1b[0m";
		Sleep(700);
		return 1;
	}
}

void Game(int pause)
{
	int grid[21][21]{};
	int zmeay[444][2]{};
	int lengthZ = 2;

	zmeay[0][0] = 10;
	zmeay[0][1] = 10;
	zmeay[1][0] = 10;
	zmeay[1][1] = 9;

	grid[10][10] = 1;
	grid[10][9] = 1;

	int directionY = 0;
	int directionX = 1;

	bool appl = 1;
	int aX, aY, xvostX, xvostY;

	while (true)
	{
		system("cls");

		int keyInput = 0;

		if (appl)
		{
			while (true)
			{
				aX = rand() % 21;
				aY = rand() % 21;

				if (!grid[aY][aX])
				{
					grid[aY][aX] = 2;
					appl = 0;
					break;
				}
			}
		}

		cout << "Äëèííà: " << lengthZ << endl;
		cout << "# # # # # # # # # # # # # # # # # # # # # # #" << endl;
		for (int i = 0; i < 21; i++)
		{
			cout << "# ";
			for (int j = 0; j < 21; j++)
			{
				switch (grid[i][j])
				{
				case 1: cout << "@ "; break;
				case 2: cout << "O "; break;
				default: cout << ". "; break;
				}
			}
			cout << "#\n";
		}
		cout << "# # # # # # # # # # # # # # # # # # # # # # #" << endl;

		Sleep(pause);

		if (_kbhit())
		{
			keyInput = _getch();

			switch (keyInput)
			{
				// W
			case 119:

				directionY = -1;
				directionX = 0;

				break;
				// S
			case 115:

				directionY = 1;
				directionX = 0;

				break;
				// A
			case 97:

				directionY = 0;
				directionX = -1;

				break;
				// D
			case 100:

				directionY = 0;
				directionX = 1;

				break;
			default:
				break;
			}
		}

		xvostY = zmeay[lengthZ - 1][0];
		xvostX = zmeay[lengthZ - 1][1];

		for (int i = lengthZ; i > 0; i--)
		{
			zmeay[i][0] = zmeay[i - 1][0];
			zmeay[i][1] = zmeay[i - 1][1];
		}

		zmeay[0][0] += directionY;
		zmeay[0][1] += directionX;

		if (zmeay[0][0] >= 0 && zmeay[0][0] <= 20 && zmeay[0][1] >= 0 && zmeay[0][1] <= 20)
		{
			if (grid[zmeay[0][0]][zmeay[0][1]] != 1)
			{
				if (grid[zmeay[0][0]][zmeay[0][1]] == 2)
				{
					lengthZ++;
					zmeay[lengthZ - 1][0] = xvostY;
					zmeay[lengthZ - 1][1] = xvostY;

					appl = 1;
				}


				grid[zmeay[0][0]][zmeay[0][1]] = 1;

				grid[xvostY][xvostX] = 0;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}

	}

	system("cls");

	cout << "\t\x1b[91mÏîðàæåíèå\x1b[0m";

	Sleep(700);
}