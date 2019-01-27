#pragma once
#include "Enemy.h"
//#include <iostream>
//#include <string>
#include "Player.h"
using namespace std;

class ArmlessGoblin : public Enemy  // making armless goblin child of Enemy
{
public:
	ArmlessGoblin();
	~ArmlessGoblin();

	virtual void Special() {}
};

