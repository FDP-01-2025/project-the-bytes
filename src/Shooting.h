#ifndef SHOOTING1_H
#define SHOOTING1_H

#include <string>
using namespace std;

class Shooting
{
private:
    int shootX;
    int y;
    std::string Cord;

public:
    Shooting();
    Shooting(int a, int b, string c);

    void Input_Coord();          // Coordenadas del jugador
    void Draw_Shooting();        // Muestra tableros en pantalla
    void Update_Player_Grid();   // Turno de disparo de la computadora
    void Update_Computer_Grid(); // Turno de disparo del jugador
};

// Variables globales para smart shooting sin vector
extern int positions[100][2]; // Arreglo de coordenadas
extern int posCount;          // Cantidad de elementos en 'positions'
extern int Count_Computer;
extern int Count_Player;

// Funciones auxiliares de manejo de posiciones
void PushPosition(int x, int y);
bool PopPosition(int &x, int &y);

#endif
