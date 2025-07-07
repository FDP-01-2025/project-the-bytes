#include <iostream>
using namespace std;
#include <windows.h>
#include <mmsystem.h>
#include "menu_song.h"
#pragma comment(lib, "winmm.lib")

int volume = 10; // It define the initial value of the volume

// Volume from 0 to 100
void setVolume(int percentage) {
    DWORD v = (percentage * 0xFFFF) / 100;
    DWORD finalValue = (v & 0xFFFF) | ((v & 0xFFFF) << 16);
    waveOutSetVolume(0, finalValue);
}

// Starts the music in the background in a loop
void playMusic() {
    PlaySound(TEXT("src/pirates_music.wav"), NULL, SND_ASYNC | SND_LOOP);

}

// Stop the music completely
void stopMusic() {
    PlaySound(NULL, 0, 0);
}

// Volume settings menu
void soundOptions() {
    int soundOption;
    bool exitMenu = false;

    while (!exitMenu) {
        // Options
        cout << "|======Sound Options======|" << endl;
        cout << "Current volume: " << volume << "%\n\n";
        cout << "1. Increase volume (+10%)" << endl;
        cout << "2. Decrease volume (-10%)" << endl;
        cout << "3. Mute music" << endl;
        cout << "4. Resume music" << endl;
        cout << "5. Return to main menu" << endl;
        cout << "Select an option: ";
        cin >> soundOption;

        switch (soundOption) {
            case 1:
                system("cls");
                if (volume < 100) volume += 10; // Increase the volume
                setVolume(volume); // The new volume is applied
                break;
            case 2:
                system("cls");
                if (volume > 0) volume -= 10; // Decrease the volume
                setVolume(volume); // The new volume is applied
                break;
            case 3:
                system("cls");
                stopMusic(); // Stop the music
                break;
            case 4:
                system("cls");
                playMusic(); // Resume music
                setVolume(volume); // The sound returns
                break;
            case 5:
                system("cls");
                exitMenu = true;
                break;
            default:
                cout << "Invalid option." << endl; // If user types any other option
                Sleep(1000); // Pause for 1 second
        }
    }
}