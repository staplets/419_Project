/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/25/16
* Last Modification Date:	4/26/16
* Filename:				BallroomSource.cpp
*
* Overview:
*	This file holds the implementation for the Ballroom objects and interaction.
*
* Input:
*	The user may input several commands that will be offered to navigate and do
*    different actions throughout the game.
*
* Output:
*	The program will provide a action options and a player inventory option
*    to a user as they play and there will be prompts for information and responses
*    as the player goes from room to room.
*
******************************/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
//included for playing piano functionality
#include <chrono>
#include <thread>

//include ballroom header
#include "BallroomHeader.h"

void inspectBallroomObj(std::string objName, std::unordered_map<std::string, std::string>& inventory)
{
	//intialize objects
	Piano piano;
	Bar bar;

	if (objName.compare("Examine piano") == 0) { //if object is piano
		piano.checkPiano(inventory);
	}
	else {
		bar.checkBar(inventory);
	}
}

int movePlayerFromBallroom(std::string location)
{
	int intChoice;
	if (location.compare("Billiards room") == 0) {
		std::cout << "\nGoing out to the Billiards Room.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 7;
	}
	else if (location.compare("Library") == 0) {
		std::cout << "\nWalking into the Library.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 11;
	}
	else {
		std::cout << "\nWalking into the Sitting Room.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 5;
	}

	return intChoice;
}

//member function for piano
void Piano::playPiano()
{
	std::string ans;

	do {
		//Ascii art taken from: http://www.ascii-code.com/ascii-art/music/musical-notation.php and modified
		//logic to imitate sherlock sleeping for three seconds
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "\n\n" <<
			"      |~~~~~~~~~~~~~|\n" <<
			"      |~~~~~~~~~~~~~|\n" <<
			"   __ |          __ |\n" <<
			"  /~~\\|         /~~\\|\n" <<
			"  \\__/          \\__/  \n\n\n\n";

		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "\n\n" <<
			"      |~~~~~~~~~~~~~|\n" <<
			"      |~~~~~~~~~~~~~|\n" <<
			"   __ |          __ |\n" <<
			"  /~~\\|         /~~\\|\n" <<
			"  \\__/          \\__/  \n\n\n\n";

		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "\n\n" <<
			"      |~~~~~~~~~~~~~|\n" <<
			"      |~~~~~~~~~~~~~|\n" <<
			"   __ |          __ |\n" <<
			"  /~~\\|         /~~\\|\n" <<
			"  \\__/          \\__/  \n\n\n\n";

		std::cout << "\nWould you like to continue playing piano?\n\n";

		//check user input
		do
		{
			std::cout << "\n\nPlease choose 'y' or 'n' to continue: \n\n";
			std::cout << std::endl << std::endl;
			std::cin >> ans;

			while (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin >> ans;
			}

			//clear input stream
			std::cin.clear();
			std::cin.ignore(255, '\n');

		} while (ans != "y" && ans != "n");

	} while (ans != "n");
}

