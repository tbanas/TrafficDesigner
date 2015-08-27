#include "ButtonAddLane.h"
#include "Lane.h"
#include "Road.h"
#include "Intersection.h"

ButtonAddLane::ButtonAddLane(Lane* lane, int position)
{
	this->lane = lane;
	changePosition(position);
	this->w = 20;
	this->h = 20;
	isVisible = true;
}


ButtonAddLane::~ButtonAddLane()
{
}

int ButtonAddLane::getX()
{
	return this->x;
}

int ButtonAddLane::getY()
{
	return this->y;
}

int ButtonAddLane::getW()
{
	return this->w;
}

int ButtonAddLane::getH()
{
	return this->h;
}

void ButtonAddLane::setLane(Lane* lane)
{
	this->lane = lane;
}

void ButtonAddLane::setVisibility(bool isVisible)
{
	this->isVisible = isVisible;
}

bool ButtonAddLane::getVisibility()
{
	return isVisible;
}

void ButtonAddLane::changePosition(int position)
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

Lane* ButtonAddLane::getLane()
{
	return this->lane;
}
