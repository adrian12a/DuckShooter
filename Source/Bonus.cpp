#include "Bonus.h"
#include <string>

Bonus::Bonus()
{
	y = 0;
	x = 0;
	seconds = 0;
	waiter = 0;
	i = 0;
	speed = 0;
	radius = 0;
	right = 1;
	left = 2;
	direction = right;
	drawBonus = false;
	parachute = NULL;
}

Bonus::Bonus(double seconds, int speed, vector<ALLEGRO_BITMAP*> bitmaps) {
	y = -100 - rand() % 400;
	x = 200 + rand() % 1400;
	this->seconds = seconds;
	this->speed = speed;
	bitmap = bitmaps;
	waiter = 0;
	radius = 0;
	i = 0;
	drawBonus = true;
	right = 1;
	left = 2;
	direction = right;
	string filename = "parachute_" + to_string(1 + rand() % 8) + ".png";
	parachute = al_load_bitmap(filename.c_str());
}

void Bonus::draw() {
	if (drawBonus) {
		animation();
		y += speed;
		if (radius >= 0.15)
			direction = left;
		if (radius <= -0.15)
			direction = right;
		if (direction == right)
			radius += 0.005;
		else
			radius -= 0.005;
		if (y - al_get_bitmap_height(bitmap[0]) - al_get_bitmap_height(parachute) > Engine::getInstance().height)
			drawBonus = false;
	}
}

void Bonus::animation() {
	if (waiter == 0) {
		waiter = al_get_time();
	}
	if (al_get_time() >= waiter + seconds) {
		if (i + 1 < bitmap.size())
			i++;
		else
			i = 0;
		waiter = 0;
	}
	int bonus_w = al_get_bitmap_width(bitmap[i]);
	int bonus_h = al_get_bitmap_height(bitmap[i]);
	int parachute_w = al_get_bitmap_width(parachute);
	int parachute_h = al_get_bitmap_height(parachute);
	al_draw_rotated_bitmap(parachute, parachute_w / 2, parachute_h, x - 10, y, radius, 0);
	al_draw_rotated_bitmap(bitmap[i], bonus_w / 2, 0, x, y, radius, 0);
}