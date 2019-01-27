#include "Enemy.h"
#include "Player.h"

int Enemy::EnemyCount = 0;

Enemy::Enemy()
{
	
}

Enemy::Enemy(const Enemy & CopyEnemy) // copy constructor for the enemy
{
	cout << "Enemy Copied" << endl;
	Name = CopyEnemy.Name;
	Health = CopyEnemy.Health;
	Stamina = CopyEnemy.Stamina;
	EnemyCount++;
	
}

Enemy & Enemy::operator=(const Enemy & CopyEnemy) // assignment operator for the enemy
{
	if (this != &CopyEnemy)
	{
		cout << "Enemy assigned" << endl;
		Name = CopyEnemy.Name;		
		Health = CopyEnemy.Health;
		Stamina = CopyEnemy.Stamina;
	}
	return *this;
}

Enemy::~Enemy() // destructor that lowers the enemy count
{
	EnemyCount--;
}

void Enemy::Status() // displays the status of the enemy
{
	cout << "------------------------------------------" << endl;
	cout << "Name: " << Name << endl;
	cout << "Health: " << Health << endl;
	cout << "Stamina: " << Stamina << endl;
	cout << "------------------------------------------" << endl;

}

int Enemy::attack() // the enemies attack 
{
	int Chance = rand() % 100 + 1; // gets a random number between 1 and 100
	
	if (Chance > 40 && Stamina > 30) // checks to see if the enemy can attack
	{
		cout << "------------------------------------------" << endl;
		cout << "The " << Name << " attacks you doing " << Attack << "\ndamage." << endl;
		cout << "------------------------------------------" << endl;
		Stamina = Stamina - 20;
		return Attack; // returns the attack so that the player can defend against it
	}
	else
	{
		cout << "------------------------------------------" << endl;
		cout << "The " << Name << " failed to attack" << endl;
		cout << "------------------------------------------" << endl;
		return 0;
	}
}

void Enemy::heal() // the enemies heal ability
{
	int Chance = rand() % 100 + 1; // gets a random number between 1 and 100
	
	if (Chance > 85) // checks to see if the enemy heals themselves
	{
		Health = Health + 10; 
		Stamina = 100;
		cout << "------------------------------------------" << endl;
		cout << "The " << Name << " healed itself by 10 " << endl;
		cout << "health." << endl;
		cout << "------------------------------------------" << endl;
	}
	else
	{
		cout << "------------------------------------------" << endl;
		cout << "The " << Name << " failed to heal itself" << endl;
		cout << "------------------------------------------" << endl;
	}
}

void Enemy::Drops(Player &P) // generates the gold drop when defeating an enemy
{
	int Random = rand() % 15 + 1; // gets a random number between 1 and 100
	system("cls");
	cout << "------------------------------------------" << endl;
	cout << "The enemy dropped " << Random << " gold" << endl;
	cout << "------------------------------------------" << endl;
	system("pause"); 
	P.playerInv->gold.SetAmount(P.playerInv->gold.GetAmount() + Random); // updates the players inventory to receive the dropped gold

}


bool Enemy::defend(int Damage) // the enemies defend function
{
	Health = Health - Damage;
	if (Health < 1) // checks to see if the enemy is dead
	{
		cout << "------------------------------------------" << endl;
		cout << "You have killed the " << Name << "." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		return true; // returns that the player is dead
	}
	return false; // returns that the player is not dead
}

void Enemy::Special(Player &P) // the enemies special ability 
{
}
