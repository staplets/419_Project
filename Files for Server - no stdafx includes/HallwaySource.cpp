/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/24/16
* Last Modification Date:	4/24/16
* Filename:				HallwaySource.cpp
*
* Overview:
*	This file holds the implementation for the Hallway Room objects and interaction.
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

//include hallway header
#include "HallwayHeader.h"
#include "animation.hpp"

void inspectHallwayObj(std::string objName, std::unordered_map<std::string, std::string>& inventory)
{
	//intialize objects
	Shelf shelf;
	EndTable endTable;

	if (objName.compare("Examine shelf") == 0) { //if object is shelf
		shelf.checkShelf(inventory);
	}
	else {
		endTable.checkEndTable(inventory);
	}
}

int movePlayerFromHallway(std::string location)
{
	int intChoice;

	if (location.compare("Foyer") == 0) {
		std::cout << "\nGoing down to the Foyer.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 2;
	}
	else if (location.compare("Study") == 0) {
		std::cout << "\nGoing down into the Study.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 4;
	}
	else if (location.compare("Bedroom") == 0) {
		std::cout << "\nWalking into the Bedroom.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 15;
	}
	else if (location.compare("Servants room") == 0) {
		std::cout << "\nWalking into the Servants Quarters.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 17;
	}
	else {
		std::cout << "\nGoing up to the Attic.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 20;
	}
	return intChoice;
}

