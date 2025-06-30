#include "Player2.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <ctime>
#include "Shooting2.h"

using namespace std;

int Count_Player1 = 0;
int Count_Player2 = 0;

int shootX1 = 0, shootY1 = 0;
int shootX2 = 0, shootY2 = 0;
string Cord1 = "", Cord2 = "";

void Shooting2()
{
    shootX1 = shootY1 = shootX2 = shootY2 = 0;
    Cord1 = Cord2 = "";
}

void InitShooting2(int a, int b, string c)
{
    shootX2 = a;
    shootY2 = b;
    Cord2 = c;
}

// 🔹 Entrada para Player 1
void Input_Coord1()
{
    bool correct_cord;
    do
    {
        cout << "   Player 1, input coordinates to shoot at Player 2 (Ex.: A5): ";
        cin >> Cord1;

        shootX1 = Cord1[0] - 64;
        shootY1 = Cord1[1] - 47;

        correct_cord = false;

        if (Cord1.size() == 2)
        {
            for (char i = 'A'; i <= 'J'; i++)
            {
                if (Cord1[0] == i && isdigit(Cord1[1]))
                {
                    correct_cord = true;
                    break;
                }
            }
        }
    } while (!correct_cord);
}

// 🔹 Entrada para Player 2
void Input_Coord2()
{
    bool correct_cord;
    do
    {
        cout << "   Player 2, input coordinates to shoot at Player 1 (Ex.: A5): ";
        cin >> Cord2;

        shootX2 = Cord2[0] - 64;
        shootY2 = Cord2[1] - 47;

        correct_cord = false;

        if (Cord2.size() == 2)
        {
            for (char i = 'A'; i <= 'J'; i++)
            {
                if (Cord2[0] == i && isdigit(Cord2[1]))
                {
                    correct_cord = true;
                    break;
                }
            }
        }
    } while (!correct_cord);
}

// 🔹 Mostrar tableros
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
            if (player2Board[i][j] == 0 || player2Board[i][j] == 2 || player2Board[i][j] == 1)
                cout << ". ";
            else if (player2Board[i][j] == 3)
                cout << "X ";
            else if (player2Board[i][j] == 4)
                cout << "* ";
        }
        cout << endl;
    }
}

// 🔹 Player 1 dispara a Player 2
void Update_Player1_Grid()
{
    while (true)
    {
        if (player2Board[shootX1][shootY1] != 3 && player2Board[shootX1][shootY1] != 4)
        {
            if (player2Board[shootX1][shootY1] == 1)
            {
                player2Board[shootX1][shootY1] = 3;
                cout << "   Player 1 HIT Player 2!\n";
                Count_Player1++;
            }
            else
            {
                player2Board[shootX1][shootY1] = 4;
                cout << "   Player 1 missed.\n";
            }
            break;
        }
        else
        {
            cout << "   Already shot there. Try again.\n";
            Input_Coord1();
        }
    }
}

// 🔹 Player 2 dispara a Player 1
void Update_Player2_Grid()
{
    while (true)
    {
        if (playerBoard[shootX2][shootY2] != 3 && playerBoard[shootX2][shootY2] != 4)
        {
            if (playerBoard[shootX2][shootY2] == 1)
            {
                playerBoard[shootX2][shootY2] = 3;
                cout << "   Player 2 HIT Player 1!\n";
                Count_Player2++;
            }
            else
            {
                playerBoard[shootX2][shootY2] = 4;
                cout << "   Player 2 missed.\n";
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
void Draw_Player1_View()
{
    cout << "        PLAYER 1 VIEW (Attacking Player 2)\n";
    cout << "         0 1 2 3 4 5 6 7 8 9\n";
    char letter = 'A';
    for (int i = 1; i < player2Rows - 1; i++)
    {
        cout << "       " << letter++ << " ";
        for (int j = 1; j < player2Columns - 1; j++)
        {
            if (player2Board[i][j] == 0 || player2Board[i][j] == 2 || player2Board[i][j] == 1)
                cout << ". ";
            else if (player2Board[i][j] == 3)
                cout << "X ";
            else if (player2Board[i][j] == 4)
                cout << "* ";
        }
        cout << endl;
    }
}

void Draw_Player2_View()
{
    cout << "        PLAYER 2 VIEW (Attacking Player 1)\n";
    cout << "         0 1 2 3 4 5 6 7 8 9\n";
    char letter = 'A';
    for (int i = 1; i < playerRows - 1; i++)
    {
        cout << "       " << letter++ << " ";
        for (int j = 1; j < playerColumns - 1; j++)
        {
            if (playerBoard[i][j] == 0 || playerBoard[i][j] == 2 || playerBoard[i][j] == 1)
                cout << ". ";
            else if (playerBoard[i][j] == 3)
                cout << "X ";
            else if (playerBoard[i][j] == 4)
                cout << "* ";
        }
        cout << endl;
    }
}

// 🔹 Bucle de juego por turnos
void StartBattle()
{
    while (Count_Player1 != 20 && Count_Player2 != 20)
    {
        system("CLS");
        cout << "\n   PLAYER 1 TURN\n";
        Draw_Player1_View();
        Input_Coord1();
        Update_Player1_Grid();
        if (Count_Player1 == 20)
        {
            cout << " Player 1 Wins!\n";
            break;
            system("PAUSE");
            Sleep(2000);
            system("CLS");
        }
        system("PAUSE");

        system("CLS");
        cout << "\n   PLAYER 2 TURN\n";
        Draw_Player2_View();
        Input_Coord2();
        Update_Player2_Grid();
        if (Count_Player2 == 20)
        {
            cout << " Player 2 Wins!\n";
            break;
            system("PAUSE");
            Sleep(2000);
            system("CLS");

        }

        system("PAUSE");
    }
}
