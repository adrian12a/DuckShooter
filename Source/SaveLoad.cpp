#include "SaveLoad.h"

using namespace std;

SaveLoad SaveLoad::instance = SaveLoad();

SaveLoad& SaveLoad::getInstance()
{
	return instance;
}

void SaveLoad::loadSaves()
{
	while (!saves.empty())
		saves.pop_back();
	string filename = "save.txt";
	bool exit = false;
	int i = 0;
	while (!exit) {
		Save save = Save();
		if (save.loadFromFile(filename)) {
			saves.push_back(save);
			i++;
			filename = "save" + to_string(i) + ".txt";
		}
		else
			exit = true;
	}
}

int SaveLoad::mainLoop()
{
	while (!options.empty())
		options.pop_back();
	loadSaves();
	current = -1;
	bool exit = false;
	ALLEGRO_EVENT_QUEUE* queue = Engine::getInstance().queue;
	ALLEGRO_EVENT event = Engine::getInstance().event;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(background, 0, 0, 0);
	int size = 5;
	if (saves.size() < 5)
		size = saves.size();
	for (int i = 0; i < size; i++) {
		options.push_back(MenuOption("button_background_a.png", "button_background_u.png", 850, 250 + i * 100));
		al_draw_bitmap(options[i].inactive, options[i].x, options[i].y, 0);
	}
	for (int i = 0; i < size; i++)
		al_draw_textf(Engine::getInstance().text_font, al_map_rgb(255, 255, 255), 855, 265 + (size - i - 1) * 100, 0, "Zapis nr %d: %d pkt", i + 1, saves[i].score);
	options.push_back(MenuOption("back_a.png", "back_u.png", 850, 750));
	al_draw_bitmap(options.back().inactive, options.back().x, options.back().y, 0);
	al_flip_display();
	while (!exit) {
		al_wait_for_event(queue, &event);
		if (event.type == ALLEGRO_EVENT_KEY_DOWN)
			switch (event.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				exit = true;
				current = options.size() - 1;
				break;
			case ALLEGRO_KEY_UP:
				current = Menu::getInstance().menuUp(options, current);
				if (options.size() > 1) {
					if (current == options.size() - 1)
						al_draw_textf(Engine::getInstance().text_font, al_map_rgb(255, 255, 255), 855, 265, 0, "Zapis nr %d: %d pkt", size, saves[size - 1].score);
					if (current < options.size() - 2)
						al_draw_textf(Engine::getInstance().text_font, al_map_rgb(255, 255, 255), 855, 265 + (current + 1) * 100, 0, "Zapis nr %d: %d pkt", size - current - 1, saves[size - current - 2].score);
					if (current < options.size() - 1)
						al_draw_textf(Engine::getInstance().text_font, al_map_rgb(255, 255, 255), 855, 265 + current * 100, 0, "Zapis nr %d: %d pkt", size - current, saves[size - current - 1].score);
				}
				break;
			case ALLEGRO_KEY_DOWN:
				current = Menu::getInstance().menuDown(options, current);
				if (options.size() > 1) {
					if (current > 0)
						al_draw_textf(Engine::getInstance().text_font, al_map_rgb(255, 255, 255), 855, 265 + (current - 1) * 100, 0, "Zapis nr %d: %d pkt", size - current + 1, saves[size - current].score);
					if (current < options.size() - 1)
						al_draw_textf(Engine::getInstance().text_font, al_map_rgb(255, 255, 255), 855, 265 + current * 100, 0, "Zapis nr %d: %d pkt", size - current, saves[size - current - 1].score);
				}
				break;
			case ALLEGRO_KEY_ENTER:
				if (current >= 0)
					exit = true;
				break;
			}
		if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
			current = menuMouse(event.mouse.x, event.mouse.y, options, current);
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (event.mouse.button & 1 && current >= 0)
				exit = true;
		}
		al_flip_display();
	}
	if (current != options.size() - 1) {
		Game::getInstance().loadGame(saves[options.size() - current - 2].score, saves[options.size() - current - 2].playerName, saves[options.size() - current - 2].bullets, saves[options.size() - current - 2].remainingTime);
		Game::getInstance().mainLoop();
	}
	al_play_sample_instance(Menu::getInstance().clickEffect);
	return 4;
}

int SaveLoad::menuMouse(int x, int y, vector <MenuOption> bitmaps, int current)
{
	int savesSize = 5;
	if (saves.size() < 5)
		savesSize = saves.size();
	int size = bitmaps.size();
	for (int i = 0; i < size; i++) {
		if (Menu::getInstance().collision(bitmaps[i].inactive, bitmaps[i].x, bitmaps[i].y, x, y)) {
			al_draw_bitmap(bitmaps[i].active, bitmaps[i].x, bitmaps[i].y, 0);
			current = i;
		}
		else
			al_draw_bitmap(bitmaps[i].inactive, bitmaps[i].x, bitmaps[i].y, 0);
	}
	for (int j = 0; j < savesSize; j++)
		al_draw_textf(Engine::getInstance().text_font, al_map_rgb(255, 255, 255), 855, 265 + (savesSize - j - 1) * 100, 0, "Zapis nr %d: %d pkt", j + 1, saves[j].score);
	return current;
}

SaveLoad::SaveLoad() {
	background = al_load_bitmap("saveload_background.png");
	current = -1;
}

SaveLoad::~SaveLoad() {
	al_destroy_bitmap(background);
}