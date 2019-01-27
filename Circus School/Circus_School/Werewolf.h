#pragma once
#include "Enemy.h"
#include "Player.h"
using namespace std;

class Werewolf : public Enemy // sets the werewolf to be a child fo enemy
{
public:
	Werewolf();
	~Werewolf();
	virtual void Special() {}
};

