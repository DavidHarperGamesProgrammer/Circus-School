#pragma once
#include "Enemy.h"
#include "Player.h"
using namespace std;

class MauriceBleubeau : public Enemy // makes Maurice a child of enemy
{
public:
	MauriceBleubeau();
	~MauriceBleubeau();

	virtual void Special(Player &P);
};

