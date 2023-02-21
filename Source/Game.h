#pragma once
#include "Enemy.h"
#include "Engine.h"
#include "Destroy.h"
#include "Animation.h"
#include "Bonus.h"
#include <vector>
#include <iostream>

using namespace std;

/*!
* \class Game
* \brief Glowna klasa gry
*
* \param background tlo gry
* \param bullet bitmapa pocisku
* \param crosshair bitmapa celownika
* \param bonus1 kolekcja bitmap bonusu nr 1
* \param bonus2 kolekcja bitmap bonusu nr 2
* \param score wynik
* \param bullets liczba pociskow
* \param counter zmienna pomocnicza do obliczania czasu
* \param remainingTime pozostaly czas
* \param playerName nazwa gracza
* \param e kolekcja obiektow przeciwnikow
* \param dstr kolekcja obiektow wybuchow (np. po zestrzeleniu przeciwnika)
* \param bonus obiekt aktualnego bonusu
* \param gameMusic muzyka w grze
* \param shootEffect odglos strzalu
* \param enemyAnimationLeft kolekcja bitmap przeciwnika (kierunek w lewo)
* \param enemyAnimationLeft kolekcja bitmap przeciwnika (kierunek w prawo)
* \param specialEnemyAnimationLeft kolekcja bitmap specjalnego przeciwnika (kierunek w lewo)
* \param specialEnemyAnimationLeft kolekcja bitmap specjalnego przeciwnika (kierunek w prawo)
* \param enemyAnimationLeft kolekcja bitmap wybuchu
*/

class Game
{
public:
	ALLEGRO_BITMAP* background;
	ALLEGRO_BITMAP* bullet;
	ALLEGRO_BITMAP* crosshair;
	vector<ALLEGRO_BITMAP*> bonus1;
	vector<ALLEGRO_BITMAP*> bonus2;
	int score;
	int bullets;
	int counter;
	int remainingTime;
	string playerName;
	vector<Enemy> e;
	vector<Destroy> dstr;
	Bonus bonus;
	ALLEGRO_SAMPLE_INSTANCE* gameMusic;
	ALLEGRO_SAMPLE_INSTANCE* shootEffect;
	Animation enemyAnimationLeft;
	Animation enemyAnimationRight;
	Animation specialEnemyAnimationLeft;
	Animation specialEnemyAnimationRight;
	Animation explosion;
	/**
	 * Pobranie instancji klasy Game
	 *
	 * \return obiekt klasy Game
	 */
	static Game& getInstance();
	/**
	 * Destruktor
	 *
	 */
	~Game();
	/**
	 * Petla glowna
	 *
	 * \return wybrana opcja (np. powrot do menu po zakonczeniu gry)
	 */
	int mainLoop();
	/**
	 * Zresetowanie rozgrywki, rozpoczecie nowej gry
	 *
	 */
	void clearGame();
	/**
	 * Zaladowanie gry z savea
	 *
	 * \param score wynik gracza
	 * \param playerName nazwa gracza
	 * \param bullets liczba pociskow
	 * \param remainingTime pozostaly czas
	 */
	void loadGame(int score, string playerName, int bullets, int remainingTime);
	/**
	 * Dodanie nowych wrogow
	 *
	 */
	void newEnemies();
	/**
	 * Wyswietlenie elementow interfejsu gry
	 *
	 * \param mouse_x wspolrzedna x kursora myszy
	 * \param mouse_y wspolrzedna y kursora myszy
	 */
	void draw(int mouse_x, int mouse_y);
	/**
	 * Przeladowanie broni
	 *
	 */
	void reload();
	/**
	 * Strzal po wcisnieciu lewego przycisku myszy
	 *
	 * \param x wspolrzedna x kursora myszy
	 * \param y wspolrzedna y kursora myszy
	 */
	void mouseClick(int x, int y);
	/**
	 * Kolizja miedzy kursorem myszy a wrogiem (zestrzelenie wroga)
	 *
	 * \param e obiekt wroga
	 * \param x wspolrzedna x kursora myszy
	 * \param y wspolrzedna y kursora myszy
	 * \return true - kolizja wystapila, false - kolizja nie wystapila
	 */
	bool collision(Enemy e, double x, double y);
	/**
	 * Kolizja miedzy kursorem myszy a bonusem (zestrzlenie bonusu)
	 *
	 * \param b obiekt bonusu
	 * \param x wspolrzedna x kursora myszy
	 * \param y wspolrzedna y kursora myszy
	 * \return true - kolizja wystapila, false - kolizja nie wystapila
	 */
	bool collision(Bonus b, double x, double y);
	/**
	 * Kolizja miedzy wrogami (zapobieganie generowania wrogow jeden na drugim)
	 *
	 * \param e1 obiekt 1 wroga
	 * \param e2 obiekt 2 wroga
	 * \return true - kolizja wystapila, false - kolizja nie wystapila
	 */
	bool collision(Enemy e1, Enemy e2);
	/**
	 *
	 *
	 * \param x
	 * \param y
	 */
private:
	/**
	 * Konstruktor
	 *
	 */
	Game();
	/**
	 * Instancja klasy Game
	 */
	static Game instance;
};
