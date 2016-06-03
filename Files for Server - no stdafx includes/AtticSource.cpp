/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/30/16
* Last Modification Date:	     5/30/16
* Filename:					AtticSource.cpp
*
* Overview:
*	This file holds the implementation for the Attic Room objects.
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
#include "AtticHeader.h"

//animation header
#include "animation.hpp"


//member function for NightStand
void NightStand::checkStand(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nNight Stand\n\n\n\n";

     std::cout << "\nFrom closer inspection of the night stand, you note the following: " << getDescription() << "\n\n";

     //check if pic frame is already in inventory
     auto search = inv.find("pic frame");
     if (search != inv.end()){
          std::cout << "\nThere isn't anything of note on the night stand since you have already grabbed the " << getPicFrame() << " from here.\n\n";
     }
     else{

          std::cout << "\nThe is also a picture frame with a picture of Mr. Glass and Miss Wolf on traveling at the Swiss Alps.\n\n";

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

          if (ans == "y"){
               inv.insert({ "pic frame", getPicFrame() });
               std::cout << "\nOkay, " << getPicFrame() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getPicFrame() << " not added to inventory.\n\n";
          }
     }
}

//Accessor Functions for accessing private variables in Trash.
std::string NightStand::getPicFrame() const { return picFrame; }

std::string NightStand::getDescription() const { return description; }

//Mutator Functions to change private variables.
void NightStand::setDescription(const std::string theDescription){ description = theDescription; }

void NightStand::setPicFrame(const std::string thePicFrame){ picFrame = thePicFrame; }



//member function to output information provided of each item
void MrGlass::personInformation(std::unordered_map<std::string, std::string>& inventory)
{
	std::cout << "Description : " << this->description << "\n\n\n";
}


