/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/21/16
* Last Modification Date:	4/21/16
* Filename:				BilliardsSource.cpp
*
* Overview:
*	This file holds the implementation for the Billiards Room objects and interaction.
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

//include billiards header
#include "BilliardsHeader.h"

void inspectBilliardsObj(std::string objName, std::unordered_map<std::string, std::string>& inventory)
{
	//intialize objects
	PoolTable poolTable;
	CoffeeTable coffeeTable;

	if (objName.compare("Look at pool table") == 0) { //if object is pool table
		poolTable.checkTable(inventory);
	}
	else {
		coffeeTable.checkCoffeeTable(inventory);
	}
}

int movePlayerFromBilliards(std::string location)
{
	int intChoice;
	if (location.compare("Deck") == 0) {
		std::cout << "\nGoing out to the Deck.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 13;
	}
	else if (location.compare("Study") == 0) {
		std::cout << "\nWalking into the Study.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 4;
	}
	else if (location.compare("Smoking room") == 0) {
		std::cout << "\nWalking into the Smoking Room.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 6;
	}
	else if (location.compare("Ballroom") == 0) {
		std::cout << "\nWalking into the Ballroom.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 16;
	}
	else {
		std::cout << "\nGoing up to the Kitchen.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 9;
	}
	return intChoice;
}

//member function to get into the trunk of Pool Table
void PoolTable::checkTable(std::unordered_map<std::string, std::string>& inv)
{
	//user input var
	std::string ans;
	int checkInventory = 0;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nThe Pool Table\n\n\n\n";

	std::cout << "\nFrom closer inspection of the pool table, Sherlock notes it as: " << getDescription() << "\n\n";

	//check if pool ball is already in inventory
	auto search = inv.find("pool ball");
	if (search != inv.end()) {
		checkInventory = 1;
	}

	//check if pool stick is already in inventory
	search = inv.find("pool stick");
	if (search != inv.end()) {
		//if stick found and ball found
		if (checkInventory == 1) {
			checkInventory = 2;
		}
		//if pie found but steak not found
		else if (checkInventory == 0) {
			checkInventory = 3;
		}

	}

	//handle output to user based on whether the ball or stick are on the table
	switch (checkInventory) {
	case 0: // stick and ball not in user inventory
			//output choices
		std::cout << "Sherlock takes note of a " << getBall() << " and the " << getStick() << " and wonders if they would be worthwhile evidence.\n\n";

		//check to add ball to inventory
		std::cout << "Would you like to add a " << getBall() << " to your inventory?\n\n";

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
			inv.insert({ "pool ball", getBall() });
			std::cout << "\nOkay, " << getBall() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getBall() << " not added to inventory.\n\n";
		}

		//check to add stick to inventory
		std::cout << "Would you like to add a " << getStick() << " to your inventory?\n\n";

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
			inv.insert({ "pool stick", getStick() });
			std::cout << "\nOkay, " << getStick() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getStick() << " not added to inventory.\n\n";
		}

		break;
	case 1: //only ball in user inventory
			//output choices
		std::cout << "Sherlock takes note of the " << getStick() << ", since he already grabbed a pool ball and wonders if it would be worthwhile evidence.\n\n";

		std::cout << "Would you like to add a " << getStick() << " to your inventory?\n\n";

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
			inv.insert({ "pool stick", getStick() });
			std::cout << "\nOkay, " << getStick() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getStick() << " not added to inventory.\n\n";
		}
		break;
	case 2: // stick and ball in user inventory
			//output choices
		std::cout << "There are still a few pool balls on the pool table and a stick, but Sherlock has already collected a stick and ball and is content.\n\n";
		break;
	case 3: // stick found but not ball in user inventory
			//output choices
		std::cout << "Sherlock takes note of the " << getBall() << ", since he already grabbed a " << getStick() << " and wonders if it would be worthwhile evidence.\n\n";

		std::cout << "Would you like to add a " << getBall() << " to your inventory?\n\n";

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
			inv.insert({ "pool ball", getBall() });
			std::cout << "\nOkay, " << getBall() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getBall() << " not added to inventory.\n\n";
		}
		break;
	}

}

//Accessor Functions for accessing private variables in CoatCloset.
std::string PoolTable::getDescription() const { return description; }

std::string PoolTable::getBall() const { return ball; }

std::string PoolTable::getStick() const { return stick; }

//Mutator Functions to change private variables.
void PoolTable::setDescription(const std::string theDescription) { description = theDescription; }

