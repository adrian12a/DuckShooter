#include "Menu.h"
#include "MenuOption.h"
#include "Engine.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

Menu Menu::instance = Menu();

Menu& Menu::getInstance() {
	return instance;
}

Menu::Menu() {
	background = al_load_bitmap("menu_background.png");
	menu_options.push_back(MenuOption("menu_1_a.png", "menu_1_u.png", Engine::getInstance().width / 2 - 95, 500));
	menu_options.push_back(MenuOption("menu_2_a.png", "menu_2_u.png", Engine::getInstance().width / 2 - 95, 600));
	menu_options.push_back(MenuOption("menu_3_a.png", "menu_3_u.png", Engine::getInstance().width / 2 - 95, 700));
	menu_options.push_back(MenuOption("menu_4_a.png", "menu_4_u.png", Engine::getInstance().width / 2 - 95, 800));
	menu_options.push_back(MenuOption("menu_5_a.png", "menu_5_u.png", Engine::getInstance().width / 2 - 95, 900));
	current = -1;

	al_reserve_samples(2);
	menuMusic = al_create_sample_instance(al_load_sample("menuMusic.ogg"));
	al_set_sample_instance_playmode(menuMusic, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(menuMusic, al_get_default_mixer());
	al_set_sample_instance_gain(menuMusic, 0.1);
	al_play_sample_instance(menuMusic);

	clickEffect = al_create_sample_instance(al_load_sample("clickButton.ogg"));
	al_set_sample_instance_playmode(clickEffect, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(clickEffect, al_get_default_mixer());
}

Menu::~Menu() {
	al_destroy_bitmap(background);
	al_destroy_sample_instance(menuMusic);
	al_destroy_sample_instance(clickEffect);
}

void Menu::showMenu(vector <MenuOption> bitmaps)
{
	int size = bitmaps.size();
	for (int i = 0; i < size; i++)
		al_draw_bitmap(bitmaps[i].inactive, bitmaps[i].x, bitmaps[i].y, 0);
	al_flip_display();
}

int Menu::menuUp(vector <MenuOption> bitmaps, int current)
{
	if (current == -1)
		current = 0;
	else {
		al_draw_bitmap(bitmaps[current].inactive, bitmaps[current].x, bitmaps[current].y, 0);
		if (current == 0)
			current = bitmaps.size() - 1;
		else
			current--;
	}
	al_draw_bitmap(bitmaps[current].active, bitmaps[current].x, bitmaps[current].y, 0);
	al_flip_display();
	return current;
}

int Menu::menuDown(vector <MenuOption> bitmaps, int current)
{
	if (current == -1)
		current = 0;
	else {
		al_draw_bitmap(bitmaps[current].inactive, bitmaps[current].x, bitmaps[current].y, 0);
		if (current == bitmaps.size() - 1)
			current = 0;
		else
			current++;
	}
	al_draw_bitmap(bitmaps[current].active, bitmaps[current].x, bitmaps[current].y, 0);
	al_flip_display();
	return current;
}

int Menu::menuMouse(int x, int y, vector <MenuOption> bitmaps, int current)
{
	int size = bitmaps.size();
	for (int i = 0; i < size; i++) {
		if (collision(bitmaps[i].inactive, bitmaps[i].x, bitmaps[i].y, x, y)) {
			al_draw_bitmap(bitmaps[i].active, bitmaps[i].x, bitmaps[i].y, 0);
			current = i;
		}
		else
			al_draw_bitmap(bitmaps[i].inactive, bitmaps[i].x, bitmaps[i].y, 0);
		al_flip_display();
	}

	return current;
}

bool Menu::collision(ALLEGRO_BITMAP* bitmap, double x1, double y1, double x2, double y2)
{
	int w = al_get_bitmap_width(bitmap);
	int h = al_get_bitmap_height(bitmap);
	if (x2 > x1 && x2 < x1 + w && y2  > y1 && y2 < y1 + h)
		return true;
	else
		return false;
}

int Menu::mainLoop() {
	bool exit = false;
	current = -1;
	ALLEGRO_EVENT_QUEUE* queue = Engine::getInstance().queue;
	ALLEGRO_EVENT event = Engine::getInstance().event;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(background, 0, 0, 0);
	showMenu(menu_options);
	while (!exit) {
		al_wait_for_event(queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				exit = true;
				current = 4;
				break;
			case ALLEGRO_KEY_UP:
				current = menuUp(menu_options, current);
				break;
			case ALLEGRO_KEY_DOWN:
				current = menuDown(menu_options, current);
				break;
			case ALLEGRO_KEY_ENTER:
				if (current >= 0)
					exit = true;
				break;
			}
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
			current = menuMouse(event.mouse.x, event.mouse.y, menu_options, current);
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (event.mouse.button & 1 && current >= 0)
				exit = true;
		}
	}
	al_play_sample_instance(clickEffect);
	return current;
}