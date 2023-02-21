#include "Engine.h"
#include "Menu.h"
#include "Game.h"
#include "Ranking.h"
#include "SaveLoad.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

using namespace std;

Engine Engine::instance = Engine(1920, 1080, true, 60);

Engine& Engine::getInstance() {
	return instance;
}

Engine::Engine(int width, int height, bool fullscreen, int fps) {
	al_init();
	al_init_image_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_init_acodec_addon();
	if (fullscreen)
		al_set_new_display_flags(ALLEGRO_NOFRAME);
	display = al_create_display(width, height);
	this->width = width;
	this->height = height;
	this->fps = fps;
	queue = al_create_event_queue();
	timer = al_create_timer(1.0 / fps);
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);
	option = 4;
	big_font = al_load_ttf_font("ocr.ttf", 45, 0);
	small_font = al_load_ttf_font("ocr.ttf", 15, 0);
	text_font = al_load_ttf_font("textFont.otf", 25, 0);
}

Engine::~Engine() {
	al_stop_timer(timer);
	al_destroy_event_queue(queue);
	al_destroy_font(big_font);
	al_destroy_font(small_font);
}

void Engine::mainLoop() {
	bool exit = false;
	while (!exit) {
		switch (option) {
		case 0:
			Game::getInstance().clearGame();
			option = Game::getInstance().mainLoop();
			break;
		case 1:
			option = Game::getInstance().mainLoop();
			break;
		case 2:
			option = SaveLoad::getInstance().mainLoop();
			break;
		case 3:
			option = Ranking::getInstance().mainLoop();
			break;
		case 4:
			option = Menu::getInstance().mainLoop();
			if (option == 4)
				exit = true;
			break;
		}
	}
}