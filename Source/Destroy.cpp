#include "Destroy.h"
#include "Engine.h"
#include <iostream>

Destroy::Destroy(int x, int y, Animation animation, double scale)
{
	this->x = x;
	this->y = y;
	this->animation = animation;
	this->scale = scale;
	flag = 0;
}

bool Destroy::draw()
{
	if (flag == 0 && animation.i > 0)
		flag = 1;
	if (flag == 1 && animation.i == 0)
		return false;
	else {
		animation.animate(x, y, scale);
		return true;
	}
}