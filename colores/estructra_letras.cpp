#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h, 12); // Texto rojo claro
    cout << "Este texto es rojo" << endl;

    SetConsoleTextAttribute(h, 7);  // Volver al color normal
    cout << "Este texto es normal" << endl;

    return 0;
}
