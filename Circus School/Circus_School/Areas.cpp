#include "Areas.h"



Areas::Areas()
{
	// sets all boolean checks and counters
	fighting = true;
	lunch = false;
	GymCount = 0;
}


Areas::~Areas()
{
}

void Areas::Encounter(Player &P, Enemy &E) // structures the encounter between player and enemy
{
	while (fighting) // checks to see if the fight is still in action
	{
		
		system("cls");
		PlayerTurn(P, E); // begins the players turn
		system("cls");



	
		if (fighting) // checks to see that the fight hasn't ended on players turn
		{
			E.Special(P);
			EnemyTurn(P, E);  // begins enemies turn
		}
	}
	fighting = true;
	
}

void Areas::PlayerTurn(Player &P, Enemy &E)  // structures the players turn
{
	P.Status(); // displays the player status
	E.Status(); // displays the enemy status

	// checks to see what the player would like to do
	int answer = 0;
	cout << "------------------------------------------" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1 - Attack the enemy" << endl;
	cout << "2 - Run from the enemy" << endl;
	cout << "3 - Rest" << endl;
	cout << "4 - Open inventory" << endl;
	cout << "5 - Leave the training for good (QUIT)" << endl;
	cout << "------------------------------------------" << endl;
	cin >> answer;

	if (answer == 1)
	{
		if (E.defend(P.attacking())) // attacks the enemy using the player attack
		{
			// sets fighting to false, calls the enemy drop function and deletes the enemy on enemy death
			fighting = false;
			E.Drops(P);
			delete &E;
			
		}
	}
	else if (answer == 2)
	{
		if (P.running(E)) // checks for the enemy to run from battle
		{
			// sets fighting to false and deletes the enemy if the player runs successfully
			fighting = false; 
			delete &E;
		}
	}
	else if (answer == 3)
	{
		P.Rest();
	}
	else if (answer == 4)
	{
		int answer = 0;
		P.playerInv->DisplayInv(); // displays the player inventory

		// checks to see if the player would like to use anything
		cout << "Would you like to use something from your" << endl;
		cout << "inventory?" << endl;
		cout << "1 - YES" << endl;
		cout << "2 - NO" << endl;
		cout << "------------------------------------------" << endl;
		cin >> answer;

		if (answer == 1)
		{
			P.playerInv->Useitem(&P); // checks and uses an item
		}
		else
		{
			system("cls");
			PlayerTurn(P, E); // returns to the players turn
		}
	}
	else if (answer == 5)
	{
		// checks to see if the player is sure they wish to quit
		int answer = 0;
		cout << "------------------------------------------" << endl;
		cout << "Are you sure you wish to quit?" << endl;
		cout << "1 - YES" << endl;
		cout << "2 - NO" << endl;
		cout << "------------------------------------------" << endl;
		cin >> answer;
		if (answer == 1)
		{
			exit(10); // quits with error code 10 so i know that it was a forced leave of the game
		}
		else
		{
			system("cls");
			PlayerTurn(P,E); // returns to the players turn
		}
	}
	else
	{
		cout << "------------------------------------------" << endl;
		cout << "You have wasted a move, rookie!" << endl;		
		cout << "------------------------------------------" << endl;
		system("pause");
	}
}

void Areas::EnemyTurn(Player & P, Enemy & E) //structures the enemy turn
{
	P.Status(); // shows the status of the player
	E.Status(); // shows the status of the enemy

	if (P.Defend(E.attack())) // player defends against enemy attack
	{
		cout << "------------------------------------------" << endl;
		cout << "You have been killed in action." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		exit(10);
	}
	E.heal(); // checks to see if enemy heals 
	
	system("pause");
}

void Areas::Training(Player &P) // plays the trainig area
{
	ArmlessGoblin *armlessgoblin = new ArmlessGoblin; // creates an armeless goblin

	// story text
	cout << "------------------------------------------" << endl;
	cout << "All training is done through combat here." << endl;
	cout << "We'll start you off easy with a Goblin." << endl;
	cout << "Luckily this one doesn't have arms" << endl;
	cout << "though, otherwise you'd be toast." << endl;
	cout << "When in combat you will see both yours" << endl;
	cout << "and your opponents stats ans then options" << endl;
	cout << "on how you wish to commence. Simply select" << endl;
	cout << "your option of choice and let the fight" << endl;
	cout << "get underway. Keep going and you may win!" << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");

	Encounter(P, *armlessgoblin); // runs and encounter with the enemy
	
}

