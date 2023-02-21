#pragma once
#include "MenuOption.h"
#include "Engine.h"
#include "Save.h"
#include "Menu.h"
#include <string>
#include <vector>

using namespace std;

/*!
* \class Ranking
* \brief Wyswietlanie i tworzenie rankingu
*
* \param saves lista saveow uzywana do tworzenia rankingu
* \param background tlo rankingu
* \param back przycisk powrotu do menu
*/

class Ranking
{
public:
	vector<Save> saves;
	ALLEGRO_BITMAP* background;
	MenuOption back;
	/**
	 * Pobranie instancji klasy Ranking
	 *
	 * \return obiekt klasy Ranking
	 */
	static Ranking& getInstance();
	/**
	 * Petla glowna
	 *
	 * \return wybrana opcja (np. powrot do menu po zakonczeniu przegladania rankingu)
	 */
	int mainLoop();
	/**
	 * Sortowanie saveow
	 *
	 */
	void sort();
	/**
	 * Dodawanie nowego savea
	 *
	 * \param save obiekt klasy Save
	 */
	void addSave(Save save);
	/**
	 * Destruktor
	 *
	 */
	~Ranking();
	/**
	 * Ladowanie rankingu z pliku
	 *
	 */
	void loadFromFile();
	/**
	 * Zapisywanie rankingu do pliku
	 *
	 */
	void saveToFile();
private:
	/**
	 * Konstruktor
	 *
	 */
	Ranking();
	/**
	 * Instancja klasy Ranking
	 */
	static Ranking instance;
};
