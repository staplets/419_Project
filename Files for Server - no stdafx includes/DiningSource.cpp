/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/22/16
* Last Modification Date:	     5/22/16
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
#include <vector>

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

	std::cout << "\nWalking towards the bird, you note: " << getDescription() << "\n\n";

	//set up navigation
	std::cout << "The parrot turns it's head towards you as you come near in its own cross examination of your approach.\n\n" <<
		"You can try to see if the parrot will repeat anything it overheard.\n\n" <<
		"Otherwise nothing stands out from an examination of the cage.\n\n" <<
		"Talk to parrot? (Enter \"1\").\n\n" <<
		"Finished with parrot (Enter \"2\")\n\n" <<
		"Check your inventory of items (Enter \"3\").\n\n" <<
		"Choose a number between 1 and 3.";

	//inspect the room
	do{

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
			else{
				if (firstTime != 0){
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "You can try to see if the parrot will repeat anything it overheard.\n\n" <<
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
		switch (choice){
		case 1:
			//output parrots reply depending on random number
			if (parrotReply == 1){
				std::cout << "\n\nYou speak to the bird in hopes of getting a response. The parrot replies: \n";
				std::cout << parrot.speak << "\n\n";
			}
			else if (parrotReply == 2){
				std::cout << "\n\nYou speak to the bird in hopes of getting a response. The parrot replies: \n";
				std::cout << parrot.speakTwo << "\n\n";
			}
			break;
		case 2:
			std::cout << "\nYou: \"See you later Polly.\"\n\n";
			break;
		case 3:
			std::cout << "\n\nInventory contains: \n\n";
			int c = 1;
			for (auto it = inv.begin(); it != inv.end(); ++it){
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
void Parrot::setDescription(const std::string theDescription){ description = theDescription; }

void Parrot::setSpeak(const std::string theSpeak){ speak = theSpeak; }

void Parrot::setSpeakTwo(const std::string theSpeakTwo){ speakTwo = theSpeakTwo; }


//member function to output information provided of each item
void DiningTable::checkDiningTable(std::unordered_map<std::string, std::string>& inv){

	//user input var
	std::string ans;
	int checkInventory = 0;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nThe Dining Table\n\n\n\n";

	std::cout << "\nUpon further examination, you note: " << getDescription() << "\n\n";

	//check if wine glass is already in inventory
	auto search = inv.find("lipstick glass");
	if (search != inv.end()){
		checkInventory = 1;
	}

	//check if handkerchief is already in inventory
	search = inv.find("handk");
	if (search != inv.end()){
		//if handk found and wglass found
		if (checkInventory == 1){
			checkInventory = 2;
		}
		//if handk found but wglass not found
		else if (checkInventory == 0){
			checkInventory = 3;
		}

	}

	//handle output to user based on whether the wglass or handk are on the table
	switch (checkInventory){
	case 0: // handk and wglass not in user inventory
		//output choices
		std::cout << "You take note of a " << getLipGlass() << " and a " << getHandk() << " and wonder if they would be worthwhile evidence.\n\n";

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

		if (ans == "y"){
			inv.insert({ "lipstick glass", getLipGlass() });
			std::cout << "\nOkay, " << getLipGlass() << " added to inventory.\n\n";
		}
		else{
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

		if (ans == "y"){
			inv.insert({ "handk", getHandk() });
			std::cout << "\nOkay, " << getHandk() << " added to inventory.\n\n";
		}
		else{
			std::cout << "\nOkay, " << getHandk() << " not added to inventory.\n\n";
		}

		break;
	case 1: //only wine glass in user inventory
		//output choices
		std::cout << "You take note of the " << getHandk() << ", since you already grabbed the wine glass and wonder if it would be worthwhile evidence.\n\n";

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

		if (ans == "y"){
			inv.insert({ "handk", getHandk() });
			std::cout << "\nOkay, " << getHandk() << " added to inventory.\n\n";
		}
		else{
			std::cout << "\nOkay, " << getHandk() << " not added to inventory.\n\n";
		}
		break;
	case 2: // handk and wine glass in user inventory
		//output choices
		std::cout << "There is still some miscellaneous food scraps on the table, but you have already collected the wine glass and handkerchief.\n\n";
		break;
	case 3: // handk found but not wine glass in user inventory
		//output choices
		std::cout << "You take note of the " << getLipGlass() << ", since you already grabbed a " << getHandk() << "\n\nand wonder if it would be worthwhile evidence.\n\n";

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

		if (ans == "y"){
			inv.insert({ "lipstick glass", getLipGlass() });
			std::cout << "\nOkay, " << getLipGlass() << " added to inventory.\n\n";
		}
		else{
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
void DiningTable::setHandk(const std::string theHandk){ handk = theHandk; }

void DiningTable::setDescription(const std::string theDescription){ description = theDescription; }

void DiningTable::setLipGlass(const std::string theLipGlass){ lipGlass = theLipGlass; }

/////Room class functions/////
//get functions
std::string RoomDining::getName() const { return name; }

int RoomDining::getNumRooms() const { return numRooms; }

int RoomDining::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomDining::getExits() const { return exits; }

std::vector<std::string> RoomDining::getObjects() const { return objects; }

std::string RoomDining::getDescription() const { return description; }

//set functions
void RoomDining::setName(const std::string theName){ name = theName; }

void RoomDining::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomDining::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomDining::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomDining::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomDining::setDescription(const std::string theDescription){ description = theDescription; }
