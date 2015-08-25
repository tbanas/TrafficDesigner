#include "Render.h"

Render &Render::GetInstance()
{
	static Render instance;
	return instance;
}

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
	font = al_load_ttf_font("font.ttf", 20, 0);

	al_clear_to_color(al_map_rgb(32, 32, 32));
}

void Render::update()
{
	al_flip_display();
	al_clear_to_color(al_map_rgb(32, 32, 32));
}

void Render::drawButton(int x, int y, int w, int h, std::string text, ALLEGRO_EVENT e)
{
	if (isMouseOver(x, y, w, h, e))
	{
		al_draw_filled_rectangle(x, y, x + w, y + h, al_map_rgb(160, 160, 160));
	}
	else
	{
		al_draw_filled_rectangle(x, y, x + w, y + h, al_map_rgb(64, 64, 64));
	}
	al_draw_text(font, al_map_rgb(255, 255, 255), x + 10, y + 5, NULL, text.c_str());
}

void Render::drawIntersection(int id, int size)
{
	al_draw_filled_rectangle((id + 1) * 300, 300, (id + 1) * 300 + size * 20, 300 + size * 20, al_map_rgb(0, 160, 160));
}

void Render::drawRoad(int id, int intersectionId, int size, int intersectionSize)
{
	while (id >= 4)
	{
		id -= 4;
	}
	if (id % 2 == 0)
	{
		if (id % 3 == 0)
		{
			al_draw_filled_rectangle((intersectionId + 1) * 300, 150, (intersectionId + 1) * 300 + size * 20, 300, al_map_rgb(160, 160, 160));
		}
		else
		{
			al_draw_filled_rectangle((intersectionId + 1) * 300, 300 + 20 * intersectionSize, (intersectionId + 1) * 300 + size * 20, 450 + intersectionSize * 20, al_map_rgb(160, 160, 160));
		}
	}
	else
	{
		if (id % 3 == 0)
		{
			al_draw_filled_rectangle((intersectionId + 1) * 300 - 150, 300, (intersectionId + 1) * 300, 300 + 20 * size, al_map_rgb(160, 160, 160));
		}
		else
		{
			al_draw_filled_rectangle((intersectionId + 1) * 300 + 20 * intersectionSize, 300, (intersectionId + 1) * 300 + 150 + 20 * intersectionSize, 300 + size * 20, al_map_rgb(160, 160, 160));
		}
	}
}

void Render::drawLane(int id, int roadId, int intersectionId)
{

}

void Render::drawAddLaneButton(int x, int y, ALLEGRO_EVENT e)
{
	if (isMouseOver(x, y, 20, 20, e))
	{
		al_draw_filled_rectangle(x, y, x + 20, y + 20, al_map_rgb(0, 153, 0));
	}
	else
	{
		al_draw_filled_rectangle(x, y, x + 20, y + 20, al_map_rgb(0, 53, 0));
	}
	al_draw_filled_rectangle(x + 9, y + 4, x + 11, y + 16, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(x + 4, y + 9, x + 16, y + 11, al_map_rgb(255, 255, 255));
}

void Render::drawAddRoadButton(int x, int y, int roadId, int intersectionId, ALLEGRO_EVENT e)
{
	if (isMouseOver(x, y, 20, 20, e))
	{
		al_draw_filled_rectangle(x, y, x + 20, y + 20, al_map_rgb(160, 160, 160));
	}
	else
	{
		al_draw_filled_rectangle(x, y, x + 20, y + 20, al_map_rgb(64, 64, 64));
	}
	al_draw_filled_rectangle(x + 9, y + 4, x + 11, y + 16, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(x + 4, y + 9, x + 16, y + 11, al_map_rgb(255, 255, 255));
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
	al_destroy_font(font);
}
