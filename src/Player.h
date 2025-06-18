#include <String>

#ifndef __PLAYER__
#define __PLAYER__

using namespace std;

const int Rows = 12;    // The rows that has the board
const int Columns = 12; // The columns that has the board
extern int playerBoard[Rows + 1][Columns + 1];

class Player
{
private:
    int CoordsX, CoordsY;
    string Coordenate;
    char playerPos;
    // There are variables that use in the cpp document

public:
    Player();
    Player(int coordA, int coordB, string coordsC, char positionD);

    void Drawboard();          // Function to draw the player board.
    void startingCoords();     // Function to write the coords into the game.
    void startirgPos();        // Function to get the orientation of the ship.
    void updatedCoords(int i); // Function to put the ship into the board.
    // We declare functions to use later into the cpp document.
};

#endif // !__Player__