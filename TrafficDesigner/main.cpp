#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include <allegro5\allegro.h>
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
	/*srand(time(NULL));
	Intersection* exI = new Intersection;
	cout << "Intersection: " << endl << endl;
	
	for (int i = 0; i < 4; i++)
	{
		cout << "   Road " << i + 1 << endl;
		exI->addRoad(i, new Road);
		int s = 6; // rand() % 6 + 1;

		for (int j=0; j < s; j++)
		{
			exI->getRoads()[i].addLane(j, j % 2 == 0, new Lane);
			cout << "      " << exI->getRoads()[i].getLanes()[j].getId();
			if (exI->getRoads()[i].getLanes()[j].isEntry())
			{
				cout << " Entry Lane" << endl;
			}
			else
			{
				cout << " Departure Lane" << endl;
			}
		}
		cout << endl;
	}

	exI->addConnection(exI->getRoads()[1].getLanes()[0], exI->getRoads()[2].getLanes()[1]);
	exI->addConnection(exI->getRoads()[1].getLanes()[2], exI->getRoads()[2].getLanes()[3]);
	exI->addConnection(exI->getRoads()[1].getLanes()[4], exI->getRoads()[2].getLanes()[5]);

	if (exI->isConnected(exI->getRoads()[1].getLanes()[2], exI->getRoads()[2].getLanes()[3]))
		cout << "2 is connected to 3" << endl;
	*/
	UserInterface* UI = new UserInterface;
	UI->init();
	while (1)
	{
		UI->update();
	}
	/*
	Render* draw = new Render;
	Button* button1 = new Button(50, 50, 200, 37, "Button1");

	draw->init();
	draw->drawButton(button1->getX(), button1->getY(), button1->getW(), button1->getH(), button1->getText().c_str(), true);

	draw->update();
	draw->destroy();
	*/

	system("pause");
	return 0;
}