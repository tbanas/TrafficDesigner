#include "AddRoadButton.h"


AddRoadButton::AddRoadButton(int roadId, int intersectionId)
{
	this->roadId = roadId;
	this->intersectionId = intersectionId;
	int changeX = 0, changeY = 0;
	int checkRoadId = roadId;
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
	this->x = (intersectionId + 1) * 300 + changeX;
	this->y = 300 + changeY;
	this->w = 20;
	this->h = 20;
	isVisible = true;
}


AddRoadButton::~AddRoadButton()
{
}

int AddRoadButton::getRoadId()
{
	return roadId;
}
int AddRoadButton::getIntersectionId()
{
	return intersectionId;
}

bool AddRoadButton::getVisiblity()
{
	return isVisible;
}

void AddRoadButton::setVisiblity(bool isVisible)
{
	this->isVisible = isVisible;
}

void AddRoadButton::setPosition(int intersectionSize)
{
	int changeX = 0, changeY = 0;
	int checkRoadId = roadId;
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
		changeX = 25 + (intersectionSize - 1) * 20;
		changeY = 0;
	}
	else if (checkRoadId == 2)
	{
		changeX = 0;
		changeY = 25 + (intersectionSize - 1) * 20;
	}
	else if (checkRoadId == 3)
	{
		changeX = -25;
		changeY = 0;
	}
	this->x = (intersectionId + 1) * 300 + changeX;
	this->y = 300 + changeY;
}

void AddRoadButton::render(ALLEGRO_EVENT e)
{
	Render::GetInstance().drawAddRoadButton(x, y, roadId, intersectionId, e);
}

bool AddRoadButton::isMouseDown(ALLEGRO_EVENT e)
{
	if (Render::GetInstance().isMouseDown(x, y, w, h, e))
	{
		return true;
	}
	return false;
}
