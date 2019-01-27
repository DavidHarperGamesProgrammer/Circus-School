#pragma once

#include "Player.h"
#include "Areas.h"
#include "Inventory.h"
#include "Juggler.h"
#include "TightropeWalker.h"
#include "Magician.h"


using namespace std;

class Game
{
public:
	Game();
	~Game();

	// creating class types
	Player* player;
	Areas area;

	// game funcitons
	void Menu();
	void Play();
	void Quit();
	void Options();
	void playerCreation();
	void showTimetable();
	
private:
	// booleans for game
	bool running;
	bool fighting;
};

