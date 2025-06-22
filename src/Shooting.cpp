#include "Shooting.h"
#include "Player.h"
#include "CPU.h"
#include <iostream>
#include <string>
#include <ctime> // time to randomize  the time

using namespace std;

int Count_Player = 0;
int Count_Computer = 0;

int positions[100][2]; // 
int posCount = 0;      // número de elementos en positions

// Funciones auxiliares
void PushPosition(int x, int y)
{
    if (posCount < 100)
    {
        positions[posCount][0] = x;
        positions[posCount][1] = y;
        posCount++;
    }
}
Shooting::Shooting()
{
    Cord = "";
    shootX = 0;
    y = 0;
}
Shooting::Shooting(int a, int b, string c)
{
    shootX = a;
    y = b;
    Cord = c;
}
void Shooting::Input_Coord()
{
    bool correct_cord;

    do
    {
        cout << "   Input a coordinates X & Y to shoot (Ex.: A5): ";
        cin >> Cord;

        // Assci Table
        shootX = Cord[0] - 64; // Char Letter to our needed number
        y = Cord[1] - 47;      // Char number to our needed number

        // Checking if input is correct
        correct_cord = false;

        if (Cord.size() == 2)
        { // Correct number of symbols - 2
            for (char i = 'A'; i <= 'J'; i++)
            {
                if (Cord[0] == i)
                { // Checking if FIRST entered symbol is equal to a letter coordinate
                    correct_cord = true;
                    break;
                }
            }

            if (!(isdigit(Cord[1])))
            {                         // Checking if SECOND entered symbol is a digit
                correct_cord = false; // It will be false if symbol isn't a digit
            }
        }
    } while (!(correct_cord));
}
void Shooting::Draw_Shooting()
{
    cout << "                   Player                         Computer\n            0 1 2 3 4 5 6 7 8 9             0 1 2 3 4 5 6 7 8 9\n";
    char letter = 'A';

    for (int i = 1; i < playerRows - 1; i++)
    {
        // PLAYER
        cout << "          " << letter << " ";
        for (int j = 1; j < playerColumns - 1; j++)
        {
            if (playerBoard[i][j] == 0 || playerBoard[i][j] == 2) // 0 for free Coordinate; 2 for Ship sides
                cout << ". ";
            else if (playerBoard[i][j] == 3)
                cout << "X ";
            else if (playerBoard[i][j] == 4)
                cout << "* ";
            else if (playerBoard[i][j] == 1) // 1 for SHIP
                cout << "0 ";
        }
        // COMPUTER
        cout << "          " << letter++ << " ";
        for (int j = 1; j < playerColumns - 1; j++)
        {
            if (computerBoard[i][j] == 2 || computerBoard[i][j] == 1 || computerBoard[i][j] == 0) // 0 - EMPTY PLACE; 1 - SHIP; 2 - SHIP SIDES;
                cout << ". ";
            else if (computerBoard[i][j] == 3) // HITTED SHIP
                cout << "X ";
            else if (computerBoard[i][j] == 4) // UNHITTED SHIP
                cout << "* ";
        }
        cout << endl;
    }
}
void Shooting::Update_Computer_Grid()
{
    while (true)
    {
        if (computerBoard[shootX][y] != 3 && computerBoard[shootX][y] != 4)
        {
            if (computerBoard[shootX][y] == 1)
            {
                computerBoard[shootX][y] = 3; // 3 if hit
                cout << "   Player HIT!\n";
                Count_Player++;
            }
            else if (computerBoard[shootX][y] == 2 || computerBoard[shootX][y] == 0)
                computerBoard[shootX][y] = 4; // 4 if missed
            break;
        }
        else
            Input_Coord();
    }
}

bool PopPosition(int &x, int &y)
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

// ... tus constructores y métodos Input_Coord, Draw_Shooting se mantienen igual ...

// Reemplaza en Update_Player_Grid:
void Shooting::Update_Player_Grid()
{
    srand((unsigned int)time(NULL)); // semilla aleatoria
    if (!PopPosition(shootX, y))
    {
        shootX = 1 + (rand() % 10);
        y = 1 + (rand() % 10);
    }

    while (true)
    {
        if (playerBoard[shootX][y] != 3 && playerBoard[shootX][y] != 4)
        {
            if (playerBoard[shootX][y] == 1)
            {
                playerBoard[shootX][y] = 3;
                cout << "   CPU HIT!\n";
                Count_Computer++;

                // Smart shooting (simplificado para ejemplo)
                if (posCount == 0)
                {
                    if (y - 1 >= 1 && (playerBoard[shootX][y - 1] == 2 || playerBoard[shootX][y - 1] == 0 || playerBoard[shootX][y - 1] == 1))
                        PushPosition(shootX, y - 1);
                    if (y + 1 <= 10 && (playerBoard[shootX][y + 1] == 2 || playerBoard[shootX][y + 1] == 0 || playerBoard[shootX][y + 1] == 1))
                        PushPosition(shootX, y + 1);
                    if (shootX - 1 >= 1 && (playerBoard[shootX - 1][y] == 2 || playerBoard[shootX - 1][y] == 0 || playerBoard[shootX - 1][y] == 1))
                        PushPosition(shootX - 1, y);
                    if (shootX + 1 <= 9 && (playerBoard[shootX + 1][y] == 2 || playerBoard[shootX + 1][y] == 0 || playerBoard[shootX + 1][y] == 1))
                        PushPosition(shootX + 1, y);
                }
            }
            else if (playerBoard[shootX][y] == 2 || playerBoard[shootX][y] == 0)
                playerBoard[shootX][y] = 4;
            break;
        }
        else
        {
            shootX = 1 + (rand() % 10);
            y = 1 + (rand() % 10);
        }
    }
    cout << "   --------------------\n   Computer shoots: " << char(shootX + 64) << y - 1 << endl;
}
