/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/02/16
* Last Modification Date:	5/02/16
* Filename:					DiningSource.cpp
*
* Overview:
*	This file holds the implementation for the Dining Room objects and interaction.
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

//include dining header
#include "DiningHeader.h"

//member function to talk with parrot
void Parrot::convoParrot(std::unordered_map<std::string, std::string>& inv)
{
	//initialize the parrott
	Parrot parrot;
	int firstTime = 0;
	//choice from player
	int choice = 0;
	int retry = 0;
	std::string ans;

	//initialize random seed
	srand((unsigned int)time(NULL));

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nThe Parrot\n\n\n\n";

	std::cout << "\nWalking towards the bird, Sherlock notes: " << getDescription() << "\n\n";

	//set up navigation
	std::cout << "The parrot turns it's head towards Sherlock as he comes near in his own cross examination of the approaching human.\n\n" <<
		"Sherlock can try to see if the parrot will repeat anything it overheard.\n\n" <<
		"Otherwise nothing stands out from an examination of the cage.\n\n" <<
		"Talk to parrot? (Enter \"1\").\n\n" <<
		"Finished with parrot (Enter \"2\")\n\n" <<
		"Check your inventory of items (Enter \"3\").\n\n" <<
		"Choose a number between 1 and 3.";

	//inspect the room
	do {

		//navigation choice
		choice = 0;
		retry = 0;

		//get random number between 1 and 3 to time a smack on the spider
		int parrotReply = rand() % 2 + 1;

		do
		{
			if (retry > 0)
			{
				std::cout << "\n\nPlease select a number between 1 and 3 for questioning: \n\n";
			}
			else {
				if (firstTime != 0) {
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "Sherlock can try to see if the parrot will repeat anything it overheard.\n\n" <<
						"Talk to parrot? (Enter \"1\").\n\n" <<
						"Finished with parrot (Enter \"2\")\n\n" <<
						"Check your inventory of items (Enter \"3\").\n\n" <<
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


		//output responses from the parrot
		switch (choice) {
		case 1:
			//output parrots reply depending on random number
			if (parrotReply == 1) {
				std::cout << "\n\nSherlock speaks to the bird in hopes of getting a response. The parrot replies: \n";
				std::cout << parrot.speak << "\n\n";
			}
			else if (parrotReply == 2) {
				std::cout << "\n\nSherlock speaks to the bird in hopes of getting a response. The parrot replies: \n";
				std::cout << parrot.speakTwo << "\n\n";
			}
			break;
		case 2:
			std::cout << "\nSherlock: \"See you later Polly.\"\n\n";
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

//Accessor Functions for accessing private variables in Parrot.
std::string Parrot::getDescription() const { return description; }

std::string Parrot::getSpeak() const { return speak; }

std::string Parrot::getSpeakTwo() const { return speakTwo; }

//Mutator Functions to change private variables.
void Parrot::setDescription(const std::string theDescription) { description = theDescription; }

void Parrot::setSpeak(const std::string theSpeak) { speak = theSpeak; }

void Parrot::setSpeakTwo(const std::string theSpeakTwo) { speakTwo = theSpeakTwo; }


//member function to output information provided of each item
void DiningTable::checkDiningTable(std::unordered_map<std::string, std::string>& inv) {

	//user input var
	std::string ans;
	int checkInventory = 0;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nThe Dining Table\n\n\n\n";

	std::cout << "\nUpon further examination, Sherlock notes: " << getDescription() << "\n\n";

	//check if wine glass is already in inventory
	auto search = inv.find("lipstick glass");
	if (search != inv.end()) {
		checkInventory = 1;
	}

	//check if handkerchief is already in inventory
	search = inv.find("handk");
	if (search != inv.end()) {
		//if handk found and wglass found
		if (checkInventory == 1) {
			checkInventory = 2;
		}
		//if handk found but wglass not found
		else if (checkInventory == 0) {
			checkInventory = 3;
		}

	}

	//handle output to user based on whether the wglass or handk are on the table
	switch (checkInventory) {
	case 0: // handk and wglass not in user inventory
			//output choices
		std::cout << "Sherlock takes note of a " << getLipGlass() << " and a " << getHandk() << " and wonders if they would be worthwhile evidence.\n\n";

		//check to add lipstick glass to inventory
		std::cout << "Would you like to add a " << getLipGlass() << " to your inventory?\n\n";

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
			inv.insert({ "lipstick glass", getLipGlass() });
			std::cout << "\nOkay, " << getLipGlass() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getLipGlass() << " not added to inventory.\n\n";
		}

		//check to add handk to inventory
		std::cout << "Would you like to add a " << getHandk() << " to your inventory?\n\n";

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
			inv.insert({ "handk", getHandk() });
			std::cout << "\nOkay, " << getHandk() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getHandk() << " not added to inventory.\n\n";
		}

		break;
	case 1: //only wine glass in user inventory
			//output choices
		std::cout << "Sherlock takes note of the " << getHandk() << ", since he already grabbed the wine glass and wonders if it would be worthwhile evidence.\n\n";

		std::cout << "Would you like to add a " << getHandk() << " to your inventory?\n\n";

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
			inv.insert({ "handk", getHandk() });
			std::cout << "\nOkay, " << getHandk() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getHandk() << " not added to inventory.\n\n";
		}
		break;
	case 2: // handk and wine glass in user inventory
			//output choices
		std::cout << "There is still some miscellaneous food scraps on the table, but Sherlock has already collected the wine glass and handkerchief.\n\n";
		break;
	case 3: // handk found but not wine glass in user inventory
			//output choices
		std::cout << "Sherlock takes note of the " << getLipGlass() << ", since he already grabbed a " << getHandk() << "\n\nand wonders if it would be worthwhile evidence.\n\n";

		std::cout << "Would you like to add a " << getLipGlass() << " to your inventory?\n\n";

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
			inv.insert({ "lipstick glass", getLipGlass() });
			std::cout << "\nOkay, " << getLipGlass() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getLipGlass() << " not added to inventory.\n\n";
		}
		break;
	}

}


//Accessor Functions for accessing private variables in DiningTable.
std::string DiningTable::getHandk() const { return handk; }

std::string DiningTable::getDescription() const { return description; }

std::string DiningTable::getLipGlass() const { return lipGlass; }

//Mutator Functions to change private variables.
void DiningTable::setHandk(const std::string theHandk) { handk = theHandk; }

void DiningTable::setDescription(const std::string theDescription) { description = theDescription; }

void DiningTable::setLipGlass(const std::string theLipGlass) { lipGlass = theLipGlass; }

//navigation function to handle game play while the player is in the dining room
int diningNavigate(std::unordered_map<std::string, std::string>& inventory) {

	//boolean to find out if player wants to move to another room
	bool move = false;
	int firstTime = 0;

	//intialize objects
	DiningTable diningTable;
	Parrot parrot;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Dining Room\n\n\n\n" <<
		"Sherlock is in the Dining Room.\n\nIn the center of the room, there is an exquisite Dining Table.\n\n" <<
		"In the corner of the room there is also a Parrot.\n\n" <<
		"Look at Dining Table? (Enter \"1\").\n\n" <<
		"Go over to see the Parrot? (Enter \"2\").\n\n" <<
		"You may go to the Deck outside (Enter \"3\")\n\n" <<
		"You may go into the Kitchen (Enter \"4\").\n\n" <<
		"You may walk into the Foyer (Enter \"5\").\n\n" <<
		"Check your inventory of items ( Enter \"6\").\n\n" <<
		"What would you like to do? Choose a number between 1 and 6.";

	//choice from player
	int choice = 0;
	int retry = 0;
	std::string ans;

	//inspect the room
	do {

		//navigation choice
		choice = 0;
		retry = 0;

		do
		{
			if (retry > 0)
			{
				std::cout << "\n\nPlease select a number between 1 and 6 to navigate: \n\n";
			}
			else {
				if (firstTime != 0) {
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "\n\nThe Dining Room\n\n\n\n" <<
						"Sherlock is in the Dining Room.\n\nIn the center of the room, there is an exquisite Dining Table.\n\n" <<
						"In the corner of the room there is also a Parrot.\n\n" <<
						"Look at Dining Table? (Enter \"1\").\n\n" <<
						"Go over to see the Parrot? (Enter \"2\").\n\n" <<
						"You may go to the Deck outside (Enter \"3\")\n\n" <<
						"You may go into the Kitchen (Enter \"4\").\n\n" <<
						"You may walk into the Foyer (Enter \"5\").\n\n" <<
						"Check your inventory of items ( Enter \"6\").\n\n" <<
						"What would you like to do? Choose a number between 1 and 6.";
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

		} while (choice < 1 || choice > 6);


		//take users choice and interact based on that
		switch (choice) {
		case 1:
			diningTable.checkDiningTable(inventory);
			break;
		case 2:
			parrot.convoParrot(inventory);
			break;
		case 3:
			std::cout << "\nGoing out to the Deck.\n";
			//change choice to reflect our room mapping and update move
			choice = 13;
			move = true;
			break;
		case 4:
			std::cout << "\nWalking into the Kitchen.\n";
			//change choice to reflect our room mapping and update move
			choice = 9;
			move = true;
			break;
		case 5:
			std::cout << "\nGoing into the Foyer.\n";
			//change choice to reflect our room mapping and update move
			choice = 2;
			move = true;
			break;
		case 6:
			std::cout << "\n\nInventory contains: \n\n";
			int c = 1;
			for (auto it = inventory.begin(); it != inventory.end(); ++it) {
				std::cout << c << ": " << it->second << "\n";
				c++;
			}
			break;
		}

	} while (!move);

	return choice;
}