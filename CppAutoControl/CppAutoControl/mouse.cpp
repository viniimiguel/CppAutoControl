#include "mouse.h"
#include <Windows.h>

std::pair<int, int> Mal::mGetPosition()
{
	POINT cursorPoint;
	if (GetCursorPos(&cursorPoint))
	{
		int x = cursorPoint.x;
		int y = cursorPoint.y;
		return std::make_pair(x, y);
	}
}

void Mal::mClick(std::string typeOfClick, int numClicks, int delay)
{
	for (int i = 0; i < numClicks; i++)
	{
		if (typeOfClick == "left")
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		if (typeOfClick == "right")
		{
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			Sleep(delay);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		}
	}
}

void Mal::mDragTo(int fx, int fy, int duration)
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	POINT currentPos;
	GetCursorPos(&currentPos);

	int start_x = currentPos.x;
	int start_y = currentPos.y;

	const int numSteps = 100;

	double stepX = static_cast<double>(fx - start_x) / numSteps;
	double stepY = static_cast<double>(fy - start_y) / numSteps;

	for (int i = 1; i <= numSteps; i++)
	{
		int currentX = static_cast<int>(start_x + i * stepX);
		int currentY = static_cast<int>(start_y + i * stepY);
		SetCursorPos(currentX, currentY);
		Sleep(duration / numSteps);
	}
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}

void Mal::mMoveTo(int x, int y, int duration)
{
	POINT currentPos;
	GetCursorPos(&currentPos);

	int start_x = currentPos.x;
	int start_y = currentPos.y;

	const int numSteps = 100;
	double stepX = static_cast<double>(x - start_x) / numSteps;
	double stepY = static_cast<double>(y - start_y) / numSteps;

	for (int i = 1; i <= numSteps; i++)
	{
		int currentX = static_cast<int>(start_x + i * stepX);
		int currentY = static_cast<int>(start_y + i * stepY);
		SetCursorPos(currentX, currentY);
		Sleep(duration / numSteps);

	}
	SetCursorPos(x, y);
}






