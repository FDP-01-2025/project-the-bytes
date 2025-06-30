// #ifndef SHOOTING2_H
// #define SHOOTING2_H

// #include <string>
// using namespace std;

// extern int Count_Player2; // Player 2 point counter
// extern int shootX2;       // Shoot in x of player 2
// extern int shootY2;       // Shoot in y of player 2
// extern string Cord2;      // Couple of coordenates

// void Shooting2();
// void InitShooting2(int a, int b, string c);
// void Input_Coord2();        // Coords of the player 2
// void Draw_Shooting2();      // Show board in the screen
// void Update_Player2_Grid(); // Player's shooting turn
// void Update_Player1_Grid();

// #endif

#ifndef SHOOTING2_H
#define SHOOTING2_H

#include <string>
using namespace std;

extern int Count_Player1; // Points of player 1
extern int Count_Player2; // Points of player 2

extern int shootX1, shootY1; // Coords of shoot of player 1
extern int shootX2, shootY2; // Coords of shoot of player 2
extern string Cord1, Cord2;  // Coords writed like string

void Shooting2();
void InitShooting2(int a, int b, string c);
void Input_Coord1();        // Coords of Player 1
void Input_Coord2();        // Coords of Player 2
void Draw_Shooting2();      // Show boards
void Update_Player1_Grid(); // Player 1 shoot
void Update_Player2_Grid(); // Player 2 shoot
void Draw_Player1_View();   // Interspersed turns
void Draw_Player2_View();   // Interpersed turns
void StartBattle();         // Battle for turns

#endif
