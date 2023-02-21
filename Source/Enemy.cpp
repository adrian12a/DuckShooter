#include "Enemy.h"
#include "Animation.h"
#include "Engine.h"

Enemy::Enemy(int direction, Animation animation, Type type) {
	this->direction = direction;
	this->type = type;
	this->animation = animation;
	scale = (50 + rand() % 80) * 0.01;
	y = 150 + rand() % (Engine::getInstance().height - 350);
	if (direction)
		x = -1 * (al_get_bitmap_width(animation.bitmap[0])) - rand() % 400;
	else
		x = Engine::getInstance().width + al_get_bitmap_width(animation.bitmap[0]) + rand() % 400;
}

void Enemy::draw(int x, int y) {
	this->x = x;
	this->y = y;
	animation.animate(x, y, scale);
}

int Enemy::score() {
	if (type == SPECIAL)
		return 30;
	else
		return 10;
}