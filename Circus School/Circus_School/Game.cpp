#include "Game.h"
#include <random>
#include <time.h>


Game::Game(): player(nullptr)
{
	// sets all booleans up
	running = true;
	fighting = true;
}


Game::~Game()
{
	
}


void Game::Menu() // runs main menu
{
	system("cls");
	int answer = 0;
	cout << "------------------------------------------" << endl;
	cout << "CIRCUS SCHOOL" << endl;
	cout << "------------------------------------------" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1 - Play the Game" << endl;
	cout << "2 - Options" << endl;
	cout << "3 - Quit" << endl;
	cout << "------------------------------------------" << endl;
	cin >> answer;

	if (answer == 1)
	{
		Play(); // runs game
	}
	else if (answer == 2)
	{
		Options(); // takes you to options menu
	}
	else if (answer == 3)
	{
		Quit();
	}
	else 
	{
		Menu();
	}
}

void Game::Play()
{
	srand(time(NULL));
	system("cls");
	
	playerCreation(); // select class type
	system("cls");
	player->Init(); // set all stats for player
	system("cls");
	while (running)
	{
		// story text
		cout << "------------------------------------------" << endl;
		cout << "Welcome to circus school " << player->getName() << ". " << endl;
		cout << "I am the headmaster, Maurice Bleubeau." << endl;
		cout << "Here you will train to become the best in" << endl;
		cout << "your field in just two days. I should" << endl;
		cout << "warn you though, we have some pretty" << endl;
		cout << "outlandish techniques! I wish you all" << endl;
		cout << "the luck and look forward to your" << endl;
		cout << "graduation! I need to mention as well that" << endl;
		cout << "your bursary has arrived and so here is 20" << endl;
		cout << "gold, 2 bandages and 3 bottles of water." << endl;
		cout << "------------------------------------------" << endl;

		// gives player initial items
		player->playerInv->gold.SetAmount(20);
		player->playerInv->Store(player->playerInv->gold);
		player->playerInv->bandage.SetAmount(2);
		player->playerInv->Store(player->playerInv->bandage);
		player->playerInv->water.SetAmount(3);
		player->playerInv->Store(player->playerInv->water);

		system("pause");
		system("cls");

		//level plan
		// Day 1

		area.Training(*player); // training
		 
		showTimetable();

		area.lessonDexterity(*player);  // lesson 1
		area.lessonStrength(*player); // lesson 2
		
		cout << "------------------------------------------" << endl;
		cout << "Since its your first lunchtime let's make " << endl;
		cout << "sure you get to the canteen! It's just" << endl;
		cout << " over here." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		system("cls");

		area.Canteen(*player); // Canteen

		area.lessonHealing(*player); // lesson 3

		area.Explore(*player); // explore after school

		// Day 2

		area.lessonProtection(*player); // lesson 1
		area.lessonFitness(*player); // lesson 2

		area.Explore(*player); // explore at lunch

		area.Graduation(*player); // graduation
		running = false;
	}
	system("cls");
	cout << "------------------------------------------" << endl;
	cout << "Congratulations " << player->getName() << " you have graduated with" << endl;
	cout << "flying colours! We hope to see you in the" << endl;
	cout << "biggest and best circuses some day!" << endl;
	cout << "------------------------------------------" << endl;
	system("pause");
	delete player;
	

}

void Game::Quit()
{
	system("cls");
	int answer = 0;
	cout << "------------------------------------------" << endl;
	cout << "Are you sure you wish to quit?" << endl;
	cout << "1 - YES" << endl;
	cout << "2 - NO" << endl;
	cout << "------------------------------------------" << endl;
	cin >> answer;
	if (answer == 1)
	{
		exit(10); // exit using code 10 so i know its a user exit
	}
	else if (answer == 2)
	{
		Menu();
	}
	else
	{
		Quit();
	}
	
}

void Game::Options()
{
	int answer = 0;
	system("cls");
	cout << "------------------------------------------" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1 - Instructions" << endl;
	cout << "2 - Menu" << endl;
	cout << "------------------------------------------" << endl;
	cin >> answer;

	if (answer == 1)
	{
		cout << "------------------------------------------" << endl;
		cout << "Type the number of the option you would" << endl;
		cout << "like to navigate through the game and take" << endl;
		cout << "part in fights etc. Enjoy the game!" << endl;
		cout << "------------------------------------------" << endl;
		system("pause");
		system("cls");

		Menu();
	
		

	}
	else if (answer == 2)
	{
		Menu();
	}
	
	else
	{
		Options();
	}

}



void Game::playerCreation()
{
	system("cls");
	int answer = 0;
	cout << "------------------------------------------" << endl;
	cout << "Who would you like to be?" << endl;
	cout << "1 - Juggler" << endl;
	cout << "2 - Magician" << endl;
	cout << "3 - Tight-rope walker" << endl;
	cout << "------------------------------------------" << endl;
	cin >> answer;

	if (answer == 1)
	{
		player = new Juggler;
	}
	else if (answer == 2)
	{
		player = new Magician;
	}
	else if (answer == 3)
	{
		player = new TightropeWalker;
	}
	else
	{
		cout << "------------------------------------------" << endl;
		cout << "Sorry, that's not an option, try again." << endl;
		cout << "------------------------------------------" << endl;
		system("pause");

		playerCreation();
	}
	if (dynamic_cast<Juggler*>(player)) // checks if player is a juggler
	{
		Juggler* Myplayer = dynamic_cast<Juggler*>(player); // casts player to juggler
		Myplayer->showboat();
	}

	if (dynamic_cast<Magician*>(player)) // checks if player is a magician
	{
		Magician* Myplayer = dynamic_cast<Magician*>(player); // casts player to magician
		Myplayer->showboat();
	}

	if (dynamic_cast<TightropeWalker*>(player)) // checks if player is a tightrope walker
	{
		TightropeWalker* Myplayer = dynamic_cast<TightropeWalker*>(player); // casts player to tight rope walker
		Myplayer->showboat();
	}
}

void Game::showTimetable() // draws timetable
{

	cout << "Here is your timetable " << player->getName() << "." << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "|Timetable - Day 1     |Timetable - Day 2     |"<< endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "|Lesson 1 - 10am-12pm  |Lesson 1 - 10am-12pm  |" << endl;
	cout << "|Dexterity             |Protection            |" << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "|Lesson 2 - 12-2pm     |Lesson 2 - 12-2pm     |" << endl;
	cout << "|Strength              |Fitness               |" << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "|Lunch - 2-3pm         |Lunch - 2-3pm         |" << endl;
	cout << "|---------------------------------------------|" << endl;
	cout << "|Lesson 3 - 12-2pm     |Lesson 2 - 12-2pm     |" << endl;
	cout << "|Healing               |Graduation            |" << endl;
	cout << "-----------------------------------------------" << endl;
	system("pause");
	system("cls");

}
