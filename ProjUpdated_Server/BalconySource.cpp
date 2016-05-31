/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/30/16
* Last Modification Date:	5/30/16
* Filename:				BalconySource.cpp
*
* Overview:
*	This file holds the implementation for the Balcony objects.
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
#include "BalconyHeader.h"

//member function for FoldingTable
void FoldingTable::checkTable(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;
     int checkInventory = 0;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Folding Table\n\n\n\n";

     std::cout << "\nFrom closer inspection of the folding table, you note it as: " << getDescription() << "\n\n";

     //check if cigs is already in inventory
     auto search = inv.find("cigs");
     if (search != inv.end()){
          checkInventory = 1;
     }

     //check if lipstick is already in inventory
     search = inv.find("lipstick");
     if (search != inv.end()){
          //if lipstick found and cigs found
          if (checkInventory == 1){
               checkInventory = 2;
          }
          //if lipstick found but cigs not found
          else if (checkInventory == 0){
               checkInventory = 3;
          }

     }

     //handle output to user based on whether the cigs or lipstick are on the table
     switch (checkInventory){
     case 0: // lipstick and cigs not in user inventory
          //output choices
          std::cout << "On the table you see some magazines and an ash tray, but you are interested by the " << getCigarettes() << "\n\nand also notice " << getLipstick() << " and wonder if they would be worthwhile evidence.\n\n";

          //check to add cigs to inventory
          std::cout << "Would you like to add a " << getCigarettes() << " to your inventory?\n\n";

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
               inv.insert({ "cigs", getCigarettes() });
               std::cout << "\nOkay, " << getCigarettes() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getCigarettes() << " not added to inventory.\n\n";
          }

          //check to add lipstick to inventory
          std::cout << "Would you like to add a " << getLipstick() << " to your inventory?\n\n";

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
               inv.insert({ "lipstick", getLipstick() });
               std::cout << "\nOkay, " << getLipstick() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getLipstick() << " not added to inventory.\n\n";
          }

          break;
     case 1: //only cigs in user inventory
          //output choices
          std::cout << "On the table you see some magazines and an ash tray, but since you already grabbed the " << getCigarettes() << "\n\nyou only see the " << getLipstick() << " as worthwhile evidence.\n\n";

          std::cout << "Would you like to add a " << getLipstick() << " to your inventory?\n\n";

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
               inv.insert({ "lipstick", getLipstick() });
               std::cout << "\nOkay, " << getLipstick() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getLipstick() << " not added to inventory.\n\n";
          }
          break;
     case 2: // lipstick and cigs in user inventory
          //output choices
          std::cout << "On the table you see some magazines and an ash tray, but since you already grabbed the " << getCigarettes() << "\n\nand " << getLipstick() << " nothing appears to be worthwhile evidence.\n\n";
          break;
     case 3: // lipstick found but not cigs in user inventory
          //output choices
          std::cout << "On the table you see some magazines and an ash tray, but since you already grabbed the " << getLipstick() << "\n\nyou only see the " << getCigarettes() << " as worthwhile evidence.\n\n";

          std::cout << "Would you like to add a " << getCigarettes() << " to your inventory?\n\n";

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
               inv.insert({ "cigs", getCigarettes() });
               std::cout << "\nOkay, " << getCigarettes() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getCigarettes() << " not added to inventory.\n\n";
          }
          break;
     }
}

//Accessor Functions for accessing private variables in FoldingTable.
std::string FoldingTable::getDescription() const { return description; }

std::string FoldingTable::getLipstick() const { return lipstick; }

std::string FoldingTable::getCigarettes() const { return cigarettes; }

//Mutator Functions to change private variables.
void FoldingTable::setDescription(const std::string theDescription){ description = theDescription; }

void FoldingTable::setLipstick(const std::string theLipstick){ lipstick = theLipstick; }

void FoldingTable::setCigarettes(const std::string theCigarettes){ cigarettes = theCigarettes; }


//member function to output information provided of each item
void MrDeeds::personInformation(std::unordered_map<std::string, std::string>& inventory)
{
     std::cout << "Description of the man is : " << this->description << "\n\n\n";
}

