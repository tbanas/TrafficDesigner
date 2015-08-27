#include "Button.h"


Button::Button(int x, int y, int w, int h, std::string text)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->text = text;
}


Button::~Button()
{
}

int Button::getX()
{
	return x;
}

int Button::getY()
{
	return y;
}

int Button::getW()
{
	return w;
}

int Button::getH()
{
	return h;
}

std::string Button::getText()
{
	return text;
}
//
//bool Button::isMouseDown(ALLEGRO_EVENT e)
//{
//	if (Render::GetInstance().isMouseDown(x, y, w, h, e))
//	{
//		return true;
//	}
//	return false;
//}
