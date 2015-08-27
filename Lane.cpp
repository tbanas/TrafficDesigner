#include "Lane.h"
#include "Road.h"

Lane::Lane(Road* road, int id)
{
	this->road = road;
	this->id = id;
	this->entry = true;
}

Lane::~Lane()
{
}

void Lane::setId(int newId)
{
	this->id = newId;
}

void Lane::setEntry(bool entry)
{
	this->entry = entry;
}

void Lane::setRoad(Road* road)
{
	this->road = road;
}

int Lane::getId()
{
	return id;
}

bool Lane::isEntry()
{
	return entry;
}

Road* Lane::getRoad()
{
	return this->road;
}
