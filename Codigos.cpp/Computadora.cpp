#include "Computadora.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // time for random

using namespace std;

int gameBoard[Filas + 1][Columns + 1] = {0};

Computer::Computer()
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

void Computer::Update_Coord(int i)
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

			coordenateX = 1 + (rand() % 10); //To randomize the coordenate in X
			coordenateY = 1 + (rand() % 10); //To randomize the coordenate in Y

			if (i < 7) //Position is necesary until the last ship (6)
			{ 
				posicion = rand() % 2;

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
		}
	}

	if (i < 7)
	{
		while (true)
		{ // It will stop if it's okay to put ship into board
			if (pos == 'Vertical')
			{ // VERTICAL POSITION **************************************************************
				if (i == 1)
				{
					if (coordenateX < 8)
					{ // Ship wouldn't pass a bottom border
						if (gameBoard[coordenateX + 1][coordenateY] == 0 && gameBoard[coordenateX + 2][coordenateY] == 0 && gameBoard[coordenateX + 3][coordenateY] == 0)
						{ // Checking if 4 long ship coordinates are free for ship
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX + 1][coordenateY] = 1;
							gameBoard[coordenateX + 2][coordenateY] = 1;
							gameBoard[coordenateX + 3][coordenateY] = 1;
							break;
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else
					{ // ship passes a border
						repeatEntrance = true;
					}
				}
				else if (i >= 2 && i < 4)
				{
					if (coordenateX < 9)
					{ // Ship wouldn't pass a bottom border
						if (gameBoard[coordenateX + 1][coordenateY] == 0 && gameBoard[coordenateX + 2][coordenateY] == 0)
						{ // Checking if 3 long ship coordinates are free for ship
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX + 1][coordenateY] = 1;
							gameBoard[coordenateX + 2][coordenateY] = 1;
							break;
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else
					{
						repeatEntrance = true;
					}
				}
				else if (i > 3 && i < 7)
				{
					if (coordenateX < 10)
					{ // Ship wouldn't pass a bottom border
						if (gameBoard[coordenateX + 1][coordenateY] == 0)
						{ // Checking if 2 long ship coordinates are free for ship
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX + 1][coordenateY] = 1;
							break;
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else
					{
						repeatEntrance = true;
					}
				}
			}
			else if (pos == 'Horizontal')
			{ // HORIZONTAL POSITION **************************************************************
				if (i == 1)
				{
					if (coordenateY < 8)
					{ // Ship wouldn't pass a RIGHT border
						if (gameBoard[coordenateX][coordenateY + 1] == 0 && gameBoard[coordenateX][coordenateY + 2] == 0 && gameBoard[coordenateX][coordenateY + 3] == 0)
						{ // Checking if 4 long ship coordinates are free for ship
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX][coordenateY + 1] = 1;
							gameBoard[coordenateX][coordenateY + 2] = 1;
							gameBoard[coordenateX][coordenateY + 3] = 1;
							break;
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else
					{ // ship passes a border
						repeatEntrance = true;
					}
				}
				else if (i >= 2 && i < 4)
				{
					if (coordenateY < 9)
					{ // Ship wouldn't pass a RIGHT border
						if (gameBoard[coordenateX][coordenateY + 1] == 0 && gameBoard[coordenateX][coordenateY + 2] == 0)
						{ // Checking if 3 long ship coordinates are free for ship
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX][coordenateY + 1] = 1;
							gameBoard[coordenateX][coordenateY + 2] = 1;
							break;
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else
					{
						repeatEntrance = true;
					}
				}
				else if (i > 3 && i < 7)
				{
					if (coordenateY < 10)
					{ // Ship wouldn't pass a RIGHT border
						if (gameBoard[coordenateX][coordenateY + 1] == 0)
						{ // Checking if 2 long ship coordinates are free for ship
							gameBoard[coordenateX][coordenateY] = 1;
							gameBoard[coordenateX][coordenateY + 1] = 1;
							break;
						}
						else
						{
							repeatEntrance = true;
						}
					}
					else
					{
						repeatEntrance = true;
					}
				}
			}
			if (repeatEntrance)
			{
				srand((unsigned int)time(NULL)); // random time to generate random number EVERYTIME

				coordenateX = 1 + (rand() % 10);
				coordenateY = 1 + (rand() % 10);

				if (i < 7)
				{ // Position is needed UNTIL 7th ship
					posicion = rand() % 2;

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
			}
		}
	}
	for (int p = 0; p < 4; p++)
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