//member function for Piano
void Piano::checkPiano(std::unordered_map<std::string, std::string>& inv)
{
	//initialize the couch object
	Piano piano;
	int firstTime = 0;
	//user input var
	std::string ans;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nThe Piano\n\n\n\n";

	std::cout << "\nFrom closer inspection of the piano, Sherlock notes it as: " << getDescription() << "\n\n";


	//check if knife is already in inventory
	auto search = inv.find("music notes");
	if (search != inv.end()) {

		//set up navigation
		std::cout << "Sherlock has already grabbed the " << getNotes() << ", but he could still play a little piano.\n\n" <<
			"What would you like to do? \n\n" <<
			"Play piano? (Enter \"1\") \n\n" <<
			"Done with piano? (Enter \"2\")\n\n" <<
			"Check your inventory of items ( Enter \"3\").\n\n" <<
			"Choose a number between 1 and 3.";

		//choice from player
		int choice = 0;
		int retry = 0;

		//inspect the room
		do {

			//navigation choice
			choice = 0;
			retry = 0;

			do
			{
				if (retry > 0)
				{
					std::cout << "\n\nPlease select a number between 1 and 3: \n\n";
				}
				else {
					if (firstTime != 0) {
						//formatting
						std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

						std::cout << "\n\nThe Piano\n\n\n\n" <<
							"Sherlock has already grabbed the " << getNotes() << ", but he could still play a little piano.\n\n" <<
							"What would you like to do? \n\n" <<
							"Play piano? (Enter \"1\") \n\n" <<
							"Done with piano? (Enter \"2\")\n\n" <<
							"Check your inventory of items ( Enter \"3\").\n\n" <<
							"Choose a number between 1 and 3.";
					}
				}
				std::cout << std::endl << std::endl;
				//Take input for program choice.
				std::cin >> choice;

				while (!std::cin)
				{
					std::cin.clear();
					std::cin.ignore(255, '\n');
					std::cout << "\n\nPlease enter a choice : \n\n";
					std::cin >> choice;
				}
				retry++;
				firstTime++;

			} while (choice < 1 || choice > 3);


			//navigate based on choice
			switch (choice) {
			case 1:
				//call function to play piano
				piano.playPiano();
				std::cout << "\n\nSherlock finishes his masterpiece and feels accomplished!\n\n";
				break;
			case 2:
				std::cout << "\nSherlock moves away from the piano.\n\n";
				break;
			case 3:
				std::cout << "\n\nInventory contains: \n\n";
				int c = 1;
				for (auto it = inv.begin(); it != inv.end(); ++it) {
					std::cout << c << ": " << it->second << "\n";
					c++;
				}
				break;
			}

		} while (choice != 2);
	}
	else {

		//set up navigation
		std::cout << "\nThe piano has some beautiful art work on the side, and there are " << getNotes() << " on top of it that interest him.\n\n" <<
			"What would you like to do? \n\n" <<
			"Look at music notes? (Enter \"1\").\n\n" <<
			"Play the piano? (Enter \"2\") \n\n" <<
			"Done with piano? (Enter \"3\")\n\n" <<
			"Check your inventory of items ( Enter \"4\").\n\n" <<
			"Choose a number between 1 and 4.";

		//choice from player
		int choice = 0;
		int retry = 0;

		//inspect the couch
		do {

			//navigation choice
			choice = 0;
			retry = 0;

			do
			{
				if (retry > 0)
				{
					std::cout << "\n\nPlease select a number between 1 and 4: \n\n";
				}
				else {
					if (firstTime != 0) {
						//formatting
						std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

						std::cout << "\n\nThe Piano\n\n\n\n" <<
							"\nThe piano has some beautiful art work on the side, and there are " << getNotes() << " on top of it that interest him.\n\n" <<
							"What would you like to do? \n\n" <<
							"Look at music notes? (Enter \"1\").\n\n" <<
							"Play the piano? (Enter \"2\") \n\n" <<
							"Done with piano? (Enter \"3\")\n\n" <<
							"Check your inventory of items ( Enter \"4\").\n\n" <<
							"Choose a number between 1 and 4.";
					}
				}
				std::cout << std::endl << std::endl;
				//Take input for program choice.
				std::cin >> choice;

				while (!std::cin)
				{
					std::cin.clear();
					std::cin.ignore(255, '\n');
					std::cout << "\n\nPlease enter a choice : \n\n";
					std::cin >> choice;
				}
				retry++;
				firstTime++;

			} while (choice < 1 || choice > 4);


			//output responses from Mr Whtie
			switch (choice) {
			case 1:
				std::cout << "\nSherlock sees that the " << getNotes() << " are for a few songs by Beethoven.\n\n";

				std::cout << "Would you like to add the " << getNotes() << " to your inventory?\n\n";

				//check user input
				do
				{
					std::cout << "\n\nPlease choose 'y' or 'n' to continue: \n\n";
					std::cout << std::endl << std::endl;
					std::cin >> ans;

					while (!std::cin)
					{
						std::cin.clear();
						std::cin.ignore(255, '\n');
						std::cin >> ans;
					}

					//clear input stream
					std::cin.clear();
					std::cin.ignore(255, '\n');

				} while (ans != "y" && ans != "n");

				if (ans == "y") {
					inv.insert({ "music notes", getNotes() });
					std::cout << "\nOkay, " << getNotes() << " added to inventory.\n\n";
					//change choice to go back out to room loop
					choice = 3;
				}
				else {
					std::cout << "\nOkay, " << getNotes() << " not added to inventory.\n\n";
				}
				break;
			case 2:
				//call function to play piano
				piano.playPiano();
				std::cout << "\n\nSherlock finishes his masterpiece and feels accomplished!\n\n";
				break;
			case 3:
				std::cout << "\nSherlock moves away from the piano.\n\n";
				break;
			case 4:
				std::cout << "\n\nInventory contains: \n\n";
				int c = 1;
				for (auto it = inv.begin(); it != inv.end(); ++it) {
					std::cout << c << ": " << it->second << "\n";
					c++;
				}
				break;
			}

		} while (choice != 3);
	}

}

