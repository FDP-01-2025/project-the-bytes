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

public:
	CPU();
	void Update_Coord(int i);
};

#endif // __InteligentCPU__