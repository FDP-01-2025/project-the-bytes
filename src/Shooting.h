#include <string>
#ifndef __Shooting__
#define __Shooting__

using namespace std;

extern int Count_Player;
extern int Count_Computer;

class Shooting
{
private:
	int x, y;
	string Cord;

public:
	Shooting();
	Shooting(int a, int b, string c);


	void startCoord();
	void drawshoot();
	void updateBoardCPU();
	void updateBoardplayer();
};

#endif