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

void drawBoard2();
void startingCoords2();
void startingPosition2();
void newCordsplayer2(int i);

#endif
