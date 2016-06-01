/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/19/16
* Last Modification Date:	4/19/16
* Filename:				GardenSource.cpp
*
* Overview:
*	This file holds the implementation for the Garden objects.
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

//guards for header
#include "GardenHeader.h"

//animation header
#include "animation.hpp"

//member function to output information provided of each item in Dog
void Dog::dogInformation()
{
     std::cout << "\n\nType of dog is: " << this->type << "\n\nDescription of dog: " << this->description << "\n\n\n";
}

//member function to check if user has treat and get hydrangea sap if so
void Dog::giveTreat(std::unordered_map<std::string, std::string>& inv){

     //user input var
     std::string ans;

	 //animation variables
	 int start_row = 4;
	 int start_column = 4;
	 int i;
	 int speed;

	 //dog tail-wagging animation
	 initscr();
	 clear();
	 printDog(start_row, start_column);
	 for (i = 0; i <= 7; i++)
	 {
		 printTail1(start_row, start_column);
		 refresh();
		 for (speed = 1; speed <= 30000000; speed++);
		 printTail2(start_row, start_column);
		 refresh();
		 for (speed = 1; speed <= 30000000; speed++);
		 printTail3(start_row, start_column);
		 refresh();
		 for (speed = 1; speed <= 30000000; speed++);
		 printTail4(start_row, start_column);
		 refresh();
		 for (speed = 1; speed <= 30000000; speed++);
		 printTail3(start_row, start_column);
		 refresh();
		 for (speed = 1; speed <= 30000000; speed++);
		 printTail2(start_row, start_column);
		 refresh();
		 for (speed = 1; speed <= 30000000; speed++);
	 }
	 getch();
	 endwin();

     //check if sap is already in inventory
     auto search = inv.find("sap");
     if (search != inv.end()){
          std::cout << "\nYou give the dog the treat and he moves, however you have already grabbed the " << getSap() << " from behind him.\n\n";
     }
     else{

          //check if dog treat is already in inventory
          auto search = inv.find("dog treat");
          if (search != inv.end()){
               std::cout << "\nYou give the dog the treat and he allows you to pass. You inspects the plant behind him and notice it is a Hydrangea plant.\n\n";
               std::cout << "You can collect a sample of the sap in one of your containers.\n\n";

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
                    inv.insert({ "sap", getSap() });
                    std::cout << "\nOkay, " << getSap() << " added to inventory.\n\n";
                    getSap();
               }
               else{
                    std::cout << "\nOkay, " << getSap() << " not added to inventory.\n\n";
               }

          }
          else{

               std::cout << "\nYou don't have any treats on you to give to the dog!\n\n";
          }
     }

}

