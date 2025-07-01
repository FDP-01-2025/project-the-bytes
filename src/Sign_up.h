#ifndef SIGN_UP_H
#define SIGN_UP_H

#include <string>
using namespace std;

struct Jugador // Struct to have the name and ID of the user
{
    string name; // Name of the player
    string ID;   // ID of the player
};

void SaveData(const Jugador &jugador); // Function to save data of players
void SignUp1Player();                  // Function to write the name and ID in gamemode vs CPU
void SignUp1vs1();                     // Function to write the name and ID in gamemode multiplayer

#endif
