#pragma once
#include "Enemy.h"
#include "Player.h"
using namespace std;

class Lich : public Enemy // makes the lich a child of enemy
{
public:
	Lich();
	~Lich();
	virtual void Special(Player &P);  // overrides the special ability for the lich
};

