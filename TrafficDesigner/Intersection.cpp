#include "Intersection.h"


Intersection::Intersection(int id, int size)
{
	this->id = id;
	this->size = size;
}


Intersection::~Intersection()
{
}

void Intersection::addRoad(int id, Road* road)
{
	roads.push_back(*road);
	roads.back().setId(id);
}

void Intersection::updateSize()
{
	int max = 0;
	for (int i = 0; i < roads.size(); i++)
	{
		if (roads[i].getLanes().size()>max)
		{
			max = roads[i].getLanes().size();
		}
	}
	if (max > 1)
	{
		size = max;
	}
}

std::vector<Road>& Intersection::getRoads()
{
	return roads;
}

Road& Intersection::getRoadById(int id)
{
	for (int i = 0; i < getRoads().size(); i++)
	{
		if (getRoads()[i].getId() == id)
		{
			return getRoads()[i];
		}
	}
}

int Intersection::getId()
{
	return id;
}

int Intersection::getSize()
{
	return size;
}

void Intersection::render()
{
	Render::GetInstance().drawIntersection(id, size);
}

void Intersection::addConnection(Lane lane1, Lane lane2)
{
	if (lane1.isEntry() && !lane2.isEntry())
	{
		std::pair<Lane, Lane> newConnection;
		newConnection.first = lane1;
		newConnection.second = lane2;
		connections.push_back(newConnection);
	}
}

bool Intersection::isConnected(Lane lane1, Lane lane2)
{
	int i = 0;
	std::pair<Lane,Lane> checkConnection;
	checkConnection.first = lane1;
	checkConnection.second = lane2;

	while (i != connections.size() && (checkConnection.first.getId() != connections[i].first.getId() || checkConnection.second.getId() != connections[i].second.getId()))
	{
		i++;
	}

	return (i<connections.size())? true : false;
}