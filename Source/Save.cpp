#include "Save.h"

Save::Save(int score, string playerName, int bullets, int remainingTime)
{
	this->score = score;
	this->playerName = playerName;
	this->bullets = bullets;
	this->remainingTime = remainingTime;
}

Save::Save(int score, string playerName)
{
	this->score = score;
	this->playerName = playerName;
	bullets = 7;
	remainingTime = 90;
}

Save::Save()
{
	score = 0;
	playerName = "";
	bullets = 7;
	remainingTime = 90;
}

void Save::saveToFile()
{
	string filename = "save.txt";
	int i = 0;
	bool exit = false;
	while (!exit) {
		ifstream file(filename);
		if (file.is_open()) {
			i++;
			filename = "save" + to_string(i) + ".txt";
			file.close();
		}
		else
			exit = true;
	}
	ofstream file(filename);
	file << score << endl;
	file << playerName << endl;
	file << bullets << endl;
	file << remainingTime << endl;
}

bool Save::loadFromFile(string filename)
{
	string line;
	ifstream file(filename);
	if (file.is_open())
	{
		getline(file, line);
		score = stoi(line);
		getline(file, line);
		playerName = line;
		getline(file, line);
		bullets = stoi(line);
		getline(file, line);
		remainingTime = stoi(line);
		file.close();
		return true;
	}
	else
		return false;
}