void Areas::lessonDexterity(Player &P)
{
	Goblin *goblin = new Goblin; // creates a goblin

	// story text
	cout << "------------------------------------------" << endl;
	cout << "Welcome to your lesson in dexterity!" << endl;
	cout << "We've got a nice Goblin for you to fight," << endl;
	cout << "and I can assure you this one has arms!" << endl;
	cout << "Remember dexterity is key to dodging enemy" << endl;
	cout << "attacks. Anyway, my classes are more" << endl;
	cout << "practical work than others, so lets see" << endl;
	cout << "how you do, good luck! Oh, and the names" << endl;
	cout << "Professor Swift!" << endl;	
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");

	Encounter(P, *goblin); // runs and encounter with the enemy

}

void Areas::lessonStrength(Player &P)
{
	Ork *ork = new Ork; // goblin

	// story text
	cout << "------------------------------------------" << endl;
	cout << "Ah, you must be the new student, welcome " << endl;
	cout << "to your lesson in strength! I'm not going" << endl;
	cout << "to say much other than that my name is" << endl;
	cout << "Doctor backbone and that you're about to" << endl;
	cout << "fight an incredibly strong Ork. Also," << endl;
	cout << "because I like the way you don't speak" << endl;
	cout << "much, I'll let you know this secret. " << endl;
	cout << "Strength comes in many places! Good luck!" << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");

	Encounter(P, *ork); // runs and encounter with the enemy

}

void Areas::lessonHealing(Player &P)
{
	
	Werewolf *werewolf = new Werewolf; // creates a werewolf

	// story text
	cout << "------------------------------------------" << endl;
	cout << "Welcome to a room of healing! Today you'll" << endl;
	cout << "be fighting a werewolf! If you want to " << endl;
	cout << "make it far as a circus act you'll need" << endl;
	cout << "to understand when it's time to stop and" << endl;
	cout << "heal up, so you can carry on stronger." << endl;
	cout << "I'm Mrs Salubrious, good luck against" << endl;
	cout << "the Werewolf!" << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");

	Encounter(P, *werewolf); // runs and encounter with the enemy
}

void Areas::lessonProtection(Player &P)
{
	Lich *lich = new Lich; // creates a lich

	// story text
	cout << "------------------------------------------" << endl;
	cout << "Welcome to your second day at the school." << endl;
	cout << "I'm Mr Haven and this is where you will" << endl;
	cout << "learn about protection by fighting a Lich." << endl;
	cout << "By now you should be quite used to" << endl;
	cout << "fighting and all the techniques! This is" << endl;
	cout << "simply to rough you up a bit. At the end" << endl;
	cout << "of the day what doesn't kill you makes you" << endl;
	cout << "stronger! Right?" << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");

	Encounter(P, *lich); // runs and encounter with the enemy
}

void Areas::lessonFitness(Player &P)
{
	Troll *troll = new Troll; // creates a troll

	// story text
	cout << "------------------------------------------" << endl;
	cout << "Welcome to your final class before " << endl;
	cout << "graduation, do you feel ready for the" << endl;
	cout << "circus yet? The last thing that you need" << endl;
	cout << "to learn and that I will teach you is" << endl;
	cout << "stamina. You'll be doing shows all day," << endl;
	cout << "every day. So a high level of stamina is" << endl;
	cout << "Key! In my class you'll fight a Troll." << endl;
	cout << "While the troll is not the quickest, he is" << endl;
	cout << "strong, so take your time and pace" << endl;
	cout << "yourself. Good luck and hopefully I'll" << endl;
	cout << "see you at the graduation party tomorrow." << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");

	Encounter(P, *troll); // runs and encounter with the enemy
}

void Areas::Graduation(Player &P)
{
	Lich *lich = new Lich; // creates a lich
	MauriceBleubeau *maurice = new MauriceBleubeau; // creast maurice

	// story text
	cout << "------------------------------------------" << endl;
	cout << "Hello there, I forgot to mention my name" << endl;
	cout << "in the our stamina lesson last period. My" << endl;
	cout << "name is Roberto Robustez and this is your" << endl;
	cout << "graduation party! Now when I say party you" << endl;
	cout << "should know by now that everything" << endl;
	cout << "involves a fight! I hope you've come" << endl;
	cout << "prepared... Today you won't be fighting" << endl;
	cout << "any old beast though. Today you'll be" << endl;
	cout << "taking on the great headmaster Maurice" << endl;
	cout << "Bleubeau. But first, why the hell not" << endl;
	cout << "fight a Lich, right? I love a graduation." << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	system("cls");

	Encounter(P, *lich); // runs and encounter with the enemy
	Encounter(P, *maurice); // runs and encounter with the enemy

}

