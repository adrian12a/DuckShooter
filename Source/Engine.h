#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

/*!
* \class Engine
* \brief Glowna klasa silnika gry
*
* \param width szerokosc ekranu
* \param height wysokosc ekranu
* \param option aktualnie wybrana opcja (np. uruchomienie gry, uruchomienie menu)
* \param fps liczba klatek na sekunde
* \param display ekran
* \param timer timer
* \param queue kolejka
* \param event event
* \param big_font duza czcionka (wielkosc 45)
* \param small_font mala czcionka (wielkosc 15)
* \param text_font czcionka do tekstu na przyciskach (wielkosc 25)
*/

class Engine
{
public:
	int width;
	int height;
	int option;
	int fps;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_EVENT event;
	ALLEGRO_FONT* big_font;
	ALLEGRO_FONT* small_font;
	ALLEGRO_FONT* text_font;
	/**
	 * Pobranie instancji klasy Engine
	 *
	 * \return obiekt klasy Engine
	 */
	static Engine& getInstance();
	/**
	 * Petla glowna
	 *
	 */
	void mainLoop();
	/**
	 * Destruktor
	 *
	 */
	~Engine();
private:
	/**
	 * Konstruktor
	 *
	 * \param width szerokosc ekranu
	 * \param height wysokosc ekranu
	 * \param fullscreen true - uruchomienie aplikacji w trybie pelnoekranowym, false - w oknie
	 * \param fps liczba klatek na sekunde
	 */
	Engine(int width, int height, bool fullscreen, int fps);
	/**
	 * Instancja klasy Engine
	 */
	static Engine instance;
};
