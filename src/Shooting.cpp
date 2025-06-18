#include "Shooting.h"
#include "Player.h"
#include "InteligentCPU.h"
#include <iostream>
#include <string>
#include <ctime> // time for random
#include <vector>

using namespace std;

int Count_Player = 0;
int Count_Computer = 0;

vector<int> positions; // vector for smart shooting

Shooting::Shooting()
{
    Cord = "";
    x = 0;
    y = 0;
}
Shooting::Shooting(int a, int b, string c)
{
    x = a;
    y = b;
    Cord = c;
}
Shooting::~Shooting() {}

void Shooting::Input_Coord()
{
    bool correct_cord;

    do
    {
        cout << "   Input a coordinates X & Y to shoot (Ex.: A5): ";
        cin >> Cord;

        // Assci Table
        x = Cord[0] - 64; // Char Letter to our needed number
        y = Cord[1] - 47; // Char number to our needed number

        // Checking if input is correct
        correct_cord = false;

        if (Cord.size() == 2)
        { // Correct number of symbols - 2
            for (char i = 'A'; i <= 'J'; i++)
            {
                if (Cord[0] == i)
                { // Checking if FIRST entered symbol is equal to a letter coordinate
                    correct_cord = true;
                    break;
                }
            }

            if (!(isdigit(Cord[1])))
            {                         // Checking if SECOND entered symbol is a digit
                correct_cord = false; // It will be false if symbol isn't a digit
            }
        }
    } while (!(correct_cord));
}
void Shooting::Draw_Shooting()
{
    cout << "                   Player                         Computer\n            0 1 2 3 4 5 6 7 8 9             0 1 2 3 4 5 6 7 8 9\n";
    char letter = 'A';

    for (int i = 1; i < rowsPlayer - 1; i++)
    { // Player

        cout << "          " << letter << " ";
        for (int j = 1; j < columnsPlayer - 1; j++)
        {
            if (playerBoard[i][j] == 0 || playerBoard[i][j] == 2) // 0 for free Coordinate; 2 for Ship sides
                cout << ". ";
            else if (playerBoard[i][j] == 3)
                cout << "X ";
            else if (playerBoard[i][j] == 4)
                cout << "* ";
            else if (playerBoard[i][j] == 1) // 1 for SHIP
                cout << "0 ";
        }
        // COMPUTER
        cout << "          " << letter++ << " ";
        for (int j = 1; j < columnsPlayer - 1; j++)
        {
            if (boardCPU[i][j] == 2 || boardCPU[i][j] == 1 || boardCPU[i][j] == 0) // 0 - EMPTY PLACE; 1 - SHIP; 2 - SHIP SIDES;
                cout << ". ";
            else if (boardCPU[i][j] == 3) // HITTED SHIP
                cout << "X ";
            else if (boardCPU[i][j] == 4) // UNHITTED SHIP
                cout << "* ";
        }
        cout << endl;
    }
}
void Shooting::Update_Player_Grid()
{

    srand((unsigned int)time(NULL)); // random time to generate random number EVERYTIME

    if (!positions.empty())
    {
        x = positions.front();
        positions.erase(positions.begin());
        y = positions.front();
        positions.erase(positions.begin());
    }
    else
    {
        x = 1 + (rand() % 10);
        y = 1 + (rand() % 10);
    }

    while (true)
    {
        if (playerBoard[x][y] != 3 && playerBoard[x][y] != 4)
        { // checking if first coordinate is free for ship
            if (playerBoard[x][y] == 1)
            {
                playerBoard[x][y] = 3; // 3 if hit
                cout << "   CPU HIT!\n";
                Count_Computer++;

                //////////////////////////////////////////////////////////////////////////////// smart shooting
                if (positions.empty())
                {
                    if (y - 1 >= 1)
                    { // GOES TO LEFT
                        if (playerBoard[x][y - 1] == 2 || playerBoard[x][y - 1] == 0)
                        { // Water or Ship sides
                            positions.push_back(x);
                            positions.push_back(y - 1);
                        }
                        else if (playerBoard[x][y - 1] == 1)
                        { // hit ship once more
                            positions.push_back(x);
                            positions.push_back(y - 1);

                            if (y - 2 >= 1)
                            {
                                if (playerBoard[x][y - 2] == 2 || playerBoard[x][y - 2] == 0)
                                { // Water or Ship sides
                                    positions.push_back(x);
                                    positions.push_back(y - 2);
                                }
                                else if (playerBoard[x][y - 2] == 1)
                                { // hit ship once more
                                    positions.push_back(x);
                                    positions.push_back(y - 2);

                                    if (y - 3 >= 1)
                                    {
                                        if (playerBoard[x][y - 3] == 2 || playerBoard[x][y - 3] == 0)
                                        { // Water or Ship sides
                                            positions.push_back(x);
                                            positions.push_back(y - 3);
                                        }
                                        else if (playerBoard[x][y - 3] == 1)
                                        { // hit ship once more
                                            positions.push_back(x);
                                            positions.push_back(y - 3);
                                        }
                                    }
                                }
                            }
                            // break;
                        }
                    } // add y & x
                    if (y + 1 <= 10)
                    { // GOES TO RIGHT
                        if (playerBoard[x][y + 1] == 2 || playerBoard[x][y + 1] == 0)
                        { // Water or Ship sides
                            positions.push_back(x);
                            positions.push_back(y + 1);
                        }
                        else if (playerBoard[x][y + 1] == 1)
                        { // hit ship once more
                            positions.push_back(x);
                            positions.push_back(y + 1);

                            if (y + 2 <= 10)
                            {
                                if (playerBoard[x][y + 2] == 2 || playerBoard[x][y + 2] == 0)
                                { // Water or Ship sides
                                    positions.push_back(x);
                                    positions.push_back(y + 2);
                                }
                                else if (playerBoard[x][y + 2] == 1)
                                { // hit ship once more
                                    positions.push_back(x);
                                    positions.push_back(y + 2);

                                    if (y + 3 <= 10)
                                    {
                                        if (playerBoard[x][y + 3] == 2 || playerBoard[x][y + 3] == 0)
                                        { // Water or Ship sides
                                            positions.push_back(x);
                                            positions.push_back(y + 3);
                                        }
                                        else if (playerBoard[x][y + 3] == 1)
                                        { // hit ship once more
                                            positions.push_back(x);
                                            positions.push_back(y + 3);
                                        }
                                    }
                                }
                            }
                            // break;
                        }
                    } // add y & x
                    if (x - 1 >= 1)
                    { // GOES UP
                        if (playerBoard[x - 1][y] == 2 || playerBoard[x - 1][y] == 0)
                        { // Water or Ship sides
                            positions.push_back(x - 1);
                            positions.push_back(y);
                        }
                        else if (playerBoard[x - 1][y] == 1)
                        { // hit ship once more
                            positions.push_back(x - 1);
                            positions.push_back(y);

                            if (x - 2 >= 1)
                            {
                                if (playerBoard[x - 2][y] == 2 || playerBoard[x - 2][y] == 0)
                                { // Water or Ship sides
                                    positions.push_back(x - 2);
                                    positions.push_back(y);
                                }
                                else if (playerBoard[x - 2][y] == 1)
                                { // hit ship once more
                                    positions.push_back(x - 2);
                                    positions.push_back(y);

                                    if (x - 3 >= 1)
                                    {
                                        if (playerBoard[x - 3][y] == 2 || playerBoard[x - 3][y] == 0)
                                        { // Water or Ship sides
                                            positions.push_back(x - 3);
                                            positions.push_back(y);
                                        }
                                        else if (playerBoard[x - 3][y] == 1)
                                        { // hit ship once more
                                            positions.push_back(x - 3);
                                            positions.push_back(y);
                                        }
                                    }
                                }
                            }
                            // break;
                        }
                    } // add x & y
                    if (x + 1 <= 9)
                    { // GOES DOWN
                        if (playerBoard[x + 1][y] == 2 || playerBoard[x + 1][y] == 0)
                        { // Water or Ship sides
                            positions.push_back(x + 1);
                            positions.push_back(y);
                        }
                        else if (playerBoard[x + 1][y] == 1)
                        { // hit ship once more
                            positions.push_back(x + 1);
                            positions.push_back(y);

                            if (x + 2 <= 9)
                            {
                                if (playerBoard[x + 2][y] == 2 || playerBoard[x + 2][y] == 0)
                                { // Water or Ship sides
                                    positions.push_back(x + 2);
                                    positions.push_back(y);
                                }
                                else if (playerBoard[x + 2][y] == 1)
                                { // hit ship once more
                                    positions.push_back(x + 2);
                                    positions.push_back(y);

                                    if (x + 3 <= 9)
                                    {
                                        if (playerBoard[x + 3][y] == 2 || playerBoard[x + 3][y] == 0)
                                        { // Water or Ship sides
                                            positions.push_back(x + 3);
                                            positions.push_back(y);
                                        }
                                        else if (playerBoard[x + 3][y] == 1)
                                        { // hit ship once more
                                            positions.push_back(x + 3);
                                            positions.push_back(y);
                                        }
                                    }
                                }
                            }
                            // break;
                        }
                    } // add x & y
                }
                //////////////////////////////////////////////////////////////////////////////////
            }
            else if (playerBoard[x][y] == 2 || playerBoard[x][y] == 0)
                playerBoard[x][y] = 4; // 4 if missed
            break;
        }
        else
        {                                    // Else for ship coordinates collision
            srand((unsigned int)time(NULL)); // random time to generate random number EVERYTIME

            x = 1 + (rand() % 10);
            y = 1 + (rand() % 10);
        }
    }
    cout << "   --------------------\n   Computer shoots: " << char(x + 64) << y - 1 << endl;
    /*
    cout << "PATAIKYTA: " << x << " " << y << endl;
    for (auto i : positions) {
        cout << i << " ";
    }
    cout << endl;*/
}
void Shooting::Update_Computer_Grid()
{
    while (true)
    {
        if (boardCPU[x][y] != 3 && boardCPU[x][y] != 4)
        {
            if (boardCPU[x][y] == 1)
            {
                boardCPU[x][y] = 3; // 3 if hit
                cout << "   Player HIT!\n";
                Count_Player++;
            }
            else if (boardCPU[x][y] == 2 || boardCPU[x][y] == 0)
                boardCPU[x][y] = 4; // 4 if missed
            break;
        }
        else
            Input_Coord();
    }
}