void Areas::Gym(Player &P)
{
	switch (GymCount) // checks to see how many times you've visited the gym
	{
	case 0:
	{
		// story text
		cout << "------------------------------------------" << endl;
		cout << "You enter the gym to see a massive Troll" << endl;
		cout << "in front of you ready to fight." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		system("cls");
		Troll *troll = new Troll; // creates a troll
		Encounter(P, *troll); // runs and encounter with the enemy
		GymCount++; // adds to the gymcount so that the next gym visit is different
	}
		break;
	case 1:
	{
		// story text
		cout << "------------------------------------------" << endl;
		cout << "As you enter the gym for a second time " << endl;
		cout << "you see a nasty Lich in front of you ready " << endl;
		cout << "to fight." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		system("cls");
		Lich *lich = new Lich; // creates a lich
		Encounter(P, *lich); // runs and encounter with the enemy
		GymCount++;  // adds to the gymcount so that the next gym visit is different
	}
		break;
	case 2:
	{
		// story text
		cout << "------------------------------------------" << endl;
		cout << "The third time you enter the gym you see a" << endl;
		cout << "nasty Lich and a scary Werewolf in front " << endl;
		cout << "of you ready to fight." << endl;
		cout << "------------------------------------------" << endl;
		Lich *lich = new Lich; //creates a lich
		Werewolf *werewolf = new Werewolf; //creates a werewolf
		Encounter(P, *lich); // runs and encounter with the enemy
		Encounter(P, *werewolf); // runs and encounter with the enemy
		GymCount++;  // adds to the gymcount so that the next gym visit is different
	}
		break;
	default:
	{
		// story text
		cout << "------------------------------------------" << endl;
		cout << "You seem to have scared any monsters from" << endl;
		cout << "returning to the gym any time soon! Well " << endl;
		cout << "done!" << endl;
		cout << "------------------------------------------" << endl;
	}
		break;
	}
}

void Areas::Canteen(Player &P)
{
	system("cls");
	int answer = 0;
	// story text
	cout << "------------------------------------------" << endl;
	cout << "Hello there, welcome to the school canteen" << endl;
	cout << "you can buy all sorts of food here to get" << endl;
	cout << "you fighting fit for the rest of your day!" << endl;
	cout << "You get free meals, what would you like" << endl;
	cout << "to eat?" << endl;
	cout << "1 - Coq au vin" << endl;
	cout << "2 - Turkey twizzlers" << endl;
	cout << "3 - Jellied moose nose" << endl;
	cout << "------------------------------------------" << endl;
	cin >> answer;
	switch(answer)
	{
	case 1:
		// story text
		cout << "Here's a delicious Coq au vin, I hope you" << endl;
		cout << "enjoy it! It should make you fighting fit" << endl;
		cout << "for the rest of your day ahead." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		system("cls");
		// sets the stats after eating
		P.SetHealth(100);
		P.SetStamina(100);
		break;
	case 2:
		// story text
		cout << "Here's some Turkey twizzlers, I hope you" << endl;
		cout << "enjoy them! They should make you fighting" << endl;
		cout << "fit for your day ahead." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		system("cls");
		// sets the stats after eating
		P.SetHealth(100);
		P.SetStamina(100);
		break;
	case 3:
		// story text
		cout << "Here's some Jellied moose nose, I hope you" << endl;
		cout << "enjoy it! It should make you fighting fit" << endl;
		cout << "for your day ahead." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		system("cls");
		// sets the stats after eating
		P.SetHealth(100);
		P.SetStamina(100);
		break;
	default:// fail safe for wrong answers
		cout << "------------------------------------------" << endl;
		cout << "Unfortunately that not an option. Please" << endl;
		cout << "try again." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		Canteen(P);
		break;
		
	}
	
	system("cls");

}

