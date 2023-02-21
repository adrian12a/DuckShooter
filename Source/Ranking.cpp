#include "Ranking.h"

using namespace std;

Ranking Ranking::instance = Ranking();

Ranking& Ranking::getInstance() {
	return instance;
}

Ranking::Ranking() {
	background = al_load_bitmap("ranking_background.png");
	back = MenuOption("back_a.png", "back_u.png", 850, 700);
}

Ranking::~Ranking() {
	al_destroy_bitmap(background);
}

void Ranking::loadFromFile() {
	while (!saves.empty())
		saves.pop_back();
	string line;
	ifstream file("ranking.txt");
	if (file.is_open())
	{
		while (getline(file, line)) {
			int score = stoi(line);
			getline(file, line);
			string playerName = line;
			saves.push_back(Save(score, playerName));
		}
	}
}

void Ranking::saveToFile() {
	ofstream file("ranking.txt");
	for (int i = 0; i < saves.size(); i++) {
		file << saves[i].score << endl;
		file << saves[i].playerName << endl;
	}
}

int Ranking::mainLoop() {
	loadFromFile();
	bool exit = false;
	ALLEGRO_EVENT_QUEUE* queue = Engine::getInstance().queue;
	ALLEGRO_EVENT event = Engine::getInstance().event;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(background, 0, 0, 0);
	al_draw_bitmap(back.inactive, back.x, back.y, 0);
	int size = 5;
	if (saves.size() < 5)
		size = saves.size();
	for (int i = 0; i < size; i++)
		al_draw_textf(Engine::getInstance().text_font, al_map_rgb(255, 255, 255), 855, 350 + i * 75, 0, "Miejsce %d: %s %d pkt", i + 1, saves[i].playerName, saves[i].score);
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
	al_play_sample_instance(Menu::getInstance().clickEffect);
	return 4;
}

void Ranking::sort()
{
	for (int i = 0; i < saves.size(); i++)
		for (int j = 1; j < saves.size() - i; j++)
			if (saves[j - 1].score < saves[j].score)
				swap(saves[j - 1], saves[j]);
}

void Ranking::addSave(Save save)
{
	loadFromFile();
	saves.push_back(save);
	sort();
	saveToFile();
}