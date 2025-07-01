
#include <iostream>
#include <fstream>
#include "scoreManager.h"

using namespace std;

int main()
{
    updateScore();
}

void updateScore()
{
    bool playerWon = true;
    int wins = 0;
    int losses = 0;
    if (playerWon)
    {
        wins++;
    }
    else
    {
        losses++;
    }

    ofstream scoreFile("score.txt");
    if (scoreFile.is_open())
    {
        scoreFile << "Partidas ganadas por el jugador: " << wins << endl;
        scoreFile << "Partidas ganadas por la computadora: " << losses << endl;
        scoreFile.close();
    }
    else
    {
        cerr << "Error al abrir el archivo de puntuaciones." << endl;
    }

    cout << "Partidas ganadas por el jugador: " << wins << endl;
    cout << "Partidas ganadas por la computadora: " << losses << endl;
}
