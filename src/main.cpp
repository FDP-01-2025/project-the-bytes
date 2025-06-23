#include <iostream>
#include <String>
#include <stdlib.h>
#include "windows.h"
#include "Player.h"
#include "CPU.h"
#include "Shooting.h"
#include "Animated_Title.h"
#include "Menu.h"
#include "ScoreManager.h" 


using namespace std;



int main()
{
    system("cls");       // To clean the terminal
    showAnimatedTitle(); // We call the function

    Player A[12];
    Computer B[12];
    Shooting C[100];

    Menu();

    for (int i = 0; i < 10; i++)
    {
        A[i].drawBoard(); // PLAYER

        A[i].startingCoords();
        if (i < 6) // Position is mandatory until the last ship
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

    bool playerWon = Count_Player == 20;
    if (playerWon)
        cout << "\n   Computer WON!";
      
    else
        cout << "\n   Player Won!";
        
        updateScore(playerWon); // Actualizar el registro de puntuaciones

    cout << endl;
    system("pause");
}
