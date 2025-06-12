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
int fil = 0, col = 0, matrix_2[filas][elementos], matrix_alea[filas][elementos] = {0}, matrix_3[filas][elementos] = {0}, barcos_derribados = 0, ataques = 0, bajas = 0, nivel = 0, seleccion = 0, alea1 = 0, alea2 = 0, ataque_filas = 0, ataque_columnas = 0, alea4 = 0;
char matrix[filas][elementos], matrix_alea2[filas][elementos] = {'~'}, matrix_barco_enemigo[filas][elementos] = {'~'};

void Tablero_1()
{
    system("cls");       // Para limpiar la pantalla
    ataque_filas = 0;    // Reinicio de las posiciones de las filas para atacar
    ataque_columnas = 0; // Reinicio de las posiciones de las columnas a atacar

    cout << "Si quieres rendirte presiona -1 en cualquier coordenada (X O Y)\nPara atacar: Primero ingresa la coordenada 'Y' y luego ingresa la coordenada 'X'" << endl;
    ataques++;                              // Para conocer la cantidad de veces quehas atacado
    cin >> ataque_filas >> ataque_columnas; // Toma de posiciones a atacar

    if (ataque_filas < 0 || ataque_columnas < 0) // En caso decida rendirse el rival
    {
        system("cls"); // Para limpiar la pantalla
        cout << "\n\n\n\n\n\t\t\tPERDISTE, TE HAS RENDIDO.\n\n\n\n\n";
        exit(-1); // Para finalizar el programa sin importar donde se encuentre
    }
    if (matrix_3[ataque_filas][ataque_columnas] == 0)
    {
        if (matrix_alea[ataque_filas][ataque_columnas] == 0) // En el casono haya ningun otro barco
        {
            matrix_3[ataque_filas][ataque_columnas] = 1; // Asignacion de la matriz discreta de 1
        }
        if (matrix_alea[ataque_filas][ataque_columnas] == 1) // En el caso que ya haya un barco ahi
        {
            matrix_3[ataque_filas][ataque_columnas] = 2; // Se le asigna el valor de 2 a la matriz "discreta"
            barcos_derribados++;                         // Incrementa el numero de barcos hundidos
        }
    }
    else // Por si ya se selecciono esa posicion
    {
        cout << "\n\tEsta posicion ya la atacaste, elige otra!" << endl;
        ataques--;   // Decrementa el numero de ataques
        Sleep(2000); // Retardo de 2 segundos
        Tablero_1(); // Se llama a la funcion para que sea "recursiva"
    }

