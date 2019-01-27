#include "TightropeWalker.h"



TightropeWalker::TightropeWalker()
{
}


TightropeWalker::~TightropeWalker()
{
}

int TightropeWalker::attacking() // tight rope walker attack
{
	if (Stamina >= 30) // checks if you can attack
	{
		cout << "------------------------------------------" << endl;
		cout << "You use your balance and agility to throw " << endl;
		cout << "three punches and kicks at the enemy." << endl;
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

void TightropeWalker::showboat() // player showboat
{
	cout << "------------------------------------------" << endl;
	cout << "You do the perfect back flip, proving " << endl;
	cout << "you're the best tight-rope walker around." << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");
}
