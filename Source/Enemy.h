#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Animation.h"
#include <vector>

using namespace std;

/*!
* \class Enemy
* \brief Klasa przechowujaca obiekty wrogow
*
* \param scale skala wroga
* \param direction kierunek w ktorym porusza sie wrog
* \param x wspolrzedna x wroga
* \param y wspolrzedna y wroga
* \param type typ wroga
* \param animation obiekt animacji wroga
*/

enum Type {
	NORMAL, SPECIAL
};

class Enemy
{
public:
	double scale;
	int direction;
	int x;
	int y;
	Type type;
	Animation animation;
	/**
	 * Konstruktor
	 *
	 * \param direction kierunek poruszania sie
	 * \param type typ wroga
	 * \param animation obiekt animacji wroga
	 */
	Enemy(int direction, Animation animation, Type type);
	/**
	 * Wyswietlenie wroga
	 *
	 * \param x wspolrzedna x wroga
	 * \param y wspolrzedna y wroga
	 */
	void draw(int x, int y);
	/**
	 * pobranie wyniku jaki gracz uzyskal podczas gry
	 *
	 * \return wynik gracza
	 */
	int score();
};
