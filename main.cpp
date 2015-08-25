#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include <stdio.h>

#include "Render.h"
#include "UserInterface.h"
#include "Intersection.h"
#include "Lane.h"
#include "Road.h"

#include "Button.h"

using namespace std;

int main(int argc, char **argv)
{
	UserInterface* UI = new UserInterface;
	UI->init();
	while (1)
	{
		UI->update();
	}
	
	system("pause");
	return 0;
}
