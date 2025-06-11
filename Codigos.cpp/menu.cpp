#include <iostream>
using namespace std;
#include "menu.h"

void menu()
{

    int menu;

    cout << "========== BATALLA NAVAL ==========" << endl;
    cout << "Ingrese la opción que desee:" << endl;
    cout << " 1 - Jugar" << endl;
    cout << " 2 - Instrucciones del juego" << endl;
    cout << " 3 - Salir del juego" << endl;
    cout << "===================================" << endl;
    cin >> menu;

    switch (menu)
    {
    case 1:
        cout << "Iniciando juego..." << endl;
        break;

    case 2:
        cout << "\nInstrucciones:\n";
        cout << "- Acomoda tus barcos" << endl;
        cout << "- Dispara a coordenadas enemigas" << endl;
        cout << "- Gana hundiendo todos los barcos rivales" << endl;
        break;

    case 3:
        cout << "Saliendo del juego..." << endl;
        break;

    default:
        cout << "Ingrese una opción válida" << endl;

        
 
    }
    return;
}  
