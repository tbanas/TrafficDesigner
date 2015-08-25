#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/mouse.h>
#include <iostream>
#include <string>

class Render
{
private:
	ALLEGRO_DISPLAY *display;
	ALLEGRO_FONT *font;

public:
	static Render &GetInstance();
	Render();
	~Render();
	void init();
	void update();
	void drawButton(int x, int y, int w, int h, std::string text, ALLEGRO_EVENT e);
	void drawAddRoadButton(int x, int y, int roadId, int intersectionId, ALLEGRO_EVENT e);
	void drawIntersection(int id, int size);
	void drawRoad(int id, int intersectionId, int size, int intersectionSize);
	void drawLane(int id, int roadId, int intersectionId);
	void drawAddLaneButton(int x, int y, ALLEGRO_EVENT e);
	bool isMouseOver(int x, int y, int w, int h, ALLEGRO_EVENT e);
	bool isMouseDown(int x, int y, int w, int h, ALLEGRO_EVENT e);
	void destroy();
};

