#include "Sign_up.h"
#include <fstream>
#include <iostream>

using namespace std;

void saveData(const Jugador &Player)
{
    ofstream archivo("SIGN UP.txt", ios::app);
    if (!archivo)
    {
        cerr << "Error, the file doesn't work." << endl; //If the document doesn't work
        return;
    }

    archivo << "Name: " << Player.name << " | ID: " << Player.ID << endl; //We write the info in the document.txt
    archivo.close();

    cout << "Sign up correctly.\n";
}

void SignUp1Player()
{
    Jugador Player;

    cin.ignore(); // To clean buffer
    cout << "REGISTER OF PLAYER\n";
    cout << "Name: "; //The user write his/her name
    getline(cin, Player.name);

    Sleep(1000);

    cout << "ID: ";
    getline(cin, Player.ID);

    saveData(Player);

    Sleep(1500);
    system("cls");
}

void SignUp1vs1()
{
    Jugador Player1, Player2;

    cin.ignore(); // To clean the buffer

    cout << "REGISTER OF PLAYER 1\n";
    cout << "Name: ";
    getline(cin, Player1.name);

    Sleep(1000);

    cout << "ID: ";
    getline(cin, Player1.ID);
    saveData(Player1);
    Sleep(2000);

    cout << "\nREGISTER OF PLAYER 2\n";
    cout << "Name: ";
    getline(cin, Player2.name);

    Sleep(1000);

    cout << "ID: ";
    getline(cin, Player2.ID);
    saveData(Player2);
    Sleep(2000);
    system("cls");
}
