#include "ButtonAddRoad.h"
#include "Road.h"
#include "Intersection.h"

ButtonAddRoad::ButtonAddRoad(Road* road)
{
	this->road = road;
	int changeX = 0, changeY = 0;
	int checkRoadId = this->road->getId();
	while (checkRoadId >= 4)
	{
		checkRoadId -= 4;
	}
	if (checkRoadId == 0)
	{
		changeX = 0;
		changeY = -25;
	}
	else if (checkRoadId == 1)
	{
		changeX = 25;
		changeY = 0;
	}
	else if (checkRoadId == 2)
	{
		changeX = 0;
		changeY = 25;
	}
	else if (checkRoadId == 3)
	{
		changeX = -25;
		changeY = 0;
	}
	this->x = (this->road->getIntersection()->getId() + 1) * 300 + changeX;
	this->y = 300 + changeY;
	this->w = 20;
	this->h = 20;
	isVisible = true;
}


ButtonAddRoad::~ButtonAddRoad()
{
}

int ButtonAddRoad::getX()
{
	return this->x;
}

int ButtonAddRoad::getY()
{
	return this->y;
}

int ButtonAddRoad::getW()
{
	return this->w;
}

int ButtonAddRoad::getH()
{
	return this->h;
}

Road* ButtonAddRoad::getRoad()
{
	return this->road;
}

bool ButtonAddRoad::getVisiblity()
{
	return isVisible;
}

void ButtonAddRoad::setVisiblity(bool isVisible)
{
	this->isVisible = isVisible;
}

void ButtonAddRoad::changePosition()
{
	int changeX = 0, changeY = 0;
	int checkRoadId = this->road->getId();
	while (checkRoadId >= 4)
	{
		checkRoadId -= 4;
	}
	if (checkRoadId == 0)
	{
		changeX = 0;
		changeY = -25;
	}
	else if (checkRoadId == 1)
	{
		changeX = 25 + (this->road->getIntersection()->getSize() - 1) * 20;
		changeY = 0;
	}
	else if (checkRoadId == 2)
	{
		changeX = 0;
		changeY = 25 + (this->road->getIntersection()->getSize() - 1) * 20;
	}
	else if (checkRoadId == 3)
	{
		changeX = -25;
		changeY = 0;
	}
	this->x = (this->road->getIntersection()->getId() + 1) * 300 + changeX;
	this->y = 300 + changeY;
}