//member function to get into the trunk of Shelf
void Shelf::checkShelf(std::unordered_map<std::string, std::string>& inv)
{
	int start_row = 4;
	int start_column = 4;
	int i;
	int speed;
	
	//user input var
	std::string ans;

	//initialize random seed
	srand((unsigned int)time(NULL));

	//get random number between 1 and 3 to time a smack on the spider
	int catchSpider = rand() % 3 + 1;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nThe Shelf\n\n\n\n";

	std::cout << "\nFrom closer inspection of the shelf, Sherlock notes: " << getDescription() << "\n\n";

	//check if candle is already in inventory
	auto search = inv.find("candle");
	if (search != inv.end()) {

		if (getDead() == true) {
			//if spider dead and candle in inventory
			std::cout << "\nThe shelf is empty. Sherlock already grabbed the " << getCandle() << " and killed a spider.\n\n";
		}
		else {
			//candle in inventory but spider lives on
			std::cout << "\nThe shelf has a Spider on it, but Sherlock already grabbed the " << getCandle() << ".\n\n";

			std::cout << "\nWould you like to try and kill the " << getSpider() << ".\n\n";

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

			//Spider animation
			initscr();
			for (i = 1; i <= 12; i++)
			{
				printSpider1(start_row, start_column);
				refresh();
				for (speed = 1; speed <= 55000000; speed++);
				eraseSpider(start_row, start_column);
				refresh();
				start_column++;
	
				printSpider2(start_row, start_column);
				refresh();
				for (speed = 1; speed <= 55000000; speed++);
				eraseSpider(start_row, start_column);
				refresh();
				start_column++;
	
				printSpider3(start_row, start_column);
				refresh();
				for (speed = 1; speed <= 55000000; speed++);
				eraseSpider(start_row, start_column);
				refresh();
				start_column++;
	
				printSpider2(start_row, start_column);
				refresh();
				for (speed = 1; speed <= 55000000; speed++);
				eraseSpider(start_row, start_column);
				refresh();
				start_column++;
	
			}
			endwin();

			if (ans == "y") {
				//guess right number to catch spider
				std::cout << "\nOkay, in order to kill the spider you have to try timing when you want to smack him correctly.\n\n";

				//choice from player
				int choice = 0;
				int retry = 0;

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
						std::cout << "\n\nTry to smack the spider on the count of 1, 2, or 3: \n\n";
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

				} while (choice < 1 || choice > 3);

				//check if guessed right
				if (choice == catchSpider) {
					std::cout << "\n\nGood timing! You got the spider!\n\n";
					setDead(true);
				}
				else {
					std::cout << "\n\nClose but no cigar! Should have tried on " << catchSpider << "\n\n";
				}

			}
			else {
				std::cout << "\nOkay, the " << getSpider() << " will live on!\n\n";
			}
		}

	}
	else {

		if (getDead() == true) {
			//if spider dead and candle not in inventory
			std::cout << "\nThe shelf has a " << getCandle() << ", which is lit to provide light.\n\n";

			std::cout << "Would you like to add the " << getCandle() << " to your inventory?\n\n";

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
				inv.insert({ "candle", getCandle() });
				std::cout << "\nOkay, " << getCandle() << " added to inventory.\n\n";
			}
			else {
				std::cout << "\nOkay, " << getCandle() << " not added to inventory.\n\n";
			}
		}
		else {
			//spider alive and candle on shelf
			std::cout << "\nThe shelf has a spider crawling around on it and a " << getCandle() << ", which is lit to provide light.\n\n";

			std::cout << "Would you like to add the " << getCandle() << " to your inventory?\n\n";

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
				inv.insert({ "candle", getCandle() });
				std::cout << "\nOkay, " << getCandle() << " added to inventory.\n\n";
			}
			else {
				std::cout << "\nOkay, " << getCandle() << " not added to inventory.\n\n";
			}

			std::cout << "\nWould you like to try and kill the " << getSpider() << ".\n\n";

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
			
			//Spider animation
			initscr();
			for (i = 1; i <= 12; i++)
			{
				printSpider1(start_row, start_column);
				refresh();
				for (speed = 1; speed <= 55000000; speed++);
				eraseSpider(start_row, start_column);
				refresh();
				start_column++;
	
				printSpider2(start_row, start_column);
				refresh();
				for (speed = 1; speed <= 55000000; speed++);
				eraseSpider(start_row, start_column);
				refresh();
				start_column++;
	
				printSpider3(start_row, start_column);
				refresh();
				for (speed = 1; speed <= 55000000; speed++);
				eraseSpider(start_row, start_column);
				refresh();
				start_column++;
	
				printSpider2(start_row, start_column);
				refresh();
				for (speed = 1; speed <= 55000000; speed++);
				eraseSpider(start_row, start_column);
				refresh();
				start_column++;
	
			}
			endwin();

			if (ans == "y") {
				//guess right number to catch spider
				std::cout << "\nOkay, in order to kill the spider you have to try timing when you want to smack him correctly.\n\n";

				//choice from player
				int choice = 0;
				int retry = 0;

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
						std::cout << "\n\nTry to smack the spider on the count of 1, 2, or 3: \n\n";
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

				} while (choice < 1 || choice > 3);

				//check if guessed right
				if (choice == catchSpider) {
					std::cout << "\n\nGood timing! You got the spider!\n\n";
					setDead(true);
				}
				else {
					std::cout << "\n\nClose but no cigar! Should have tried on " << catchSpider << "\n\n";
				}

			}
			else {
				std::cout << "\nOkay, the " << getSpider() << " will live on!\n\n";
			}
		}

	}

}

//Accessor Functions for accessing private variables in CoatCloset.
std::string Shelf::getDescription() const { return description; }

std::string Shelf::getSpider() const { return spider; }

bool Shelf::getDead() const { return dead; }

std::string Shelf::getCandle() const { return candle; }

//Mutator Functions to change private variables.
void Shelf::setDescription(const std::string theDescription) { description = theDescription; }

void Shelf::setSpider(const std::string theSpider) { spider = theSpider; }

void Shelf::setDead(const bool theDead) { dead = theDead; }

void Shelf::setCandle(const std::string theCandle) { candle = theCandle; }



