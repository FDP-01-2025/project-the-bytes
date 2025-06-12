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
void aleatorio()
{
    system("cls"); // Se limpia la pantalla
    cout << "\n\n\n\n\n\t\t\tEspera a que tu oponente posicione sus 10 barcos unitarios...\n\n";
    alea1 = 0; // Seteo de valores para la coordenada en y
    alea2 = 0; // Seteo de valores para la coordenada en x

    for (int i = 0; i < 10; i++) // Se llena 10 veces para los 10 barcos colocados aleatoriamente
    {
        srand(time(NULL));                  // Para la generacion de numeros pseudoaleatorios
        alea1 = (rand() % 10);              // Se asigna valores a "alea1"
        alea2 = (rand() * rand()) % 10;     // Se asigna valores a "alea2"
        if (matrix_alea[alea1][alea2] == 0) // Es la condicion para generar 10 barcos en coordenadas distintas
        {
            matrix_alea[alea1][alea2] = 1; // Si su sigue siendo cero, entonces se encuentra vacio
        }
        else
        {
            i = i - 1; // Si su valor no es cero, se decrementa para tomar una posicion diferente
        }
    }
    for (int i = 0; i < filas; i++) // Recorrido de filas
    {
        for (int j = 0; j < elementos; j++)
        {
            if (matrix_alea[i][j] == 1) // Condicion para conocer si se posiciona un barco en el tablero de la computadora
            {
                matrix_alea2[i][j] = 'O'; // Se asigna el caracter 'O' para donde se posicione el barco de la computadora
            }
        }
    }
    cout << "\n\n\n\n\n\t\t\t\t!Tu oponente a posicionado sus barcos!" << endl; // Mensaje para mencionar que ya se colocaron los barcos de la computadora
    Sleep(3000);                                                                // Retraso de 3 segundos
    system("cls");                                                              // Para limpiar la pantalla
    return;                                                                     // Finaliza la funcion "aleatorio"
}