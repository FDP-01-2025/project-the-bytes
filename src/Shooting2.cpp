#include "Player2.h"
#include"Player.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int Count_Player2 = 0; // Puntos del jugador 1 contra el jugador 2

int shootX2 = 0;
int shootY2 = 0;
string Cord2 = "";

void Shooting2()
{
    shootX2 = 0;
    shootY2 = 0;
    Cord2 = "";
}

void InitShooting2(int a, int b, string c)
{
    shootX2 = a;
    shootY2 = b;
    Cord2 = c;
}

void Input_Coord2()
{
    bool correct_cord;
    do
    {
        cout << "   Input coordinates X & Y to shoot at Player 2 (Ex.: A5): ";
        cin >> Cord2;

        shootX2 = Cord2[0] - 64;
        shootY2 = Cord2[1] - 47;

        correct_cord = false;

        if (Cord2.size() == 2)
        {
            for (char i = 'A'; i <= 'J'; i++)
            {
                if (Cord2[0] == i)
                {
                    correct_cord = true;
                    break;
                }
            }

            if (!isdigit(Cord2[1]))
                correct_cord = false;
        }
    } while (!correct_cord);
}

void Draw_Shooting2()
{
    cout << "                   Player 1                         Player 2\n            0 1 2 3 4 5 6 7 8 9             0 1 2 3 4 5 6 7 8 9\n";
    char letter = 'A';

    for (int i = 1; i < player2Rows - 1; i++)
    {
        cout << "          " << letter << " ";
        for (int j = 1; j < player2Columns - 1; j++)
        {
            if (playerBoard[i][j] == 0 || playerBoard[i][j] == 2)
                cout << ". ";
            else if (playerBoard[i][j] == 3)
                cout << "X ";
            else if (playerBoard[i][j] == 4)
                cout << "* ";
            else if (playerBoard[i][j] == 1)
                cout << "0 ";
        }

        cout << "          " << letter++ << " ";
        for (int j = 1; j < player2Columns - 1; j++)
        {
            if (player2Board[i][j] == 2 || player2Board[i][j] == 1 || player2Board[i][j] == 0)
                cout << ". ";
            else if (player2Board[i][j] == 3)
                cout << "X ";
            else if (player2Board[i][j] == 4)
                cout << "* ";
        }
        cout << endl;
    }
}

void Update_Player2_Grid()
{
    while (true)
    {
        if (player2Board[shootX2][shootY2] != 3 && player2Board[shootX2][shootY2] != 4)
        {
            if (player2Board[shootX2][shootY2] == 1)
            {
                player2Board[shootX2][shootY2] = 3;
                cout << "   Player 1 HIT Player 2!\n";
                Count_Player2++;
            }
            else if (player2Board[shootX2][shootY2] == 2 || player2Board[shootX2][shootY2] == 0)
            {
                player2Board[shootX2][shootY2] = 4;
                cout << "   Player 1 missed.\n";
            }
            break;
        }
        else
        {
            cout << "   Already shot there. Try again.\n";
            Input_Coord2();
        }
    }
}
