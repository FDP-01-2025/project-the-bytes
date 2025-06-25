#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

int playerBoard[playerRows + 1][playerColumns + 1] = {0};
int Coordx = 0, Coordy = 0;
string Coordenate = "";
char position = ' ';

void drawBoard() {
	cout << "                   Player\n            0 1 2 3 4 5 6 7 8 9\n";
	char letter = 'A';

	for (int i = 1; i < playerRows - 1; i++) {
		cout << "          " << letter++ << " ";
		for (int j = 1; j < playerColumns - 1; j++) {
			if (playerBoard[i][j] == 0 || playerBoard[i][j] == 2)
				cout << ". ";
			else if (playerBoard[i][j] == 1)
				cout << "0 ";
		}
		cout << endl;
	}
}

void startingCoords() {
	bool correct_cord;

	do {
		cout << "   Input a coordinates X & Y (Ex.: A5): ";
		cin >> Coordenate;

		Coordx = Coordenate[0] - 64;
		Coordy = Coordenate[1] - 47;

		correct_cord = false;

		if (Coordenate.size() == 2) {
			for (char i = 'A'; i <= 'J'; i++) {
				if (Coordenate[0] == i) {
					correct_cord = true;
					break;
				}
			}

			if (!(isdigit(Coordenate[1]))) {
				correct_cord = false;
			}
		}
	} while (!(correct_cord));
}

void startingPosition() {
	do {
		cout << "   Enter position H/V: ";
		cin >> position;

		if ((position == 'V') || (position == 'v') || (position == 'h') || (position == 'H')) {
			break;
		} else {
			cout << "Please write a valid coords" << endl;
		}
	} while (true);
}

void newCordsplayer(int i) {
	bool repeat_input = false;

	while (true) {
		if (playerBoard[Coordx][Coordy] == 0) {
			if (i > 6)
				playerBoard[Coordx][Coordy] = 1;
			break;
		} else {
			startingCoords();
			if (i < 7)
				startingPosition();
		}
	}

	if (i < 7)
		while (true) {
			if (position == 'V') {
				if (i == 1) {
					if (Coordx < 8 && playerBoard[Coordx + 1][Coordy] == 0 && playerBoard[Coordx + 2][Coordy] == 0 && playerBoard[Coordx + 3][Coordy] == 0) {
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx + 1][Coordy] = 1;
						playerBoard[Coordx + 2][Coordy] = 1;
						playerBoard[Coordx + 3][Coordy] = 1;
						break;
					} else repeat_input = true;
				}
				else if (i >= 2 && i < 4) {
					if (Coordx < 9 && playerBoard[Coordx + 1][Coordy] == 0 && playerBoard[Coordx + 2][Coordy] == 0) {
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx + 1][Coordy] = 1;
						playerBoard[Coordx + 2][Coordy] = 1;
						break;
					} else repeat_input = true;
				}
				else if (i > 3 && i < 7) {
					if (Coordx < 10 && playerBoard[Coordx + 1][Coordy] == 0) {
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx + 1][Coordy] = 1;
						break;
					} else repeat_input = true;
				}
			}
			else if (position == 'H') {
				if (i == 1) {
					if (Coordy < 8 && playerBoard[Coordx][Coordy + 1] == 0 && playerBoard[Coordx][Coordy + 2] == 0 && playerBoard[Coordx][Coordy + 3] == 0) {
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx][Coordy + 1] = 1;
						playerBoard[Coordx][Coordy + 2] = 1;
						playerBoard[Coordx][Coordy + 3] = 1;
						break;
					} else repeat_input = true;
				}
				else if (i >= 2 && i < 4) {
					if (Coordy < 9 && playerBoard[Coordx][Coordy + 1] == 0 && playerBoard[Coordx][Coordy + 2] == 0) {
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx][Coordy + 1] = 1;
						playerBoard[Coordx][Coordy + 2] = 1;
						break;
					} else repeat_input = true;
				}
				else if (i > 3 && i < 7) {
					if (Coordy < 10 && playerBoard[Coordx][Coordy + 1] == 0) {
						playerBoard[Coordx][Coordy] = 1;
						playerBoard[Coordx][Coordy + 1] = 1;
						break;
					} else repeat_input = true;
				}
			}

			if (repeat_input) {
				startingCoords();
				if (i < 7)
					startingPosition();
			}
		}

	for (int p = 0; p < 4; p++) {
		if (playerBoard[Coordx + 1][Coordy] == 0)
			playerBoard[Coordx + 1][Coordy] = 2;
		if (playerBoard[Coordx][Coordy + 1] == 0)
			playerBoard[Coordx][Coordy + 1] = 2;
		if (playerBoard[Coordx - 1][Coordy] == 0)
			playerBoard[Coordx - 1][Coordy] = 2;
		if (playerBoard[Coordx][Coordy - 1] == 0)
			playerBoard[Coordx][Coordy - 1] = 2;
		if (playerBoard[Coordx + 1][Coordy + 1] == 0)
			playerBoard[Coordx + 1][Coordy + 1] = 2;
		if (playerBoard[Coordx - 1][Coordy - 1] == 0)
			playerBoard[Coordx - 1][Coordy - 1] = 2;
		if (playerBoard[Coordx + 1][Coordy - 1] == 0)
			playerBoard[Coordx + 1][Coordy - 1] = 2;
		if (playerBoard[Coordx - 1][Coordy + 1] == 0)
			playerBoard[Coordx - 1][Coordy + 1] = 2;

		if (playerBoard[Coordx + 1][Coordy] == 1)
			Coordx++;
		if (playerBoard[Coordx][Coordy + 1] == 1)
			Coordy++;
	}
}
