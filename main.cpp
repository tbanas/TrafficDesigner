#include <iostream>
#include <cstdlib>
#include "Render.h"
#include "UserInterface.h"
#include "Intersection.h"
#include "Lane.h"
#include "Road.h"

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
