#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <windows.h>
#include "Colocar.h"
#include "Dificultad.h"
#include "Instrucciones.h"
#include "Aleatorio.h"
#include "Rellenar.h"
#include "Show_2.h"
#include "Tablero_1.h"
#include "Tablero_2.h"
#include "Transicion.h"

using namespace std;

const int filas = 10;
const int elementos = 10;
int fil = 0, col = 0, matrix_2[filas][elementos], matrix_alea[filas][elementos] = {0};
int matrix_3[filas][elementos] = {0}, barcos_derribados = 0, ataques = 0, bajas = 0;
int nivel = 0, seleccion = 0, alea1 = 0, alea2 = 0, ataque_filas = 0, ataque_columnas = 0, alea4 = 0;
char matrix[filas][elementos], matrix_alea2[filas][elementos] = {'~'}, matrix_barco_enemigo[filas][elementos] = {'~'};

void instrucciones()
{

    cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t...BATTLESHIP..." << endl; // Nombre del juego
    Sleep(4000);                                                    // Se usa para pausar la ejecucion por un periodo de tiempo
    system("cls");                                                  // Se usa para limpiar la pantalla
    // El mensaje de entrada al juego
    cout << "\t\t\t\t\t\t--INTRODUCCION--\n\nBattleship es un juego en el que te enfrentas a la computadora posicionando embarcaciones en tu propio campo, sin que el contrincante sepa\nde ellas.\n\n\n\n\t\t\t\t\t\t--MODO DE JUEGO--\n\nAl comenzar la partida se intentara adivinar las posiciones de los barcos del contrincante, si alguno logra tumbar\nlos barcos del otro rival, entonces este sera el ganador.\n\n\n\n\t\t\t\t\t\t--DETALLES--\n\nCada jugador tendra barcos unitarios y jugaras contra la CPU, la cual ganara si adivina 2\nposiciones de tus barcos.\n\n\n\n\t\t\t\t\t\t--SUERTE MARINERO--\n\n"
         << endl;
    system("pause"); // Para pausar la ejecucion
    system("cls");   // Para limpiar la pantalla
    return;          // Finaliza la funcion "instrucciones"
}
