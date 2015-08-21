#include "Intersection.h"


Intersection::Intersection()
{
}


Intersection::~Intersection()
{
}

void Intersection::addRoad(int id, Road* road)
{
	roads.push_back(*road);
	roads.back().setId(id);
}

std::vector<Road>& Intersection::getRoads()
{
	return roads;
}

int Intersection::getId()
{
	return id;
}