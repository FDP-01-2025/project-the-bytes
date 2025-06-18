#include "Player.h"
#include <iostream>
#include <String>

using namespace std;

int Board[rowsPlayer + 1][columnsPlayer + 1] = { 0 };

Player::Player()
{
	Coordenate = "";
	playerPos = ' ';
	CoordsX = 0;
	CoordsY = 0;
}
Player::Player(int a, int b, string c, char d)
{
	CoordsX = a;
	CoordsY = b;
	Coordenate = c;
	playerPos = d;
}
Player::~Player() {} //Destructor

void Player::Drawboard()
{
	cout << "                   Player\n            0 1 2 3 4 5 6 7 8 9\n";
	char letter = 'A';

	for (int i = 1; i < rowsPlayer- 1; i++) {
		cout << "          " << letter++ << " ";
		for (int j = 1; j < columnsPlayer - 1; j++) {

			if (playerBoard[i][j] == 0 || playerBoard[i][j] == 2) // 0 for free Coordinate; 2 for Ship sides
				cout << ". ";
			else if (playerBoard[i][j] == 1) // 1 for SHIP
				cout << "0 ";
		}
		cout << endl;
	}
}
void Player::startingCoords()
{
	bool trueCord;

	do {
		cout << "   Input a coordinates X & Y (Ex.: A5): ";
		cin >> Coordenate;

		//Assci Table
		CoordsX = Coordenate[0] - 64; // Char Letter to our needed number 
		CoordsY = Coordenate[1] - 47; // Char number to our needed number

		// Checking if input is correct
		trueCord = false;

		if (Coordenate.size() == 2) { // Correct number of symbols - 2
			for (char i = 'A'; i <= 'J'; i++) {
				if (Coordenate[0] == i) { //Checking if FIRST entered symbol is equal to a letter coordinate
					trueCord = true;
					break;
				}
			}

			if (!(isdigit(Coordenate[1]))) { //Checking if SECOND entered symbol is a digit
				trueCord = false; // It will be false if symbol isn't a digit
			}
		}
	} while (!(trueCord));
}
void Player::startirgPos()
{
	do {
		cout << "   Enter position H/V: ";
		cin >> playerPos;

		if ((playerPos == 'V') || (playerPos == 'H')) break;
	} while (true);
}
void Player::updatedCoords(int i)
{
	bool repeat_input = false;
	
	while (true) {
		if (Board[x][y] == 0) { // checking if first coordinate is free for ship

			if (i > 6)  Board[x][y] = 1; // It puts 1 size ships here
			break;
		}
		else { //Else for ship coordinates collision
			Input_Coord();
			if (i < 7) Input_Pos(); // Position is needed UNTIL 7th ship
		}
	}

	if (i < 7)
		while (true) { // It will stop if it's okay to put ship into board
			if (pos == 'V') { // VERTICAL POSITION **************************************************************
				if (i == 1) {
					if (x  < 8) { // Ship wouldn't pass a bottom border
						if (Board[x+1][y] == 0 && Board[x+2][y] == 0 && Board[x+3][y] == 0) { //Checking if 4 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x+1][y] = 1;
							Board[x+2][y] = 1;
							Board[x+3][y] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else {//ship passes a border
						repeat_input = true;
					}
				}
				else if (i >= 2 && i < 4) {
					if (x < 9) { // Ship wouldn't pass a bottom border
						if (Board[x+1][y] == 0 && Board[x+2][y] == 0) { //Checking if 3 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x+1][y] = 1;
							Board[x+2][y] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else {
						repeat_input = true;
					}
				}
				else if (i > 3 && i < 7) {
					if (x < 10) { // Ship wouldn't pass a bottom border
						if (Board[x+1][y] == 0) { //Checking if 2 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x+1][y] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else {
						repeat_input = true;
					}
				}
			}
			else if (pos == 'H') { // HORIZONTAL POSITION **************************************************************
				if (i == 1) {
					if (y < 8) { // Ship wouldn't pass a RIGHT border
						if (Board[x][y+1] == 0 && Board[x][y+2] == 0 && Board[x][y+3] == 0) { //Checking if 4 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x][y+1] = 1;
							Board[x][y+2] = 1;
							Board[x][y+3] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else { //ship passes a border
						repeat_input = true;
					}
				}
				else if (i >= 2 && i < 4) {
					if (y < 9) { // Ship wouldn't pass a RIGHT border
						if (Board[x][y+1] == 0 && Board[x][y+2] == 0) { //Checking if 3 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x][y+1] = 1;
							Board[x][y+2] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else {
						repeat_input = true;
					}
				}
				else if (i > 3 && i < 7) {
					if (y < 10) { // Ship wouldn't pass a RIGHT border
						if (Board[x][y+1] == 0) { //Checking if 2 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x][y+1] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else {
						repeat_input = true;
					}
				}
			}

			if (repeat_input) {
				Input_Coord();
				if (i < 7) Input_Pos(); // Position is needed UNTIL 7th ship
			}
		}
	// Area around the ship
	for (int p = 0; p < 4; p++) {

		if (Board[x + 1][y] == 0) Board[x + 1][y] = 2;
		if (Board[x][y + 1] == 0) Board[x][y + 1] = 2;
		if (Board[x - 1][y] == 0) Board[x - 1][y] = 2;
		if (Board[x][y - 1] == 0) Board[x][y - 1] = 2;
		if (Board[x + 1][y + 1] == 0) Board[x + 1][y + 1] = 2;
		if (Board[x - 1][y - 1] == 0) Board[x - 1][y - 1] = 2;
		if (Board[x + 1][y - 1] == 0) Board[x + 1][y - 1] = 2;
		if (Board[x - 1][y + 1] == 0) Board[x - 1][y + 1] = 2;

		if (Board[x + 1][y] == 1) x++;
		if (Board[x][y + 1] == 1) y++;
	}
}