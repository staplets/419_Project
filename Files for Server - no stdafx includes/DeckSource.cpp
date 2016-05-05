/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/20/16
* Last Modification Date:	4/21/16
* Filename:				DeckSource.cpp
*
* Overview:
*	This file holds the implementation for the Deck objects and interaction.
*
* Input:
*	The user may input several commands that will be offered to navigate and do
*    different actions throughout the game.
*
* Output:
*	The program will provide action options and a player inventory option
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
#include "animation.hpp"

//include deck header
#include "DeckHeader.h"

void inspectDeckChair(std::string objName, std::unordered_map<std::string, std::string>& inventory)
{
	//initialize object
	Chair chair;

	chair.checkChair(inventory);
}

bool inspectDeckHotTub(std::string objName, std::unordered_map<std::string, std::string>& inventory)
{
	//initialize object
	HotTub hotTub;

	std::string isWet = "no";
	bool dry = true;

	isWet = hotTub.checkHotTub(inventory);
	//if sherlock gets wet he will have to get the towel to dry off before leaving
	if (isWet == "yes")
	{
		dry = false;
	}
	std::cout << isWet << std::endl;
	return dry;
}

int movePlayerFromDeck(std::string location)
{
	int intChoice;

	if (location.compare("Dining room") == 0) {
		std::cout << "\nEntering the Dining Room.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 8;
	}
	else if (location.compare("Billiards room") == 0) {
		std::cout << "\nEntering the Billiards Room.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 7;
	}
	else if (location.compare("Kitchen") == 0) {
		std::cout << "\nEntering the Kitchen.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 9;
	}
	else {
		std::cout << "\nWalking Out to the Garden.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 3;
	}

	return intChoice;
}

//member function to output information provided of each item in CoatCloset
void Chair::chairInformation(std::unordered_map<std::string, std::string>& inv)
{
	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nThe Deck Chair\n\n\n\n";

	std::cout << "\nFrom inspection of the deck chair, you note the following:\n";

	std::cout << "\n\nThe wood color is : " << this->color << "\n\nThere are " << this->numBirds << " birds sitting on the chair.\n\n\n";

}

//member function to get into the trunk of Chair
void Chair::checkChair(std::unordered_map<std::string, std::string>& inv)
{
	//user input var
	std::string ans;
	Chair chair;

	//output details
	chair.chairInformation(inv);

	//check if towel is already in inventory
	auto search = inv.find("towel");
	if (search != inv.end()) {
		std::cout << "\nThere is nothing besides the birds. You have already grabbed the towel from here.\n\n";
	}
	else {

		std::cout << "\nUnderneath the birds there is also a " << getTowel() << "\n\n";

		std::cout << "Would you like to add this item to your inventory?\n\n";

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
			inv.insert({ "towel", getTowel() });
			std::cout << "\nOkay, " << getTowel() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getTowel() << " not added to inventory.\n\n";
		}
	}

}

//Accessor Functions for accessing private variables in CoatCloset.
std::string Chair::getColor() const { return color; }

int Chair::getNumBirds() const { return numBirds; }

std::string Chair::getTowel() const { return towel; }

//Mutator Functions to change private variables.
void Chair::setColor(const std::string theColor) { color = theColor; }

void Chair::setNumBirds(const int theNumBirds) { numBirds = theNumBirds; }

void Chair::setTowel(const std::string theTowel) { towel = theTowel; }


//member function to output information provided of each item
void HotTub::hotTubInformation()
{
	std::cout << "Description: " << this->description << "\n\n";
}

