#include <iostream>
#include <String>
#include <stdlib.h>
#include "windows.h"
#include "Player.h"
#include "CPU.h"
#include "Shooting.h"
#include "Animated_Title.h"

using namespace std;

void Menu();

int main()
{
    system("cls");       // Limpiar pantalla
    showAnimatedTitle(); // Llamada desde la función del .h/.cpp

    Player A[12];
    Computer B[12];
    Shooting C[100];

    Menu();

    for (int i = 0; i < 10; i++)
    {
        A[i].drawBoard(); // PLAYER

        A[i].startingCoords();
        if (i < 6) // Position is needed UNTIL 7th ship
            A[i].startingPosition();

        A[i].newCordsplayer(i + 1);
        B[i].updatedComputerCords(i + 1);
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
void Menu()
{
    int opcion;

MENU:
    cout << "                          BATTLESHIP \n";
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
            cout << "                           BATTLESHIP \n";
            cout << "-------------------------------------------------------------------------------------------------------------\n";
            cout << "                       GENERAL INFORMATION\n";
            cout << "-------------------------------------------------------------------------------------------------------------\n";
            cout << "You're a marine soldier. Your work here is to sink all the ships of the rival." << endl;
            cout << "Your and your enemy have the same ships, ten ships, here with the list:" << endl;
            cout << "1. One ships whith size of 4." << endl;
            cout << "2. Two ships with size of 3." << endl;
            cout << "3. Three ships with size of 2." << endl;
            cout << "4. Four ships with size of 1." << endl;
            cout << "-------------------------------------------------------------------------------------------------------------\n";
            cout << "                              RULES \n";
            cout << "-------------------------------------------------------------------------------------------------------------\n";
            cout << "1. You have to place these ships starting from the biggest one (ships can't touch each other)." << endl;
            cout << "2. Enter an upper letter and a number from 0 to 9 without space to place the ship." << endl;
            cout << "3. Select horizontal or vertical position with H/V letters." << endl;
            cout << "4. After placing it, board of CPU will show up. Here game will start! You have to sink all the ships of the enemy." << endl;
            cout << "5. The first one who gets 20 straight shoots will become a winner!" << endl;

            system("pause");
            system("cls");
            goto MENU;
        }
        else if (opcion == 3)
        {
            system("cls");
            cout << "                          BATTLESHIP \n";
            cout << "---------------------------------------------------------------" << endl;
            cout << "                   A GAME CREATED BY: THE BYTES" << endl;
            cout << "---------------------------------------------------------------" << endl;
            cout << "                        MEMBERS OF THE TEAM" << endl;
            cout << "---------------------------------------------------------------" << endl;
            cout << " 1. Hector Andres Lopez Medrano     00015725" << endl;
            cout << " 2. Rodrigo Josue Medrano Marquez   00148625" << endl;
            cout << " 3. Andres Eduardo Vega Mena        00077125" << endl;
            cout << " 4. Ricardo Antonio Ramos Rosales  00025325" << endl;
            cout << R"(

  ____        _   _   _           _____ _     _       
 |  _ \      | | | | | |         / ____| |   (_)      
 | |_) | __ _| |_| |_| | ___    | (___ | |__  _ _ __        __/___
 |  _ < / _` | __| __| |/ _ \    \___ \| '_ \| | '_ \    __/_____/____|  
 | |_) | (_| | |_| |_| |  __/    ____) | | | | | |_) |   \           \
 |____/ \__,_|\__|\__|_|\___|   |_____/|_| |_|_| .__/    ~~~~~~~~~~~~~~~
                                               | |    
                                               |_|    
)";

            system("pause");
            system("cls");
            goto MENU;
        }
        else if (opcion == 4)
            exit(EXIT_FAILURE);
    }
}