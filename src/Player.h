#include <String>

#ifndef __PLAYER__
#define __PLAYER__

using namespace std;

const int playerRows = 12;
const int playerColumns = 12;
extern int playerBoard[playerRows + 1][playerColumns + 1];

class Player {
private:
	int Coordx, Coordy;
	string Coordenate;
	char position;
public:
	Player();
	Player(int a, int b, string c, char d);
	

	void drawBoard();
	void startingCoords();
	void startingPosition();
	void newCordsplayer(int i);
};

#endif 