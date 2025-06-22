#include "Player.h"
#include <iostream>
#include <String>

using namespace std;

int playerBoard[playerRows + 1][playerColumns + 1] = {0};

Player::Player()
{
	Coordenate = "";
	position = ' ';
	Coordx = 0;
	Coordy = 0;
}
Player::Player(int a, int b, string c, char d)
{
	Coordx = a;
	Coordy = b;
	Coordenate = c;
	position = d;
}


void Player::drawBoard()
{
	cout << "                   Player\n            0 1 2 3 4 5 6 7 8 9\n";
	char letter = 'A';

	for (int i = 1; i < playerRows - 1; i++)
	{
		cout << "          " << letter++ << " ";
		for (int j = 1; j < playerColumns - 1; j++)
		{

			if (playerBoard[i][j] == 0 || playerBoard[i][j] == 2) // 0 for free Coordinate; 2 for Ship sides
				cout << ". ";
			else if (playerBoard[i][j] == 1) // 1 for SHIP
				cout << "0 ";
		}
		cout << endl;
	}
}
void Player::startingCoords()
{
	bool correct_cord;

	do
	{
		cout << "   Input a coordinates X & Y (Ex.: A5): ";
		cin >> Coordenate;

		// Assci Table
		Coordx = Coordenate[0] - 64; // Char Letter to our needed number
		Coordy = Coordenate[1] - 47; // Char number to our needed number

		// Checking if input is correct
		correct_cord = false;

		if (Coordenate.size() == 2)
		{ // Correct number of symbols - 2
			for (char i = 'A'; i <= 'J'; i++)
			{
				if (Coordenate[0] == i)
				{ // Checking if FIRST entered symbol is equal to a letter coordinate
					correct_cord = true;
					break;
				}
			}

			if (!(isdigit(Coordenate[1])))
			{						  // Checking if SECOND entered symbol is a digit
				correct_cord = false; // It will be false if symbol isn't a digit
			}
		}

	} while (!(correct_cord));
}
void Player::startingPosition()
{
	do
	{
		cout << "   Enter position H/V: ";
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
void Player::newCordsplayer(int i)
{
	bool repeat_input = false;

	while (true)
	{
		if (playerBoard[Coordx][Coordy] == 0)
		{ // checking if first coordinate is free for ship

			if (i > 6)
				playerBoard[Coordx][Coordy] = 1; // It puts 1 size ships here
			break;
		}
		else
		{ // Else for ship coordinates collision
			startingCoords();
			if (i < 7)
				startingPosition(); // Position is needed UNTIL 7th ship
		}
	}

	if (i < 7)
		while (true)
		{ // It will stop if it's okay to put ship into board
			if (position == 'V')
			{ // VERTICAL POSITION **************************************************************
				if (i == 1)
				{
					if (Coordx < 8)
					{ // Ship wouldn't pass a bottom border
						if (playerBoard[Coordx + 1][Coordy] == 0 && playerBoard[Coordx + 2][Coordy] == 0 && playerBoard[Coordx + 3][Coordy] == 0)
						{ // Checking if 4 long ship coordinates are free for ship
							playerBoard[Coordx][Coordy] = 1;
							playerBoard[Coordx + 1][Coordy] = 1;
							playerBoard[Coordx + 2][Coordy] = 1;
							playerBoard[Coordx + 3][Coordy] = 1;
							break;
						}
						else
						{
							repeat_input = true;
						}
					}
					else
					{ // ship passes a border
						repeat_input = true;
					}
				}
				else if (i >= 2 && i < 4)
				{
					if (Coordx < 9)
					{ // Ship wouldn't pass a bottom border
						if (playerBoard[Coordx + 1][Coordy] == 0 && playerBoard[Coordx + 2][Coordy] == 0)
						{ // Checking if 3 long ship coordinates are free for ship
							playerBoard[Coordx][Coordy] = 1;
							playerBoard[Coordx + 1][Coordy] = 1;
							playerBoard[Coordx + 2][Coordy] = 1;
							break;
						}
						else
						{
							repeat_input = true;
						}
					}
					else
					{
						repeat_input = true;
					}
				}
				else if (i > 3 && i < 7)
				{
					if (Coordx < 10)
					{ // Ship wouldn't pass a bottom border
						if (playerBoard[Coordx + 1][Coordy] == 0)
						{ // Checking if 2 long ship coordinates are free for ship
							playerBoard[Coordx][Coordy] = 1;
							playerBoard[Coordx + 1][Coordy] = 1;
							break;
						}
						else
						{
							repeat_input = true;
						}
					}
					else
					{
						repeat_input = true;
					}
				}
			}
			else if (position == 'H')
			{ // HORIZONTAL POSITION **************************************************************
				if (i == 1)
				{
					if (Coordy < 8)
					{ // Ship wouldn't pass a RIGHT border
						if (playerBoard[Coordx][Coordy + 1] == 0 && playerBoard[Coordx][Coordy + 2] == 0 && playerBoard[Coordx][Coordy + 3] == 0)
						{ // Checking if 4 long ship coordinates are free for ship
							playerBoard[Coordx][Coordy] = 1;
							playerBoard[Coordx][Coordy + 1] = 1;
							playerBoard[Coordx][Coordy + 2] = 1;
							playerBoard[Coordx][Coordy + 3] = 1;
							break;
						}
						else
						{
							repeat_input = true;
						}
					}
					else
					{ // ship passes a border
						repeat_input = true;
					}
				}
				else if (i >= 2 && i < 4)
				{
					if (Coordy < 9)
					{ // Ship wouldn't pass a RIGHT border
						if (playerBoard[Coordx][Coordy + 1] == 0 && playerBoard[Coordx][Coordy + 2] == 0)
						{ // Checking if 3 long ship coordinates are free for ship
							playerBoard[Coordx][Coordy] = 1;
							playerBoard[Coordx][Coordy + 1] = 1;
							playerBoard[Coordx][Coordy + 2] = 1;
							break;
						}
						else
						{
							repeat_input = true;
						}
					}
					else
					{
						repeat_input = true;
					}
				}
				else if (i > 3 && i < 7)
				{
					if (Coordy < 10)
					{ // Ship wouldn't pass a RIGHT border
						if (playerBoard[Coordx][Coordy + 1] == 0)
						{ // Checking if 2 long ship coordinates are free for ship
							playerBoard[Coordx][Coordy] = 1;
							playerBoard[Coordx][Coordy + 1] = 1;
							break;
						}
						else
						{
							repeat_input = true;
						}
					}
					else
					{
						repeat_input = true;
					}
				}
			}

			if (repeat_input)
			{
				startingCoords();
				if (i < 7)
					startingPosition(); // Position is needed UNTIL 7th ship
			}
		}
	// Area around the ship
	for (int p = 0; p < 4; p++)
	{

		if (playerBoard[Coordx + 1][Coordy] == 0)
			playerBoard[Coordx + 1][Coordy] = 2;
		if (playerBoard[Coordx][Coordy + 1] == 0)
			playerBoard[Coordx][Coordy + 1] = 2;
		if (playerBoard[Coordx - 1][Coordy] == 0)
			playerBoard[Coordx - 1][Coordy] = 2;
		if (playerBoard[Coordx][Coordy - 1] == 0)
			playerBoard[Coordx][Coordy - 1] = 2;
		if (playerBoard[Coordx + 1][Coordy + 1] == 0)
			playerBoard[Coordx + 1][Coordy + 1] = 2;
		if (playerBoard[Coordx - 1][Coordy - 1] == 0)
			playerBoard[Coordx - 1][Coordy - 1] = 2;
		if (playerBoard[Coordx + 1][Coordy - 1] == 0)
			playerBoard[Coordx + 1][Coordy - 1] = 2;
		if (playerBoard[Coordx - 1][Coordy + 1] == 0)
			playerBoard[Coordx - 1][Coordy + 1] = 2;

		if (playerBoard[Coordx + 1][Coordy] == 1)
			Coordx++;
		if (playerBoard[Coordx][Coordy + 1] == 1)
			Coordy++;
	}
}