#include "Magician.h"



Magician::Magician()
{
}


Magician::~Magician()
{
}

int Magician::attacking() // magician attack function
{
	if (Stamina >= 30) // checks to see if the magician can attack
	{
		cout << "------------------------------------------" << endl;
		cout << "You cast a firebolt at the enemy!" << endl;
		cout << "------------------------------------------" << endl;
		Stamina = Stamina - 20;
		system("pause");
		return Attack;

	}
	else
	{
		cout << "------------------------------------------" << endl;
		cout << "You need more stamina to attack the enemy." << endl;		
		cout << "------------------------------------------" << endl;
		system("pause");
		return 0;
	}
}

void Magician::showboat() // magician showboat function
{
	cout << "------------------------------------------" << endl;
	cout << "You cast fireworks from your hands, " << endl;
	cout << "proving you're the best Magician around." << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");
}
