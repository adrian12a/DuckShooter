#include "PlayerName.h"

PlayerName PlayerName::instance = PlayerName();

PlayerName& PlayerName::getInstance()
{
	return instance;
}

string PlayerName::mainLoop()
{
	bool exit = false;
	string playerName = "";
	ALLEGRO_EVENT_QUEUE* queue = Engine::getInstance().queue;
	ALLEGRO_EVENT event = Engine::getInstance().event;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(background, 0, 0, 0);
	while (!exit) {
		if (event.type == ALLEGRO_EVENT_TIMER) {
			al_draw_bitmap(background, 0, 0, 0);
			al_draw_textf(Engine::getInstance().big_font, al_map_rgb(255, 255, 255), 600, 600, 0, "Wprowadz nazwe gracza: %s", playerName);
			al_flip_display();
		}
		al_wait_for_event(queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_CHAR) {
			if (event.keyboard.keycode > 0 && event.keyboard.keycode < 37 && playerName.size() < 15)
				playerName += event.keyboard.unichar;
		}
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE && playerName.size() != 0)
				playerName.erase(playerName.end() - 1);
			if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
				if (playerName.size() == 0)
					playerName = "Guest";
				exit = true;
			}
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				playerName = "";
				exit = true;
			}
		}
	}
	return playerName;
}

PlayerName::PlayerName()
{
	background = al_load_bitmap("choose_name_background.png");
}