void PoolTable::setBall(const std::string theBall) { ball = theBall; }

void PoolTable::setStick(const std::string theStick) { stick = theStick; }



//member function to output information provided of each item
void CoffeeTable::checkCoffeeTable(std::unordered_map<std::string, std::string>& inv) {

	//initialize the fish bowl object
	CoffeeTable coffeeTable;
	//user input var
	std::string ans;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Coffee Table\n\n\n\n";

	//coffee table info
	std::cout << "\nWalking over to the coffee table, Sherlock notes: " << getDescription() << "\n\n";

	//check if knife is already in inventory
	auto search = inv.find("brochure");
	if (search != inv.end()) {
		std::cout << "\nThe table has a Life magazine, but Sherlock already grabbed the " << getBrochure() << " that interested him.\n\n";
	}
	else {

		std::cout << "\nThe table has a copy of Life magazine and a " << getBrochure() << ", which catches his eye.\n\n";

		std::cout << "Would you like to add the brochure to your inventory?\n\n";

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
			inv.insert({ "brochure", getBrochure() });
			std::cout << "\nOkay, " << getBrochure() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getBrochure() << " not added to inventory.\n\n";
		}
	}

}


//Accessor Functions for accessing private variables in CoffeeTable.
std::string CoffeeTable::getBrochure() const { return brochure; }

std::string CoffeeTable::getDescription() const { return description; }

//Mutator Functions to change private variables.
void CoffeeTable::setBrochure(const std::string theBrochure) { brochure = theBrochure; }

void CoffeeTable::setDescription(const std::string theDescription) { description = theDescription; }

//navigation function to handle game play while the player is in the billiards room
int billiardsNavigate(std::unordered_map<std::string, std::string>& inventory) {

	//boolean to find out if player wants to move to another room
	bool move = false;
	int firstTime = 0;

	//intialize objects
	PoolTable poolTable;
	CoffeeTable coffeeTable;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Billiards Room\n\n\n\n" <<
		"Sherlock is in the Billiards Room.\n\nLooking around, he sees a Pool Table in the center of the room and in the corner of the room there is a coffee table.\n\nLook at Pool Table? (Enter \"Look at pool table\").\n\n" <<
		"Go over to look at Coffee Table? (Enter \"Look at coffee table\").\n\n" <<
		"You may go to the Deck outside (Enter \"Deck\")\n\nYou may go into the Study (Enter \"Study\").\n\n" <<
		"You may walk into the Smoking Room (Enter \"Smoking room\")\n\nYou may go into the Ballroom (Enter \"Ballroom\").\n\n" <<
		"Check your inventory of items ( Enter \"Check inventory\").\n\n" <<
		"What would you like to do?";

	//choice from player
	std::string choice;
	int retry = 0;
	std::string ans;
	int intChoice;

	//inspect the room
	do {

		//navigation choice
		retry = 0;

		do
		{
			if (retry > 0)
			{
				std::cout << "\n\nPlease select a number between 1 and 7 to navigate: \n\n";
			}
			else {
				if (firstTime != 0) {
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "\n\nThe Billiards Room\n\n\n\n" <<
						"Sherlock is in the Billiards Room.\n\nLooking around, he sees a Pool Table in the center of the room and in the corner of the room there is a coffee table.\n\nLook at Pool Table? (Enter \"Look at pool table\").\n\n" <<
						"Go over to look at Coffee Table? (Enter \"Look at coffee table\").\n\n" <<
						"You may go to the Deck outside (Enter \"Deck\")\n\nYou may go into the Study (Enter \"Study\").\n\n" <<
						"You may walk into the Smoking Room (Enter \"Smoking room\")\n\nYou may go into the Ballroom (Enter \"Ballroom\").\n\n" <<
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

		} while ((choice.compare("Look at pool table") != 0) && (choice.compare("Look at coffee table") != 0) && (choice.compare("Deck") != 0) &&
			(choice.compare("Study") != 0) && (choice.compare("Smoking room") != 0) && (choice.compare("Ballroom") != 0) && (choice.compare("Check inventory") != 0));


		//take users choice and interact based on that
		if ((choice.compare("Deck") == 0) || (choice.compare("Study") == 0) || (choice.compare("Smoking room") == 0) || ((choice.compare("Ballroom") == 0)
			&& (choice.compare("Check inventory") == 0))) {
			intChoice = movePlayerFromBilliards(choice);
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
			inspectBilliardsObj(choice, inventory);
		}

	} while (!move);

	return intChoice;
}