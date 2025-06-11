#include <iostream>
#include <time.h>
#include <math.h>
#include <windows.h>

const int filas = 10;
const int elementos = 10;

using namespace std;

int main()
{
    const int filas = 10;
    const int elementos = 10;
    int fil = 0, col = 0, matrix_2[filas][elementos], matrix_alea[filas][elementos] = {0};
    int matrix_3[filas][elementos] = {0}, barcos_derribados = 0, ataques = 0, bajas = 0;
    int nivel = 0, seleccion = 0, alea1 = 0, alea2 = 0, ataque_filas = 0, ataque_columnas = 0, alea4 = 0;
    char matrix[filas][elementos], matrix_alea2[filas][elementos] = {'~'}, matrix_barco_enemigo[filas][elementos] = {'~'};

    system("cls"); // Se limpia la pantalla
    cout << "Acabas de posicionar tus barcos de esta manera:\n\n"<< endl;
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
}