//member function to output information provided of each item
void EndTable::checkEndTable(std::unordered_map<std::string, std::string>& inv) {

	//initialize the fish bowl object
	EndTable endTable;
	//user input var
	std::string ans;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe End Table\n\n\n\n";

	//coffee table info
	std::cout << "\nWalking over to the end table, Sherlock notes: " << getDescription() << "\n\n";

	//check if knife is already in inventory
	auto search = inv.find("sculpture");
	if (search != inv.end()) {
		std::cout << "\nThe end table has a mirror above it, but Sherlock already grabbed the " << getSculpture() << " from here.\n\n";

		std::cout << "Would you like to look at mirror?\n\n";

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
			std::cout << getMirror() << "\n\n";
		}

	}
	else {

		std::cout << "\nThe table has a mirror above it and a " << getSculpture() << ", which catches his eye.\n\n";

		std::cout << "Would you like to add the sculpture to your inventory?\n\n";

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
			inv.insert({ "sculpture", getSculpture() });
			std::cout << "\nOkay, " << getSculpture() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getSculpture() << " not added to inventory.\n\n";
		}


		//prompt user to look at mirror
		std::cout << "Would you like to look at mirror?\n\n";

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
			std::cout << getMirror() << "\n\n";
		}
	}

}


//Accessor Functions for accessing private variables in EndTable.
std::string EndTable::getMirror() const { return mirror; }

std::string EndTable::getDescription() const { return description; }

std::string EndTable::getSculpture() const { return sculpture; }

//Mutator Functions to change private variables.
void EndTable::setMirror(const std::string theMirror) { mirror = theMirror; }

void EndTable::setDescription(const std::string theDescription) { description = theDescription; }

void EndTable::setSculpture(const std::string theSculpture) { sculpture = theSculpture; }


//navigation function to handle game play while the player is in the hallway room
int hallwayNavigate(std::unordered_map<std::string, std::string>& inventory) {

	//boolean to find out if player wants to move to another room
	bool move = false;
	int firstTime = 0;

	//intialize objects
	Shelf shelf;
	EndTable endTable;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Hallway\n\n\n\n" <<
		"Sherlock is in the upstairs Hallway.\n\nLooking around, he sees a Shelf on the wall and also sees an end table along the hall.\n\nExamine the Shelf? (Enter \"Examine shelf\").\n\n" <<
		"Go over to look at End Table? (Enter \"Look at end table\").\n\n" <<
		"You may go downstairs either to the Foyer (Enter \"Foyer\")\n\nor go downstairs into the Study (Enter \"Study\").\n\n" <<
		"You may walk into the Bedroom (Enter \"Bedroom\")\n\nYou may go into the Servants Room (Enter \"Servants room\").\n\n" <<
		"You may go up into the Attic (Enter \"Attic\").\n\n" <<
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
				std::cout << "\n\nPlease enter an option to navigate: \n\n";
			}
			else {
				if (firstTime != 0) {
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "\n\nThe Hallway\n\n\n\n" <<
						"Sherlock is in the upstairs Hallway.\n\nLooking around, he sees a Shelf on the wall and also sees an end table along the hall.\n\nExamine the Shelf? (Enter \"Examine shelf\").\n\n" <<
						"Go over to look at End Table? (Enter \"Look at end table\").\n\n" <<
						"You may go downstairs either to the Foyer (Enter \"Foyer\")\n\nor go downstairs into the Study (Enter \"Study\").\n\n" <<
						"You may walk into the Bedroom (Enter \"Bedroom\")\n\nYou may go into the Servants Room (Enter \"Servants room\").\n\n" <<
						"You may go up into the Attic (Enter \"Attic\").\n\n" <<
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
				std::cout << "\n\nPlease enter a valid option (Examine shelf, Look at end table, Foyer, Study, Bedroom, Servants room, Attic or Check inventory) : \n\n";
				std::cin >> choice;
			}
			retry++;
			firstTime++;

		} while ((choice.compare("Examine shelf") != 0) && (choice.compare("Look at end table") != 0) && (choice.compare("Foyer") != 0)
			&& (choice.compare("Study") != 0) && (choice.compare("Bedroom") != 0) && (choice.compare("Servants room") != 0)
			&& (choice.compare("Attic") != 0) && (choice.compare("Check inventory") != 0));


		//take users choice and interact based on that
		if (choice.compare("Foyer") == 0 || choice.compare("Study") == 0 || choice.compare("Bedroom") == 0 ||
			choice.compare("Servants room") == 0 || choice.compare("Attic") == 0) {
			intChoice = movePlayerFromHallway(choice);
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
			inspectHallwayObj(choice, inventory);
		}

	} while (!move);

	return intChoice;
}
