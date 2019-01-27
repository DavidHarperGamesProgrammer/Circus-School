#pragma once
#include "Player.h"

class Juggler : public Player // makes juggler a child of player
{
public:
	Juggler();
	~Juggler();

	// juggler functions
	virtual int attacking();
	void showboat();
};

