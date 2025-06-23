#include <iostream>
#include <stdlib.h>
#include "Menu.h"

using namespace std;

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
        {
            exit(EXIT_FAILURE);
        }
    }
}