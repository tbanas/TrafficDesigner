#ifndef LANE_H
#define LANE_H

class Road;

class Lane
{
private:
	int id;
	bool entry;
	Road* road;

public:
	Lane(Road* road, int id);
	~Lane();

	void setId(int id);
	void setEntry(bool entry);
	void setRoad(Road* road);

	int getId();
	bool isEntry();
	Road* getRoad();
};

#endif
