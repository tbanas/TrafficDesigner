#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Render.h"
#include "Button.h"
#include "AddRoadButton.h"
#include "AddLaneButton.h"
#include "Intersection.h"

class UserInterface
{
private:
	std::vector<Button*> buttons;
	std::vector<AddRoadButton*> addRoadButtons;
	std::vector<AddLaneButton*> addLaneButtons;
	ALLEGRO_EVENT_QUEUE* eventQueue;
	std::vector<Intersection*> intersections;
	int lanesIds;
	int roadsIds;
	int intersectionsIds;

public:
	UserInterface();
	~UserInterface();

	void init();
	void AddIntersection();
	void update();
	void render();
};

