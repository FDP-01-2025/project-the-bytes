#ifndef SHOOTING2_H
#define SHOOTING2_H

#include <string>
using namespace std;

extern int Count_Player2; // Player 2 point counter
extern int shootX2;       // Shoot in x of player 2
extern int shootY2;       // Shoot in y of player 2
extern string Cord2;      // Couple of coordenates

void Shooting2();
void InitShooting2(int a, int b, string c);
void Input_Coord2();        // Coords of the player 2
void Draw_Shooting2();      // Show board in the screen
void Update_Player2_Grid(); // Player's shooting turn

#endif
