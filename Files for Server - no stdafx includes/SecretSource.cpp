/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				4/29/16
* Last Modification Date:	4/29/16
* Filename:					SecretSource.cpp
*
* Overview:
*	This file holds the implementation for the Secret Room objects and interaction.
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
#include "animation.hpp"

//include secret header
#include "SecretHeader.h"
#include "animation.hpp"

//member function 
void Safe::checkSafe(std::unordered_map<std::string, std::string>& inv)
{
	//initialize the fish bowl object
	Safe safe;
	//user input var
	std::string ans;
	int checkInventory = 0;
	int start_row = 4;
	int start_column = 4;
	int i;
	int speed;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nThe Safe\n\n\n\n";

	std::cout << "\nSherlock walks up to the safe and notes: " << this->description << "\n\n";

	//check if key is already in inventory
	auto search = inv.find("key");
	if (search != inv.end()) {

		std::cout << "\nUpon inspection Sherlock notices that the safe requires a key.\n\n" <<
			"Fortunately he has one on him thanks to Mr. Glass\n\n";
		
		//key unlocking animation	
		initscr();
		for (i = 1; i <= 28; i++)
		{
			printKey(start_row, start_column);
			eraseLock(6, 54, 9, 8);
			refresh();
			for (speed = 1; speed <= 55000000; speed++);

			eraseKey(start_row, start_column);
			refresh();

			printLock(6, 48, 9, 5);
			eraseLock(6, 54, 9, 8);

			start_row++;
		}
		printKey(start_row, start_column);
		eraseLock(6, 54, 9, 8);
		refresh();

		getch();
		endwin();

		//check if new will is already in inventory
		search = inv.find("new will");
		if (search != inv.end()) {
			checkInventory = 1;
		}

		//check if jfk is already in inventory
		search = inv.find("jfk");
		if (search != inv.end()) {
			//if jfk found and new will found
			if (checkInventory == 1) {
				checkInventory = 2;
			}
			//if jfk found but new will not found
			else if (checkInventory == 0) {
				checkInventory = 3;
			}

		}

		//handle output to user based on whether the new will or jfk are in the safe
		switch (checkInventory) {
		case 0: // jfk and new will not in user inventory
				//output choices
			std::cout << "In the safe, Sherlock notices that there is a document: \"" << getNewWill() << "\" and also interestingly enough " << getJfkFiles() << ".\n\n";

			//check to add new will to inventory
			std::cout << "Would you like to add a " << getNewWill() << " to your inventory?\n\n";

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
				inv.insert({ "new will", getNewWill() });
				std::cout << "\nOkay, " << getNewWill() << " added to inventory.\n\n";
			}
			else {
				std::cout << "\nOkay, " << getNewWill() << " not added to inventory.\n\n";
			}

			//check to add jfk to inventory
			std::cout << "Would you like to add " << getJfkFiles() << " to your inventory?\n\n";

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
				inv.insert({ "jfk", getJfkFiles() });
				std::cout << "\nOkay, " << getJfkFiles() << " added to inventory.\n\n";
			}
			else {
				std::cout << "\nOkay, " << getJfkFiles() << " not added to inventory.\n\n";
			}

			break;
		case 1: //only new will in user inventory
				//output choices
			std::cout << "Sherlock already grabbed the new will of Mr. Glass, but there are still " << getJfkFiles() << "\n\n";

			std::cout << "Would you like to add " << getJfkFiles() << " to your inventory?\n\n";

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
				inv.insert({ "jfk", getJfkFiles() });
				std::cout << "\nOkay, " << getJfkFiles() << " added to inventory.\n\n";
			}
			else {
				std::cout << "\nOkay, " << getJfkFiles() << " not added to inventory.\n\n";
			}
			break;
		case 2: // jfk and new will in user inventory
				//output choices
			std::cout << "The safe is empty, since you already grabbed the updated will and JFK files.\n\n";
			break;
		case 3: // jfk found but not new will in user inventory
				//output choices
			std::cout << "Sherlock already grabbed the JFK files, but there is still a document: " << getNewWill() << "\n\n";

			std::cout << "Would you like to add a " << getNewWill() << " to your inventory?\n\n";

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
				inv.insert({ "new will", getNewWill() });
				std::cout << "\nOkay, " << getNewWill() << " added to inventory.\n\n";
			}
			else {
				std::cout << "\nOkay, " << getNewWill() << " not added to inventory.\n\n";
			}
			break;
		}


	}
	else {

		std::cout << "\nUpon closer review, Sherlock notices that the safe requires a specific key to open it.\n\n" <<
			"Perhaps there is a key somewhere in the mansion ...\n\n";
	}

}

//Accessor Functions for accessing private variables in Safe.
std::string Safe::getDescription() const { return description; }

std::string Safe::getNewWill() const { return newWill; }

std::string Safe::getJfkFiles() const { return jfkFiles; }

//Mutator Functions to change private variables.
void Safe::setDescription(const std::string theDescription) { description = theDescription; }

void Safe::setNewWill(const std::string theNewWill) { newWill = theNewWill; }

