#pragma once
#include "Player.h"

class Magician : public Player // makes the magician a child of player
{
public:
	Magician();
	~Magician();

	// magician functions
	virtual int attacking();
	void showboat();
};

