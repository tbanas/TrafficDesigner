#include "FileManager.h"


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
		project->InsertEndChild(intersection);
		for (int j = 0; j < intersections[i]->getRoads().size(); j++)
		{
			tinyxml2::XMLElement* road = newFile.NewElement("Road");
			road->SetAttribute("id", intersections[i]->getRoads()[j].getId());
			intersection->InsertEndChild(road);
			for (int k = 0; k < intersections[i]->getRoads()[j].getLanes().size(); k++)
			{
				tinyxml2::XMLElement* lane = newFile.NewElement("Lane");
				lane->SetAttribute("id", intersections[i]->getRoads()[j].getLanes()[k].getId());
				road->InsertEndChild(lane);
			}
		}
	}
	newFile.SaveFile(filename.c_str());

}



