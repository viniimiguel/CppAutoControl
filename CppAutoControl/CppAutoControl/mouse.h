#pragma once
#include <utility>
#include <string>
class Mal
{
public:
	int x;
	int y;
	std::pair<int, int> mGetPosition();
	void mClick(std::string typeOfClicks, int numberOfClicks, int delay);
	void mMoveTo(int fx, int fy, int duration);
	void mDragTo(int x, int y, int duration);

};