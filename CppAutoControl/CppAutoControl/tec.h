#pragma once
#include <string>
#include <unordered_map>
#include <windows.h>
#include <ctime>

class Tec
{
public:
	void press(BYTE key, int numPress, int delay);
	void write(std::string words);
	void hotkey(BYTE key, BYTE key2);
	std::unordered_map<std::string, BYTE> keyMap;
	BYTE mapKey(const std::string& key);

};