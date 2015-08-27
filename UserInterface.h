#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#pragma once

#include <string>
#include <iostream>
#include <vector>

#include "Render.h"
#include "Button.h"

class UserInterface
{
private:
	Render* render;
	std::vector<Button*> buttons;
	std::vector<AddRoadButton*> addRoadButtons;
	std::vector<AddLaneButton*> addLaneButtons;
	ALLEGRO_EVENT_QUEUE* eventQueue;
	std::vector<Intersection*> intersections;
	int lanesCounter;
	int roadsCounter;
	int intersectionsCounter;

public:
	UserInterface();
	~UserInterface();

	void setRender(Render*);
	Render* getRender();
	void init();
	void AddIntersection();
	void update();
	Intersection* getIntersectionById(int id);
};

#endif
