#ifndef __Computer__
#define __Computer__

using namespace std;

const int Filas = 12;
const int Columns = 12;
extern int gameBoard[Filas + 1][Columns + 1]; // Se usara para el tablero mas adelante

class Computer
{
private:
	int coordenateX, coordenateY;
	int posicion;
	char pos;

public:
	Computer();
	void Update_Coord(int i);
};

#endif // !__Computer__