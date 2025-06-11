#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t...BATTLESHIP..." << endl; // Nombre del juego
    Sleep(4000);                                                    // Se usa para pausar la ejecucion por un periodo de tiempo
    system("cls");                                                  // Se usa para limpiar la pantalla
    // El mensaje de entrada al juego
    cout << "\t\t\t\t\t\t--INTRODUCCION--\n\nBattleship es un juego en el que te enfrentas a la computadora posicionando embarcaciones en tu propio campo, sin que el contrincante sepa\nde ellas.\n\n\n\n\t\t\t\t\t\t--MODO DE JUEGO--\n\nAl comenzar la partida se intentara adivinar las posiciones de los barcos del contrincante, si alguno logra tumbar\nlos barcos del otro rival, entonces este sera el ganador.\n\n\n\n\t\t\t\t\t\t--DETALLES--\n\nCada jugador tendra barcos unitarios y jugaras contra la CPU, la cual ganara si adivina x\nposiciones de tus barcos.\n\n\n\n\t\t\t\t\t\t--SUERTE MARINERO--\n\n" << endl;
    system("pause"); // Para pausar la ejecucion
    system("cls");   // Para limpiar la pantalla
    return 0;
}
