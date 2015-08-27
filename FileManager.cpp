#include "FileManager.h"
#include "tinyxml2.h"

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}

void FileManager::saveFile(std::vector<Intersection*> intersections, std::string filename)
{
	tinyxml2::XMLDocument newFile;
	tinyxml2::XMLNode* project = newFile.NewElement("Project");
	newFile.InsertFirstChild(project);

	for (int i = 0; i < intersections.size(); i++)
	{
		tinyxml2::XMLElement* intersection = newFile.NewElement("Intersection");
		intersection->SetAttribute("id", intersections[i]->getId());
		intersection->SetAttribute("size", intersections[i]->getSize());
		project->InsertEndChild(intersection);
		for (int j = 0; j < intersections[i]->getRoads().size(); j++)
		{
			tinyxml2::XMLElement* road = newFile.NewElement("Road");
			road->SetAttribute("id", intersections[i]->getRoads()[j]->getId());
			intersection->InsertEndChild(road);
			for (int k = 0; k < intersections[i]->getRoads()[j]->getLanes().size(); k++)
			{
				tinyxml2::XMLElement* lane = newFile.NewElement("Lane");
				lane->SetAttribute("id", intersections[i]->getRoads()[j]->getLanes()[k]->getId());
				road->InsertEndChild(lane);
			}
		}
	}
	newFile.SaveFile(filename.c_str());
}

std::vector<Intersection*> FileManager::loadFile(std::string filename)
{
	tinyxml2::XMLDocument newFile;
	newFile.LoadFile(filename.c_str());
	tinyxml2::XMLNode* project = newFile.FirstChild();
	tinyxml2::XMLElement* intersection = project->FirstChildElement("Intersection");
	std::vector<Intersection*> intersections;
	while (intersection != nullptr)
	{
		int id, size;
		intersection->QueryIntAttribute("id", &id);
		intersection->QueryIntAttribute("size", &size);
		intersections.push_back(new Intersection(id, size));
		tinyxml2::XMLElement* road = intersection->FirstChildElement("Road");
		while (road != nullptr)
		{
			int rId;
			road->QueryIntAttribute("id", &rId);
			intersections.back()->addRoad(new Road(intersections.back(),rId));
			tinyxml2::XMLElement* lane = road->FirstChildElement("Lane");
			while (lane != nullptr)
			{
				int lId;
				lane->QueryIntAttribute("id", &lId);
				intersections.back()->getRoads().back()->addLane(lId, true, new Lane(intersections.back()->getRoads().back(), lId));
				lane = lane->NextSiblingElement("Lane");
			}
			road = road->NextSiblingElement("Road");
		}
		intersection = intersection->NextSiblingElement("Intersection");
	}
	return intersections;
}


