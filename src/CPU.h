#ifndef __Computer__
#define __Computer__

const int computerRows = 12;
const int computerColumns = 12;
extern int computerBoard[computerRows + 1][computerColumns + 1]; // We use that for the board later

void initComputer();
void updatedComputerCords(int i);

#endif 
