#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
#include "Road.h"

class Intersection
{
private:
	std::vector<Road> roads;
	int id;
	int size;
	int x;
	int y;
	std::vector<std::pair<Lane, Lane> > connections;

public:
	Intersection(int id, int size);
	~Intersection();
	void addRoad(int id, Road* road);
	void updateSize();
	std::vector<Road>& getRoads();
	Road& getRoadById(int id);
	int getId();
	int getSize();
	void render();
	void addConnection(Lane lane1, Lane lane2);
	bool isConnected(Lane lane1, Lane lane2);\

};

#endif
