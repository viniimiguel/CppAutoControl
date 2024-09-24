#include "tec.h"


std::unordered_map<std::string, BYTE> keyMap = {

    {"F1", VK_F1}, {"F2", VK_F2}, {"F3", VK_F3}, {"F4", VK_F4},
    {"F5", VK_F5}, {"F6", VK_F6}, {"F7", VK_F7}, {"F8", VK_F8},
    {"F9", VK_F9}, {"F10", VK_F10}, {"F11", VK_F11}, {"F12", VK_F12},


    {"A", 'A'}, {"B", 'B'}, {"C", 'C'}, {"D", 'D'}, {"E", 'E'}, {"F", 'F'}, {"G", 'G'},
    {"H", 'H'}, {"I", 'I'}, {"J", 'J'}, {"K", 'K'}, {"L", 'L'}, {"M", 'M'}, {"N", 'N'},
    {"O", 'O'}, {"P", 'P'}, {"Q", 'Q'}, {"R", 'R'}, {"S", 'S'}, {"T", 'T'}, {"U", 'U'},
    {"V", 'V'}, {"W", 'W'}, {"X", 'X'}, {"Y", 'Y'}, {"Z", 'Z'},


    {"a", 'A'}, {"b", 'B'}, {"c", 'C'}, {"d", 'D'}, {"e", 'E'}, {"f", 'F'}, {"g", 'G'},
    {"h", 'H'}, {"i", 'I'}, {"j", 'J'}, {"k", 'K'}, {"l", 'L'}, {"m", 'M'}, {"n", 'N'},
    {"o", 'O'}, {"p", 'P'}, {"q", 'Q'}, {"r", 'R'}, {"s", 'S'}, {"t", 'T'}, {"u", 'U'},
    {"v", 'V'}, {"w", 'W'}, {"x", 'X'}, {"y", 'Y'}, {"z", 'Z'},


    {"1", '1'}, {"2", '2'}, {"3", '3'}, {"4", '4'}, {"5", '5'},
    {"6", '6'}, {"7", '7'}, {"8", '8'}, {"9", '9'}, {"0", '0'},


    {"ESC", VK_ESCAPE}, {"SPACE", VK_SPACE}, {"ENTER", VK_RETURN},
    {"UP", VK_UP}, {"DOWN", VK_DOWN}, {"LEFT", VK_LEFT}, {"RIGHT", VK_RIGHT},
    {"SHIFT", VK_SHIFT}, {"CTRL", VK_CONTROL}, {"ALT", VK_MENU},
    {"TAB", VK_TAB}, {"CAPS", VK_CAPITAL}, {"BACKSPACE", VK_BACK}, {"DELETE", VK_DELETE}
};


BYTE mapKey(const std::string& key) {
    auto it = keyMap.find(key);
    if (it != keyMap.end()) {
        return it->second;
    }
    else {
        return 0;
    }
}

void Tec::hotkey(BYTE key, BYTE key2)
{

}
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

}

