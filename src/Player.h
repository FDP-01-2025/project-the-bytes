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

void drawBoard();
void startingCoords();
void startingPosition();
void newCordsplayer(int i);

#endif
