#include "Player.h"
#include <iostream>
#include <String>

using namespace std;

int playerBoard[rowsPlayer + 1][columnsPlayer + 1] = {0};

Player::Player()
{
    Coordenate = "";
    playerPos = ' ';
    CoordsX = 0;
    CoordsY = 0;
}
Player::Player(int coordA, int coordB, string coordsC, char positionD)
{
    CoordsX = coordA;
    CoordsY = coordB;
    Coordenate = coordsC;
    playerPos = positionD;
}

void Player::Drawboard()
{
    cout << "                   Player\n            0 1 2 3 4 5 6 7 8 9\n";
    char letter = 'A';

    for (int i = 1; i < rowsPlayer - 1; i++)
    {
        cout << "          " << letter++ << " ";
        for (int j = 1; j < columnsPlayer - 1; j++)
        {

            if (playerBoard[i][j] == 0 || playerBoard[i][j] == 2) // We use 0 to free cords, then we use 2 to ship sides
                cout << ". ";
            else if (playerBoard[i][j] == 1) // We use 1 to indicate that exist the ship
                cout << "0 ";                // The ship is printed
        }
        cout << endl;
    }
}
void Player::startingCoords()
{
    bool trueCord;

    do
    {
        cout << "   Input a coordinates X & Y (Ex.: B1): "; // We ask the user for a coord
        cin >> Coordenate;

        // Assci Table
        CoordsX = Coordenate[0] - 64; // Char Letter to our needed number
        CoordsY = Coordenate[1] - 47; // Char number to our needed number

        // Checking if input is correct
        trueCord = false;

        if (Coordenate.size() == 2) // We check if the size of the coords it's ok or not
        {                           // Correct number of symbols - 2
            for (char i = 'A'; i <= 'J'; i++)
            {
                if (Coordenate[0] == i) // We check if first char digited is a letter
                {
                    trueCord = true;
                    break;
                }
            }

            if (!(isdigit(Coordenate[1])))
            { // We check if second char digited is a number
                trueCord = false;
            } // It gonna be false if symbol isn't a number
        }

    } while (!(trueCord));
}
void Player::startirgPos()
{
    do
    {
        cout << "   Enter position Horizontal or vertical (H)/(V): "; // The user write the orientation
        cin >> playerPos;

        if ((playerPos == 'V') || (playerPos == 'H'))
        {
            break;
        }
    
    } while (true);
}
void Player::updatedCoords(int i)
{
    bool repeat_input = false;

    while (true)
    {
        if (playerBoard[CoordsX][CoordsY] == 0) // We checking if the first coordinate is free to put a ship
        {

            if (i > 6)
                playerBoard[CoordsX][CoordsY] = 1; // It gonna put ship with size 1
            break;
        }
        else // We use this else for ship coords coliision
        {    // Else for ship coordinates collision
            startingCoords();

            if (i < 7) // Is mandatory do this until the last ship.
            {
                startirgPos();
            }
        }
    }

    if (i < 7)
        while (true) // It gonna stop if it's okay to put ships in any position
        {
            if (playerPos == 'V') // This is only for vertical position
            {
                if (i == 1) // Size of the ship (one) box
                {
                    if (CoordsX < 8) // The ship must never leave the limits
                    {
                        if (playerBoard[CoordsX + 1][CoordsY] == 0 && playerBoard[CoordsX + 2][CoordsY] == 0 && playerBoard[CoordsX + 3][CoordsY] == 0)
                        {
                            playerBoard[CoordsX][CoordsY] = 1;
                            playerBoard[CoordsX + 1][CoordsY] = 1;
                            playerBoard[CoordsX + 2][CoordsY] = 1;
                            playerBoard[CoordsX + 3][CoordsY] = 1;
                            break;
                            // We checking if four long ship coordinates are free for ship
                        }
                        else
                        {
                            repeat_input = true;
                        }
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
                else if (i >= 2 && i < 4) // Size of the ship (two) box
                {
                    if (CoordsX < 9) // The ship must never leave the limits
                    {
                        if (playerBoard[CoordsX + 1][CoordsY] == 0 && playerBoard[CoordsX + 2][CoordsY] == 0)
                        { // Checking if 3 long ship coordinates are free for ship
                            playerBoard[CoordsX][CoordsY] = 1;
                            playerBoard[CoordsX + 1][CoordsY] = 1;
                            playerBoard[CoordsX + 2][CoordsY] = 1;
                            break;
                            // We checking if three long ship coordinates are free for ship
                        }
                        else
                        {
                            repeat_input = true;
                        }
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
                else if (i > 3 && i < 7) // Size of the ship (three) box
                {
                    if (CoordsX < 10) // The ship must never leave the limits
                    {
                        if (playerBoard[CoordsX + 1][CoordsY] == 0)
                        {
                            playerBoard[CoordsX][CoordsY] = 1;
                            playerBoard[CoordsX + 1][CoordsY] = 1;
                            break;
                            // Checking if two long ship coordinates are free for ship
                        }
                        else
                        {
                            repeat_input = true;
                        }
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
            }
            else if (playerPos == 'H') // This is only to  horizontal position.
            {
                if (i == 1) // Size of the ship (one) box
                {
                    if (CoordsY < 8) // The ship must never leave the limits
                    {
                        if (playerBoard[CoordsX][CoordsY + 1] == 0 && playerBoard[CoordsX][CoordsY + 2] == 0 && playerBoard[CoordsX][CoordsY + 3] == 0)
                        {
                            playerBoard[CoordsX][CoordsY] = 1;
                            playerBoard[CoordsX][CoordsY + 1] = 1;
                            playerBoard[CoordsX][CoordsY + 2] = 1;
                            playerBoard[CoordsX][CoordsY + 3] = 1;
                            break;
                            // Checking if four long ship coordinates are free for ship
                        }
                        else
                        {
                            repeat_input = true;
                        }
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
                else if (i >= 2 && i < 4) // Size of the ship (two) box
                {
                    if (CoordsY < 9) // The ship must never leave the limits
                    {
                        if (playerBoard[CoordsX][CoordsY + 1] == 0 && playerBoard[CoordsX][CoordsY + 2] == 0)
                        {
                            playerBoard[CoordsX][CoordsY] = 1;
                            playerBoard[CoordsX][CoordsY + 1] = 1;
                            playerBoard[CoordsX][CoordsY + 2] = 1;
                            break;
                            // Checking if three long ship coordinates are free for ship
                        }
                        else
                        {
                            repeat_input = true;
                        }
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
                else if (i > 3 && i < 7) // Size of the ship (three) box
                {
                    if (CoordsY < 10) // The ship must never leave the limits
                    {
                        if (playerBoard[CoordsX][CoordsY + 1] == 0)
                        {
                            playerBoard[CoordsX][CoordsY] = 1;
                            playerBoard[CoordsX][CoordsY + 1] = 1;
                            break;
                            // Checking if two long ship coordinates are free for ship
                        }
                        else
                        {
                            repeat_input = true;
                        }
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
            }

            if (repeat_input)
            {
                startingCoords();
                if (i < 7)
                    startirgPos(); // Is mandatory do this until the last ship.
            }
        }

    for (int p = 0; p < 4; p++) // This is the area around the ship
    {

        if (playerBoard[CoordsX + 1][CoordsY] == 0)
        {
            playerBoard[CoordsX + 1][CoordsY] = 2;
        }
        if (playerBoard[CoordsX][CoordsY + 1] == 0)
        {
            playerBoard[CoordsX][CoordsY + 1] = 2;
        }
        if (playerBoard[CoordsX - 1][CoordsY] == 0)
        {
            playerBoard[CoordsX - 1][CoordsY] = 2;
        }
        if (playerBoard[CoordsX][CoordsY - 1] == 0)
        {
            playerBoard[CoordsX][CoordsY - 1] = 2;
        }
        if (playerBoard[CoordsX + 1][CoordsY + 1] == 0)
        {
            playerBoard[CoordsX + 1][CoordsY + 1] = 2;
        }
        if (playerBoard[CoordsX - 1][CoordsY - 1] == 0)
        {
            playerBoard[CoordsX - 1][CoordsY - 1] = 2;
        }
        if (playerBoard[CoordsX + 1][CoordsY - 1] == 0)
        {
            playerBoard[CoordsX + 1][CoordsY - 1] = 2;
        }
        if (playerBoard[CoordsX - 1][CoordsY + 1] == 0)
        {
            playerBoard[CoordsX - 1][CoordsY + 1] = 2;
        }
        if (playerBoard[CoordsX + 1][CoordsY] == 1)
        {
            CoordsX++;
        }
        if (playerBoard[CoordsX][CoordsY + 1] == 1)
        {
            CoordsY++;
        }
    }
}