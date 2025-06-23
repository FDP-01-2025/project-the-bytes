

// ScoreManager.cpp
#include <iostream>
#include <fstream>
using namespace std;

// Variables globales para contar las partidas ganadas y perdidas
int wins = 0;
int losses = 0;

void updateScore(bool playerWon) {
    if (playerWon) {
        wins++;
    } else {
        losses++;
    }

    // Guardar los resultados en un archivo
    ofstream scoreFile("score.txt");
    if (scoreFile.is_open()) {
        scoreFile << "Partidas ganadas por el jugador: " << wins << endl;
        scoreFile << "Partidas ganadas por la computadora: " << losses << endl;
        scoreFile.close();
    } else {
        cerr << "Error al abrir el archivo de puntuaciones." << endl;
    }

    // Mostrar el resultado actual
    cout << "Partidas ganadas por el jugador: " << wins << endl;
    cout << "Partidas ganadas por la computadora: " << losses << endl;
}
