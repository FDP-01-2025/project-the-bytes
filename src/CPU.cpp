#include "CPU.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // This library is to randomize the time

using namespace std;

int computerBoard[computerRows + 1][computerColumns + 1] = {0};

int computerX, computerY;
int computerCoordenate;
char computerPosition;

void initComputer()
{
    srand((unsigned int)time(NULL)); // To generate random numbers
    computerPosition = ' ';
    computerX = 1 + (rand() % 10);   // To randomize the coordenate in X
    computerY = 1 + (rand() % 10);   // To randomize the coordenate in Y
    computerCoordenate = rand() % 2; // To randomize the coordenates of position

    switch (computerCoordenate)
    {
    case 0:
        computerPosition = 'H';
        break;
    case 1:
        computerPosition = 'V';
        break;
    }
}

void updatedComputerCords(int i)
{
    bool repeat_input = false;

    while (true)
    {
        if (computerBoard[computerX][computerY] == 0) // We checking if the coordenate is free to put a ship
        {
            if (i > 6)
                computerBoard[computerX][computerY] = 1; // It gonna put a ship size 1x1
            break;
        }
        else // Else for ship coordinates collision
        {
            srand((unsigned int)time(NULL));
            computerX = 1 + (rand() % 10); // To randomize the coordenate in X
            computerY = 1 + (rand() % 10); // To randomize the coordenate in Y

            if (i < 7) // Position is mandatory until the last ship
            {
                computerCoordenate = rand() % 2;

                switch (computerCoordenate) // Two cases, horizontal or vertical
                {
                case 0:
                    computerPosition = 'H';
                    break;
                case 1:
                    computerPosition = 'V';
                    break;
                }
            }
        }
    }

    if (i < 7)
    {
        while (true) // It gonna stop if it's ok to put ships into de gameboard
        {
            if (computerPosition == 'V') // It is for the vertical position
            {
                // Ship wouldn't pass a bottom border
                if (i == 1 && computerX < 8 && computerBoard[computerX + 1][computerY] == 0 && computerBoard[computerX + 2][computerY] == 0 && computerBoard[computerX + 3][computerY] == 0)
                {
                    // Checking if 4 long ship coordinates are free for ship
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX + 1][computerY] = 1;
                    computerBoard[computerX + 2][computerY] = 1;
                    computerBoard[computerX + 3][computerY] = 1;
                    break;
                }

                // Ship wouldn't pass a bottom border
                else if ((i >= 2 && i < 4) && computerX < 9 && computerBoard[computerX + 1][computerY] == 0 && computerBoard[computerX + 2][computerY] == 0)
                {
                    // Checking if 3 long ship coordinates are free for ship
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX + 1][computerY] = 1;
                    computerBoard[computerX + 2][computerY] = 1;
                    break;
                }

                // Ship wouldn't pass a bottom border
                else if ((i > 3 && i < 7) && computerX < 10 && computerBoard[computerX + 1][computerY] == 0)
                {
                    // Checking if 2 long ship coordinates are free for ship
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX + 1][computerY] = 1;
                    break;
                }
                else
                {
                    repeat_input = true; // ship passes a border
                }
            }
            else if (computerPosition == 'H') // This is for horizontal position
            {
                // Ship wouldn't pass the limit of the board
                if (i == 1 && computerY < 8 && computerBoard[computerX][computerY + 1] == 0 && computerBoard[computerX][computerY + 2] == 0 && computerBoard[computerX][computerY + 3] == 0)
                {
                    // Checking if 4 long ship coordinates are free for ship
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX][computerY + 1] = 1;
                    computerBoard[computerX][computerY + 2] = 1;
                    computerBoard[computerX][computerY + 3] = 1;
                    break;
                }
                // Ship wouldn't pass the limit of the board
                else if ((i >= 2 && i < 4) && computerY < 9 && computerBoard[computerX][computerY + 1] == 0 && computerBoard[computerX][computerY + 2] == 0)
                {
                    // Checking if 3 long ship coordinates are free for ship
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX][computerY + 1] = 1;
                    computerBoard[computerX][computerY + 2] = 1;
                    break;
                }
                // Ship wouldn't pass the limit of the board
                else if ((i > 3 && i < 7) && computerY < 10 && computerBoard[computerX][computerY + 1] == 0)
                {
                    // Checking if 2 long ship coordinates are free for ship
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX][computerY + 1] = 1;
                    break;
                }
                else
                {
                    repeat_input = true; // ship passes a border
                }
            }

            if (repeat_input)
            {
                srand((unsigned int)time(NULL)); // To randomizer numbers
                computerX = 1 + (rand() % 10);
                computerY = 1 + (rand() % 10);

                if (i < 7) // Position is mandatory until the last ship
                {
                    computerCoordenate = rand() % 2;
                }
                switch (computerCoordenate)
                {
                case 0:
                    computerPosition = 'H';
                    break;
                case 1:
                    computerPosition = 'V';
                    break;
                }
            }
        }
    }

    for (int p = 0; p < 4; p++) // Area around the ship
    {
        if (computerBoard[computerX + 1][computerY] == 0)
        {
            computerBoard[computerX + 1][computerY] = 2;
        }

        if (computerBoard[computerX][computerY + 1] == 0)
        {
            computerBoard[computerX][computerY + 1] = 2;
        }

        if (computerBoard[computerX - 1][computerY] == 0)
        {
            computerBoard[computerX - 1][computerY] = 2;
        }

        if (computerBoard[computerX][computerY - 1] == 0)
        {
            computerBoard[computerX][computerY - 1] = 2;
        }
        if (computerBoard[computerX + 1][computerY + 1] == 0)
        {
            computerBoard[computerX + 1][computerY + 1] = 2;
        }
        if (computerBoard[computerX - 1][computerY - 1] == 0)
        {
            computerBoard[computerX - 1][computerY - 1] = 2;
        }
        if (computerBoard[computerX + 1][computerY - 1] == 0)
        {
            computerBoard[computerX + 1][computerY - 1] = 2;
        }
        if (computerBoard[computerX - 1][computerY + 1] == 0)
        {
            computerBoard[computerX - 1][computerY + 1] = 2;
        }
        if (computerBoard[computerX + 1][computerY] == 1)
        {
            computerX++;
        }

        if (computerBoard[computerX][computerY + 1] == 1)
        {
            computerY++;
        }
    }
}
