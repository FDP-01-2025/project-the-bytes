#include <iostream>
using namespace std;
int main()
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

    switch (opcion)
    {
    case 1:

        break;

    case 2:
        cout << "\033[46m------------------------------------------------------\033[0m" << endl;
        cout << "\033[46m|                INSTRUCCIOMES DE JUEGO              |\033[0m" << endl;
        cout << "\033[46m|                                                    |\033[0m" << endl;
        cout << "\033[46m| 1. CADA JUGADOR CUENTA CON UNA CUADRICULA 8X8 DONDE|\033[0m" << endl;
        cout << "\033[46m|    PODRA COLOCAR 4 EMBARCACIONES EN EL ORDEN QUE   |\033[0m" << endl;
        cout << "\033[46m|    GUSTE.                                          |\033[0m" << endl;
        cout << "\033[46m|                                                    |\033[0m" << endl;
        cout << "\033[46m| 2. SI UN JUGADOR CONSIGUE IMPACTAR A UNO DE LOS    |\033[0m" << endl;
        cout << "\033[46m|    BARCOS DEL RIVAL, VUELVE A REPETIR EL TURNO. EL |\033[0m" << endl;
        cout << "\033[46m|    TURNO FINALIZA HASTA QUE FALLE EL DISPARO       |\033[0m" << endl;
        cout << "\033[46m|                                                    |\033[0m" << endl;
        cout << "\033[46m| 3. GANA EL PRIMER JUGADOR QUE DESTRUYA LOS BARCOS  |\033[0m" << endl;
        cout << "\033[46m|    DEL RIVAL.                                      |\033[0m" << endl;
        cout << "\033[46m|                                                    |\033[0m" << endl;
        cout << "\033[46m------------------------------------------------------\033[0m" << endl;
    }
}