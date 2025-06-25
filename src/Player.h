#ifndef __PLAYER__
#define __PLAYER__

#include <string>
using namespace std;

const int playerRows = 12;
const int playerColumns = 12;

extern int playerBoard[playerRows + 1][playerColumns + 1];
extern int Coordx, Coordy;
extern string Coordenate;
extern char position;
 // There are variables that use in the cpp document

void drawBoard(); // Function to draw the player board.
void startingCoords(); // Function to write the coords into the game.
void startingPosition(); // Function to get the orientation of the ship.
void newCordsplayer(int i); // Function to put the ship into the board.

#endif
