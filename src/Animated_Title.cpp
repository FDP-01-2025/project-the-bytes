#include <iostream>
#include <windows.h> // To use Sleep and manipulate the terminal
#include "Animated_Title.h"
using namespace std;

int getconsoleheight() // This is a function to get the height of the console
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int rows = 25; // Default value
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; // The size of the console modified
    }
    return rows;
}

void showAnimatedTitle() // Function to display the title with vertical animation
{
    string titulo = R"(

  ____        _   _   _           _____ _     _       
 |  _ \      | | | | | |         / ____| |   (_)      
 | |_) | __ _| |_| |_| | ___    | (___ | |__  _ _ __        __/___
 |  _ < / _` | __| __| |/ _ \    \___ \| '_ \| | '_ \    __/_____/____|  
 | |_) | (_| | |_| |_| |  __/    ____) | | | | | |_) |   \           \
 |____/ \__,_|\__|\__|_|\___|   |_____/|_| |_|_| .__/    ~~~~~~~~~~~~~~~
                                               | |    
                                               |_|    
)";

    int consoleHeight = getconsoleheight();
    int titleLines = 9; // Number of the lines that has the title
    int spaceAbove = (consoleHeight - titleLines) / 2;

    for (int i = 0; i < spaceAbove; ++i)
    {
        cout << endl;
        Sleep(3000 / spaceAbove); // Animated efect of three seconds
    }

    cout << titulo;
}