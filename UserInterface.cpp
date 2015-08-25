#include "UserInterface.h"


UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}

void UserInterface::init()
{
	Render::GetInstance().init();
	buttons.push_back(new Button(50, 50, 200, 37, "Add Intersection"));
	buttons.push_back(new Button(300, 50, 200, 37, "Simulate"));
	buttons.push_back(new Button(550, 50, 200, 37, "Save Project"));

	eventQueue = al_create_event_queue();
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	intersectionsIds = 0;
	roadsIds = 0;
	lanesIds = 0;
}

void UserInterface::update()
{
	ALLEGRO_EVENT e;
	al_wait_for_event(eventQueue, &e);
	for (int i = 0; i < buttons.size(); i++)
	{
		buttons[i]->render(e);
	}

	if (buttons[0]->isMouseDown(e))
	{
		intersections.push_back(new Intersection(intersectionsIds, 1));

		for (int i = roadsIds; i < roadsIds + 4; i++)
		{
			addRoadButtons.push_back(new AddRoadButton(i, intersectionsIds));
		}
		roadsIds += 4;
		intersectionsIds++;
	}

	for (int i = 0; i < intersections.size(); i++)
	{
		intersections[i]->render();
		for (int j = 0; j < intersections[i]->getRoads().size(); j++)
		{
			intersections[i]->getRoads()[j].render(intersections[i]->getSize());
		}
	}
	for (int i = 0; i < addRoadButtons.size(); i++)
	{
		if (addRoadButtons[i]->getVisiblity())
		{
			addRoadButtons[i]->setPosition(intersections[addRoadButtons[i]->getIntersectionId()]->getSize());
			addRoadButtons[i]->render(e);
			if (addRoadButtons[i]->isMouseDown(e))
			{
				intersections[addRoadButtons[i]->getIntersectionId()]->addRoad(addRoadButtons[i]->getRoadId(), new Road);
				std::cout << "Successfully added road " << addRoadButtons[i]->getRoadId() << " to intersection " << addRoadButtons[i]->getIntersectionId() << std::endl;
				addRoadButtons[i]->setVisiblity(false);
				addLaneButtons.push_back(new AddLaneButton(addRoadButtons[i]->getRoadId(), addRoadButtons[i]->getIntersectionId(), 0, 1));
			}
			
		}
	}
	for (int i = 0; i < addLaneButtons.size(); i++)
	{
		if (addLaneButtons[i]->getVisibility())
		{
			addLaneButtons[i]->setPosition(intersections[addLaneButtons[i]->getIntersectionId()]->getRoadById(addLaneButtons[i]->getRoadId()).getLanes().size(), intersections[addLaneButtons[i]->getIntersectionId()]->getSize());
			addLaneButtons[i]->render(e);
			if (addLaneButtons[i]->isMouseDown(e))
			{
				intersections[addLaneButtons[i]->getIntersectionId()]->getRoadById(addLaneButtons[i]->getRoadId()).addLane(lanesIds, true, new Lane);
				lanesIds++;
				intersections[addLaneButtons[i]->getIntersectionId()]->updateSize();
				
			}
			
		}
		
	}

	Render::GetInstance().update();
}

void UserInterface::AddIntersection()
{
	std::cout << "Added intersection" << std::endl;
}
