#include <iostream>
#include <string>
#include <stdlib.h>
#include "windows.h"
#include "./src/Animated_Title.cpp"
#include "./src/Menu.cpp"
#include "./src/CPU.cpp"
#include "./src/Player.cpp"
#include "./src/Player2.cpp"
#include "./src/Shooting.cpp"
#include "./src/Shooting2.cpp"
#include "./src/Sign_up.cpp"
#include "./src/menu_song.cpp"
#include "./src/explosion.cpp"
using namespace std;

int main()
{
    system("cls");       // Clean the terminal
    showAnimatedTitle(); // Shows the animated title
    Menu();              // Call the function menu
    return 0;
}