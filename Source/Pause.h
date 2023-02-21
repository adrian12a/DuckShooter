#pragma once
#include "MenuOption.h"
#include "Menu.h"
#include <vector>

/*!
* \class Pause
* \brief Klasa obslugujaca menu pauzy
*
* \param current aktualnie wybrana opcja w menu
* \param background bitmapa tla menu
* \param menu_option kolekcja przyciskow/opcji w menu
*/

class Pause
{
public:
	int current;
	ALLEGRO_BITMAP* background;
	vector <MenuOption> menu_options;
	/**
	 * Pobranie instancji klasy Pause
	 *
	 * \return obiekt klasy Pause
	 */
	static Pause& getInstance();
	/**
	 * Petla glowna
	 *
	 * \return wybrana opcja w menu
	 */
	int mainLoop();
	/**
	 * Destruktor
	 *
	 */
	~Pause();
private:
	/**
	 * Konstruktor
	 *
	 */
	Pause();
	/**
	 * Instancja klasy Pause
	 */
	static Pause instance;
};
