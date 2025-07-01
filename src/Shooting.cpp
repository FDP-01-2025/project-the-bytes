#include "Shooting.h"
#include "Player.h"
#include "CPU.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int Count_Player = 0;   // Count of points of  player
int Count_Computer = 0; // Count of point of computer

int positions[100][2]; // Size of the array
int posCount = 0;      // Number of elements in position

int shootX = 0;
int shootY = 0;
string Cord = "";

void Shooting()
{
    shootX = 0;
    shootY = 0;
    Cord = "";
}

void InitShooting(int a, int b, string c)
{
    shootX = a;
    shootY = b;
    Cord = c;
}

void PushPosition(int x, int y)
{
    if (posCount < 100)
    {
        positions[posCount][0] = x;
        positions[posCount][1] = y;
        posCount++;
    }
}

bool PopPosition(int x, int y)
{
    if (posCount == 0)
        return false;
    x = positions[0][0];
    y = positions[0][1];
    for (int i = 1; i < posCount; ++i)
    {
        positions[i - 1][0] = positions[i][0];
        positions[i - 1][1] = positions[i][1];
    }
    posCount--;
    return true;
}

void Input_Coord()
{
    bool correct_cord;
    do
    {
        cout << "   Input a coordinates X & Y to shoot (Ex.: A5): ";
        cin >> Cord;

        shootX = Cord[0] - 64; // Char Letter to our needed number
        shootY = Cord[1] - 47; // Char number to our needed number

        correct_cord = false; // Checking if input is correct

        if (Cord.size() == 2) // Correct number of symbols - 2
        {
            for (char i = 'A'; i <= 'J'; i++) // We checking if the first coord is equal to a letter of the coordenate
            {
                if (Cord[0] == i)
                {
                    correct_cord = true;
                    break;
                }
            }
            if (!isdigit(Cord[1]))    // We check if the second coord is equal to a digit of the coordenate
                correct_cord = false; // It gonna be false if symbol isn't a digit
        }
    } while (!correct_cord);
}

void Draw_Shooting()
{
    cout << "                   Player                         Computer\n            0 1 2 3 4 5 6 7 8 9             0 1 2 3 4 5 6 7 8 9\n";
    char letter = 'A';

    for (int i = 1; i < playerRows - 1; i++)
    {
        cout << "          " << letter << " ";
        for (int j = 1; j < playerColumns - 1; j++)
        {
            if (playerBoard[i][j] == 0 || playerBoard[i][j] == 2) // 0 for free coordinate and 2 for ship place
            {
                cout << ". ";
            }
            else if (playerBoard[i][j] == 3) // 3 if the shoot impact in a ship
            {
                cout << "X ";
            }
            else if (playerBoard[i][j] == 4) // 4 if the shoot not impact in a ship
            {
                cout << "* ";
            }
            else if (playerBoard[i][j] == 1) // 1 if exist a ship
            {
                cout << "0 ";
            }
        }

        // Part of computer
        cout << "          " << letter++ << " ";
        for (int j = 1; j < playerColumns - 1; j++)
        {
            if (computerBoard[i][j] == 2 || computerBoard[i][j] == 1 || computerBoard[i][j] == 0) // 0 if the space is void. 1 if exist a ship. 2 for the sides ship;
            {
                cout << ". ";
            }
            else if (computerBoard[i][j] == 3) // This gonna pass if the shoot impact with any ship
            {
                cout << "X ";
            }
            else if (computerBoard[i][j] == 4) // This gonna pass if the shoot not impact in any ship
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
}

void Update_Computer_Grid()
{
    while (true)
    {
        if (computerBoard[shootX][shootY] != 3 && computerBoard[shootX][shootY] != 4)
        {
            if (computerBoard[shootX][shootY] == 1)
            {
                computerBoard[shootX][shootY] = 3; // 3 if player hit in any ship
                cout << "   Player HIT!\n";
                Count_Player++;
            }
            else if (computerBoard[shootX][shootY] == 2 || computerBoard[shootX][shootY] == 0)
                computerBoard[shootX][shootY] = 4; // 4 if player miss the shoot
            break;
        }
        else
        {
            Input_Coord();
        }
    }
}

void Update_Player_Grid()
{
    srand((unsigned int)time(NULL)); // This is to randomize the position
    if (!PopPosition(shootX, shootY))
    {
        shootX = 1 + (rand() % 10);
        shootY = 1 + (rand() % 10);
    }

    while (true)
    {
        if (playerBoard[shootX][shootY] != 3 && playerBoard[shootX][shootY] != 4)
        {
            if (playerBoard[shootX][shootY] == 1)
            {
                playerBoard[shootX][shootY] = 3; // If the cpu hit the ship, print this
                cout << "   CPU HIT A SHIP!\n";
                Count_Computer++;

                if (posCount == 0)
                {
                    if (shootY - 1 >= 1 && (playerBoard[shootX][shootY - 1] == 2 || playerBoard[shootX][shootY - 1] == 0 || playerBoard[shootX][shootY - 1] == 1))
                    {
                        PushPosition(shootX, shootY - 1);
                    }
                    if (shootY + 1 <= 10 && (playerBoard[shootX][shootY + 1] == 2 || playerBoard[shootX][shootY + 1] == 0 || playerBoard[shootX][shootY + 1] == 1))
                    {
                        PushPosition(shootX, shootY + 1);
                    }
                    if (shootX - 1 >= 1 && (playerBoard[shootX - 1][shootY] == 2 || playerBoard[shootX - 1][shootY] == 0 || playerBoard[shootX - 1][shootY] == 1))
                    {
                        PushPosition(shootX - 1, shootY);
                    }
                    if (shootX + 1 <= 9 && (playerBoard[shootX + 1][shootY] == 2 || playerBoard[shootX + 1][shootY] == 0 || playerBoard[shootX + 1][shootY] == 1))
                    {
                        PushPosition(shootX + 1, shootY);
                    }
                }
            }
            else if (playerBoard[shootX][shootY] == 2 || playerBoard[shootX][shootY] == 0)
            {
                playerBoard[shootX][shootY] = 4;
                break;
            }
        }
        else
        {
            shootX = 1 + (rand() % 10);
            shootY = 1 + (rand() % 10);
        }
    }
    cout << "   --------------------\n   Computer shoots: " << char(shootX + 64) << shootY - 1 << endl;
}
