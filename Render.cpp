#include "Render.h"
#include "Intersection.h"
#include "ButtonAddLane.h"
#include "Button.h"
#include "ButtonAddRoad.h"
#include "Road.h"
#include "Lane.h"

Render::Render()
{
}

Render::~Render()
{
}

void Render::init()
{
	if (!al_init())
	{
		std::cout << "Failed to initialize allegro!" << std::endl;
		return;
	}

	display = al_create_display(1280, 720);
	if (!display)
	{
		std::cout << "failed to create display!" << std::endl;
		return;
	}

	al_set_window_title(display, "Traffic Designer");

	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	this->font = al_load_ttf_font("fonts/font.ttf", 20, 0);

	al_clear_to_color(al_map_rgb(32, 32, 32));
	al_flip_display();
}

void Render::update()
{
	al_flip_display();
	al_clear_to_color(al_map_rgb(32, 32, 32));
}

void Render::renderButton(Button* button, ALLEGRO_EVENT e)
{
	if (isMouseOver(button->getX(), button->getY(), button->getW(), button->getH(), e))
	{
		al_draw_filled_rectangle(button->getX(), button->getY(), button->getX() + button->getW(), button->getY() + button->getH(), al_map_rgb(160, 160, 160));
	}
	else
	{
		al_draw_filled_rectangle(button->getX(), button->getY(), button->getX() + button->getW(), button->getY() + button->getH(), al_map_rgb(64, 64, 64));
	}

	al_draw_text(this->font, al_map_rgb(255, 255, 255), button->getX() + 10, button->getY() + 5, NULL, button->getText().c_str());
}

void Render::renderIntersection(Intersection* intersection)
{
	al_draw_filled_rectangle((intersection->getId() + 1) * 300, 300, (intersection->getId() + 1) * 300 + intersection->getSize() * 20, 300 + intersection->getSize() * 20, al_map_rgb(0, 160, 160));

	this->renderRoads(intersection->getRoads());
}

void Render::renderRoads(std::vector<Road*> roads)
{
	for (int i = 0; i < roads.size(); i++)
	{
		this->renderRoad(roads[i]);
	}
}

void Render::renderRoad(Road* road)
{
	while (road->getId() >= 4)
	{
		road->setId(road->getId() - 4);
	}
	if (road->getId() % 2 == 0)
	{
		if (road->getId() % 3 == 0)
		{
			al_draw_filled_rectangle((road->getIntersection()->getId() + 1) * 300, 150, (road->getIntersection()->getId() + 1) * 300 + road->getLanes().size() * 20, 300, al_map_rgb(160, 160, 160));
		}
		else
		{
			al_draw_filled_rectangle((road->getIntersection()->getId() + 1) * 300, 300 + 20 * road->getIntersection()->getSize(), (road->getIntersection()->getId() + 1) * 300 + road->getLanes().size() * 20, 450 + road->getIntersection()->getSize() * 20, al_map_rgb(160, 160, 160));
		}
	}
	else
	{
		if (road->getId() % 3 == 0)
		{
			al_draw_filled_rectangle((road->getIntersection()->getId() + 1) * 300 - 150, 300, (road->getIntersection()->getId() + 1) * 300, 300 + 20 * road->getLanes().size(), al_map_rgb(160, 160, 160));
		}
		else
		{
			al_draw_filled_rectangle((road->getIntersection()->getId() + 1) * 300 + 20 * road->getIntersection()->getSize(), 300, (road->getIntersection()->getId() + 1) * 300 + 150 + 20 * road->getIntersection()->getSize(), 300 + road->getLanes().size() * 20, al_map_rgb(160, 160, 160));
		}
	}
}

void Render::renderButtonAddLane(ButtonAddLane* ButtonAddLane, ALLEGRO_EVENT e)
{
	if (isMouseOver(ButtonAddLane->getX(), ButtonAddLane->getY(), 20, 20, e))
	{
		al_draw_filled_rectangle(ButtonAddLane->getX(), ButtonAddLane->getY(), ButtonAddLane->getX() + 20, ButtonAddLane->getY() + 20, al_map_rgb(0, 153, 0));
	}
	else
	{
		al_draw_filled_rectangle(ButtonAddLane->getX(), ButtonAddLane->getY(), ButtonAddLane->getX() + 20, ButtonAddLane->getY() + 20, al_map_rgb(0, 53, 0));
	}
	al_draw_filled_rectangle(ButtonAddLane->getX() + 9, ButtonAddLane->getY() + 4, ButtonAddLane->getX() + 11, ButtonAddLane->getY() + 16, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(ButtonAddLane->getX() + 4, ButtonAddLane->getY() + 9, ButtonAddLane->getX() + 16, ButtonAddLane->getY() + 11, al_map_rgb(255, 255, 255));
}

void Render::renderButtonAddRoad(ButtonAddRoad* ButtonAddRoad, ALLEGRO_EVENT e)
{
	if (isMouseOver(ButtonAddRoad->getX(), ButtonAddRoad->getY(), 20, 20, e))
	{
		al_draw_filled_rectangle(ButtonAddRoad->getX(), ButtonAddRoad->getY(), ButtonAddRoad->getX() + 20, ButtonAddRoad->getY() + 20, al_map_rgb(160, 160, 160));
	}
	else
	{
		al_draw_filled_rectangle(ButtonAddRoad->getX(), ButtonAddRoad->getY(), ButtonAddRoad->getX() + 20, ButtonAddRoad->getY() + 20, al_map_rgb(64, 64, 64));
	}
	al_draw_filled_rectangle(ButtonAddRoad->getX() + 9, ButtonAddRoad->getY() + 4, ButtonAddRoad->getX() + 11, ButtonAddRoad->getY() + 16, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(ButtonAddRoad->getX() + 4, ButtonAddRoad->getY() + 9, ButtonAddRoad->getX() + 16, ButtonAddRoad->getY() + 11, al_map_rgb(255, 255, 255));
}

void Render::renderLane(Lane* lane)
{

}

bool Render::isMouseOver(int x, int y, int w, int h, ALLEGRO_EVENT e)
{
	if (e.type == ALLEGRO_EVENT_MOUSE_AXES || e.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY || e.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if (e.mouse.x >= x && e.mouse.y >= y && e.mouse.x <= x + w && e.mouse.y <= y + h)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool Render::isMouseDown(int x, int y, int w, int h, ALLEGRO_EVENT e)
{
	if (e.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if (e.mouse.x >= x && e.mouse.y >= y && e.mouse.x <= x + w && e.mouse.y <= y + h)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void Render::destroy()
{
	al_destroy_display(display);
	al_destroy_font(this->font);
}
