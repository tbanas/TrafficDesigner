#include "Road.h"


Road::Road()
{
}


Road::~Road()
{
}

void Road::addLane(int id, bool entry, Lane* lane)
{
	lanes.push_back(*lane);
	lanes.back().setId(id);
	lanes.back().setEntry(entry);
}

void Road::setId(int id)
{
	this->id = id;
}

std::vector<Lane>& Road::getLanes()
{
	return lanes;
}

int Road::getId()
{
	return id;
}