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

void show_2()
{

    system("cls"); // Se limpia la pantalla
    cout << "Acabas de posicionar tus barcos de esta manera:\n\n";
    for (int i = 0; i < filas; i++) // Recorrido de las filas
    {
        for (int j = 0; i < elementos; j++) // Recorrido de las columnas
        {
            if (matrix_2[i][j] == 1) // Se lee matrix_2 para determinar el ubicacion y posicion de los barcos
            {
                matrix[i][j] = 'T'; // Se asigna el caracter 'T' en la posicion donde se encuentre un barco
            }
            cout << matrix[i][j]; // Se imprime el tablero al usuario
        }
        cout << "\n"; // Se imprime un salto de linea
    }
    seleccion = 0; // El valor de la seleccion reiniciado por si se quiere cambiar la posicion de los barcos

    cout << " \n Estas de acuerdo con la posicion de tus barcos o deseas modificarlas?\n\n1 = ESTOY DE ACUERDO\t2 = CAMBIAR POSICIONES" << endl;
    cin >> seleccion;
    switch (seleccion)
    {
    case 1:            // Esta de acuerdo el usuario con sus posiciones
        system("cls"); // Se limpia la pantalla y el programa sigue
        break;

    case 2: // Por si el usuario quiere modificar las coordenadas de sus barcos
        for (int i = 0; i < 10; i++) //Recorrido por las filas
        {
            for (int j = 0; i < 10; j++)//Recorrido por las columnas
            {
                matrix[i][j] = '~';//Se rellena el tablero del jugador con "~"
                matrix_2[i][j] = 0;//Llenado de la matriz del jugador con los valores de 0
            }
        }
        system("cls");
        void colocar(); //Se llama la funcion "colocar" para volver a colocar los barcos del usuario
        break;
    }
    return;//Finaliza la funcion "Show_2"
}