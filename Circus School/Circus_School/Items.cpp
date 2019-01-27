#include "Items.h"



Items::Items()
{
}


Items::~Items()
{
}


bool operator!= (const Items &c1, const Items &c2) // overloads the not equal too operator to allow comparison of items
{
	return !(c1.name == c2.name);
}