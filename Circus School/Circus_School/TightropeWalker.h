#pragma once
#include "player.h"

class TightropeWalker : public Player // makes the tight rope walker a child of Player
{
public:
	TightropeWalker();
	~TightropeWalker();

	// tight rope walker functions
	virtual int attacking();
	void showboat();
};

