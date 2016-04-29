/***********************************************************
* Author:					Shaun Stapleton, Robyn Lin
* Date Created:			4/24/16
* Last Modification Date:	4/24/16
* Filename:				SmokingSource.cpp
*
* Overview:
*	This file holds the implementation for the Smoking Room objects and interaction.
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

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

//include hallway header
#include "SmokingHeader.h"

void inspectSmokingObj(std::string objName, std::unordered_map<std::string, std::string>& inventory)
{
	//intialize objects
	RecliningChair recliningChair;
	Painting painting;

	if (objName.compare("Examine reclining chair") == 0) { //if object is reclining chair
		recliningChair.checkRecliningChair(inventory);
	}
	else {
		painting.checkPainting(inventory);
	}
}

int movePlayerFromSmoking(std::string location)
{
	int intChoice;
	if (location.compare("Kitchen") == 0) {
		std::cout << "\nEntering the Kitchen.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 9;
	}
	else if (location.compare("Sitting room") == 0) {
		std::cout << "\nEntering the Sitting Room.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 5;
	}
	else {
		std::cout << "\nEntering the Billiards Room.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 7;
	}
	return intChoice;
}

//member function 
void RecliningChair::checkRecliningChair(std::unordered_map<std::string, std::string>& inv)
{
	//user input var
	std::string ans;

	//initialize random seed
	srand((unsigned int)time(NULL));

	//get random number between 1 and 3 to time a smack on the spider
	int catchSpider = rand() % 3 + 1;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nThe Reclining Chair\n\n\n\n";

	std::cout << "\nFrom closer inspection of the recliner, Sherlock notes: " << getDescription() << "\n\n";

	//check if pipe is already in inventory
	auto search = inv.find("pipe");
	if (search != inv.end()){
		std::cout << "\nThe recliner has nothing of note as Sherlock already grabbed the " << getPipe() << " that interested him.\n\n";
	}
	else{

		std::cout << "\nSherlock notices a " << getPipe() << " on the recliner, which catches his eye.\n\n";

		std::cout << "Would you like to add the " << getPipe() << " to your inventory?\n\n";

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
			inv.insert({ "pipe", getPipe() });
			std::cout << "\nOkay, " << getPipe() << " added to inventory.\n\n";
		}
		else{
			std::cout << "\nOkay, " << getPipe() << " not added to inventory.\n\n";
		}
	}

}

//Accessor Functions for accessing private variables in RecliningChair.
std::string RecliningChair::getDescription() const { return description; }

std::string RecliningChair::getPipe() const { return pipe; }

//Mutator Functions to change private variables.
void RecliningChair::setDescription(const std::string theDescription){ description = theDescription; }

void RecliningChair::setPipe(const std::string thePipe){ pipe = thePipe; }


//member function to output information provided of each item
void Painting::checkPainting(std::unordered_map<std::string, std::string>& inv){

	//initialize the painting object
	Painting painting;
	int firstTime = 0;
	//user input var
	std::string ans;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Painting\n\n\n\n";

	//coffee table info
	std::cout << "\nWalking over to the painting, Sherlock notes: " << getDescription() << "\n\n";

	//check if knife is already in inventory
	auto search = inv.find("knife");
	if (search != inv.end()){
		std::cout << "\nSherlock admires the painting, however he notices it may be hanging a bit askew.\n\n" <<
			"He thinks there may be something behind it, but it appears to be stuck to the wall.\n\n" <<
			"No worries! You have a knife on you to try and pry this thing open.\n\n";

		std::cout << "Would you like to try and pry the painting off the wall?\n\n";

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

			//check if revolver is already in inventory
			auto search = inv.find("revolver");
			if (search != inv.end()){
				std::cout << "\n\nSherlock uses the knife and is able to open the painting from the right side with what appears to be hinges.\n\n" <<
					"There is a small hiding spot behind the painting, however Sherlock has already grabbed the revolver.\n\n";
			}
			else{

				std::cout << "\n\nSherlock uses the knife and is able to open the painting from the right side with what appears to be hinges.\n\n" <<
					"There is a small hiding spot behind the painting where a revolver sits.\n\nWould you like to add the revolver to the inventory?\n\n";

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
					inv.insert({ "revolver", getRevolver() });
					std::cout << "\nOkay, " << getRevolver() << " added to inventory.\n\n";
				}
				else{
					std::cout << "\nOkay, " << getRevolver() << " not added to inventory.\n\n";
				}
			}
		}
		else{
			//user decides not to pull forward painting
			std::cout << "\nOkay, Sherlock leave the painting as is.\n\n";
		}

	}
	else{

		std::cout << "\nSherlock admires the painting, however he notices it may be hanging a bit askew.\n\n" <<
			"He thinks there may be something behind it, but it appears to be stuck to the wall.\n\n" <<
			"Perhaps if you had something sharp with you, such as a knife, you could pry it open ...\n\n";
	}
}


//Accessor Functions for accessing private variables in Painting.
std::string Painting::getRevolver() const { return revolver; }

std::string Painting::getDescription() const { return description; }

//Mutator Functions to change private variables.
void Painting::setRevolver(const std::string theRevolver){ revolver = theRevolver; }

void Painting::setDescription(const std::string theDescription){ description = theDescription; }

//navigation function to handle game play while the player is in the smoking room
int smokingRoomNavigate(std::unordered_map<std::string, std::string>& inventory){

	//boolean to find out if player wants to move to another room
	bool move = false;
	int firstTime = 0;

	//intialize objects
	RecliningChair recliningChair;
	Painting painting;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Smoking Room\n\n\n\n" <<
		"Sherlock is in the Smoking Room.\n\nLooking around, he sees a Reclining Chair and also sees a painting on the wall that it noteworthy.\n\n" <<
		"Examine the Reclining Chair? (Enter \"Examine reclining chair\").\n\n" <<
		"Go over to look at Painting? (Enter \"Look at painting\").\n\n" <<
		"You may go into the Kitchen (Enter \"Kitchen\")\n\nYou may go into the Sitting Room (Enter \"Sitting room\").\n\n" <<
		"You may walk into the Billiards Room (Enter \"Billiards room\")\n\n" <<
		"Check your inventory of items ( Enter \"Check inventory\").\n\n" <<
		"What would you like to do?";

	//choice from player
	std::string choice;
	int intChoice;
	int retry = 0;
	std::string ans;

	//inspect the room
	do{

		//navigation choice
		retry = 0;

		do
		{
			if (retry > 0)
			{
				std::cout << "\n\nPlease enter an option to navigate: \n\n";
			}
			else{
				if (firstTime != 0){
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "\n\nThe Smoking Room\n\n\n\n" <<
						"Sherlock is in the Smoking Room.\n\nLooking around, he sees a Reclining Chair and also sees a painting on the wall that it noteworthy.\n\n" <<
						"Examine the Reclining Chair? (Enter \"Examine reclining chair\").\n\n" <<
						"Go over to look at Painting? (Enter \"Look at painting\").\n\n" <<
						"You may go into the Kitchen (Enter \"Kitchen\")\n\nYou may go into the Sitting Room (Enter \"Sitting room\").\n\n" <<
						"You may walk into the Billiards Room (Enter \"Billiards room\")\n\n" <<
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
				std::cout << "\n\nPlease enter a valid option (Examining reclining chair, Look at painting, Kitchen, Sitting room, Billiards room or Check inventory) : \n\n";
				std::cin >> choice;
			}
			retry++;
			firstTime++;

		} while ((choice.compare("Examine reclining chair") != 0) && (choice.compare("Look at painting") != 0) && (choice.compare("Kitchen") != 0)
			&& (choice.compare("Sitting room") != 0) && (choice.compare("Billiards room") != 0) && (choice.compare("Check inventory") != 0));


		//take users choice and interact based on that
		if (choice.compare("Kitchen") == 0 || choice.compare("Sitting room") == 0 || choice.compare("Billiards room") == 0) {
			intChoice = movePlayerFromSmoking(choice);
			move = true;
		}
		else if (choice.compare("Check inventory") == 0) {
			std::cout << "\n\nInventory contains: \n\n";
			int c = 1;
			for (auto it = inventory.begin(); it != inventory.end(); ++it){
				std::cout << c << ": " << it->second << "\n";
				c++;
			}
		}
		else {
			inspectSmokingObj(choice, inventory);
		}

	} while (!move);

	return intChoice;
}