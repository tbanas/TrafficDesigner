#ifndef ROAD_H
#define ROAD_H

#include <vector>

class Lane;
class Intersection;

class Road
{
private:
	std::vector<Lane*> lanes;
	int id;
	Intersection* intersection;

public:
	Road(Intersection* intersection, int id);
	~Road();

	void addLane(int id, bool entry, Lane* lane);
	void setId(int id);
	std::vector<Lane*> getLanes();
	int getId();
	Intersection* getIntersection();
};

#endif
