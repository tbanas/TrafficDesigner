#include "Lane.h"


Lane::Lane()
{
	this->entry = true;
}


Lane::~Lane()
{
}

void Lane::setId(int newId)
{
	this->id = newId;
}

void Lane::setEntry(int newEntry)
{
	this->entry = newEntry;
}

int Lane::getId()
{
	return id;
}

bool Lane::isEntry()
{
	return entry;
}
