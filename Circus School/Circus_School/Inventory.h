#pragma once

#include <vector>
#include "Items.h"

#include "Gold.h"
#include "Bandage.h"
#include "Water.h"

using namespace std;

class Player; // predeclaration of player class

class Inventory
{
public:
	Inventory();
	~Inventory();

	// inventory functions
	void DisplayInv();
	void Store(Items I);
	void Remove(Items I);
	void Useitem(Player* P);
	
	// inventory items
	Gold gold;
	Bandage bandage;
	Water water;
	Items temp;

private:

	vector<Items> inventory;
};

