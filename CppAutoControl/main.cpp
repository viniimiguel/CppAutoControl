#include <iostream>
#include "AutoControl.h"

int main()
{
	AutoControl::Mouse mouse;
	int x = 0, y = 0;
	mouse.GetMousePosition(x, y);

	std::cout << x << "," << y << std::endl;
	return 0;
}