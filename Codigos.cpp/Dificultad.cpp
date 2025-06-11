#include <iostream>
#include <time.h>
#include <math.h>
#include <windows.h>
#include "Colocar.h"
#include "Dificultad.h"
#include"Instrucciones.h"
#include"Aleatorio.h"
#include"Rellenar.h"
#include"Show_2.h"
#include"Tablero_1.h"
#include"Tablero_2.h"
#include"Transicion.h"


using namespace std;
const int filas = 10;
const int elementos = 10;
int fil = 0, col = 0, matrix_2[filas][elementos], matrix_alea[filas][elementos] = {0};
int matrix_3[filas][elementos] = {0}, barcos_derribados = 0, ataques = 0, bajas = 0;
int nivel = 0, seleccion = 0, alea1 = 0, alea2 = 0, ataque_filas = 0, ataque_columnas = 0, alea4 = 0;
char matrix[filas][elementos], matrix_alea2[filas][elementos] = {'~'}, matrix_barco_enemigo[filas][elementos] = {'~'};

void dificultad()
{
    cout << "Selecciona la dificultad en la que jugaras: \n\n\t1. FACIL\t(Ganas si tumbas 1 barco enemigo)\n\n\t2. INTERMEDIO\t(Ganas si tumbas 2 barcos enemigos)\n\n\t3. DIFICIL\t(Ganas si tumbas 3 barcos enemigos)" << endl;
    cin >> seleccion; // Seleccion de dificultad en el juego

    switch (seleccion)
    {
    case 1:
        nivel = 1; // Es la dificultad "facil" elegida por el usuario
        break;
    case 2:
        nivel = 2; // Es la dificultad "media" elegida por el usuario
        break;
    case 3:
        nivel = 3; // Es la dificultad "dificil" elegida por el usuario
        break;
    default:
    }
    system("cls");  // Para limpiar la pantalla
    void colocar(); // Se llama a la funcion "colocar"
    return;         // Finaliza la funcion "Dificultad"
}