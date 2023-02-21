#pragma once
#include "Engine.h"
#include "Menu.h"
#include "MenuOption.h"

/*!
* \class GameResult
* \brief Ekran podsumowujacy po zakonczeniu gry
*
* \param background tlo ekranu
* \param back przycisk powrotu do menu
*/

class GameResult
{
public:
	ALLEGRO_BITMAP* background;
	MenuOption back;
	/**
	 * Petla glowna
	 *
	 * \param score wynik gracza
	 */
	void mainLoop(int score);
	/**
	 * Pobranie instancji klasy GameResult
	 *
	 * \return obiekt klasy GameResult
	 */
	static GameResult& getInstance();
	/**
	 * Destruktor
	 *
	 */
	~GameResult();
private:
	/**
	 * Konstruktor
	 *
	 */
	GameResult();
	/**
	 * Instancja klasy GameResult
	 */
	static GameResult instance;
};
