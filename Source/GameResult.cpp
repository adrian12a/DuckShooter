#include "GameResult.h"

GameResult GameResult::instance = GameResult();

GameResult& GameResult::getInstance() {
	return instance;
}

GameResult::~GameResult()
{
	al_destroy_bitmap(background);
}

GameResult::GameResult() {
	background = al_load_bitmap("gameresult_background.png");
	back = MenuOption("back_to_menu_a.png", "back_to_menu_u.png", 850, 700);
}

void GameResult::mainLoop(int score)
{
	bool exit = false;
	ALLEGRO_EVENT_QUEUE* queue = Engine::getInstance().queue;
	ALLEGRO_EVENT event = Engine::getInstance().event;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(background, 0, 0, 0);
	al_draw_bitmap(back.inactive, back.x, back.y, 0);
	al_draw_textf(Engine::getInstance().big_font, al_map_rgb(0, 0, 0), 700, 600, 0, "Uzyskany wynik: %d pkt", score);
	al_flip_display();
	while (!exit) {
		al_wait_for_event(queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE || event.keyboard.keycode == ALLEGRO_KEY_ENTER)
				exit = true;
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
			if (Menu::getInstance().collision(back.inactive, back.x, back.y, event.mouse.x, event.mouse.y))
				al_draw_bitmap(back.active, back.x, back.y, 0);
			else
				al_draw_bitmap(back.inactive, back.x, back.y, 0);
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.button & 1)
			if (Menu::getInstance().collision(back.inactive, back.x, back.y, event.mouse.x, event.mouse.y))
				exit = true;
		al_flip_display();
	}
}