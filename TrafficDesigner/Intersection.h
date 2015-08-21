#pragma once

#include <vector>
#include "Road.h"

class Intersection
{
private:
	std::vector<Road> roads;
	int id;

public:
	Intersection();
	~Intersection();
	void addRoad(int id, Road* road);
	std::vector<Road>& getRoads();
	int getId();
};

