#include "Juggler.h"



Juggler::Juggler()
{
}


Juggler::~Juggler()
{
}

int Juggler::attacking() // juggler attack function
{
	if (Stamina >= 30) // checks if the juggler can attack
	{
		cout << "------------------------------------------" << endl;
		cout << "You throw one of your juggling daggers at" << endl;
		cout << "the enemy!" << endl;
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

void Juggler::showboat() // juggler showboat function
{
	cout << "------------------------------------------" << endl;
	cout << "You juggle three daggers and prove you're" << endl;
	cout << "the best Juggler" << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");
}