//Accessor Functions for accessing private variables in Piano.
std::string Piano::getDescription() const { return description; }

std::string Piano::getNotes() const { return notes; }

//Mutator Functions to change private variables.
void Piano::setDescription(const std::string theDescription) { description = theDescription; }

void Piano::setNotes(const std::string theNotes) { notes = theNotes; }


//member function to output information provided of each item
void Bar::checkBar(std::unordered_map<std::string, std::string>& inv) {
	
	//used for animation
	int start_row = 4;
	int start_column = 4;
	int i;
	int speed;

	//initialize the bar object
	Bar bar;
	//user input var
	std::string ans;


	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Bar\n\n\n\n";

	//coffee table info
	std::cout << "\nWalking over to the bar, Sherlock notes: " << getDescription() << "\n\n";

	if (getNumDrinks() < 3) {
		std::cout << "\nOn top of the bar there is a bottle of " << getAlcohol() << ". Sherlock doesn't see anything else out of place, but he always enjoys a drink.\n\n";

		std::cout << "Would you like to have a drink of " << getAlcohol() << "?\n\n";

		//check user input
		do
		{
			std::cout << "\n\nPlease choose 'y' or 'n' to continue: \n\n";
			std::cout << std::endl << std::endl;
			std::cin >> ans;

			while (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cin >> ans;
			}

			//clear input stream
			std::cin.clear();
			std::cin.ignore(255, '\n');

		} while (ans != "y" && ans != "n");

		if (ans == "y") {
			
			initscr();
			printBar(start_row, start_column);
			for (i = 1; i <= 5; i++)
			{
				for (speed = 1; speed <= 50000000; speed++);
				refresh();
			}

			for (i = 1; i <= 11; i++)
			{
				if (i == 4)
				{
					start_row++;
				}
				printPour(start_row, start_column);
				refresh();
				for (speed = 1; speed <= 59000000; speed++);
				start_row++;
				refresh();
			}
			
			start_row--;
	
			for (i = 1; i <= 7; i++)
			{
				if (i == 3)
				{erasePour(start_row - 9, start_column);}
				if (i == 4)
				{erasePour(start_row - 7, start_column);}
				if (i == 5)
				{erasePour(start_row - 5, start_column);}
				if (i == 6)
				{printGlass(start_row - 3, start_column);}
				if (i == 7)
				{erasePour(start_row - 1, start_column);}
				
				printFill(start_row, start_column);
				refresh();
				for (speed = 1; speed <= 48000000; speed++);
				start_row--;
				refresh();
			}
			getch();
			endwin();
			
			int amount = getNumDrinks();
			setNumDrinks(amount + 1);

			std::cout << "\nOkay, That's " << getNumDrinks() << " drink(s) for Sherlock. Don't go overboard or he may need to have a water!\n\n";
		}
		else {
			std::cout << "\nOkay, Sherlock has had" << getNumDrinks() << " drink(s).\n\n";
		}
	}
	else
	{
		std::cout << "\nOn top of the bar there is a bottle of " << getAlcohol() << ". Sherlock has had " << getNumDrinks() << " drink(s) already and needs a water.\n\n";
		std::cout << "That brings down his consumption count one drink.\n\n";
		int amount = getNumDrinks();
		setNumDrinks(amount - 1);
	}

}