void Areas::Shop(Player &P)
{
	system("cls");
	int answer = 0;
	// story text
	cout << "------------------------------------------" << endl;
	cout << "Hello there, Welcome to the school shop!" << endl;
	cout << "We haven't had a delivery in a long time," << endl;
	cout << "so we can only offer you the basics I'm" << endl;
	cout << "afraid! Looks like you currently have" << endl;
	cout <<  P.playerInv->gold.GetAmount() << " gold. What would you like?" << endl;
	cout << "1 - Bandages costing " << P.playerInv->bandage.GetCost() << " gold each." << endl;
	cout << "2 - Water costing " << P.playerInv->water.GetCost() << " gold each." << endl;
	cout << "------------------------------------------" << endl;
	cin >> answer;
	switch (answer)
	{
	case 1:
		cout << "------------------------------------------" << endl;
		cout << "Sure! How many bandages would you like?" << endl;
		cin >> answer;
		cout << "------------------------------------------" << endl;
		if ((P.playerInv->gold.GetAmount()) >= (P.playerInv->bandage.GetCost()*answer)) // checks to see if the player has enough money to purchase what they wish
		{
			cout << "------------------------------------------" << endl;
			cout << "No Problem, here you go!" << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			system("cls");
			P.playerInv->bandage.SetAmount(P.playerInv->bandage.GetAmount()+answer); // sets players amount to include the ones they just bought
			P.playerInv->gold.SetAmount(P.playerInv->gold.GetAmount() - (P.playerInv->bandage.GetCost()*answer)); // takes the gold that they spent
			
		}
		else
		{
			cout << "------------------------------------------" << endl;
			cout << "Unfortunately you do not have enough " << endl;
			cout << "gold to purchase that." << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			system("cls");

		}
		cout << "------------------------------------------" << endl;
		cout << "Would you like more from the shop?" << endl;
		cout << "1 - YES" << endl;
		cout << "2 - NO" << endl;
		cout << "------------------------------------------" << endl;
		cin >> answer;
		switch (answer) // checks whether the player would like anything else
		{
		case 1:
			Shop(P); // runs the shop again
			break;
		case 2:
			cout << "------------------------------------------" << endl;
			cout << "That's okay, see you soon!" << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "------------------------------------------" << endl;
			cout << "That's not what I asked I'm going to" << endl;
			cout << "ask you to leave the shop!" << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			system("cls");
		}

		break;
	case 2:
		cout << "------------------------------------------" << endl;
		cout << "Sure! How much water would you like?" << endl;
		cout << "------------------------------------------" << endl;
		cin >> answer;
		cout << "------------------------------------------" << endl;
		if ((P.playerInv->gold.GetAmount()) >= (P.playerInv->water.GetCost()*answer))  // checks to see if the player has enough money to purchase what they wish
		{
			cout << "------------------------------------------" << endl;
			cout << "No Problem, here you go!" << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			system("cls");
			P.playerInv->water.SetAmount(P.playerInv->water.GetAmount()+answer); // sets players amount to include the ones they just bought
			P.playerInv->gold.SetAmount(P.playerInv->gold.GetAmount() - (P.playerInv->water.GetCost()*answer)); // takes the gold that they spent
			
		}
		else
		{

			cout << "Unfortunately you do not have enough " << endl;
			cout << "gold to purchase that." << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			system("cls");

		}
		cout << "------------------------------------------" << endl;
		cout << "Would you like more from the shop?" << endl;
		cout << "1 - YES" << endl;
		cout << "2 - NO" << endl;
		cout << "------------------------------------------" << endl;
		cin >> answer;
		switch (answer) // checks if the player wants 
		{
		case 1:
			Shop(P); // enters the shop
			break;
		case 2:
			cout << "------------------------------------------" << endl;
			cout << "That's okay, see you soon!" << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			system("cls");
			break;
		default:
			cout << "------------------------------------------" << endl;
			cout << "That's not what I asked I'm going to" << endl;
			cout << "ask you to leave the shop!" << endl;
			cout << "------------------------------------------" << endl;
			system("pause");
			system("cls");
		}
		break;
	default:
		cout << "------------------------------------------" << endl;
		cout << "Unfortunately that not an option. Please" << endl;
		cout << "try again." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		Shop(P); // enter the shop again
		break;
	}

}

void Areas::Explore(Player & P)
{
	int answer = 0;
	cout << "------------------------------------------" << endl;
	cout << "You'll have some free time now to explore" << endl;
	cout << "the school grounds, there's not much to do" << endl;
	cout << "at the moment due to lack of funding! But" << endl;
	cout << "still, I hope that you find something " << endl;
	cout << "useful to do." << endl;
	cout << "Where would you like to go?" << endl;
	cout << "1 - Visit the shop" << endl;
	cout << "2 - Explore the Gym" << endl;
	cout << "3 - Head to the canteen" << endl;
	cout << "4 - Carry on with your day" << endl;
	cout << "------------------------------------------" << endl;
	cin >> answer;
	switch (answer) // checks where the player wants to go
	{
	case 1:
		Shop(P); //takes the player to the shop
		Explore(P); // takes the player back to explore
		break;
	case 2: 
		Gym(P); // takes the player to the gym
		Explore(P); // takes the player back to explore
		break;
	case 3:
		Canteen(P); // takes the player to the gym
		Explore(P); // takes the player back to explore
		break;
	case 4:
		break;
	default:
		Explore(P); // takes the player back to explore
		break;
	}

	
	system("cls");
}