//member function
void MrDeeds::otherInfo(std::unordered_map<std::string, std::string>& inventory){

     //initialize MrDeeds object
     MrDeeds mrDeeds;

     //check if you already got the answer
     auto search = inventory.find("dining notes");
     if (search != inventory.end()){
          //already have vacay note
          std::cout << "\n\nMr. Deeds \"Unfortunately I have nothing else to give you sir.\"\n\n";
     }
     else{
          //get dining info 
          std::cout << "\n\nYou press Mr. Green for more information.\n\n";
          std::cout << mrDeeds.moreInfo << "\n\n";
          //collect note for inventory
          inventory.insert({ "dining notes", getDiningNote() });
          std::cout << "\n\nYou note this in your notepad.\n\n";
     }

}

//member function to conversate
void MrDeeds::conversate(std::unordered_map<std::string, std::string>& inventory){

     //initialize MrDeeds
     MrDeeds mrDeeds;
     int firstTime = 0;
     //choice from player
     int choice = 0;
     int retry = 0;
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nMr. Deeds\n\n\n\n";

     //output info about mr white
     mrDeeds.personInformation(inventory);

     //set up navigation
     std::cout << "You approach Mr. Deeds, who looks your way and puts out his cigarette.\n\n" <<
          "What would you like to ask Mr. Deeds? \n\n" <<
          "What have you been doing tonight? (Enter \"1\").\n\n" <<
          "Do you know who the murderer may be? (Enter \"2\").\n\n" <<
          "What's your age? (Enter \"3\") \n\n" <<
          "What do you do for work? (Enter \"4\").\n\n" <<
          "Is there anything else you can tell me? (Enter \"5\").\n\n" <<
          "Finished questioning him (Enter \"6\")\n\n" <<
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

                         std::cout << "What would you like to ask Mr. Deeds? \n\n" <<
                              "What have you been doing tonight? (Enter \"1\").\n\n" <<
                              "Do you know who the murderer may be? (Enter \"2\").\n\n" <<
                              "What's your age? (Enter \"3\") \n\n" <<
                              "What do you do for work? (Enter \"4\").\n\n" <<
                              "Is there anything else you can tell me? (Enter \"5\").\n\n" <<
                              "Finished questioning him (Enter \"6\")\n\n" <<
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


          //output responses from Mr Deeds
          switch (choice){
          case 1:
               std::cout << mrDeeds.doingTonight << "\n\n";
               break;
          case 2:
               std::cout << mrDeeds.knowMurderer << "\n\n";
               break;
          case 3:
               std::cout << "\nMr. Deeds \"I am " << mrDeeds.age << "\"\n\n";
               break;
          case 4:
               std::cout << mrDeeds.jobDescription << "\n\n";
               break;
          case 5:
               //check as to whether he will give up more info
               otherInfo(inventory);
               break;
          case 6:
               std::cout << "\nYou: \"Thank you for your time Mr. Green.\"\n\n";
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

//Accessor Functions for accessing private variables in MrDeeds.
std::string MrDeeds::getKnowMurderer() const { return knowMurderer; }

std::string MrDeeds::getDoingTonight() const { return doingTonight; }

int MrDeeds::getAge() const { return age; }

std::string MrDeeds::getJobDescription() const { return jobDescription; }

std::string MrDeeds::getDescription() const { return description; }

std::string MrDeeds::getMoreInfo() const { return moreInfo; }

std::string MrDeeds::getDiningNote() const { return diningNote; }

//Mutator Functions to change private variables.
void MrDeeds::setKnowMurderer(const std::string theKnowMurderer){ knowMurderer = theKnowMurderer; }

void MrDeeds::setDoingTonight(const std::string theDoingTonight){ doingTonight = theDoingTonight; }

void MrDeeds::setAge(const int theAge){ age = theAge; }

void MrDeeds::setJobDescription(const std::string theJobDescription){ jobDescription = theJobDescription; }

void MrDeeds::setDescription(const std::string theDescription){ description = theDescription; }

void MrDeeds::setMoreInfo(const std::string theMoreInfo){ moreInfo = theMoreInfo; }

void MrDeeds::setDiningNote(const std::string theDiningNote){ diningNote = theDiningNote; }

/////Room class functions/////
//get functions
std::string RoomBalcony::getName() const { return name; }

int RoomBalcony::getNumRooms() const { return numRooms; }

int RoomBalcony::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomBalcony::getExits() const { return exits; }

std::vector<std::string> RoomBalcony::getObjects() const { return objects; }

std::string RoomBalcony::getDescription() const { return description; }

//set functions
void RoomBalcony::setName(const std::string theName){ name = theName; }

void RoomBalcony::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomBalcony::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomBalcony::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomBalcony::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomBalcony::setDescription(const std::string theDescription){ description = theDescription; }