void MrGlass::getMoreInfo(std::unordered_map<std::string, std::string>& inventory){

	//initialize mrGlass object
     MrGlass mrGlass;
     //variables to detect if evidence for statement is available
     int gotEvidence = 0;
     int gotMotive = 0;
     int gotPoison = 0;
     int noPoison = 5;
     int noMotive = 5;
     int checkInventory = 0;

	 //animation variables
	 int start_row = 4;
	 int start_column = 4;
	 int i;
	 int speed;

     //check if key is already in inventory
     auto search = inventory.find("key");
     if (search != inventory.end()){

          //check if sap,wine, old/new will are already in inventory
          search = inventory.find("sap");
          if (search != inventory.end()){
               //add up if all items needed are in inventory
               gotPoison++;
          }
          else{
               gotPoison = noPoison;
          }

          search = inventory.find("grape");
          if (search != inventory.end()){
               //add up if all items needed are in inventory
               //make sure you have the first item
               if (gotPoison != noPoison){
                    gotPoison++;
               }
          }
          else{
               gotPoison = noPoison;
          }

          search = inventory.find("old will");
          if (search != inventory.end()){
               //add up if all items needed are in inventory
               gotMotive++;
          }
          else{
               gotMotive = noMotive;
          }

          search = inventory.find("new will");
          if (search != inventory.end()){
               //add up if all items needed are in inventory
               //make sure you have the first item
               if (gotMotive != noMotive){
                    gotMotive++;
               }
          }
          else{
               gotMotive = noMotive;
          }

          //if you have both motive and poison then set gotEvidence
          if ((gotMotive == 2) && (gotPoison == 2)){
               gotEvidence = 1;
          }
          //have motive but no poison
          else if ((gotMotive == 2) && (gotPoison != 2)){
               gotEvidence = 2;
          }
          //have poison but no weapon
          else if ((gotPoison == 2) && (gotMotive != 2)){
               gotEvidence = 3;
          }
          if (gotEvidence == 0){
               //have all the evidence to get a statement from Mr. Glass
               std::cout << mrGlass.getEvidence();
          }
          else if (gotEvidence == 1){
               //have all the evidence to get a statement from Mr. Glass
			   
			  //chemistry animation
			  initscr();
			  clear();
			  refresh();
			  for (i = 0; i <= 13; i++)
			  {
				  printVial(start_row, start_column);
				  printGrape(start_row + i, start_column);
				  refresh();
				  for (speed = 1; speed <= 55000000; speed++);
				  eraseGrape(start_row + i, start_column);
			  }
			  printGrape(start_row + 13, start_column);
			  printReaction(start_row, start_column);

			  getch();
			  endwin();

               std::cout << mrGlass.getEvidence();
               std::cout << "You show Mr. Glass a demonstration of the Gamay Grape mixing with the wine and it fizzles and appears to be toxic.\n\n";
               std::cout << "You also provide Mr. Glass with his old will and his new will which gives us a murder weapon and a motive.\n\n";
               std::cout << mrGlass.getConfessOne() << mrGlass.getConfessTwo() << "\n\n";
               //collect statement for inventory
               inventory.insert({ "statement", getStatement() });
          }
          else if (gotEvidence == 2){
               //do not have the evidence needed
               std::cout << getEvidence() << "\n\n";
               std::cout << "You show Mr. Glass the old and new will to provide a potential motive, but you do not have a murder weapon.\n\n";
               std::cout << "Perhaps you can find the items that may have been used to poison Mr. Cunningham...\n\n";
          }
          else if (gotEvidence == 3){
               //have all the evidence to get a statement from Mr. Glass
               std::cout << mrGlass.getEvidence();
               std::cout << "\n\nYou show Mr. Glass a demonstration of the Gamay Grape mixing with the wine and it fizzles and appears to be toxic.\n\n";
               std::cout << "\n\nYou however do not have a motive currently and will need to see what you can come up with.\n\nPerhaps something in the secret safe could help...\n\n";
          }

     }
     else{// key not in inventory

          //check if bottle is already in inventory
          search = inventory.find("bottle");
          if (search != inventory.end()){
               checkInventory = 1;
          }

          //check if notes of deadly combo is already in inventory
          search = inventory.find("combo notes");
          if (search != inventory.end()){
               //if combo notes found and bottle found
               if (checkInventory == 1){
                    checkInventory = 2;
               }
               //if combo notes found but bottle not found
               else if (checkInventory == 0){
                    checkInventory = 3;
               }

          }

          //handle output to user based on whether the bottle or combo notes are in the inventory
          switch (checkInventory){
          case 0: // combo notes and bottle not in user inventory
               //get key info
               std::cout << mrGlass.getKeyOne() << "\n\n";
               break;

          case 1: //only bottle in inventory
               std::cout << "\nYou show Mr. Glass the the bottle of beaujolais wine you found.\n\n";
               std::cout << "\nMr. Glass \"It looks like you may be onto something with that bottle\n\nbut I'd need a little more proof of what that would need to be used with to give up the key.\"\n\n";
               break;

          case 2: //both found

               //get key info 
               std::cout << mrGlass.getKeyOne();
               std::cout << "\n\nYou show Mr. Glass the wine bottle of beaujolais and the notes from the computer about how deadly the combination is with hydrangea sap.\n\n";
               std::cout << "\n\nHe looks inquisitively at it and shakes his head in agreement.\n\n";
               std::cout << mrGlass.getKeyTwo() << "\n\n";
               //collect note for inventory
               inventory.insert({ "key", getKey() });
               break;

          case 3: //only combo notes in inventory
               std::cout << "\nYou show Mr. Glass the notes that the wine mixed with grapes could be poisonous if ingested.\n\n";
               std::cout << "\nMr. Glass \"It looks like you may be onto something with those notes\n\nbut I'd need a little more proof that we even had that wine tonight in order to give up the key.\"\n\n";
               break;
          }
     }
}

