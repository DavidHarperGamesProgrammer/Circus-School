#include "Troll.h"



Troll::Troll() // sets the trolls stats
{
	Name = "Troll";
	Health = 150;
	Attack = 10;
	Stamina = 150;
	EnemyCount++;
}


Troll::~Troll()
{
}

void Troll::Special(Player &P) // sets the trolls special ability
{
	int Chance = rand() % 100 + 1; // generates a random number
	if (Chance > 50) // checks to see that the abilty succeeds
	{
		cout << "------------------------------------------" << endl;
		cout << "The Troll used it's special ability" << endl;
		cout << "and it sucks five stamina from you." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		P.SetStamina(P.GetStamina() - 5);
	}
}
