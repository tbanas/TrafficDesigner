#ifndef BUTTON_H
#define BUTTON_H

#include <string>

#include "Render.h"

class Button
{
private:
	std::string text;
	int x, y, w, h;

public:
	Button(int x, int y, int w, int h, std::string text);
	~Button();
	int getX();
	int getY();
	int getW();
	int getH();
	std::string getText();
	bool isMouseDown(ALLEGRO_EVENT e);
};

#endif
