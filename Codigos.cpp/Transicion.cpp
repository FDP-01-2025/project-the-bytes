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
void transicion()
{
    // Se explica el objetivo del jugador
    cout << " \n\n!Tu mision, derribar los barcos del rival, la mision del rival, derribar tus barcos!" << endl;
    // Se explica la interfaz del juego
    cout << "\n\nNOTA: Si en la posicion atacada hay una 'X' significa que el ataque no impacto con\nningun barco, pero si hay una 'B' significa que hubo un impacto.\n\n\n\n\n\t\t\t\tCARGANDO..." << endl;
    Sleep(10000); // Retardo de 10 segundos
    return;       // Finaliza la funcion "Transicion"
}
