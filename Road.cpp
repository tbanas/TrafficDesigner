#include "Road.h"
#include "Lane.h"
#include "Intersection.h"

Road::Road(Intersection* intersection, int id)
{
	this->intersection = intersection;
	this->id=id;
}


Road::~Road()
{
}

void Road::addLane(int id, bool entry, Lane* lane)
{
	lanes.push_back(lane);
	lanes.back()->setId(id);
}

void Road::setId(int id)
{
	this->id = id;
}

std::vector<Lane*> Road::getLanes()
{
	return lanes;
}

int Road::getId()
{
	return id;
}

Intersection* Road::getIntersection()
{
	return this->intersection;
}
