#pragma once
#include <string>
#include <fstream>

using namespace std;

/*!
* \class Save
* \brief Zapis gry
*
* \param score wynik gracza
* \param bullets liczba naboi
* \param remainingTime pozostaly czas gry
* \param playerName nazwa gracza
*/

class Save
{
public:
	int score;
	int bullets;
	int remainingTime;
	string playerName;
	/**
	 * Konstruktor (save gry)
	 *
	 * \param score wynik gracza
	 * \param playerName nazwa gracza
	 * \param bullets liczba naboi
	 * \param remainingTime pozostaly czas gry
	 */
	Save(int score, string playerName, int bullets, int remainingTime);
	/**
	 * Konstruktor (save do rankingu)
	 *
	 * \param score wynik gracza
	 * \param playerName nazwa gracza
	 */
	Save(int score, string playerName);
	/**
	 * Konstruktor domyslny
	 *
	 */
	Save();
	/**
	 * Zapis savea do pliku
	 *
	 */
	void saveToFile();
	/**
	 * Odczyt savea z pliku
	 *
	 * \param filename nazwa pliku
	 * \return true - udalo sie otworzyc plik, false - nie udalo sie otworzyc pliku
	 */
	bool loadFromFile(string filename);
};