//Accessor Functions for accessing private variables in Bar.
std::string Bar::getAlcohol() const { return alcohol; }

std::string Bar::getDescription() const { return description; }

int Bar::getNumDrinks() const { return numDrinks; }

//Mutator Functions to change private variables.
void Bar::setAlcohol(const std::string theAlcohol) { alcohol = theAlcohol; }

void Bar::setDescription(const std::string theDescription) { description = theDescription; }

void Bar::setNumDrinks(const int theNumDrinks) { numDrinks = theNumDrinks; }

//navigation function to handle game play while the player is in the billiards room
int ballroomNavigate(std::unordered_map<std::string, std::string>& inventory) {

	//boolean to find out if player wants to move to another room
	bool move = false;
	int firstTime = 0;

	//intialize objects
	Piano piano;
	Bar bar;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Ballroom\n\n\n\n" <<
		"Sherlock is in the Ballroom.\n\nLooking around, he sees a Piano in the center of the room and along the side of the room, there is a Bar.\n\n" <<
		"Examine the Piano? (Enter \"Examine piano\").\n\n" <<
		"Go over to look at the Bar? (Enter \"Look at bar\").\n\n" <<
		"You may go into the Billiards Room (Enter \"Billiards room\")\n\n" <<
		"You may go into the Library (Enter \"Library\").\n\n" <<
		"You may walk into the Sitting Room (Enter \"Sitting room\")\n\n" <<
		"Check your inventory of items ( Enter \"Check inventory\").\n\n" <<
		"What would you like to do?";

	//choice from player
	std::string choice;
	int intChoice;
	int retry = 0;
	std::string ans;

	//inspect the room
	do {

		//navigation choice
		retry = 0;

		do
		{
			if (retry > 0)
			{
				std::cout << "\n\nPlease select an option to navigate: \n\n";
			}
			else {
				if (firstTime != 0) {
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "\n\nThe Ballroom\n\n\n\n" <<
						"Sherlock is in the Ballroom.\n\nLooking around, he sees a Piano in the center of the room and along the side of the room, there is a Bar.\n\n" <<
						"Examine the Piano? (Enter \"Examine piano\").\n\n" <<
						"Go over to look at the Bar? (Enter \"Look at bar\").\n\n" <<
						"You may go into the Billiards Room (Enter \"Billiards room\")\n\n" <<
						"You may go into the Library (Enter \"Library\").\n\n" <<
						"You may walk into the Sitting Room (Enter \"Sitting room\")\n\n" <<
						"Check your inventory of items ( Enter \"Check inventory\").\n\n" <<
						"What would you like to do?";
				}
			}
			std::cout << std::endl << std::endl;
			//Take input for program choice.
			std::getline(std::cin, choice);

			while (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cout << "\n\nPlease enter a choice : \n\n";
				std::cin >> choice;
			}
			retry++;
			firstTime++;

		} while ((choice.compare("Examine piano") != 0) && (choice.compare("Look at bar") != 0) && (choice.compare("Billiards room") != 0)
			&& (choice.compare("Library") != 0) && (choice.compare("Sitting room") != 0) && (choice.compare("Check inventory") != 0));


		//take users choice and interact based on that
		if (choice.compare("Billiards room") == 0 || choice.compare("Library") == 0 || choice.compare("Sitting room") == 0) {
			intChoice = movePlayerFromBallroom(choice);
			move = true;
		}
		else if (choice.compare("Check inventory") == 0) {
			std::cout << "\n\nInventory contains: \n\n";
			int c = 1;
			for (auto it = inventory.begin(); it != inventory.end(); ++it) {
				std::cout << c << ": " << it->second << "\n";
				c++;
			}
		}
		else {
			inspectBallroomObj(choice, inventory);
		}

	} while (!move);

	return intChoice;
}
