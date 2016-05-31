/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/26/16
* Last Modification Date:	5/26/16
* Filename:				ServantsSource.cpp
*
* Overview:
*	This file holds the implementation for the Servants Room objects.
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
//included for sleeping functionality
#include <chrono>
#include <thread>
#include <vector>

//guards for header
#include "ServantsHeader.h"

//member function for Trash
void Trash::checkTrash(std::unordered_map<std::string, std::string>& inv)
{
	//initialize the couch object
	Trash trash;

	//user input var
	std::string ans;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Trash\n\n\n\n";

	std::cout << "\nWalking towards the trash can, you note: " << getDescription() << "\n\n";

	//check if wrapper is already in inventory
	auto search = inv.find("wrapper");
	if (search != inv.end()){
		std::cout << "\nYou look into the trash can and don't see anything now that you've grabbed the wrapper.\n\n" <<
			"\n\"Not a speck of trash! Wonderful service here!\" you say out loud for Mrs. White to hear.\n\n\n";
	}
	else{

		std::cout << "\nYou look into the trash can and don't see much of anything.\n\n" <<
			"\n\"The maid must do a great job cleaning up around here!\" you say out loud for Mrs. White to hear.\n\n\n" <<
			"You only see a " << getWrapper() << " in the bin.\n\n";

		std::cout << "\nWould you like to add the " << getWrapper() << " to your inventory?\n\n";

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
			inv.insert({ "wrapper", getWrapper() });
			std::cout << "\nOkay, " << getWrapper() << " added to inventory.\n\n";
		}
		else{
			std::cout << "\nOkay, " << getWrapper() << " not added to inventory.\n\n";
		}
	}
}

//Accessor Functions for accessing private variables in Trash.
std::string Trash::getWrapper() const { return wrapper; }

std::string Trash::getDescription() const { return description; }

//Mutator Functions to change private variables.
void Trash::setWrapper(const std::string theWrapper){ wrapper = theWrapper; }

void Trash::setDescription(const std::string theDescription){ description = theDescription; }


//member function to output information provided of each item
void MrsWhite::personInformation(std::unordered_map<std::string, std::string>& inventory)
{
	std::cout << "Description of the woman is : " << this->description << "\n\n\n";
}


void MrsWhite::getPassword(std::unordered_map<std::string, std::string>& inventory){

	//initialize mrsWhite object
	MrsWhite mrsWhite;

	//check if the cigarettes is already in inventory
	auto search = inventory.find("cigs");
	if (search != inventory.end()){

		//check if password is already in inventory
		search = inventory.find("password");
		if (search != inventory.end()){
			//already have secret note
			std::cout << "\n\nMrs. White \"Sir, I appreciate the extra cigarettes. I hope you can put that password to good use.\"\n\n";
		}
		else{
			//get password info 
			std::cout << mrsWhite.getPass();
			std::cout << "\n\nYou give Mrs. White a cigarette from your inventory.\n\n";
			std::cout << mrsWhite.getPassTwo() << "\n\n";
			std::cout << getPasswordInfo() << "\n\n";
			//collect note for inventory
			inventory.insert({ "password", getPasswordInfo() });
		}
	}
	else{

		//get password info 
		std::cout << mrsWhite.getPass() << "\n\n";
	}
}

