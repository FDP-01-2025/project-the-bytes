#ifndef __InteligentCPU__
#define __InteligentCPU__

using namespace std;

const int Rows = 12;
const int Columns = 12;
extern int gameBoard[Rows + 1][Columns + 1]; // Se usara para el tablero mas adelante

class CPU
{
private:
	int posicion;
	int coordenateX, coordenateY;
	char pos;
	// There are variables that we use into the cpp document

public:
	CPU();						  // Function to randomize the coords and position of the ships of the CPU
	void coordenateUpdate(int i); // Function to put the ship into the board.

	// We declare functions to use later into the cpp document
};

#endif // __InteligentCPU__