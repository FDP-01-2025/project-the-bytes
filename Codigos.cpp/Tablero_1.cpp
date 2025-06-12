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
    cout << "Acabas de atacar el tablero de tu oponente asi:\n\n"
         << endl;
    for (int i = 0; i < filas; i++) // Se recorren las filas
    {
        for (int j = 0; j < elementos; j++) // Se recorren las columnas
        {
            if (matrix_3[i][j] == 1) // Se compara si se ataco y no estaba el valor de 1
            {
                matrix_barco_enemigo[i][j] = 'X'; // Caracter que se mostrara al atacar una coordenada
            }
            if (matrix_3[i][j] == 2)
            {
                matrix_barco_enemigo[i][j] = 'B'; // caracter "B" para demostrar que se ataco yq eu si habia un barco
            }
            if (matrix_3[i][j] == 0)
            {
                matrix_barco_enemigo[i][j] = '~'; // Caracter "~" para rellenar las posiciones por atacar
            }
            cin >> matrix_barco_enemigo[i][j]; // Impresion del tablero atacado
        }
        cout << endl; // Salto de linea por tema de orden
    }
    cout << "\nHas atacado " << ataques << " veces" << endl;                 // Se muestran la cantidad de ataques que hizo el usuario
    cout << "\nHas derribado " << barcos_derribados << "/" << nivel << endl; // Muestra el numero de barcos derribados
    Sleep(4000);                                                             // Retardo de 4 segundos

    if (barcos_derribados == nivel) // Condicion para saber si los barcos que derribo coinciden con el nivel para sabersi gano
    {
        system("cls");                                                          // Para limpiar la pantalla
        cout << "\n\n\n\n\n\t\t\t!FELICIDADES, HAS GANADO EL JUEGO!\n\n\n\n\n"; // Mensaje de ganador
        exit(-1);                                                               // Para cerrar el programa donde sea que se encuentre
    }
    system("cls");    // Limpiar la pantalla
    void Tablero_2(); // Se llama a la variable "Tablero_2"
    return;           // Finaliza la funcion Tablero_1
}
