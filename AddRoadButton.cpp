#include "AddRoadButton.h"
#include "Road.h"
#include "Intersection.h"

AddRoadButton::AddRoadButton(Road* road)
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


AddRoadButton::~AddRoadButton()
{
}

int AddRoadButton::getX()
{
	return this->x;
}

int AddRoadButton::getY()
{
	return this->y;
}

int AddRoadButton::getW()
{
	return this->w;
}

int AddRoadButton::getH()
{
	return this->h;
}

Road* AddRoadButton::getRoad()
{
	return this->road;
}

bool AddRoadButton::getVisiblity()
{
	return isVisible;
}

void AddRoadButton::setVisiblity(bool isVisible)
{
	this->isVisible = isVisible;
}

void AddRoadButton::changePosition()
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
