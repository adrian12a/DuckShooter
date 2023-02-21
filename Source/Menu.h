#pragma once
#include "Engine.h"
#include "MenuOption.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>

using namespace std;

/*!
* \class Menu
* \brief Klasa obslugujaca menu
*
* \param current aktualnie wybrana opcja w menu
* \param menu_option kolekcja przyciskow/opcji w menu
* \param background bitmapa tla menu
* \param menuMusic muzyka w menu
* \param clickEffect dzwiek nacisniecia przycisku w menu
*/

class Menu
{
public:
	int current;
	vector <MenuOption> menu_options;
	ALLEGRO_BITMAP* background;
	ALLEGRO_SAMPLE_INSTANCE* menuMusic;
	ALLEGRO_SAMPLE_INSTANCE* clickEffect;
	/**
	 * Pobranie instancji klasy Menu
	 *
	 * \return obiekt klasy Menu
	 */
	static Menu& getInstance();
	/**
	 * Petla glowna
	 *
	 * \return wybrana opcja
	 */
	int mainLoop();
	/**
	 * Wyswietlenie menu
	 *
	 * \param bitmaps kolekcja obiektow przyciskow/opcji w menu
	 */
	void showMenu(vector <MenuOption> bitmaps);
	/**
	 * Zmiana opcji po nacisnieciu strzalki w gore
	 *
	 * \param bitmaps kolekcja obiektow przyciskow/opcji w menu
	 * \param current aktualnie wybrana opcja
	 * \return wybrana opcja
	 */
	int menuUp(vector <MenuOption> bitmaps, int current);
	/**
	 * Zmiana opcji po nacisnieciu strzalki w dol
	 *
	 * \param bitmaps kolekcja obiektow przyciskow/opcji w menu
	 * \param current aktualnie wybrana opcja
	 * \return wybrana opcja
	 */
	int menuDown(vector <MenuOption> bitmaps, int current);
	/**
	 * Zmiana opcji po najechaniu na nia kursorem myszki
	 *
	 * \param x wspolrzedna x kursora myszki
	 * \param y wspolrzedna y kursora myszki
	 * \param bitmaps kolekcja obiektow przyciskow/opcji w menu
	 * \param current aktualnie wybrana opcja
	 * \return wybrana opcja
	 */
	int menuMouse(int x, int y, vector <MenuOption> bitmaps, int current);
	/**
	 * Kolizja pomiedzy przyciskiem a kursorem myszki
	 *
	 * \param bitmap bitmapa przycisku/opcji w menu
	 * \param x1 wspolrzedna x przycisku/opcji w menu
	 * \param y1 wspolrzedna x przycisku/opcji w menu
	 * \param x2 wspolrzedna x kursora myszki
	 * \param y2 wspolrzedna y kursora myszki
	 * \return true - kolizja wystapila, false - kolizja nie wystapila
	 */
	bool collision(ALLEGRO_BITMAP* bitmap, double x1, double y1, double x2, double y2);
	/**
	 * Destruktor
	 *
	 */
	~Menu();
private:
	/**
	 * Konstruktor
	 *
	 */
	Menu();
	/**
	 * Instancja klasy Menu
	 */
	static Menu instance;
};
