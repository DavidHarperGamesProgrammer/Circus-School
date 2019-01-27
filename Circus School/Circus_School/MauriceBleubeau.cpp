#include "MauriceBleubeau.h"



MauriceBleubeau::MauriceBleubeau() // sets the stats for Maurice Bleubeau
{
	Name = "Maurice Bleubeau";
	Health = 150;
	Attack = 15;
	Stamina = 100;
	EnemyCount++;

}


MauriceBleubeau::~MauriceBleubeau()
{
}

void MauriceBleubeau::Special(Player & P)
{
	int Chance = rand() % 100 + 1; // creates a random number
	if (Chance > 50) // checks to see if the ability succeeds
	{
		cout << "------------------------------------------" << endl;
		cout << "Maurice used his special ability and his" << endl;
		cout << "attack has risen by one aswell as his" << endl;
		cout << "health healing by five." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		Health = Health + 5;
		Attack = Attack + 1;
	}


}
