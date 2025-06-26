#include <iostream>
#include <string>
#include <stdlib.h>
#include "windows.h"
#include "Animated_Title.h"
#include "Menu.h"

using namespace std;

int main()
{
    system("cls");       // Clean the terminal
    showAnimatedTitle(); // Shows the animated title
    Menu();              // Call the function menu
    return 0;
}
