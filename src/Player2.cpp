#include "Player2.h"
#include <iostream>
#include <string>

using namespace std;

int player2Board[player2Rows + 1][player2Columns + 1] = {0}; // Declare player 2's board, initialized to zeros.
int Coordx2 = 0, Coordy2 = 0;                                // Current coordinates that player 2 is choosing to place a ship.
string Coordenate2 = "";                                     // Saves the initial coordinate of player 2, for example
char position2 = ' ';

void drawBoard2()
{
    cout << "                 Player 2\n            0 1 2 3 4 5 6 7 8 9\n";
    char letter = 'A';

    for (int i = 1; i < player2Rows - 1; i++) // Saves whether the ship is vertical or horizontal
    {
        cout << "          " << letter++ << " ";
        for (int j = 1; j < player2Columns - 1; j++)
        {
            if (player2Board[i][j] == 0 || player2Board[i][j] == 2) // We use 0 to free cords, then we use 2 to ship sides
            {
                cout << ". ";
            }
            else if (player2Board[i][j] == 1) // We use 1 to indicate that exist the ship
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

void startingCoords2()
{
    bool correct_cord;

    do
    {
        cout << "   Input a coordinates X & Y (Ex.: A5): "; // We ask the user for a coord
        cin >> Coordenate2;

        Coordx2 = Coordenate2[0] - 64; // Char Letter to our needed number
        Coordy2 = Coordenate2[1] - 47; // Char number to our needed number

        correct_cord = false; // Checking if input is correct

        if (Coordenate2.size() == 2) // We check if the size of the coords it's ok or not. The Correct number of symbols is 2
        {
            for (char i = 'A'; i <= 'J'; i++)
            {
                if (Coordenate2[0] == i) // We check if first char digited is a letter
                {
                    correct_cord = true;
                    break;
                }
            }

            if (!(isdigit(Coordenate2[1]))) // We check if second char digited is a number
            {
                correct_cord = false; // It gonna be false if symbol isn't a number
            }
        }
    } while (!(correct_cord));
}

void startingPosition2()
{
    do
    {
        cout << "   Enter position H/V: "; // The user write the orientation
        cin >> position2;

        if ((position2 == 'V') || (position2 == 'v') || (position2 == 'h') || (position2 == 'H'))
        {
            break;
        }
        else
        {
            cout << "Please write a valid coords" << endl;
        }
    } while (true);
}

void newCordsplayer2(int i)
{
    bool repeat_input = false;

    while (true)
    {
        if (player2Board[Coordx2][Coordy2] == 0) // We checking if the first coordinate is free to put a ship
        {
            if (i > 6)
            {
                player2Board[Coordx2][Coordy2] = 1; // It gonna put ship with size 1
            }
            break;
        }
        else
        {
            startingCoords2();
            if (i < 7) // Is mandatory do this until the last ship.
            {
                startingPosition2();
            }
        }
    }

    if (i < 7) // It gonna stop if it's okay to put ships in any position
        while (true)
        {
            if (position2 == 'V' || position2 == 'v') // This is only for vertical position
            {
                if (i == 1) // Size of the ship (one) box
                {
                    // The ship must never leave the limits
                    if (Coordx2 < 8 && player2Board[Coordx2 + 1][Coordy2] == 0 && player2Board[Coordx2 + 2][Coordy2] == 0 && player2Board[Coordx2 + 3][Coordy2] == 0)
                    {
                        // Checking if 4 long ship coordinates are free for ship
                        player2Board[Coordx2][Coordy2] = 1;
                        player2Board[Coordx2 + 1][Coordy2] = 1;
                        player2Board[Coordx2 + 2][Coordy2] = 1;
                        player2Board[Coordx2 + 3][Coordy2] = 1;
                        break;
                        // We checking if four long ship coordinates are free for ship
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
                else if (i >= 2 && i < 4) // Size of the ship (two) box
                {
                    // The ship must never leave the limits
                    if (Coordx2 < 9 && player2Board[Coordx2 + 1][Coordy2] == 0 && player2Board[Coordx2 + 2][Coordy2] == 0)
                    {
                        // Checking if 3 long ship coordinates are free for ship
                        player2Board[Coordx2][Coordy2] = 1;
                        player2Board[Coordx2 + 1][Coordy2] = 1;
                        player2Board[Coordx2 + 2][Coordy2] = 1;
                        break;
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
                else if (i > 3 && i < 7) // Size of the ship (three) box
                {
                    if (Coordx2 < 10 && player2Board[Coordx2 + 1][Coordy2] == 0)
                    {
                        player2Board[Coordx2][Coordy2] = 1;
                        player2Board[Coordx2 + 1][Coordy2] = 1;
                        break;
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
            }
            else if (position2 == 'H' || position2 == 'h')
            {
                if (i == 1) // Size of the ship (one) box
                {
                    if (Coordy2 < 8 && player2Board[Coordx2][Coordy2 + 1] == 0 && player2Board[Coordx2][Coordy2 + 2] == 0 && player2Board[Coordx2][Coordy2 + 3] == 0)
                    {
                        player2Board[Coordx2][Coordy2] = 1;
                        player2Board[Coordx2][Coordy2 + 1] = 1;
                        player2Board[Coordx2][Coordy2 + 2] = 1;
                        player2Board[Coordx2][Coordy2 + 3] = 1;
                        break;
                        // Checking if 4 long ship coordinates are free for ship
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
                else if (i >= 2 && i < 4) // Size of the ship (two) box
                {
                    if (Coordy2 < 9 && player2Board[Coordx2][Coordy2 + 1] == 0 && player2Board[Coordx2][Coordy2 + 2] == 0)
                    {
                        player2Board[Coordx2][Coordy2] = 1;
                        player2Board[Coordx2][Coordy2 + 1] = 1;
                        player2Board[Coordx2][Coordy2 + 2] = 1;
                        break;
                        // Checking if 3 long ship coordinates are free for ship
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
                else if (i > 3 && i < 7) // Size of the ship (three) box
                {
                    if (Coordy2 < 10 && player2Board[Coordx2][Coordy2 + 1] == 0)
                    {
                        player2Board[Coordx2][Coordy2] = 1;
                        player2Board[Coordx2][Coordy2 + 1] = 1;
                        break;
                        // Checking if 2 long ship coordinates are free for ship
                    }
                    else // The ship exceeded the limits
                    {
                        repeat_input = true;
                    }
                }
            }

            if (repeat_input)
            {
                startingCoords2();
                if (i < 7)
                {
                    startingPosition2(); // Is mandatory do this until the last ship.
                }
            }
        }

    for (int p = 0; p < 4; p++) // This is the area around the ship
    {
        {
            if (player2Board[Coordx2 + 1][Coordy2] == 0)
            {
                player2Board[Coordx2 + 1][Coordy2] = 2;
            }

            if (player2Board[Coordx2][Coordy2 + 1] == 0)
            {
                player2Board[Coordx2][Coordy2 + 1] = 2;
            }

            if (player2Board[Coordx2 - 1][Coordy2] == 0)
            {
                player2Board[Coordx2 - 1][Coordy2] = 2;
            }

            if (player2Board[Coordx2][Coordy2 - 1] == 0)
            {
                player2Board[Coordx2][Coordy2 - 1] = 2;
            }

            if (player2Board[Coordx2 + 1][Coordy2 + 1] == 0)
            {
                player2Board[Coordx2 + 1][Coordy2 + 1] = 2;
            }

            if (player2Board[Coordx2 - 1][Coordy2 - 1] == 0)
            {
                player2Board[Coordx2 - 1][Coordy2 - 1] = 2;
            }

            if (player2Board[Coordx2 + 1][Coordy2 - 1] == 0)
            {
                player2Board[Coordx2 + 1][Coordy2 - 1] = 2;
            }

            if (player2Board[Coordx2 - 1][Coordy2 + 1] == 0)
            {
                player2Board[Coordx2 - 1][Coordy2 + 1] = 2;
            }

            if (player2Board[Coordx2 + 1][Coordy2] == 1)
            {
                Coordx2++;
            }

            if (player2Board[Coordx2][Coordy2 + 1] == 1)
            {
                Coordy2++;
            }
        }
    }
}