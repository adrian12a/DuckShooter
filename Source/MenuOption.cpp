#include "MenuOption.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

MenuOption::MenuOption(const char* bitmap_active, const char* bitmap_inactive, int x, int y) {
	active = al_load_bitmap(bitmap_active);
	inactive = al_load_bitmap(bitmap_inactive);
	this->x = x;
	this->y = y;
}

MenuOption::MenuOption() {
	active = NULL;
	inactive = NULL;
	x = 0;
	y = 0;
}