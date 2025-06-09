#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void Menu1()
{
    int opcion;
    cout << "\033[46m-----------------------------------------------------|\033[0m" << endl;
    cout << "\033[46m|                      BATTLESHIP                    |\033[0m" << endl;
    cout << "\033[46m|                 SELECCIONE UNA OPCION              |\033[0m" << endl;
    cout << "\033[46m| 1. JUGAR                                           |\033[0m" << endl;
    cout << "\033[46m| 2. INSTRUCCIONES DE JUEGO                          |\033[0m" << endl;
    cout << "\033[46m| 3. TIPOS DE EMBARCACIONES                          |\033[0m" << endl;
    cout << "\033[46m| 4. SALIR                                           |\033[0m" << endl;
    cout << "\033[46m------------------------------------------------------\033[0m" << endl;
    cin >> opcion;
}
int main()
{
    Menu1();

    return 0;
}