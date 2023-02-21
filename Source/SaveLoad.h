#pragma once
#include "Engine.h"
#include "MenuOption.h"
#include "Menu.h"
#include "Save.h"
#include "Game.h"
#include <vector>
#include <fstream>

using namespace std;

/*!
* \class SaveLoad
* \brief Ekran wczytywania saveow w menu
*
* \param saves kolekcja saveow
* \param background tlo ekranu
* \param options przyciski dla kazdego savea
* \param current aktualnie wybrany przycisk
*/

class SaveLoad
{
public:
	vector<Save> saves;
	ALLEGRO_BITMAP* background;
	vector<MenuOption> options;
	int current;
	/**
	 * Pobierz instacje klasy SaveLoad
	 *
	 * \return obiekt klasy SaveLoad
	 */
	static SaveLoad& getInstance();
	/**
	 * Petla glowna
	 *
	 * \return wybrana opcja (np. powrot do menu po zakonczeniu przegladania saveow)
	 */
	int mainLoop();
	/**
	 * Wczytanie saveow z plikow
	 *
	 */
	void loadSaves();
	/**
	 * Wybor opcji po najechaniu myszka na przycisk
	 *
	 * \return aktualnie wybrany przycisk
	 */
	int menuMouse(int x, int y, vector <MenuOption> bitmaps, int current);
	/**
	 * Destruktor
	 */
	~SaveLoad();
private:
	/**
	 * Konstruktor
	 */
	SaveLoad();
	/**
	 * Instancja klasy SaveLoad
	 */
	static SaveLoad instance;
};
