#include "Pause.h"
#include "Engine.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

Pause Pause::instance = Pause();

Pause& Pause::getInstance() {
	return instance;
}

Pause::Pause() {
	background = al_load_bitmap("pause_background.png");
	menu_options.push_back(MenuOption("pause_1_a.png", "pause_1_u.png", 850, 400));
	menu_options.push_back(MenuOption("pause_2_a.png", "pause_2_u.png", 850, 500));
	menu_options.push_back(MenuOption("pause_3_a.png", "pause_3_u.png", 850, 600));
	current = -1;
}

Pause::~Pause() {
	al_destroy_bitmap(background);
}

int Pause::mainLoop() {
	bool exit = false;
	current = -1;
	ALLEGRO_EVENT_QUEUE* queue = Engine::getInstance().queue;
	ALLEGRO_EVENT event = Engine::getInstance().event;
	al_draw_bitmap(background, 650, 200, 0);
	Menu::getInstance().showMenu(menu_options);
	while (!exit) {
		al_wait_for_event(queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				exit = true;
				current = 2;
				break;
			case ALLEGRO_KEY_UP:
				current = Menu::getInstance().menuUp(menu_options, current);
				break;
			case ALLEGRO_KEY_DOWN:
				current = Menu::getInstance().menuDown(menu_options, current);
				break;
			case ALLEGRO_KEY_ENTER:
				if (current >= 0)
					exit = true;
				break;
			}
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
			current = Menu::getInstance().menuMouse(event.mouse.x, event.mouse.y, menu_options, current);
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (event.mouse.button & 1 && current >= 0)
				exit = true;
		}
	}
	al_play_sample_instance(Menu::getInstance().clickEffect);
	return current;
}