#include "Inventory.h"
#include "Player.h"


Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

void Inventory::DisplayInv() // draws inventory to screen
{
	int listNumber = 1;
	system("cls");
	cout << "------------------------------------------" << endl;
	cout << "|            PLAYER INVENTORY            |" << endl;
	cout << "------------------------------------------" << endl;
	if (gold.GetAmount() > 0) // checks if player has any gold
	{
		cout << "1 - Gold : " << gold.GetAmount() << endl;
	}
	if (bandage.GetAmount() > 0) // checks if player has any bandages
	{
		cout << "2 - Bandage : " << bandage.GetAmount() << endl;
	}
	if (water.GetAmount() > 0) // checks if the player has any water
	{
		cout << "3 - Water : " << water.GetAmount() << endl;
	}
	cout << "------------------------------------------" << endl;
}

void Inventory::Store(const Items I)
{
	inventory.push_back(I); // enters item into the vector
}

void Inventory::Remove(const Items I)
{
	const int i = inventory.size()-1;
	while (I != inventory.at(i)) // while the item in questions is not in the last slot
	{
		rotate(inventory.begin(), inventory.begin() + 1, inventory.end()); // rotate the first two items to the back
	}
	inventory.pop_back(); // remove the last item in the vector
}

void Inventory::Useitem(Player* P)
{
	int choice = 0;
	P->playerInv->DisplayInv(); // display the inventory
	cout << "------------------------------------------" << endl;
	cout << "What would you like to use?" << endl;
	cout << "------------------------------------------" << endl;
	cin >> choice;
	if ((choice > 0) && (choice < 4))
	{
		Items *temp = new Items; // create a temporary item
		*temp = inventory.at(choice - 1); // make the temporary item the item of choice
		if (temp->name == gold.name) // checks if the item matches gold 
		{
			cout << "------------------------------------------" << endl;
			cout << "This cannot be used while fighting!" << endl;
			cout << "------------------------------------------" << endl;
		}
		else if (temp->name == bandage.name)  // checks if the item matches bandage
		{
			cout << "------------------------------------------" << endl;
			cout << "You use a bandage to heal your wounds." << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			P->SetHealth(100);

			P->playerInv->bandage.SetAmount(P->playerInv->bandage.GetAmount() - 1); // reduces the amount of bandages by one
			if (P->playerInv->bandage.GetAmount() == 0) // checks if the player has ran out of bandages
			{
				P->playerInv->Remove(bandage); // removes bandages from the vector
			}
		}
		else if (temp->name == water.name) // checks if the item matches water
		{
			cout << "------------------------------------------" << endl;
			cout << "You drink some water to regain stamina." << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			P->playerInv->water.SetAmount((P->playerInv->water.GetAmount() - 1)); // reduces the amount of water by one
			P->SetStamina(100);

			if (P->playerInv->water.GetAmount() == 0) // checks if the player has ran out of water 
			{
				P->playerInv->Remove(water); // removes water form the vector
			}
		}
		else
		{
			cout << "------------------------------------------" << endl;
			cout << "You have wasted a move, rookie!" << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			system("cls");
		}
		delete temp; // deletes the temporary item
	}
	else
	{
		Useitem(P);
	}
	
	
}


