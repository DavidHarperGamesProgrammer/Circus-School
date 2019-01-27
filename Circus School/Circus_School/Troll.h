#pragma once
#include "Enemy.h"
#include "Player.h"
using namespace std;

class Troll : public Enemy // sets the troll to be a child of enemy
{
public:
	Troll();
	~Troll();

	virtual void Special(Player &P); // overrides the special function
};

