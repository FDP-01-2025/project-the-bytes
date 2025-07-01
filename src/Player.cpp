#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

int playerBoard[playerRows + 1][playerColumns + 1] = {0};
int Coordx = 0, Coordy = 0;
string Coordenate = "";
char position = ' ';

void drawBoard()
{
	cout << "                   Player\n            0 1 2 3 4 5 6 7 8 9\n";
	char letter = 'A';

	for (int i = 1; i < playerRows - 1; i++)
	{
		cout << "          " << letter++ << " ";
		for (int j = 1; j < playerColumns - 1; j++)
		{
			if (playerBoard[i][j] == 0 || playerBoard[i][j] == 2) // We use 0 to free cords, then we use 2 to ship sides
			{
				cout << ". ";
			}
			else if (playerBoard[i][j] == 1) // We use 1 to indicate that exist the ship
			{
				cout << "0 "; // The ship is printed
			}
		}
		cout << endl;
	}
}

void startingCoords()
{
	bool correct_cord;

	do
	{
		cout << "   Input a coordinates X & Y (Ex: C5): "; // We ask the user for a coord
		cin >> Coordenate;

		// Assci Table
		Coordx = Coordenate[0] - 64; // Char Letter to our needed number
		Coordy = Coordenate[1] - 47; // Char number to our needed number

		correct_cord = false; // Checking if input is correct

		if (Coordenate.size() == 2) // We check if the size of the coords it's ok or not. The Correct number of symbols is 2
		{
			for (char i = 'A'; i <= 'J'; i++)
			{
				if (Coordenate[0] == i) // We check if first char digited is a letter
				{
					correct_cord = true;
					break;
				}
			}

			if (!(isdigit(Coordenate[1]))) // We check if second char digited is a number
			{
				correct_cord = false; // It gonna be false if symbol isn't a number
			}
		}
	} while (!(correct_cord));
}

void startingPosition()
{
	do
	{
		cout << "   Enter position H/V: "; // The user write the orientation
		cin >> position;

		if ((position == 'V') || (position == 'v') || (position == 'h') || (position == 'H'))
		{
			break;
		}
		else
		{
			cout << "Please write a valid coords" << endl;
		}
	} while (true);
}