//member function to output information provided of each item
int LightSwitch::checkLightSwitch(std::unordered_map<std::string, std::string>& inv) {

	//user input var
	std::string ans;
	int checkInventory = 0;
	int checkBulb = 0;
	
	int start_row = 4;
	int start_column = 4;
	int i;
	int speed;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nThe Light Switch\n\n\n\n";

	std::cout << "\nSherlock walks up to the light switch and notes: " << this->description << "\n\n" <<
		"He flips the switch but unfortunately it appears that the light bulb has gone out!\n\n";

	//check if matches is already in inventory
	auto search = inv.find("matches");
	if (search != inv.end()) {
		checkInventory = 1;
	}

	//check if candle is already in inventory
	search = inv.find("candle");
	if (search != inv.end()) {
		//if candle found and matches found
		if (checkInventory == 1) {
			checkInventory = 2;
		}
		//if candle found but matches not found
		else if (checkInventory == 0) {
			checkInventory = 3;
		}

	}

	//check if bulb is already in inventory
	search = inv.find("bulb");
	if (search != inv.end()) {
		checkBulb = 1;
	}

	//if bulb in the inventory then use to replace old bulb
	if (checkBulb == 1) {
		std::cout << "Luckily Sherlock has a spare light bulb in his inventory and he replaces the bulb and turns the light on.\n\n";
		return 1;
	}

	//handle output to user based on whether the matches or candle are in the inventory
	switch (checkInventory) {
	case 0: // matches and candle not in user inventory
			//output choices
		std::cout << "Sherlock unfortunately doesn't have anything on him to fix the lighting situation at this time.\n\n";
		return 0;
		break;
	case 1: //only matches in user inventory
			//output choices
		std::cout << "Sherlock unfortunately doesn't have a spare light bulb or something to light with his matches.\n\n";
		return 0;
		break;
	case 2: // candle and matches in user inventory
			//output choices
			
		for (i = 1; i <= 8; i++)
		{
			printCandle(start_row, start_column);
			printFlame1(start_row, start_column);
			refresh();
			for (speed = 1; speed <= 59000000; speed++);
			eraseFlame(start_row, start_column);
			refresh();

			printCandle(start_row, start_column);
			printFlame2(start_row, start_column);
			refresh();
			for (speed = 1; speed <= 59000000; speed++);
			eraseFlame(start_row, start_column);
			refresh();

			printCandle(start_row, start_column);
			printFlame3(start_row, start_column);
			refresh();
			for (speed = 1; speed <= 59000000; speed++);
			eraseFlame(start_row, start_column);
			refresh();

			printCandle(start_row, start_column);
			printFlame2(start_row, start_column);
			refresh();
			for (speed = 1; speed <= 59000000; speed++);
			eraseFlame(start_row, start_column);
			refresh();

		}
		endwin();
		std::cout << "Sherlock doesn't have a spare light bulb, but luckily he has a candle and matches to light up the room.\n\n";
		return 1;
		break;
	case 3: // candle found but not matches in user inventory
			//output choices
		std::cout << "Sherlock unfortunately doesn't have a spare light bulb or something to light his candle with.\n\n";
		return 0;
		break;
	}

	//if no other case triggered this would be an error but we will return 0 so no errors occur
	return 0;

}


//Accessor Functions for accessing private variables in Painting.
bool LightSwitch::getBroken() const { return broken; }

std::string LightSwitch::getDescription() const { return description; }

//Mutator Functions to change private variables.
void LightSwitch::setBroken(const bool theBroken) { broken = theBroken; }

void LightSwitch::setDescription(const std::string theDescription) { description = theDescription; }

//navigation function to handle game play while the player is in the secret
int secretNavigate(std::unordered_map<std::string, std::string>& inventory) {

	//boolean to find out if player wants to move to another room
	bool move = false;
	int firstTime = 0;

	//intialize objects
	LightSwitch lightSwitch;
	Safe safe;
	//ret whether there is light
	int retLight = 0;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Secret Room\n\n\n\n" <<
		"Sherlock is in the Secret Room.\n\nIt is quite dark in there, however he makes out a safe in the corner of the room.\n\n" <<
		"Feeling around he notices there is a light switch as well\n\n" <<
		"What would you like to do?\n\n"
		"Turn on the light switch? (Enter \"1\").\n\n" <<
		"Go over to examine the Safe? (Enter \"2\").\n\n" <<
		"You may go back out into the Library (Enter \"3\")\n\n" <<
		"Check your inventory of items ( Enter \"4\").\n\n" <<
		"What would you like to do? Choose a number between 1 and 5.";

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
				std::cout << "\n\nPlease select a number between 1 and 4 to navigate: \n\n";
			}
			else {
				if (firstTime != 0) {
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "\n\nThe Secret Room\n\n\n\n" <<
						"Sherlock is in the Secret Room.\n\nIt is quite dark in there, however he makes out a safe in the corner of the room.\n\n" <<
						"Feeling around he notices there is a light switch as well\n\n" <<
						"What would you like to do?\n\n"
						"Turn on the light switch? (Enter \"1\").\n\n" <<
						"Go over to examine the Safe? (Enter \"2\").\n\n" <<
						"You may go back out into the Library (Enter \"3\")\n\n" <<
						"Check your inventory of items ( Enter \"4\").\n\n" <<
						"What would you like to do? Choose a number between 1 and 5.";
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


		//take users choice and interact based on that
		switch (choice) {
		case 1:
			if (retLight != 0) { //if room is lit
				std::cout << "\n\nSherlock already has a light source for the room to navigate around.\n\n";
			}
			else {
				retLight = lightSwitch.checkLightSwitch(inventory);
			}
			//return 1 if new bulb in the inventory.. takes precedence over candle/match combo
			if (retLight == 1) {
				lightSwitch.setBroken(false);
			}
			else if (retLight == 2) { //return 2 if candle and match in the inventory
				lightSwitch.setBroken(false);
			}
			break;
		case 2:
			//if light or candle/match not in posession then can't navigate room
			if (lightSwitch.getBroken() == false) {
				safe.checkSafe(inventory);
			}
			else {
				std::cout << "\nIt's too dark in the room for Sherlock to navigate around.\n\n" <<
					"Maybe you can turn the light on or find a source of light?\n\n";
			}
			break;
		case 3:
			std::cout << "\nGoing into the Library.\n";
			//change choice to reflect our room mapping and update move
			choice = 11;
			move = true;
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

	} while (!move);

	return choice;
}
