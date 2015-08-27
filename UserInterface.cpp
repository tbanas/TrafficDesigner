#include "UserInterface.h"
#include "Intersection.h"
#include "Road.h"
#include "Lane.h"
#include "ButtonAddLane.h"
#include "ButtonAddRoad.h"
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
			ButtonAddRoads.push_back(new ButtonAddRoad(new Road(intersections.back(), i)));
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
	for (int i = 0; i < ButtonAddRoads.size(); i++)
	{
		if (ButtonAddRoads[i]->getVisiblity())
		{
			ButtonAddRoads[i]->changePosition();

			this->render->renderButtonAddRoad(ButtonAddRoads[i], e);
			int x = ButtonAddRoads[i]->getX();
			int y = ButtonAddRoads[i]->getY();
			int w = ButtonAddRoads[i]->getW();
			int h = ButtonAddRoads[i]->getH();

			if (this->render->isMouseDown(x, y, w, h, e))
			{
				ButtonAddRoads[i]->getRoad()->getIntersection()->addRoad(ButtonAddRoads[i]->getRoad());
				std::cout << "Successfully added road " << ButtonAddRoads[i]->getRoad()->getId() << " to intersection " << ButtonAddRoads[i]->getRoad()->getIntersection()->getId() << std::endl;
				ButtonAddRoads[i]->setVisiblity(false);
				ButtonAddLanes.push_back(new ButtonAddLane(new Lane(ButtonAddRoads[i]->getRoad(), lanesCounter), 0));
			}

		}
	}

	/*
	 * Render buttons "add lane" for each road
	 */
	for (int i = 0; i < ButtonAddLanes.size(); i++)
	{
		if (ButtonAddLanes[i]->getVisibility())
		{
			ButtonAddLanes[i]->changePosition(ButtonAddLanes[i]->getLane()->getRoad()->getLanes().size());

			this->render->renderButtonAddLane(ButtonAddLanes[i], e);
			int x = ButtonAddLanes[i]->getX();
			int y = ButtonAddLanes[i]->getY();
			int w = ButtonAddLanes[i]->getW();
			int h = ButtonAddLanes[i]->getH();

			if (this->render->isMouseDown(x, y, w, h, e))
			{
				ButtonAddLanes[i]->getLane()->getRoad()->addLane(lanesCounter, true, new Lane(ButtonAddLanes[i]->getLane()->getRoad(), lanesCounter));
				lanesCounter++;
				intersections[ButtonAddLanes[i]->getLane()->getRoad()->getIntersection()->getId()]->updateSize();

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
