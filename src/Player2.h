#ifndef __PLAYER2__
#define __PLAYER2__

#include <string>
using namespace std;

const int player2Rows = 12;
const int player2Columns = 12;

extern int player2Board[player2Rows + 1][player2Columns + 1];
extern int Coordx2, Coordy2;
extern string Coordenate2;
extern char position2;

void drawBoard2(); // Draw player 2's board on the console, with letters (A-J) and numbers (0-9).
void startingCoords2(); // Function to write the coords into the game.
void startingPosition2(); // Function to get the orientation of the ship.
void newCordsplayer2(int i); // Function to put the ship into the board.

#endif
