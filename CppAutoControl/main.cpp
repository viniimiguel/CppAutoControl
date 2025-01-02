#include <iostream>
#include "tec.h"

int main()
{
	Tec* t1 = new Tec();
	Sleep(2000);
	t1->write("ola mundo");
	delete t1;
	return 0;
}