#ifndef SHOOTING_H
#define SHOOTING_H

#include <string>
using namespace std;

extern int shootX;
extern int shootY;
extern string Cord;

extern int positions[100][2]; // Arrays of coords
extern int posCount;          // Quantity of elements in "position"
extern int Count_Computer;    // Computer's point counter
extern int Count_Player;      // Player's point counter

void Shooting(); 
void InitShooting(int a, int b, string c);

void Input_Coord();          // Coords of the player
void Draw_Shooting();        // Shows boards in the screen
void Update_Player_Grid();   // Player's shooting turn
void Update_Computer_Grid(); // Computer's shooting turn

void PushPosition(int x, int y);
bool PopPosition(int x, int y);

#endif
