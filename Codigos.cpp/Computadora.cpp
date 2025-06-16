#include "Computadora.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // time for random

using namespace std;

int gameBoard[Filas + 1][Columns + 1] = {0};

CPU::CPU()
{
	srand((unsigned int)time(NULL)); // To generate a random number
	pos = ' ';
	coordenateX = 1 + (rand() % 10); // To randomize the position in X
	coordenateY = 1 + (rand() % 10); // To randomize the coordenate in Y
	posicion = rand() % 2;			 // To randomize the coordenate of the positions

	switch (posicion)
	{
	case 0:
		pos = 'Horizontal';
		break;
	case 1:
		pos = 'Vertical';
		break;
	}
}

void CPU::Update_Coord(int i)
{
	bool repeatEntrance = false;

	while (true)
	{
		if (gameBoard[coordenateX][coordenateY] == 0) // We check if the coordinate is free
		{
			if (i > 6)
			{
				gameBoard[coordenateX][coordenateY] = 1; // Puts ships with size 1x1
				break;
			}
		}
		else // Else for ship coordinates collision
		{
			srand((unsigned int)time(NULL)); // To randomize time to generate a number aleatory

			coordenateX = 1 + (rand() % 10); // To randomize the coordenate in X
			coordenateY = 1 + (rand() % 10); // To randomize the coordenate in Y

			if (i < 7) // Position is necesary until the last ship (6)
			{
				posicion = rand() % 2;

				switch (posicion) // Two cases, Horizontal or Vertical
				{
				case 0:
					pos = 'Horizontal';
					break;
				case 1:
					pos = 'Vertical';
					break;
				}
			}
		}
	}

	if (i < 7)
	{
		while (true) // It gonna stop if it's ok to put ships into de gameboard
		{
			if (pos == 'Vertical') // It is for the vertical position
			{
				if (i == 1) // Size of the ship (one) box
				{
					if (coordenateX < 8) // The ship must never leave the limits
					{
						if (gameBoard[coordenateX + 1][coordenateY] == 0 && gameBoard[coordenateX + 2][coordenateY] == 0 && gameBoard[coordenateX + 3][coordenateY] == 0)
						{
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX + 1][coordenateY] = 1;
							gameBoard[coordenateX + 2][coordenateY] = 1;
							gameBoard[coordenateX + 3][coordenateY] = 1;
							break;
							// Checking if four long ship coordinates are free for ship
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else // The ship exceeded the limits
					{
						repeatEntrance = true;
					}
				}
				else if (i >= 2 && i < 4) // Size of the ship (two) box
				{
					if (coordenateX < 9) // The ship must never leave the limits
					{
						if (gameBoard[coordenateX + 1][coordenateY] == 0 && gameBoard[coordenateX + 2][coordenateY] == 0)
						{
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX + 1][coordenateY] = 1;
							gameBoard[coordenateX + 2][coordenateY] = 1;
							break;
							// Checking if three long ship coordinates are free for ship
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else // The ship exceeded the limits
					{
						repeatEntrance = true;
					}
				}
				else if (i > 3 && i < 7) // Size of the ship (three) box
				{
					if (coordenateX < 10) // The ship must never leave the limits
					{
						if (gameBoard[coordenateX + 1][coordenateY] == 0)
						{
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX + 1][coordenateY] = 1;
							break;
							// Checking if two long ship coordinates are free for ship
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else // The ship exceeded the limits
					{
						repeatEntrance = true;
					}
				}
			}
			else if (pos == 'Horizontal') // It is for the vertical position
			{
				if (i == 1) // Size of the ship (one) box
				{
					if (coordenateY < 8) // The ship must never leave the limits
					{
						if (gameBoard[coordenateX][coordenateY + 1] == 0 && gameBoard[coordenateX][coordenateY + 2] == 0 && gameBoard[coordenateX][coordenateY + 3] == 0)
						{ // Checking if four long ship coordinates are free for ship
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX][coordenateY + 1] = 1;
							gameBoard[coordenateX][coordenateY + 2] = 1;
							gameBoard[coordenateX][coordenateY + 3] = 1;
							break;
							// Checking if four long ship coordinates are free for ship
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else // The ship exceeded the limits
					{
						repeatEntrance = true;
					}
				}
				else if (i >= 2 && i < 4) // Size of the ship (two) box
				{
					if (coordenateY < 9) // The ship must never leave the limits
					{
						if (gameBoard[coordenateX][coordenateY + 1] == 0 && gameBoard[coordenateX][coordenateY + 2] == 0)
						{
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX][coordenateY + 1] = 1;
							gameBoard[coordenateX][coordenateY + 2] = 1;
							break;
							// Checking if three long ship coordinates are free for ship
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else // The ship exceeded the limits
					{
						repeatEntrance = true;
					}
				}
				else if (i > 3 && i < 7) // Size of the ship (three) box
				{
					if (coordenateY < 10) // The ship must never leave the limits
					{
						if (gameBoard[coordenateX][coordenateY + 1] == 0)
						{
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX][coordenateY + 1] = 1;
							break;
							// Checking if two long ship coordinates are free for ship
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else // The ship exceeded the limits
					{
						repeatEntrance = true;
					}
				}
			}
			if (repeatEntrance)
			{
				srand((unsigned int)time(NULL)); // To randomize time to generate a number aleatory

				coordenateX = 1 + (rand() % 10); // To randomize the
				coordenateY = 1 + (rand() % 10);

				if (i < 7) // Posicion is mandatory until the last ship (6)
				{
					posicion = rand() % 2;

					switch (posicion) // Two options, posicion Horizontal or posicion Vertical
					{
					case 0:
						pos = 'Horizontal';
						break;
					case 1:
						pos = 'Vertical';
						break;
					}
				}
			}
		}
	}
	for (int p = 0; p < 4; p++) // the value of all the boxes surrounding (x, y) from 0 to 2.
	{

		if (gameBoard[coordenateX + 1][coordenateY] == 0)
		{
			gameBoard[coordenateX + 1][coordenateY] = 2;
		}
		if (gameBoard[coordenateX][coordenateY + 1] == 0)
		{
			gameBoard[coordenateX][coordenateY + 1] = 2;
		}
		if (gameBoard[coordenateX - 1][coordenateY] == 0)
		{
			gameBoard[coordenateX - 1][coordenateY] = 2;
		}
		if (gameBoard[coordenateX][coordenateY - 1] == 0)
		{
			gameBoard[coordenateX][coordenateY - 1] = 2;
		}
		if (gameBoard[coordenateX + 1][coordenateY + 1] == 0)
		{
			gameBoard[coordenateX + 1][coordenateY + 1] = 2;
		}
		if (gameBoard[coordenateX - 1][coordenateY - 1] == 0)
		{
			gameBoard[coordenateX - 1][coordenateY - 1] = 2;
		}
		if (gameBoard[coordenateX + 1][coordenateY - 1] == 0)
		{
			gameBoard[coordenateX + 1][coordenateY - 1] = 2;
		}
		if (gameBoard[coordenateX - 1][coordenateY + 1] == 0)
		{
			gameBoard[coordenateX - 1][coordenateY + 1] = 2;
		}
		if (gameBoard[coordenateX + 1][coordenateY] == 1)
		{
			coordenateX++;
		}
		if (gameBoard[coordenateX][coordenateY + 1] == 1)
		{
			coordenateY++;
		}
	}
}