void newCordsplayer(int i)
{
	bool repeat_input = false;

	while (true)
	{
		if (playerBoard[Coordx][Coordy] == 0) // We checking if the first coordinate is free to put a ship
		{
			if (i > 6)
				playerBoard[Coordx][Coordy] = 1; // It gonna put ship with size 1
			break;
		}
		else // We use this else for ship coords coliision
		{
			startingCoords();
			if (i < 7) // Is mandatory do this until the last ship.
				startingPosition();
		}
	}

	if (i < 7)
		while (true) // It gonna stop if it's okay to put ships in any position
		{
			if (position == 'V') // This is only for vertical position
			{
				if (i == 1) // Size of the ship (one) box
				{
					if (Coordx < 8 && playerBoard[Coordx + 1][Coordy] == 0 && playerBoard[Coordx + 2][Coordy] == 0 && playerBoard[Coordx + 3][Coordy] == 0) // The ship must never leave the limits
					{
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx + 1][Coordy] = 1;
						playerBoard[Coordx + 2][Coordy] = 1;
						playerBoard[Coordx + 3][Coordy] = 1;
						break;
						// We checking if four long ship coordinates are free for ship
					}
					else // The ship exceeded the limits
					{
						repeat_input = true;
					}
				}
				else if (i >= 2 && i < 4) // Size of the ship (two) box
				{
					if (Coordx < 9 && playerBoard[Coordx + 1][Coordy] == 0 && playerBoard[Coordx + 2][Coordy] == 0) // The ship must never leave the limits
					{
						// Checking if 3 long ship coordinates are free for ship
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx + 1][Coordy] = 1;
						playerBoard[Coordx + 2][Coordy] = 1;
						break;
					}
					else // The ship exceeded the limits
					{
						repeat_input = true;
					}
				}
				else if (i > 3 && i < 7) // Size of the ship (three) box
				{
					if (Coordx < 10 && playerBoard[Coordx + 1][Coordy] == 0) // The ship must never leave the limits
					{
						// Checking if 2 long ship coordinates are free for ship
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx + 1][Coordy] = 1;
						break;
						// Checking if two long ship coordinates are free for ship
					}
					else // The ship exceeded the limits
					{
						repeat_input = true;
					}
				}
			}
			else if (position == 'H') // This is only to  horizontal position.
			{
				if (i == 1) // Size of the ship (one) box
				{
					// The ship must never leave the limits
					if (Coordy < 8 && playerBoard[Coordx][Coordy + 1] == 0 && playerBoard[Coordx][Coordy + 2] == 0 && playerBoard[Coordx][Coordy + 3] == 0)
					{
						// Checking if 4 long ship coordinates are free for ship
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx][Coordy + 1] = 1;
						playerBoard[Coordx][Coordy + 2] = 1;
						playerBoard[Coordx][Coordy + 3] = 1;
						break;
						// Checking if four long ship coordinates are free for ship
					}
					else // The ship exceeded the limits
					{
						repeat_input = true;
					}
				}
				else if (i >= 2 && i < 4) // Size of the ship (two) box
				{
					if (Coordy < 9 && playerBoard[Coordx][Coordy + 1] == 0 && playerBoard[Coordx][Coordy + 2] == 0)
					{
						// The ship must never leave the limits

						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx][Coordy + 1] = 1;
						playerBoard[Coordx][Coordy + 2] = 1;
						break;
						// Checking if three long ship coordinates are free for ship
					}
					else // The ship exceeded the limits
					{
						repeat_input = true;
					}
				}
				else if (i > 3 && i < 7) // Size of the ship (three) box
				{
					if (Coordy < 10 && playerBoard[Coordx][Coordy + 1] == 0) // The ship must never leave the limits
					{
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx][Coordy + 1] = 1;
						break;
						// Checking if two long ship coordinates are free for ship
					}
					else // The ship exceeded the limits
					{
						repeat_input = true;
					}
				}
			}

			if (repeat_input)
			{
				startingCoords();
				if (i < 7)
				{
					startingPosition(); // Is mandatory do this until the last ship.
				}
			}
		}

	for (int p = 0; p < 4; p++) // Area of the ship
	{
		if (playerBoard[Coordx + 1][Coordy] == 0)
		{
			playerBoard[Coordx + 1][Coordy] = 2;
		}

		if (playerBoard[Coordx][Coordy + 1] == 0)
		{
			playerBoard[Coordx][Coordy + 1] = 2;
		}

		if (playerBoard[Coordx - 1][Coordy] == 0)
		{
			playerBoard[Coordx - 1][Coordy] = 2;
		}

		if (playerBoard[Coordx][Coordy - 1] == 0)
		{
			playerBoard[Coordx][Coordy - 1] = 2;
		}

		if (playerBoard[Coordx + 1][Coordy + 1] == 0)
		{
			playerBoard[Coordx + 1][Coordy + 1] = 2;
		}

		if (playerBoard[Coordx - 1][Coordy - 1] == 0)
		{
			playerBoard[Coordx - 1][Coordy - 1] = 2;
		}

		if (playerBoard[Coordx + 1][Coordy - 1] == 0)
		{
			playerBoard[Coordx + 1][Coordy - 1] = 2;
		}

		if (playerBoard[Coordx - 1][Coordy + 1] == 0)
		{
			playerBoard[Coordx - 1][Coordy + 1] = 2;
		}

		if (playerBoard[Coordx + 1][Coordy] == 1)
		{
			Coordx++;
		}

		if (playerBoard[Coordx][Coordy + 1] == 1)
		{
			Coordy++;
		}
	}
}
