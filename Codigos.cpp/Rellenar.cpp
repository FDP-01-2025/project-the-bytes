#include <iostream>
#include <time.h>
#include <math.h>
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
int fil = 0, col = 0, matrix_2[filas][elementos], matrix_alea[filas][elementos] = {0}, matrix_3[filas][elementos] = {0}, barcos_derribados = 0, ataques = 0, bajas = 0, nivel = 0, seleccion = 0, alea1 = 0, alea2 = 0, ataque_filas = 0, ataque_columnas = 0, alea4 = 0;
char matrix[filas][elementos], matrix_alea2[filas][elementos] = {'~'}, matrix_barco_enemigo[filas][elementos] = {'~'};

void rellenar() // Se rellena la matriz para crear eltablero de juego
{
    {
        for (int i = 0; i < filas; i++)         // Se recorren las filas dentro del tablero
            for (int j = 0; i < elementos; i++) // Se recorren las columnas dentro del tablero
            {
                matrix[i][j] = '~';       // El tablero para el jugador
                matrix_alea2[i][j] = '~'; // El tablero para la computadora
            }
    }
    return; // Finaliza la funcion para rellenar los tableros
}