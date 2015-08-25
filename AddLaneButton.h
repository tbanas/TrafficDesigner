#ifndef ADDLANEBUTTON_H
#define ADDLANEBUTTON_H

#include "Render.h"

class AddLaneButton
{
private:
	int x, y, w, h;
	int laneId;
	int roadId;
	int intersectionId;
	bool isVisible;

public:
	AddLaneButton(int roadId, int intersectionId, int position, int intersectionSize);
	~AddLaneButton();
	void setLaneId(int laneId);
	void setVisibility(bool isVisible);
	bool getVisibility();
	int getRoadId();
	int getIntersectionId();
	void setPosition(int position, int intersectionSize);
	void render(ALLEGRO_EVENT e);
	bool isMouseDown(ALLEGRO_EVENT e);
};

#endif
