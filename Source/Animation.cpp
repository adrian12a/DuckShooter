#include "Animation.h"

Animation::Animation()
{
	waiter = 0.0;
	seconds = 0.0;
	i = 0;
}

Animation::Animation(double seconds)
{
	this->seconds = seconds;
	waiter = 0.0;
	i = 0;
}

void Animation::addBitmap(const char* filename)
{
	bitmap.push_back(al_load_bitmap(filename));
}

void Animation::animate(int x, int y)
{
	al_draw_bitmap(bitmap[i], x, y, 0);
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
}

void Animation::animate(int x, int y, double scale)
{
	al_draw_scaled_bitmap(bitmap[i], 0, 0, al_get_bitmap_width(bitmap[i]), al_get_bitmap_height(bitmap[i]), x, y, al_get_bitmap_width(bitmap[i]) * scale, al_get_bitmap_height(bitmap[i]) * scale, 0);
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
}