std::string HotTub::checkHotTub(std::unordered_map<std::string, std::string>& inventory) {

	//initialize the fish bowl object
	HotTub hotTub;
	int firstTime = 0;
	int start_row = 4;
	int start_column = 4;
	int i;
	int speed;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nHot Tub\n\n\n\n";

	//get hot tub info
	hotTub.hotTubInformation();

	//output choices
	std::cout << "Outside of looking luxurious, Sherlock only sees a hair in the hot tub. He could also take a dip if he feels so inclined.\"\n\n" <<
		"What would you like to do? \n\nInspect the hair? (Enter \"1\").\n\n" <<
		"Get in the hot tub? (Enter \"2\").\n\n" <<
		"Finished with Hot Tub (Enter \"3\")\n\n" <<
		"Check your inventory of items ( Enter \"4\").\n\n" <<
		"Choose a number between 1 and 4.";

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
				std::cout << "\n\nPlease select a number between 1 and 4 for questioning: \n\n";
			}
			else {
				if (firstTime != 0) {
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "\n\nHot Tub\n\n\n\n" <<
						"Outside of looking luxurious, Sherlock only sees a hair in the hot tub. He could also take a dip if he feels so inclined.\"\n\n" <<
						"What would you like to do? \n\nInspect the hair? (Enter \"1\").\n\n" <<
						"Get in the hot tub? (Enter \"2\").\n\n" <<
						"Finished with Hot Tub (Enter \"3\")\n\n" <<
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
			std::cout << "\nThe hair is a " << getHair() << " and is floating along the side of the hot tub.\n\n";

			std::cout << "Would you like to add this item to your inventory?\n\n";

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
				inventory.insert({ "hair", getHair() });
				std::cout << "\nOkay, " << getHair() << " added to inventory.\n\n";
			}
			else {
				std::cout << "\nOkay, " << getHair() << " not added to inventory.\n\n";
			}
			break;
		case 2:
			std::cout << "\nSherlock: \"Lovely night for a dip I say ... \"\n\n";
			
		//animation of dripping clothes
			initscr();
			printSherlock(start_row, start_column);
			for (i = 0; i < 19; i++)
			{
				printDrops1(start_row, start_column);
				refresh();
				eraseDrops1(start_row, start_column);
				start_row = start_row + 1;
				for (speed = 1; speed <= 56000000; speed++);
			}
			refresh();
			for (speed = 1; speed <= 5500000; speed++);
			start_row = start_row - 19;
			for (i = 0; i < 19; i++)
			{
				printDrops2(start_row, start_column);
				refresh();
				eraseDrops2(start_row, start_column);
				start_row = start_row + 1;
				for (speed = 1; speed <= 56000000; speed++);
			}
			refresh();
			for (speed = 1; speed <= 5500000; speed++);
			start_row = start_row - 19;
			for (i = 0; i < 19; i++)
			{
				printDrops1(start_row, start_column);
				refresh();
				eraseDrops1(start_row, start_column);
				start_row = start_row + 1;
				for (speed = 1; speed <= 56000000; speed++);
			}
			getch();
			endwin();
			
			std::cout << "Sherlock is now all wet. Maybe not the greatest idea.\n\n";
			setWet("yes");
			break;
		case 3:
			std::cout << "\nSherlock: \"Enough with this hot tub.\"\n\n";
			break;
		case 4:
			std::cout << "\n\nInventory contains: \n\n";
			int c = 1;
			for (auto it = inventory.begin(); it != inventory.end(); ++it) {
				std::cout << c << ": " << it->second << "\n";
				c++;
			}
			break;
		}

	} while (choice != 3);

	//return whether wet or not
	return getWet();
}


//Accessor Functions for accessing private variables in HotTub.
std::string HotTub::getHair() const { return hair; }

std::string HotTub::getDescription() const { return description; }

std::string HotTub::getWet() const { return wet; }

//Mutator Functions to change private variables.
void HotTub::setHair(const std::string theHair) { hair = theHair; }

void HotTub::setDescription(const std::string theDescription) { description = theDescription; }

void HotTub::setWet(const std::string theWet) { wet = theWet; }