void MrsWhite::conversate(std::unordered_map<std::string, std::string>& inventory){

	//initialize mrsWhite
	MrsWhite mrsWhite;
	int firstTime = 0;
	//choice from player
	int choice = 0;
	int retry = 0;
	std::string ans;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nMrs. White\n\n\n\n";

	//output info about mr white
	mrsWhite.personInformation(inventory);

	//set up navigation
	std::cout << "Mrs. White is sitting on her bed repairing a vacuum cleaner. She looks at you as you approach and smiles.\n\n" <<
		"What would you like to ask Mrs. White? \n\n" <<
		"What have you been doing tonight? (Enter \"1\").\n\n" <<
		"Do you know who the murderer may be? (Enter \"2\").\n\n" <<
		"What's your age? (Enter \"3\") \n\n" <<
		"What do you do around here for work? (Enter \"4\").\n\n" <<
		"Is there anything else you can tell me? (Enter \"5\").\n\n" <<
		"Finished questioning her (Enter \"6\")\n\n" <<
		"Check your inventory of items (Enter \"7\").\n\n" <<
		"Choose a number between 1 and 7.";

	//inspect the room
	do{

		//navigation choice
		choice = 0;
		retry = 0;

		do
		{
			if (retry > 0)
			{
				std::cout << "\n\nPlease select a number between 1 and 7 for questioning: \n\n";
			}
			else{
				if (firstTime != 0){
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "What would you like to ask Mrs. White? \n\n" <<
						"What have you been doing tonight? (Enter \"1\").\n\n" <<
						"Do you know who the murderer may be? (Enter \"2\").\n\n" <<
						"What's your age? (Enter \"3\") \n\n" <<
						"What do you do around here for work? (Enter \"4\").\n\n" <<
						"Is there anything else you can tell me? (Enter \"5\").\n\n" <<
						"Finished questioning her (Enter \"6\")\n\n" <<
						"Check your inventory of items (Enter \"7\").\n\n" <<
						"Choose a number between 1 and 7.";
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

		} while (choice < 1 || choice > 7);


		//output responses from Mr Whtie
		switch (choice){
		case 1:
			std::cout << mrsWhite.doingTonight << "\n\n";
			break;
		case 2:
			std::cout << mrsWhite.knowMurderer << "\n\n";
			break;
		case 3:
			std::cout << "\nMrs. White \"I am the same age as my husband. We are " << mrsWhite.age << ".\"\n\n";
			break;
		case 4:
			std::cout << mrsWhite.jobDescription << "\n\n";
			break;
		case 5:
			//check as to whether she will give up the secret room or not
			getPassword(inventory);
			break;
		case 6:
			std::cout << "\nYou: \"Thank you for your time Mrs. White.\"\n\n";
			break;
		case 7:
			std::cout << "\n\nInventory contains: \n\n";
			int c = 1;
			for (auto it = inventory.begin(); it != inventory.end(); ++it){
				std::cout << c << ": " << it->second << "\n";
				c++;
			}
			break;
		}

	} while (choice != 6);

}

//Accessor Functions for accessing private variables in MrsWhite.
std::string MrsWhite::getKnowMurderer() const { return knowMurderer; }

std::string MrsWhite::getDoingTonight() const { return doingTonight; }

int MrsWhite::getAge() const { return age; }

std::string MrsWhite::getJobDescription() const { return jobDescription; }

std::string MrsWhite::getDescription() const { return description; }

std::string MrsWhite::getPass() const { return pass; }

std::string MrsWhite::getPassTwo() const { return passTwo; }

std::string MrsWhite::getPasswordInfo() const { return passwordInfo; }

//Mutator Functions to change private variables.
void MrsWhite::setKnowMurderer(const std::string theKnowMurderer){ knowMurderer = theKnowMurderer; }

void MrsWhite::setDoingTonight(const std::string theDoingTonight){ doingTonight = theDoingTonight; }

void MrsWhite::setAge(const int theAge){ age = theAge; }

void MrsWhite::setJobDescription(const std::string theJobDescription){ jobDescription = theJobDescription; }

void MrsWhite::setDescription(const std::string theDescription){ description = theDescription; }

void MrsWhite::setPass(const std::string thePass){ pass = thePass; }

void MrsWhite::setPassTwo(const std::string thePassTwo){ passTwo = thePassTwo; }

void MrsWhite::setPasswordInfo(const std::string thePasswordInfo){ passwordInfo = thePasswordInfo; }

/////Room class functions/////
//get functions
std::string RoomServants::getName() const { return name; }

int RoomServants::getNumRooms() const { return numRooms; }

int RoomServants::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomServants::getExits() const { return exits; }

std::vector<std::string> RoomServants::getObjects() const { return objects; }

std::string RoomServants::getDescription() const { return description; }

//set functions
void RoomServants::setName(const std::string theName){ name = theName; }

void RoomServants::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomServants::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomServants::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomServants::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomServants::setDescription(const std::string theDescription){ description = theDescription; }
