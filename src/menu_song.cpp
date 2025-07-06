#include <iostream>
using namespace std;
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

int volume = 10; // It define the initial value of the volume

// Volume from 0 to 100
void setVolume(int percentage) {
    DWORD v = (percentage * 0xFFFF) / 100;
    DWORD finalValue = (v & 0xFFFF) | ((v & 0xFFFF) << 16);
    waveOutSetVolume(0, finalValue);
}