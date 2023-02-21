#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include "Animation.h"

using namespace std;

/*!
* \class Destroy
* \brief Klasa zarzadzajaca animacjami wybuchu/zniszczenia obiektow
*
* \param bitmaps bitmapy wybuchu
* \param x wspolrzedna x wybuchu
* \param y wspolrzedna y wybuchu
* \param flag flaga sluzaca do przerwania animacji w odpowiednim momencie
* \param scale skala animacji
* \param animation obiekt animacji
*/

class Destroy
{
public:
	vector<ALLEGRO_BITMAP*> bitmaps;
	int x;
	int y;
	bool flag;
	double scale;
	Animation animation;
	/**
	 * Konstruktor
	 *
	 * \param x wspolrzedna x wybuchu
	 * \param y wspolrzedna y wybuchu
	 * \param animation obiekt animacji
	 * \param scale skala animacji
	 */
	Destroy(int x, int y, Animation animation, double scale);
	/**
	 * Wyswietlanie animacji
	 *
	 * \return true - gdy animacja jest wyswietlana, false - gdy animacja sie zakonczyla
	 */
	bool draw();
};
