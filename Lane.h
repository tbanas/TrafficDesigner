#ifndef LANE_H
#define LANE_H

#include "Render.h"

class Lane
{
private:
	int id;
	bool entry;

public:
	Lane();
	~Lane();

	void setId(int newId);
	void setEntry(int newEntry);

	int getId();
	bool isEntry();
};

#endif
