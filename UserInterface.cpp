#include "UserInterface.h"
#include "Intersection.h"
#include "Road.h"
#include "Lane.h"
#include "AddRoadButton.h"
#include "AddLaneButton.h"
#include "FileManager.h"

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
}

void UserInterface::init()
{
	this->setRender(new Render);
	this->getRender()->init();
	buttons.push_back(new Button(50, 50, 200, 37, "Add intersection"));
	buttons.push_back(new Button(300, 50, 200, 37, "Save Project"));
	buttons.push_back(new Button(550, 50, 200, 37, "Load project"));

	eventQueue = al_create_event_queue();
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	intersectionsCounter = 0;
	roadsCounter = 0;
	lanesCounter = 0;
}

void UserInterface::setRender(Render* render)
{
	this->render = render;
}

Render* UserInterface::getRender()
{
	return this->render;
}

void UserInterface::update()
{
	ALLEGRO_EVENT e;
	al_wait_for_event(eventQueue, &e);

	for (int i = 0; i < buttons.size(); i++)
	{
		this->render->renderButton(buttons[i], e);
	}

	/*
	 * Add new intersection button
	 */
	if (this->render->isMouseDown(buttons[0]->getX(), buttons[0]->getY(), buttons[0]->getW(), buttons[0]->getH(), e))
	{
		intersections.push_back(new Intersection(intersectionsCounter, 1));

		for (int i = roadsCounter; i < roadsCounter + 4; i++)
		{
			addRoadButtons.push_back(new AddRoadButton(new Road(intersections.back(), i)));
		}
		roadsCounter += 4;
		intersectionsCounter++;
	}

	/*
	 * Save project to file button
	 */
	if (this->render->isMouseDown(buttons[1]->getX(), buttons[1]->getY(), buttons[1]->getW(), buttons[1]->getH(), e))
	{
		FileManager* fileManager = new FileManager;
		fileManager->saveFile(intersections, "TrafficDesignerProject.xml");
	}

	/*
	 * Load project from file button
	 */
	if (this->render->isMouseDown(buttons[2]->getX(), buttons[2]->getY(), buttons[2]->getW(), buttons[2]->getH(), e))
	{
		intersections.clear();
		FileManager* fileManager = new FileManager;
		intersections = fileManager->loadFile("TrafficDesignerProject.xml");
		intersections[0]->getRoads()[0]->getLanes()[0]->getId();
	}

	/*
	 * Render all created intersections
	 */
	for (int i = 0; i < intersections.size(); i++)
	{
		this->render->renderIntersection(intersections[i]);
	}

	/*
	 * Render buttons "add road" for each intersection
	 */
	for (int i = 0; i < addRoadButtons.size(); i++)
	{
		if (addRoadButtons[i]->getVisiblity())
		{
			addRoadButtons[i]->changePosition();

			this->render->renderAddRoadButton(addRoadButtons[i], e);
			int x = addRoadButtons[i]->getX();
			int y = addRoadButtons[i]->getY();
			int w = addRoadButtons[i]->getW();
			int h = addRoadButtons[i]->getH();

			if (this->render->isMouseDown(x, y, w, h, e))
			{
				addRoadButtons[i]->getRoad()->getIntersection()->addRoad(addRoadButtons[i]->getRoad());
				std::cout << "Successfully added road " << addRoadButtons[i]->getRoad()->getId() << " to intersection " << addRoadButtons[i]->getRoad()->getIntersection()->getId() << std::endl;
				addRoadButtons[i]->setVisiblity(false);
				addLaneButtons.push_back(new AddLaneButton(new Lane(addRoadButtons[i]->getRoad(), lanesCounter), 0));
			}

		}
	}

	/*
	 * Render buttons "add lane" for each road
	 */
	for (int i = 0; i < addLaneButtons.size(); i++)
	{
		if (addLaneButtons[i]->getVisibility())
		{
			addLaneButtons[i]->changePosition(addLaneButtons[i]->getLane()->getRoad()->getLanes().size());

			this->render->renderAddLaneButton(addLaneButtons[i], e);
			int x = addLaneButtons[i]->getX();
			int y = addLaneButtons[i]->getY();
			int w = addLaneButtons[i]->getW();
			int h = addLaneButtons[i]->getH();

			if (this->render->isMouseDown(x, y, w, h, e))
			{
				addLaneButtons[i]->getLane()->getRoad()->addLane(lanesCounter, true, new Lane(addLaneButtons[i]->getLane()->getRoad(), lanesCounter));
				lanesCounter++;
				intersections[addLaneButtons[i]->getLane()->getRoad()->getIntersection()->getId()]->updateSize();

			}

		}

	}

	/*
	 * Update view
	 */
	this->render->update();
}

void UserInterface::AddIntersection()
{
	std::cout << "Added intersection" << std::endl;
}

Intersection* UserInterface::getIntersectionById(int id)
{
	for (int i = 0; i < intersections.size(); i++)
	{
		if (intersections[i]->getId() == id)
		{
			return intersections[i];
		}
	}

	throw std::string("Intersection with this id doesn't exist.");
}
