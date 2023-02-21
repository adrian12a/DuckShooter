#pragma once
#include "Engine.h"
#include <iostream>

using namespace std;

/*!
* \class PlayerName
* \brief Ekran wyboru nazwy gracza
*
* \param background tlo
*/

class PlayerName
{
public:
	ALLEGRO_BITMAP* background;
	/**
	 * Pobranie instancji klasy PlayerName
	 *
	 * \return obiekt klasy PlayerName
	 */
	static PlayerName& getInstance();
	/**
	 * Petla glowna
	 *
	 * \return nazwa gracza
	 */
	string mainLoop();
private:
	/**
	 * Konstruktor
	 *
	 */
	PlayerName();
	/**
	 * Instancja klasy PlayerName
	 */
	static PlayerName instance;
};
