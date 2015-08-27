#include "AddLaneButton.h"
#include "Lane.h"
#include "Road.h"
#include "Intersection.h"

AddLaneButton::AddLaneButton(Lane* lane, int position)
{
	this->lane = lane;
	changePosition(position);
	this->w = 20;
	this->h = 20;
	isVisible = true;
}


AddLaneButton::~AddLaneButton()
{
}

int AddLaneButton::getX()
{
	return this->x;
}

int AddLaneButton::getY()
{
	return this->y;
}

int AddLaneButton::getW()
{
	return this->w;
}

int AddLaneButton::getH()
{
	return this->h;
}

void AddLaneButton::setLane(Lane* lane)
{
	this->lane = lane;
}

void AddLaneButton::setVisibility(bool isVisible)
{
	this->isVisible = isVisible;
}

bool AddLaneButton::getVisibility()
{
	return isVisible;
}

void AddLaneButton::changePosition(int position)
{
	int changeX = 0, changeY = 0;
	int checkRoadId = this->lane->getRoad()->getId();
	while (checkRoadId >= 4)
	{
		checkRoadId -= 4;
	}
	if (checkRoadId == 0)
	{
		changeX = 20 * position;
		changeY = -50;
	}
	else if (checkRoadId == 1)
	{
		changeX = 50 + (this->lane->getRoad()->getIntersection()->getSize() - 1) * 20;
		changeY = 20 * position;
	}
	else if (checkRoadId == 2)
	{
		changeX = 20 * position;
		changeY = 50 + (this->lane->getRoad()->getIntersection()->getSize() - 1) * 20;
	}
	else if (checkRoadId == 3)
	{
		changeX = -50;
		changeY = 20 * position;
	}
	this->x = (this->lane->getRoad()->getIntersection()->getId() + 1) * 300 + changeX;
	this->y = 300 + changeY;
}

Lane* AddLaneButton::getLane()
{
	return this->lane;
}
