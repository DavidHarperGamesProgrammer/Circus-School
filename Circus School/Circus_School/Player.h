#pragma once
#include <iostream>
#include <string>
#include "Enemy.h"
#include "Inventory.h"


using namespace std;

class Player
{
public:
	Player(string name = "", int age = 0, int health = 100, int stamina = 100, int attack = 10, int armour = 5);
	~Player();

	// player functions
	void Init();
	void Status();
	bool running(Enemy &E);
	virtual int attacking();
	bool Defend(int Damage);
	void Rest();
	// player inventory creation
	Inventory* playerInv = new Inventory();
	

	// getters and setters
	string getName() const {return Name; }
	void SetHealth(int H) { Health = H; }
	void SetStamina(int S) { Stamina = S; }
	int GetHealth() const { return Health; }
	int GetStamina() const { return Stamina; }

	// death boolean
	bool dead = false;
	

protected:
	// protected stats
	int Age;
	int Health;
	int Stamina;
	int Attack;
	int Armour;
	string Name;
	int Damage;
	

};

