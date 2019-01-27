#pragma once
#include "Enemy.h"
#include "Player.h"
using namespace std;

class Goblin : public Enemy // makes the goblin a child of enemy
{
public:
	Goblin();
	~Goblin();

	virtual void Special() {}
};

