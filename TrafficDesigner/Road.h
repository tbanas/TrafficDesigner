#pragma once

#include <vector>
#include "Lane.h"

class Road
{
private:
	std::vector<Lane> lanes;
	int id;

public:
	Road();
	~Road();

	void addLane(int id, bool entry, Lane* lane);
	void setId(int id);
	std::vector<Lane>& getLanes();
	int getId();
};

