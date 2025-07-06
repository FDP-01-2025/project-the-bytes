#include <iostream>
#include <stdlib.h>
#include "Menu.h"
#include "Player.h"
#include "Player2.h"
#include "CPU.h"
#include "Shooting.h"
#include "Shooting2.h"
#include "Sign_up.h"
#include "explosion.h"

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
    cout << "                        4. SOUND OPTIONS\n";
    cout << "                        5. CREDITS\n";
    cout << "                        6. EXIT\n";
    cout << "         ---------------------------------------------\n";
    cin >> opcion;

    bool status = true;
    while (status)
    {
        if (opcion == 1)
        {
            system("cls");
            status = false;

            SignUp1Player();

            initComputer();

            for (int i = 0; i < 10; i++)
            {
                drawBoard();

                startingCoords();
                if (i < 6)
                {
                    startingPosition();
                }

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
                {
                    break;
                }
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
                void playExplosionSound();
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

            SignUp1vs1();

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
            cout << "                                   BATTLESHIP                                   \n";
            cout << "--------------------------------------------------------------------------------\n";
            cout << "                             GENERAL INFORMATION                                \n";
            cout << "--------------------------------------------------------------------------------\n";
            cout << "               You're a marine soldier. Your job is to sink all rival ships.   \n";
            cout << "                                 Each player has 10 ships:                     \n";
            cout << "                       1. One ship of size 4.                                  \n";
            cout << "                       2. Two ships of size 3.                                 \n";
            cout << "                       3. Three ships of size 2.                               \n";
            cout << "                       4. Four ships of size 1.                                \n";
            cout << "--------------------------------------------------------------------------------\n";
            cout << "                                   RULES                                       \n";
            cout << "--------------------------------------------------------------------------------\n";
            cout << "          1. Ships can't touch each other.                                     \n";
            cout << "          2. Use A-J and 0-9 for coordinates (e.g. A5).                        \n";
            cout << "          3. H/V defines orientation.                                          \n";
            cout << "          4. First to reach 20 hits wins!                                      \n";

            system("pause");
            system("cls");
            goto MENU;
        }

        else if (opcion == 4)
        {
            /* code */
        }

        else if (opcion == 5)
        {
            system("cls");
            cout << "                                 BATTLESHIP                                  \n";
            cout << "-----------------------------------------------------------------------------\n";
            cout << "                        A GAME CREATED BY: THE BYTES                         \n";
            cout << "-----------------------------------------------------------------------------\n";
            cout << "                           MEMBERS OF THE TEAM                              \n";
            cout << "-----------------------------------------------------------------------------\n";
            cout << "     1. Hector Andres Lopez Medrano     00015725                             \n";
            cout << "     2. Rodrigo Josue Medrano Marquez   00148625                             \n";
            cout << "     3. Andres Eduardo Vega Mena        00077125                             \n";
            cout << "     4. Ricardo Antonio Ramos Rosales   00025325                             \n";

            system("pause");
            system("cls");
            goto MENU;
        }
        else if (opcion == 6)
        {
            exit(EXIT_FAILURE);
        }
    }

    // system("pause");
}
//}
//}
