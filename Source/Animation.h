#pragma once
#include "Engine.h"
#include <vector>

using namespace std;

/*!
* \class Animation
* \brief Klasa generujaca animacje
*
* \param waiter zmienna pomocnicza do generowania opoznienia miedzy kolejnymi klatkami animacji
* \param seconds wartosc opoznienia miedzy kolejnymi klatkami animacji liczona w sekundach
* \param i zmienna pomocnicza do generowania opoznienia miedzy kolejnymi klatkami animacji
* \param bitmap kolekcja bitmap modelu wroga
*/

class Animation
{
public:
	double waiter;
	double seconds;
	int i;
	vector<ALLEGRO_BITMAP*> bitmap;
	/**
	 * Konstruktor domyslny
	 *
	 */
	Animation();
	/**
	 * Konstruktor
	 *
	 * \param seconds wartosc opoznienia pomiedzy kolejnymi klatkami animacji
	 */
	Animation(double seconds);
	/**
	 * Dodawanie bitmapy
	 *
	 * \param filename nazwa pliku
	 */
	void addBitmap(const char* filename);
	/**
	 * wyswietlenie animacji
	 *
	 * \param x wspolrzedna x
	 * \param y wspolrzedna y
	 */
	void animate(int x, int y);
	/**
	 * wyswietlanie animacji przeskalowanego obiektu
	 *
	 * \param x wspolrzedna x
	 * \param y wspolrzedna y
	 * \param scale skala obiektu animowanego
	 */
	void animate(int x, int y, double scale);
};
