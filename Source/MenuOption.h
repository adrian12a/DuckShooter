#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

/*!
* \class MenuOption
* \brief Klasa zawierajaca obiekty przyciskow w menu
*
* \param active bitmapa - przycisk aktywny
* \param inactive bitmapa - przycisk nieaktywny
* \param x wspolrzedna x przycisku
* \param y wspolrzedna y przycisku
*/

class MenuOption {
public:
	/**
	 * Konstruktor
	 *
	 * \param bitmap_active nazwa pliku z bitmapa aktywnego przycisku
	 * \param bitmap_inactive nazwa pliku zbitmapa nieaktywnego przycisku
	 * \param x wspolrzedna x przycisku
	 * \param y wspolrzedna y przycisku
	 */
	MenuOption(const char* bitmap_active, const char* bitmap_inactive, int x, int y);
	/**
	 * Konstruktor domyslny
	 *
	 */
	MenuOption();
	ALLEGRO_BITMAP* active;
	ALLEGRO_BITMAP* inactive;
	int x;
	int y;
};
