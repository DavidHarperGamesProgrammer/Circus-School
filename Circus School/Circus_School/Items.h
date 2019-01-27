#pragma once
#include <string>
using namespace std;

class Items
{
public:
	Items();
	~Items();

	// public stats
	string name;

	// getters and setter
	int GetCost() const { return cost; }
	int GetAmount() const { return amount; }
	void SetCost(int C) { cost = C; }
	void SetAmount(int A) { amount = A; }

	// predecleration of overloaded operator
	friend bool operator!= (const Items &c1, const Items &c2);

	

private:
	//private stats
	int cost;
	int amount;

};


