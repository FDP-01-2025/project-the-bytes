#ifndef __Computer__
#define __Computer__

using namespace std;

const int computerRows = 12;
const int computerColumns = 12;
extern int computerBoard[computerRows + 1][computerColumns + 1]; // Se usara para el tablero mas adelante

class Computer
{
private:
	int computerX, computerY;
	int computerCoordenate;
	char computerPosition;

public:
	Computer();
	void updatedComputerCords(int i);
};

#endif // !__Computer__