//navigation function to handle game play while the player is in the deck
int deckNavigate(std::unordered_map<std::string, std::string>& inventory) {

	//boolean to find out if player wants to move to another room
	bool move = false;
	int firstTime = 0;

	//check whether player is dry before leaving room
	bool dry = true;
	std::string isWet = "no";

	//intialize objects
	Chair chair;
	HotTub hotTub;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Deck\n\n\n\n" <<
		"Sherlock is on the Deck outside of the Mansion.\n\nLooking around, there is a Chair you may want to take a look at (Enter \"Inspect chair\").\n\n" <<
		"There is also a hot tub you may examine more closely (Enter \"Examine hot tub\").\n\n" <<
		"You may enter the Dining Room (Enter \"Dining room\")\n\nYou may enter the Billiards Room (Enter \"Billiards room\").\n\n" <<
		"You may enter the Kitchen (Enter \"Kitchen\").\n\nYou may go out to the Garden (Enter \"Garden\").\n\n" <<
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

					std::cout << "\n\nThe Deck\n\n\n\n" <<
						"Sherlock is on the Deck outside of the Mansion.\n\nLooking around, there is a Chair you may want to take a look at (Enter \"Inspect chair\").\n\n" <<
						"There is also a hot tub you may examine more closely (Enter \"Examine hot tub\").\n\n" <<
						"You may enter the Dining Room (Enter \"Dining room\")\n\nYou may enter the Billiards Room (Enter \"Billiards room\").\n\n" <<
						"You may enter the Kitchen (Enter \"Kitchen\").\n\nYou may go out to the Garden (Enter \"Garden\").\n\n" <<
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
				std::cout << "\n\nPlease enter a valid option (Inspect chair, Examine hot tub, Dining room, Billiards room, Kitchen, Garden or Check inventory) : \n\n";
				std::cin >> choice;
			}
			retry++;
			firstTime++;

		} while ((choice.compare("Inspect chair") != 0) && (choice.compare("Examine hot tub") != 0) && (choice.compare("Dining room") != 0)
			&& (choice.compare("Billiards room") != 0) && (choice.compare("Kitchen") != 0) && (choice.compare("Garden") != 0) && (choice.compare("Check inventory") != 0));


		if ((dry != true) && ((choice.compare("Dining room") == 0) || (choice.compare("Billiards room") == 0) || (choice.compare("Kitchen") == 0)
			|| (choice.compare("Garden") == 0))) {
			std::cout << "\n\nSherlock appears to be wet from messing around in the hot tub.\n\n";

			//check if towel is already in inventory
			auto search = inventory.find("towel");
			if (search != inventory.end()) {
				std::cout << "\nLooks like you have a towel in your inventory. Dry off?\n\n";

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
					dry = true;
					std::cout << "\nOkay, he's dried off. He can now leave the room.\n\n";
				}
				else {
					std::cout << "\nOkay, he's not dried off, but he will need to dry off before leaving the deck.\n\n";
					//skip the option to leave
					//choice = 0;
					choice = "Is still wet";
				}
			}
			else {
				std::cout << "\nSherlock can't leave the deck without drying off! Perhaps there is a towel somewhere around here ...\n\n";
				//skip the option to leave
				//choice = 0;
				choice = "Is still wet";
			}
		}

		//take users choice and interact based on that
		if (choice.compare("Is still wet") == 0) { //is user is wet can't leave
			move = false;
		}
		else if (choice.compare("Dining room") == 0 || choice.compare("Billiards room") == 0 || choice.compare("Kitchen") == 0 || choice.compare("Garden") == 0) {
			//std::cout << choice << std::endl;
			intChoice = movePlayerFromDeck(choice);
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
			//std::cout << choice << std::endl;
			if (choice.compare("Inspect chair") == 0) {
				inspectDeckChair(choice, inventory);
			}
			else {
				dry = inspectDeckHotTub(choice, inventory);
			}
		}

	} while (!move);

	return intChoice;
}
