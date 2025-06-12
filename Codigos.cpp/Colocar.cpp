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


const int filas = 10;
const int elementos = 10;
int fil = 0, col = 0, matrix_2[filas][elementos], matrix_alea[filas][elementos] = {0};
int matrix_3[filas][elementos] = {0}, barcos_derribados = 0, ataques = 0, bajas = 0;
int nivel = 0, seleccion = 0, alea1 = 0, alea2 = 0, ataque_filas = 0, ataque_columnas = 0, alea4 = 0;
char matrix[filas][elementos], matrix_alea2[filas][elementos] = {'~'}, matrix_barco_enemigo[filas][elementos] = {'~'};

using namespace std;
void colocar() // Funcion para colocar los barcos
{
    // Instrucciones para colocar los barcos
    cout << "Se te han otorgado 10 barcos unitarios (1x1), colocalos ingresando primero la coordenada 'Y'\ny despues la coordenada x, separada por un espacio" << endl;
    for (int i = 0; i < 10; i++) //(10 barcos para el usuario)
    {
        cout << "Dame las coordenadas para el barco numero " << i + 1 << " ";
        cin >> fil >> col; // Toma las coordenadas
        if (matrix_2[fil][col] == 0)
        {
            matrix_2[fil][col] = 1; // Se asigna el barco en esa posicion
        }
        else
        {
            cout << "\nEsta posicion ya esta usada, seleccione una opcion diferente" << endl; // Este es el mensaje si se escribe una coordenada repetida
            i = i - 1;                                                                        // Se decrementa el valor de "i" para que vuelva a escribir una coordenada
        }
    }
    void show_2(); // Se llama a la funcion "show_2"
    return;        // Finaliza la funcion "Colocar"
}