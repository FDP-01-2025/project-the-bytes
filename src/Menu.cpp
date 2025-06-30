#include <iostream>
#include <stdlib.h>
#include "Menu.h"
#include "Player.h"
#include "Player2.h"
#include "CPU.h"
#include "Shooting.h"
#include "Shooting2.h"

using namespace std;

void Menu()
{
    int opcion;

MENU:
    cout << "                          BATTLESHIP \n";
    cout << "         ---------------------------------------------\n";
    cout << "                        1. PLAYER VS CPU\n";
    cout << "                        2. MULTIPLAYER\n";
    cout << "                        3. RULES\n";
    cout << "                        4. CREDITS\n";
    cout << "                        5. EXIT\n";
    cout << "         ---------------------------------------------\n";
    cin >> opcion;

    bool status = true;
    while (status)
    {
        if (opcion == 1)
        {
            system("cls");
            status = false;

            initComputer();

            for (int i = 0; i < 10; i++)
            {
                drawBoard();

                startingCoords();
                if (i < 6)
                    startingPosition();

                newCordsplayer(i + 1);
                updatedComputerCords(i + 1);
                system("cls");
            }

            while (true)
            {
                Draw_Shooting();
                Input_Coord();
                Update_Computer_Grid();
                Update_Player_Grid();
                cout << "   Points Computer: " << Count_Computer << endl;
                cout << "   Points Player: " << Count_Player << endl;
                cout << "   --------------------\n";
                system("PAUSE");

                system("cls");
                if (Count_Computer == 20 || Count_Player == 20)
                    break;
            }

            Draw_Shooting();

            Update_Computer_Grid();
            Update_Player_Grid();

            if (Count_Computer == 20)
            {
                cout << "\n   COMPUTER WON!";
                Sleep(4000);
                system("cls");
                cout << endl;
                system("pause");
            }
            else if (Count_Player == 20)
            {
                cout << "\n   PLAYER WON!";
                Sleep(4000);
                system("cls");
                cout << endl;
                system("pause");
            }
        }
        else if (opcion == 2)
        {

            system("cls");
            status = false;

            // PLAYER 1
            for (int i = 0; i < 10; i++)
            {
                drawBoard();

                startingCoords();
                if (i < 6)
                    startingPosition();

                newCordsplayer(i + 1);
                system("CLS");
            }

            // PLAYER 2
            for (int i = 0; i < 10; i++)
            {
                drawBoard2();

                startingCoords2();
                if (i < 6)
                    startingPosition2();

                newCordsplayer2(i + 1);
                system("CLS");
            }

            // INICIA EL JUEGO MULTIJUGADOR
            StartBattle();
        }
        else if (opcion == 3)
        {
            system("cls");
            cout << "                           BATTLESHIP \n";
            cout << "-------------------------------------------------------------------------------------------------------------\n";
            cout << "                       GENERAL INFORMATION\n";
            cout << "-------------------------------------------------------------------------------------------------------------\n";
            cout << "You're a marine soldier. Your work here is to sink all the ships of the rival." << endl;
            cout << "Each player has 10 ships:" << endl;
            cout << "1. One ship of size 4." << endl;
            cout << "2. Two ships of size 3." << endl;
            cout << "3. Three ships of size 2." << endl;
            cout << "4. Four ships of size 1." << endl;
            cout << "-------------------------------------------------------------------------------------------------------------\n";
            cout << "                              RULES \n";
            cout << "-------------------------------------------------------------------------------------------------------------\n";
            cout << "1. Ships can't touch each other." << endl;
            cout << "2. Use A-J and 0-9 for coordinates (e.g. A5)." << endl;
            cout << "3. H/V defines orientation." << endl;
            cout << "4. First to reach 20 hits wins!" << endl;

            system("pause");
            system("cls");
            goto MENU;
        }
        else if (opcion == 4)
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
            cout << " 4. Ricardo Antonio Ramos Rosales   00025325" << endl;
            system("pause");
            system("cls");
            goto MENU;
        }
        else if (opcion == 5)
        {
            exit(EXIT_FAILURE);
        }
    }

    // system("pause");
}
//}
//}
