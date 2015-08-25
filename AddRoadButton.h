#ifndef ADDROADBUTTON_H
#define ADDROADBUTTON_H

#include "Render.h"

class AddRoadButton
{
private:
	int x, y, w, h;
	int roadId;
	int intersectionId;
	bool isVisible;

public:
	AddRoadButton(int roadId, int intersectionId);
	~AddRoadButton();
	int getRoadId();
	int getIntersectionId();
	bool getVisiblity();
	void setVisiblity(bool isVisible);
	void setPosition(int intersectionSize);
	void render(ALLEGRO_EVENT e);
	bool isMouseDown(ALLEGRO_EVENT e);
};

#endif
