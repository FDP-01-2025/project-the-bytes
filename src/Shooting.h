#ifndef SHOOTING_H
#define SHOOTING_H

#include <string>
using namespace std;

class Shooting
{
private:
    int shootX;
    int shootY;
    string Cord;

public:
    Shooting();
    Shooting(int a, int b, string c);

    void Input_Coord();          // Coords of the player
    void Draw_Shooting();        // Shows boards in the screen
    void Update_Player_Grid();   // Computer's shooting turn
    void Update_Computer_Grid(); // Player's shooting turn
};

extern int positions[100][2]; // Arrays of coords
extern int posCount;          // Quantity of elements in "position"
extern int Count_Computer;    // Computer's point counter
extern int Count_Player;      // Player's point counter

// These are position management functions
void PushPosition(int x, int y);
bool PopPosition(int &x, int &y);

#endif