//member function to get into the trunk of LuxuryCar
void Dog::dogInteract(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;
     int firstTime = 0;
     Dog dog;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Dog\n\n\n\n";

     //get bowl info
     dog.dogInformation();

     //set up navigation
     std::cout << "As you approach the dog, he looks playful but growls as you gets closer.\n\n" <<
          "What would you like to do? \n\n" <<
          "Attempt to pet the dog? (Enter \"1\").\n\n" <<
          "Give the dog a treat? (Enter \"2\") \n\n" <<
          "Walk away from dog? (Enter \"3\")\n\n" <<
          "Check your inventory of items ( Enter \"4\").\n\n" <<
          "Choose a number between 1 and 4.";

     //choice from player
     int choice = 0;
     int retry = 0;

     //inspect the room
     do{

          //navigation choice
          choice = 0;
          retry = 0;

          do
          {
               if (retry > 0)
               {
                    std::cout << "\n\nPlease select a number between 1 and 4: \n\n";
               }
               else{
                    if (firstTime != 0){
                         //formatting
                         std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                         std::cout << "\n\nThe Dog\n\n\n\n" <<
                              "What would you like to do? \n\n" <<
                              "Attempt to pet the dog? (Enter \"1\").\n\n" <<
                              "Give the dog a treat? (Enter \"2\") \n\n" <<
                              "Walk away from dog? (Enter \"3\")\n\n" <<
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
          switch (choice){
          case 1:
               std::cout << dog.bark << "\n\n";
               std::cout << "The dog doesn't appear to be friendly unless you have a treat. Maybe you can find one around ... \n\n";
               break;
          case 2:
               //call function to give treat to dog
               giveTreat(inv);
               break;
          case 3:
               std::cout << "\nYou: \"See you later dog.\"\n\n";
               break;
          case 4:
               std::cout << "\n\nInventory contains: \n\n";
               int c = 1;
               for (auto it = inv.begin(); it != inv.end(); ++it){
                    std::cout << c << ": " << it->second << "\n";
                    c++;
               }
               break;
          }

     } while (choice != 3);
}

//Accessor Functions for accessing private variables in LuxuryCar.
std::string Dog::getType() const { return type; }

std::string Dog::getDescription() const { return description; }

bool Dog::getTreat() const { return treat; }

std::string Dog::getBark() const { return bark; }

std::string Dog::getSap() const { return sap; }

//Mutator Functions to change private variables.
void Dog::setType(const std::string theType){ type = theType; }

void Dog::setDescription(const std::string theDescription){ description = theDescription; }

void Dog::setTreat(const bool theTreat){ treat = theTreat; }

void Dog::setBark(const std::string theBark){ bark = theBark; }

void Dog::setSap(const std::string theSap){ sap = theSap; }


//member function to output information provided of each item
void MsWolf::personInformation(std::unordered_map<std::string, std::string>& inventory)
{
     std::cout << "\n\nDescription of the woman is : " << this->description << "\n\n\n";
}


int MsWolf::conversate(std::unordered_map<std::string, std::string>& inventory){

     //initialize mr white
     MsWolf msWolf;
     int firstTime = 0;
     //choice from player
     int choice = 0;
     int retry = 0;
     std::string ans;

	 //animation variables
	 int start_row = 4;
	 int start_column = 4;
	 int i;
	 int speed;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nMs. Wolf\n\n\n\n";

     //output info about mr white
     msWolf.personInformation(inventory);

     //check if the statement is already in inventory
     auto search = inventory.find("statement");
     if (search != inventory.end()){

          //set up navigation
          std::cout << "Ms. Wolf greets you as you approach.\n\n" <<
               "What would you like to ask Ms. Wolf? \n\n" <<
               "\n\nPresent her with the written statement and clues to her murder!!! (Enter \"1\").\n\n\n" <<
               "What have you been doing tonight? (Enter \"2\").\n\n" <<
               "Do you know who the murderer may be? (Enter \"3\").\n\n" <<
               "What's your age? (Enter \"4\") \n\n" <<
               "What do you do around here for work? (Enter \"5\").\n\n" <<
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

                              std::cout << "What would you like to ask Ms. Wolf? \n\n" <<
                                   "\n\nPresent her with the written statement and clues to her murder!!! (Enter \"1\").\n\n\n" <<
                                   "What have you been doing tonight? (Enter \"2\").\n\n" <<
                                   "Do you know who the murderer may be? (Enter \"3\").\n\n" <<
                                   "What's your age? (Enter \"4\") \n\n" <<
                                   "What do you do around here for work? (Enter \"5\").\n\n" <<
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
                    //check if the revolver is already in inventory
                    search = inventory.find("revolver");
                    if (search != inventory.end()){

                         std::cout << "\n\nYou present Ms. Wolf with the signed statement from Mr. Glass and Ms. Wolf looks as though she will burst into tears.\n\n";
                         std::cout << "Then she says \"" << getConfession() << getConfessionTwo() << getConfessionThree() << "\n\n";

						 //animation for handcuffs
						 initscr();
						 for (i = 0; i <= 7; i++)
						 {
							 printGuilty(start_row, start_column);
							 printCuffs(start_row + i, start_column);
							 refresh();
							 for (speed = 1; speed <= 55000000; speed++);
						 }
						 getch();
						 endwin();

                         std::cout << "You then handcuff her and walk her out to your Monte Carlo and take her to the station.\n\n\nWell done detective!!!\n\nThanks for playing!\n\n";

                    }
                    else{
                         //don't end game
                         choice = 0;
                         std::cout << "\nBefore presenting Ms. Wolf with the evidence, you may want to grab a weapon for protection. This is a murderer after all! Something like a gun perhaps ... \n\n";
                    }
                    break;
               case 2:
                    std::cout << msWolf.doingTonight << "\n\n";
                    break;
               case 3:
                    std::cout << msWolf.knowMurderer << "\n\n";
                    break;
               case 4:
                    std::cout << "\nI am " << msWolf.age << "\n\n";
                    break;
               case 5:
                    std::cout << msWolf.jobDescription << "\n\n";
                    break;
               case 6:
                    std::cout << "\nYou: \"Thank you for your time Ms. Wolf.\"\n\n";
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

          } while (choice != 6 && choice != 1);

          //if choice is 1, game is over
          if (choice == 1){
               return choice;
          }

     }
     else{


          //set up navigation
          std::cout << "Ms. Wolf greets you as you approach.\"\n\n" <<
               "What would you like to ask Ms. Wolf? \n\nWhat have you been doing tonight? (Enter \"1\").\n\n" <<
               "Do you know who the murderer may be? (Enter \"2\").\n\n" <<
               "What's your age? (Enter \"3\") \n\n" <<
               "What do you do around here for work? (Enter \"4\").\n\n" <<
               "Finished questioning her (Enter \"5\")\n\n" <<
               "Check your inventory of items ( Enter \"6\").\n\n" <<
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

                              std::cout << "What would you like to ask Ms. Wolf? \n\nWhat have you been doing tonight? (Enter \"1\").\n\n" <<
                                   "Do you know who the murderer may be? (Enter \"2\").\n\n" <<
                                   "What's your age? (Enter \"3\") \n\n" <<
                                   "What do you do around here for work? (Enter \"4\").\n\n" <<
                                   "Finished questioning her (Enter \"5\")\n\n" <<
                                   "Check your inventory of items ( Enter \"6\").\n\n" <<
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
                    std::cout << msWolf.doingTonight << "\n\n";
                    break;
               case 2:
                    std::cout << msWolf.knowMurderer << "\n\n";
                    break;
               case 3:
                    std::cout << "\nI am " << msWolf.age << "\n\n";
                    break;
               case 4:
                    std::cout << msWolf.jobDescription << "\n\n";
                    break;
               case 5:
                    std::cout << "\nYou: \"Thank you for your time Ms. Wolf.\"\n\n";
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

          return 0;
     }

     return 0;
}

//Accessor Functions for accessing private variables in MrWhite.
std::string MsWolf::getKnowMurderer() const { return knowMurderer; }

std::string MsWolf::getDoingTonight() const { return doingTonight; }

int MsWolf::getAge() const { return age; }

std::string MsWolf::getJobDescription() const { return jobDescription; }

std::string MsWolf::getDescription() const { return description; }

std::string MsWolf::getConfession() const { return confession; }

std::string MsWolf::getConfessionTwo() const { return confessionTwo; }

std::string MsWolf::getConfessionThree() const { return confessionThree; }

//Mutator Functions to change private variables.
void MsWolf::setKnowMurderer(const std::string theKnowMurderer){ knowMurderer = theKnowMurderer; }

void MsWolf::setDoingTonight(const std::string theDoingTonight){ doingTonight = theDoingTonight; }

void MsWolf::setAge(const int theAge){ age = theAge; }

void MsWolf::setJobDescription(const std::string theJobDescription){ jobDescription = theJobDescription; }

void MsWolf::setDescription(const std::string theDescription){ description = theDescription; }

void MsWolf::setConfession(const std::string theConfession){ confession = theConfession; }

void MsWolf::setConfessionTwo(const std::string theConfessionTwo){ confession = theConfessionTwo; }

void MsWolf::setConfessionThree(const std::string theConfessionThree){ confession = theConfessionThree; }


/////Room class functions/////
//get functions
std::string RoomGarden::getName() const { return name; }

int RoomGarden::getNumRooms() const { return numRooms; }

int RoomGarden::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomGarden::getExits() const { return exits; }

std::vector<std::string> RoomGarden::getObjects() const { return objects; }

std::string RoomGarden::getDescription() const { return description; }

//set functions
void RoomGarden::setName(const std::string theName){ name = theName; }

void RoomGarden::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomGarden::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomGarden::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomGarden::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomGarden::setDescription(const std::string theDescription){ description = theDescription; }