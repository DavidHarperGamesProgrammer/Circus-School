#include "Player.h"

using namespace std;

Player::Player(string name, int age, int health, int stamina, int attack, int armour)
{
	// setting all statistics for player to be the ones passed in on creation
	Name = name;
	Age = age;
	Health = health;
	Stamina = stamina;
	Attack = attack;
	Armour = armour;
}

Player::~Player()
{
	
}

void Player::Init() // initializes player statistics
{
	// small conversation to collect player Info and set player statistics
	cout << "------------------------------------------" << endl;
	cout << "Hi, what might your name be?" << endl;
	cin >> Name;

	cout << "Awesome, " << Name << ", and what is your age?" << endl;
	cin >> Age;

	if (Age < 150 && Age > 0)
	{
		cout << "okay, " << Age << ", that's pretty old!" << endl;
		Stamina = 100;
		Health = 100;
		
	}

	else // error trap to make sure that the details are not incorrect
	{
		cout << "I'm sorry, those details simply cannot be" << endl;
		cout << "true! Lets start again, being more honest" << endl;
		cout << "this time!" << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		system("cls");
		Init();
	}
	
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");	
}

void Player::Status() // outputs the status of the player
{
	
	cout << "------------------------------------------" << endl;
	cout << "Name: " << Name << endl;
	cout << "Age: " << Age << endl;
	cout << "Health: " << Health << endl;
	cout << "Stamina: " << Stamina << endl;
	cout << "Attack: " << Attack << endl;
	cout << "Armour: " << Armour << endl;
	cout << "------------------------------------------" << endl;
	
}

bool Player::running(Enemy &E) // player run function
{
	if (E.getName() != "Maurice Bleubeau")
	{
		int Chance = rand() % 100 + 1; // creates a random number

		if ((Stamina > 10) && (Enemy::getCount() < 2) && (Chance < 70)) // checks that the player can run
		{
			cout << "------------------------------------------" << endl;
			cout << "You run away from the enemy." << endl;
			cout << "------------------------------------------" << endl;
			Stamina = Stamina - 50;
			system("pause");
			return true;
		}
		else if (Enemy::getCount() > 1) // checks if the run failed due to too many enemies
		{
			cout << "------------------------------------------" << endl;
			cout << "There are too many enemies to run from!" << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			return false;
		}
		else if (Stamina < 10) // check if the run failed due to too little stamina
		{
			cout << "------------------------------------------" << endl;
			cout << "You don't have enough stamina to run away!" << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			return false;
		}
		else // comment for failing by chance
		{
			cout << "------------------------------------------" << endl;
			cout << "You fail to run away!" << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			return false;
		}
	}
	else {
		cout << "------------------------------------------" << endl;
		cout << "You can't run from Maurice!" << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
	}

}

int Player::attacking()
{
	return 0;
}

bool Player::Defend(int Damage) // players defense function
{
	if (Damage > Armour) // checks that the players armour doesn't nullify the attack
	{
		Health = Health - (Damage - Armour);
	}
	if (Health < 1) // checks if the player is dead
	{
		cout << "------------------------------------------" << endl;
		cout << "You have died on the field of battle." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		return true;
	}
	return false;
}

void Player::Rest() // rest function
{
	cout << "------------------------------------------" << endl;
	cout << "You rest a turn and gain 30 stamina." << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	Stamina = Stamina + 30;
	if (Stamina > 100) // if stamina is more than the cap then it equals the cap
	{
		Stamina = 100;
	}
}
