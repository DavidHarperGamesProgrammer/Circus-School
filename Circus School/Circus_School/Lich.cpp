#include "Lich.h"



Lich::Lich() // sets the stats of the lich
{
	Name = "Lich";
	Health = 100;
	Attack = 15;
	Stamina = 150;
	EnemyCount++;
}


Lich::~Lich()
{
}

void Lich::Special(Player & P) // the lich special ability
{
	int Chance = rand() % 100 + 1; // creates a random number
	if (Chance > 50) // checks to see if the ability succeeds
	{
		cout << "------------------------------------------" << endl;
		cout << "The Lich used it's special ability" << endl;
		cout << "and it's attack has risen by one." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		Attack = Attack + 1;
	}
}
