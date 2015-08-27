#include <iostream>
#include <cstdlib>

#include "UserInterface.h"

using namespace std;

int main(int argc, char **argv)
{
	UserInterface* UI = new UserInterface;
	UI->init();
	while (true)
	{
		UI->update();
	}
	
	system("pause");
	return 0;
}
