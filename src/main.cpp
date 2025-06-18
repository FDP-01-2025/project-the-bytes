#include <iostream>
#include <String>
#include <stdlib.h>
#include "windows.h"
#include "Player.h"
#include "InteligentCPU.h"
#include "Shooting.h"
#include "Animated_Title.h"

using namespace std;
void menu();

int main()
{
    system("cls");       // Limpiar pantalla
    showAnimatedTitle(); // Llamada desde la función del .h/.cpp

    Player A[12];
    CPU B[12];
    Shooting C[100];

    menu();

    for (int i = 0; i < 10; i++)
    {
        A[i].Drawboard(); // PLAYER

        A[i].startingCoords();
        if (i < 6) // Position is needed UNTIL 7th ship
            A[i].startirgPos();

        A[i].updatedCoords(i + 1);
        B[i].coordenateUpdate(i + 1);
        system("CLS");
    }
    int i = 0;
    while (true)
    {
        C[i].Draw_Shooting();        // Draw board
        C[i].Input_Coord();          // Input coordinates to shoot CPU's ships
        C[i].Update_Computer_Grid(); // Random shoot
        C[i].Update_Player_Grid();
        cout << "   Points Computer: " << Count_Computer << endl
             << "   Points Player: " << Count_Player << endl
             << "   --------------------\n";
        system("PAUSE");
        i++;
        system("CLS");
        if (Count_Computer == 20 || Count_Player == 20) // Count variables from Shooting.h
            break;
    }

    C[i].Draw_Shooting();

    C[i].Update_Computer_Grid();
    C[i].Update_Player_Grid();

    if (Count_Computer == 20)
        cout << "\n   Computer WON!";
    else
        cout << "\n   Player Won!";

    cout << endl;
    system("pause");
}

void menu()
{
    int opcion;

MENU:
    cout << "                     # BattleShip game #\n";
    cout << "         ---------------------------------------------\n";
    cout << "                          1. Play\n                          2. Rules\n                          3. Credits\n                          4. Exit\n";
    cout << "         ---------------------------------------------\n";
    cin >> opcion;

    bool status = true;
    while (status)
    {

        if (opcion == 1)
        {
            system("cls");
            status = false;
        }
        else if (opcion == 2)
        {
            system("cls");
            cout << "                     # BattleShip game #\n";
            cout << "         ---------------------------------------------\n";
            cout << "                            Rules\n";
            cout << "         ---------------------------------------------\n";
            cout << "         Your task is to sunk all enemy ships.\n";
            cout << "         There are 10 ships in total:\n          1 ship with a size of 4;\n          2 ships with a size of 3;\n          3 ships with a size of 2;\n          4 ships with a size of 1\n";
            cout << "         1. You have to place these ships starting from the biggest one (ships can't touch each other).\n";
            cout << "         2. Enter a upper letter and a number from 0 to 9 without space to place the ship.\n";
            cout << "         3. Select horizontal or vertical pozition with H/V letters.\n";
            cout << "         4. After placing, board of CPU will show up. Here game will start! You need to defeat enemy!\n";
            cout << "         5. The first one who gets 20 straight shoots will become a winner!\n\n";
            system("pause");
            system("cls");
            goto MENU;
        }
        else if (opcion == 3)
        {
            system("cls");
            cout << "                     # BattleShip game #\n";
            cout << "         ---------------------------------------------\n";
            cout << "                            Credits\n";
            cout << "         ---------------------------------------------\n";
            cout << "         Created by VGTU PRIfs 18/6 student - Rimvydas Kanapka\n";
            cout << "         Game is created with OOP C++\n";
            cout << "         Vilnius Gedimas Technology University\n\n";

            system("pause");
            system("cls");
            goto MENU;
        }
        else if (opcion == 4)
            exit(EXIT_FAILURE);
    }
}