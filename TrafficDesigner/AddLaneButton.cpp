#include "AddLaneButton.h"


AddLaneButton::AddLaneButton(int roadId, int intersectionId, int position, int intersectionSize)
{
	this->roadId = roadId;
	this->intersectionId = intersectionId;
	setPosition(position, intersectionSize);
	this->w = 20;
	this->h = 20;
	isVisible = true;
}


AddLaneButton::~AddLaneButton()
{
}

void AddLaneButton::setLaneId(int laneId)
{
	this->laneId = laneId;
}

void AddLaneButton::setVisibility(bool isVisible)
{
	this->isVisible = isVisible;
}

bool AddLaneButton::getVisibility()
{
	return isVisible;
}

int AddLaneButton::getRoadId()
{
	return roadId;
}
int AddLaneButton::getIntersectionId()
{
	return intersectionId;
}

void AddLaneButton::setPosition(int position, int intersectionSize)
{
	int changeX = 0, changeY = 0;
	int checkRoadId = roadId;
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
		changeX = 50 + (intersectionSize - 1) * 20;
		changeY = 20 * position;
	}
	else if (checkRoadId == 2)
	{
		changeX = 20 * position;
		changeY = 50 + (intersectionSize - 1) * 20;
	}
	else if (checkRoadId == 3)
	{
		changeX = -50;
		changeY = 20 * position;
	}
	this->x = (intersectionId + 1) * 300 + changeX;
	this->y = 300 + changeY;
}

void AddLaneButton::render(ALLEGRO_EVENT e)
{
	Render::GetInstance().drawAddLaneButton(x, y, e);
}

bool AddLaneButton::isMouseDown(ALLEGRO_EVENT e)
{
	if (Render::GetInstance().isMouseDown(x, y, w, h, e))
	{
		return true;
	}
	return false;
}
