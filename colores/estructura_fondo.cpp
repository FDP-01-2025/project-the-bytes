#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    // Fondo rojo (4) * 16 + texto blanco brillante (15) = 79
    SetConsoleTextAttribute(h, 16 * 4 + 15); 
    cout << "Texto con fondo rojo y letras blancas" << endl;

    // Fondo azul (1) * 16 + texto amarillo brillante (14) = 30
    SetConsoleTextAttribute(h, 16 * 1 + 14);
    cout << "Texto con fondo azul y letras amarillas" << endl;

    // Fondo verde (2) * 16 + texto negro (0) = 32
    SetConsoleTextAttribute(h, 16 * 2 + 0);
    cout << "Texto con fondo verde y letras negras" << endl;

    // Regresar al color por defecto (gris claro sobre negro)
    SetConsoleTextAttribute(h, 7);
    cout << "Texto normal (colores por defecto)" << endl;

    return 0;
}
