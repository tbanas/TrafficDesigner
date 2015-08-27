#ifndef RENDER_H
#define RENDER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/mouse.h>
#include <iostream>
#include <string>
#include <vector>

class Intersection;
class AddLaneButton;
class AddRoadButton;
class Road;
class Button;
class Lane;

class Render
{
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_FONT *font;

public:
	Render();
	~Render();
	void init();
	void update();
	void renderButton(Button* button, ALLEGRO_EVENT e);
	void renderIntersection(Intersection* intersection);
	void renderRoads(std::vector<Road*> roads);
	void renderRoad(Road* road);
	void renderAddRoadButton(AddRoadButton* addRoadButton, ALLEGRO_EVENT e);
	void renderAddLaneButton(AddLaneButton* addLaneButton, ALLEGRO_EVENT e);
	void renderLane(Lane* lane);
	bool isMouseOver(int x, int y, int w, int h, ALLEGRO_EVENT e);
	bool isMouseDown(int x, int y, int w, int h, ALLEGRO_EVENT e);
	void destroy();
};

#endif
