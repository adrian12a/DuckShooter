#pragma once
#include "Engine.h"
#include <vector>

using namespace std;

/*!
* \class Bonus
* \brief Klasa przechowujaca obiekty bonusow
*
* \param x wspolrzedna x bonusu
* \param y wspolrzedna y bonusu
* \param speed predkosc poruszania sie bonusu
* \param drawBonus zmienna pomocnicza sluzaca do sprawdzenia czy nalezy wyswietlac bonus
* \param waiter zmienna pomocnicza do generowania opoznienia miedzy kolejnymi klatkami animacji
* \param seconds wartosc opoznienia miedzy kolejnymi klatkami animacji liczona w sekundach
* \param radius kat rotacji bonusu
* \param i zmienna pomocnicza do generowania opoznienia miedzy kolejnymi klatkami animacji
* \param direction kierunek rotacji
* \param right kierunek w prawo
* \param left kierunek w lewo
* \param parachute bitmapa spadochronu
* \param bitmap bitmapy bonusu
*/

class Bonus
{
public:
	int x;
	int y;
	int speed;
	bool drawBonus;
	double waiter;
	double seconds;
	double radius;
	int i;
	int direction;
	int right;
	int left;
	ALLEGRO_BITMAP* parachute;
	vector<ALLEGRO_BITMAP*> bitmap;
	/**
	 * Konstruktor domyslny
	 */
	Bonus();
	/**
	 * Konstruktor
	 *
	 * \param seconds wartosc opoznienia miedzy kolejnymi klatkami animacji liczona w sekundach
	 * \param speed predkosc poruszania sie bonusu
	 * \param bitmaps bitmapy bonusu
	 */
	Bonus(double seconds, int speed, vector<ALLEGRO_BITMAP*> bitmaps);
	/**
	 * Wyswietlenie bonusu
	 */
	void draw();
	/**
	 * Wyswietlenie animacji
	 */
	void animation();
};
