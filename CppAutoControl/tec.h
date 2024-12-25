#pragma once
#include <string>
#include <windows.h>
class Tec
{
public:
	void press(BYTE key, int numPress, int delay);
	void write(std::string words);
	void hotkey(BYTE key, BYTE key2);

};