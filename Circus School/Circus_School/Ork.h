#pragma once
#include "Enemy.h"
#include "Player.h"
using namespace std;

class Ork : public Enemy // makes the ork a child of enemy
{
public:
	Ork();
	~Ork();
	virtual void Special() {}
};

