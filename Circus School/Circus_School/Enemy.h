#pragma once
#include <string>

using namespace std;

class Player; // declaring Player as a class

class Enemy
{
public:
	Enemy();
	Enemy(const Enemy& CopyEnemy);
	Enemy& operator=(const Enemy& CopyEnemy);
	~Enemy();

	// functions for general game play
	void Status();

	// functions for battles
	int attack();
	void heal();
	void Drops(Player &P);
	bool defend(int Damage);
	virtual void Special(Player &P);
	bool dead = false;

	// getter functions
	static int getCount() { return EnemyCount; }
	string getName() const { return Name; }
	
	
protected:
	// protected stats
	int Health;
	int Attack;
	int Stamina;
	string Name;

	// enemy count to measure how many enemies are currently constructed in the game
	static int EnemyCount;
};

