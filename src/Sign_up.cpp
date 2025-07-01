#include "Sign_up.h"
#include <fstream>
#include <iostream>

using namespace std;

void saveData(const Jugador &Player)
{
    ofstream archivo("SIGN UP.txt", ios::app);
    if (!archivo)
    {
        cerr << "Error al abrir el archivo." << endl;
        return;
    }

    archivo << "Nombre: " << Player.name << " | Carnet: " << Player.ID << endl;
    archivo.close();

    cout << "Registro guardado exitosamente.\n";
}

void SignUp1Player()
{
    Jugador Player;

    cin.ignore(); // Limpiar buffer
    cout << "REGISTRO DEL JUGADOR\n";
    cout << "Nombre: ";
    getline(cin, Player.name);

    Sleep(1000);

    cout << "Carnet: ";
    getline(cin, Player.ID);

    saveData(Player);

    Sleep(1500);
    system("cls");
}

void SignUp1vs1()
{
    Jugador Player1, Player2;

    cin.ignore(); // To clean the buffer

    cout << "REGISTRO DEL JUGADOR 1\n";
    cout << "Nombre: ";
    getline(cin, Player1.name);

    Sleep(1000);

    cout << "Carnet: ";
    getline(cin, Player1.ID);
    saveData(Player1);

    Sleep(2000);

    cout << "\nREGISTRO DEL JUGADOR 2\n";
    cout << "Nombre: ";
    getline(cin, Player2.name);

    Sleep(1000);

    cout << "Carnet: ";
    getline(cin, Player2.ID);
    saveData(Player2);
    Sleep(2000);
    system("cls");
}
