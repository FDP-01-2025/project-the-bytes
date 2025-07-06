#include <windows.h>
#include <iostream>
using namespace std;
void playExplosionSound() {
    
    if (!PlaySound(TEXT("waterShot.wav"), NULL, SND_FILENAME | SND_SYNC)) {
        // NULL: indicates that we are not using embedded resources, but rather an external file
        // SND_FILENAME: the first parameter is the name of the file
        // SND_SYNC: waits for the sound to finish before continuing
        cout << "Error playing the sound." << endl;
    }
}
