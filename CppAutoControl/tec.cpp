#include "tec.h"

void Tec::hotkey(BYTE key, BYTE key2)
{

}

#include <cstdlib>
#include <ctime>

#include <Windows.h>

void Tec::press(BYTE key, int numPress, int delay)
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = MapVirtualKey(key, MAPVK_VK_TO_VSC);
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    srand(static_cast<unsigned>(time(0)));

    for (int i = 0; i < numPress; i++)
    {
        ip.ki.wVk = key;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(delay + rand() % 20);
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(delay + rand() % 20);
    }
}



void Tec::write(std::string words)
{
    for (int i = 0; i < words.size(); i++)
    {
    	INPUT ip;

    }

}

