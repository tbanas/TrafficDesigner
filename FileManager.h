#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#pragma once

#include <vector>
#include <string>

#include "Intersection.h"
#include "Road.h"
#include "Lane.h"


class FileManager
{
public:
	FileManager();
	~FileManager();
	void saveFile(std::vector<Intersection*> intersections, std::string filename);
	std::vector<Intersection*> loadFile(std::string filename);
};

#endif