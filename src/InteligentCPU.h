#ifndef __InteligentCPU__
#define __InteligentCPU__

using namespace std;

const int rowsCPU = 12;
const int columnsCPU = 12;
extern int boardCPU[rowsCPU + 1][columnsCPU + 1]; // Se usara para el tablero mas adelante

class CPU
{
private:
	int posicion;
	int coordenateX, coordenateY;
	char posCPU;
	// There are variables that we use into the cpp document

public:
	CPU();						  // Function to randomize the coords and position of the ships of the CPU
	void coordenateUpdate(int i); // Function to put the ship into the board.

	// We declare functions to use later into the cpp document
};

#endif 