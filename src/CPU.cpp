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
            computerX = 1 + (rand() % 10);
            computerY = 1 + (rand() % 10);

            if (i < 7)
            {
                computerCoordenate = rand() % 2;
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

    if (i < 7)
    {
        while (true)
        {
            if (computerPosition == 'V')
            {
                if (i == 1 && computerX < 8 &&
                    computerBoard[computerX + 1][computerY] == 0 &&
                    computerBoard[computerX + 2][computerY] == 0 &&
                    computerBoard[computerX + 3][computerY] == 0)
                {
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX + 1][computerY] = 1;
                    computerBoard[computerX + 2][computerY] = 1;
                    computerBoard[computerX + 3][computerY] = 1;
                    break;
                }
                else if ((i >= 2 && i < 4) && computerX < 9 &&
                         computerBoard[computerX + 1][computerY] == 0 &&
                         computerBoard[computerX + 2][computerY] == 0)
                {
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX + 1][computerY] = 1;
                    computerBoard[computerX + 2][computerY] = 1;
                    break;
                }
                else if ((i > 3 && i < 7) && computerX < 10 &&
                         computerBoard[computerX + 1][computerY] == 0)
                {
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX + 1][computerY] = 1;
                    break;
                }
                else
                {
                    repeat_input = true;
                }
            }
            else if (computerPosition == 'H')
            {
                if (i == 1 && computerY < 8 &&
                    computerBoard[computerX][computerY + 1] == 0 &&
                    computerBoard[computerX][computerY + 2] == 0 &&
                    computerBoard[computerX][computerY + 3] == 0)
                {
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX][computerY + 1] = 1;
                    computerBoard[computerX][computerY + 2] = 1;
                    computerBoard[computerX][computerY + 3] = 1;
                    break;
                }
                else if ((i >= 2 && i < 4) && computerY < 9 &&
                         computerBoard[computerX][computerY + 1] == 0 &&
                         computerBoard[computerX][computerY + 2] == 0)
                {
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX][computerY + 1] = 1;
                    computerBoard[computerX][computerY + 2] = 1;
                    break;
                }
                else if ((i > 3 && i < 7) && computerY < 10 &&
                         computerBoard[computerX][computerY + 1] == 0)
                {
                    computerBoard[computerX][computerY] = 1;
                    computerBoard[computerX][computerY + 1] = 1;
                    break;
                }
                else
                {
                    repeat_input = true;
                }
            }

            if (repeat_input)
            {
                srand((unsigned int)time(NULL));
                computerX = 1 + (rand() % 10);
                computerY = 1 + (rand() % 10);
                if (i < 7)
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

    for (int p = 0; p < 4; p++)
    {
        if (computerBoard[computerX + 1][computerY] == 0)
            computerBoard[computerX + 1][computerY] = 2;
        if (computerBoard[computerX][computerY + 1] == 0)
            computerBoard[computerX][computerY + 1] = 2;
        if (computerBoard[computerX - 1][computerY] == 0)
            computerBoard[computerX - 1][computerY] = 2;
        if (computerBoard[computerX][computerY - 1] == 0)
            computerBoard[computerX][computerY - 1] = 2;
        if (computerBoard[computerX + 1][computerY + 1] == 0)
            computerBoard[computerX + 1][computerY + 1] = 2;
        if (computerBoard[computerX - 1][computerY - 1] == 0)
            computerBoard[computerX - 1][computerY - 1] = 2;
        if (computerBoard[computerX + 1][computerY - 1] == 0)
            computerBoard[computerX + 1][computerY - 1] = 2;
        if (computerBoard[computerX - 1][computerY + 1] == 0)
            computerBoard[computerX - 1][computerY + 1] = 2;
        if (computerBoard[computerX + 1][computerY] == 1)
            computerX++;
        if (computerBoard[computerX][computerY + 1] == 1)
            computerY++;
    }
}
