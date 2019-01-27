#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Ork.h"
#include "ArmlessGoblin.h"
#include "Werewolf.h"
#include "Troll.h"
#include "Lich.h"
#include "MauriceBleubeau.h"

class Areas
{
public:
	Areas();
	~Areas();

	// functions for fighting
	void Encounter(Player &P, Enemy &E);
	void PlayerTurn(Player &P, Enemy &E);
	void EnemyTurn(Player &P, Enemy &E);

	// fucntions for each area that you visit
	void Training(Player &P);
	void lessonDexterity(Player &P);
	void lessonStrength(Player &P);
	void lessonHealing(Player &P);
	void lessonProtection(Player &P);
	void lessonFitness(Player &P);
	void Graduation(Player &P);
	void Gym(Player &P);
	void Canteen(Player &P);
	void Shop(Player &P);
	void Explore(Player &P);
	

private:
	// private counters and boolean checks
	bool fighting;
	bool lunch;
	int GymCount;
};