void MrGlass::conversate(std::unordered_map<std::string, std::string>& inventory){

	//initialize mrGlass
     MrGlass mrGlass;
	int firstTime = 0;
	//choice from player
	int choice = 0;
	int retry = 0;
	std::string ans;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nMr. Glass\n\n\n\n";

	//output info about mr glass
	mrGlass.personInformation(inventory);

	//set up navigation
     std::cout << "As you approach Mr. Glass, his stare is broken and he looks to you hopefully.\n\n" <<
		"What would you like to ask Mr. Glass? \n\n" <<
		"Do you have any better idea who the murderer may be? (Enter \"1\").\n\n" <<
		"What's your age? (Enter \"2\") \n\n" <<
		"What do/did you do for work? (Enter \"3\").\n\n" <<
		"Is there anything else you can tell me? (Enter \"4\").\n\n" <<
		"Finished questioning him (Enter \"5\")\n\n" <<
		"Check your inventory of items (Enter \"6\").\n\n" <<
		"Choose a number between 1 and 6.";

	//inspect the room
	do{

		//navigation choice
		choice = 0;
		retry = 0;

		do
		{
			if (retry > 0)
			{
				std::cout << "\n\nPlease select a number between 1 and 6 for questioning: \n\n";
			}
			else{
				if (firstTime != 0){
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                         std::cout << "What would you like to ask Mr. Glass? \n\n" <<
                              "Do you have any better idea who the murderer may be? (Enter \"1\").\n\n" <<
                              "What's your age? (Enter \"2\") \n\n" <<
                              "What do/did you do for work? (Enter \"3\").\n\n" <<
                              "Is there anything else you can tell me? (Enter \"4\").\n\n" <<
                              "Finished questioning him (Enter \"5\")\n\n" <<
                              "Check your inventory of items (Enter \"6\").\n\n" <<
                              "Choose a number between 1 and 6.";
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


		//output responses from Mr Whtie
		switch (choice){
		case 1:
			std::cout << mrGlass.getKnowMurderer() << "\n\n";
			break;
		case 2:
               std::cout << "\nMr. Glass \"As you can tell I'm up there in my years. I am " << mrGlass.getAge() << ".\"\n\n";
			break;
		case 3:
               std::cout << mrGlass.getJobDescription() << "\n\n";
			break;
		case 4:
			//check as to if mr glass has more information
			mrGlass.getMoreInfo(inventory);
			break;
		case 5:
			std::cout << "\n\"Thank you for your time Mr. Glass.\"\n\n";
			break;
		case 6:
			std::cout << "\n\nInventory contains: \n\n";
			int c = 1;
			for (auto it = inventory.begin(); it != inventory.end(); ++it){
				std::cout << c << ": " << it->second << "\n";
				c++;
			}
			break;
		}

	} while (choice != 5);

}

//Accessor Functions for accessing private variables in MrGlass.
std::string MrGlass::getKnowMurderer() const { return knowMurderer; }

int MrGlass::getAge() const { return age; }

std::string MrGlass::getJobDescription() const { return jobDescription; }

std::string MrGlass::getDescription() const { return description; }

std::string MrGlass::getKeyOne() const { return keyOne; }

std::string MrGlass::getKeyTwo() const { return keyTwo; }

std::string MrGlass::getEvidence() const { return evidence; }

std::string MrGlass::getConfessOne() const { return confessOne; }

std::string MrGlass::getConfessTwo() const { return confessTwo; }

std::string MrGlass::getStatement() const { return statement; }

std::string MrGlass::getKey() const { return key; }

//Mutator Functions to change private variables.
void MrGlass::setKnowMurderer(const std::string theKnowMurderer){ knowMurderer = theKnowMurderer; }

void MrGlass::setAge(const int theAge){ age = theAge; }

void MrGlass::setJobDescription(const std::string theJobDescription){ jobDescription = theJobDescription; }

void MrGlass::setDescription(const std::string theDescription){ description = theDescription; }

void MrGlass::setKeyOne(const std::string theKeyOne){ keyOne = theKeyOne; }

void MrGlass::setKeyTwo(const std::string theKeyTwo){ keyTwo = theKeyTwo; }

void MrGlass::setEvidence(const std::string theEvidence){ evidence = theEvidence; }

void MrGlass::setConfessOne(const std::string theConfessOne){ confessOne = theConfessOne; }

void MrGlass::setStatement(const std::string theStatement){ statement = theStatement; }

void MrGlass::setKey(const std::string theKey){ key = theKey; }

/////Room class functions/////
//get functions
std::string RoomAttic::getName() const { return name; }

int RoomAttic::getNumRooms() const { return numRooms; }

int RoomAttic::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomAttic::getExits() const { return exits; }

std::vector<std::string> RoomAttic::getObjects() const { return objects; }

std::string RoomAttic::getDescription() const { return description; }

//set functions
void RoomAttic::setName(const std::string theName){ name = theName; }

void RoomAttic::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomAttic::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomAttic::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomAttic::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomAttic::setDescription(const std::string theDescription){ description = theDescription; }
