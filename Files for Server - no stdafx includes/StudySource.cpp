/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/25/16
* Last Modification Date:	4/26/16
* Filename:				StudySource.cpp
*
* Overview:
*	This file holds the implementation for the Study objects.
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
#include "StudyHeader.h"

//member function for Computer
void Computer::checkComputer(std::unordered_map<std::string, std::string>& inv)
{
     //initialize the computer object
     Computer computer;
     //user input var
     std::string ans;
     int checkInventory = 0;

     //check if password is already in inventory
     auto search = inv.find("password");
     if (search != inv.end()){
          checkInventory = 1;
     }

     //check if brochure is already in inventory
     search = inv.find("brochure");
     if (search != inv.end()){
          //if pie found and password found
          if (checkInventory == 1){
               checkInventory = 2;
          }
          //if brochure found but password not found
          else if (checkInventory == 0){
               checkInventory = 3;
          }

     }

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Computer\n\n\n\n";

     //ascii art from http://www.asciiworld.com/-Computers-.html
     std::cout << "\n\n" <<
          "\t      ____________________________\n" <<
          "\t     !\\_________________________/!\\ \n" <<
          "\t     !!                         !! \\ \n" <<
          "\t     !!                         !!  \\ \n" <<
          "\t     !!                         !!  ! \n" <<
          "\t     !!         LOGIN           !!  ! \n" <<
          "\t     !!                         !!  ! \n" <<
          "\t     !!                         !!  ! \n" <<
          "\t     !!                         !!  ! \n" <<
          "\t     !!                         !!  / \n" <<
          "\t     !!_________________________!! / \n" <<
          "\t     !/_________________________\\!/ \n" <<
          "\t        __\\_________________/__/!_ \n" <<
          "\t       !_______________________!/ \n" <<
          "\t     ________________________ \n" <<
          "\t    /oooo  oooo  oooo  oooo /! \n" <<
          "\t   /ooooooooooooooooooooooo/ / \n" <<
          "\t  /ooooooooooooooooooooooo/ / \n" <<
          "\t /______________________ /_/ \n\n\n";

     //coffee table info
     std::cout << "\nWalking over to the Computer, you note: " << getDescription() << "\n\n";

     std::cout << "\nAs you sit down, you see the computer is password protected.\n\n";

     //handle output to user based on whether the steak or pie are in the fridge
     switch (checkInventory){
     case 0: // brochure and password not in user inventory
          //output if neither are in inventory
          std::cout << "\nYou cannot get into the computer without the password. Perhaps someone in the mansion can assist with that ... \n\n";
          break;
     case 1://only password in user inventory
          std::cout << "\nYou can get into the computer with the password. However you are not sure what to look up. Perhaps if you found a book or brochure with information to search ... \n\n";
          break;
     case 2: // brochure and password in user inventory
          search = inv.find("combo notes");
          if (search != inv.end()){

               //output if already grabbed information
               std::cout << "\nYou have already taken down notes from the Vineyard's website regarding the poisonous mixture.\n\nYou don't want to check anything else out.\n\n";
          }
          else{

               //set up navigation
               std::cout << "\nYou have the password and brochure to look up the vineyard. You log in and get on the website for Beaujolais Vineyards...\n\n";
               std::cout << getInfo() << getInfoTwo() << getInfoThree() << getInfoFour() << getInfoFive() << "\n\n";


               std::cout << "Would you like to jot this note down to the notepad in your inventory?\n\n";

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
                    inv.insert({ "combo notes", getComboNote() });
                    std::cout << "\nOkay, " << getComboNote() << " added to inventory.\n\n";
               }
               else{
                    std::cout << "\nOkay, " << getComboNote() << " not added to inventory.\n\n";
               }
          }
          break;
     case 3: // brochure found but not password in user inventory
          std::cout << "\nYou cannot get into the computer without the password. Perhaps someone in the mansion can assist with that ... \n\n";
          break;
     }
}

//Accessor Functions for accessing private variables in Computer.
std::string Computer::getDescription() const { return description; }

std::string Computer::getComboNote() const { return comboNote; }

std::string Computer::getInfo() const { return info; }

std::string Computer::getInfoTwo() const { return infoTwo; }

std::string Computer::getInfoThree() const { return infoThree; }

std::string Computer::getInfoFour() const { return infoFour; }

std::string Computer::getInfoFive() const { return infoFive; }


//Mutator Functions to change private variables.
void Computer::setDescription(const std::string theDescription){ description = theDescription; }

void Computer::setComboNote(const std::string theComboNote){ comboNote = theComboNote; }

void Computer::setInfo(const std::string theInfo){ info = theInfo; }

void Computer::setInfoTwo(const std::string theInfoTwo){ infoTwo = theInfoTwo; }

void Computer::setInfoThree(const std::string theInfoThree){ infoThree = theInfoThree; }

void Computer::setInfoFour(const std::string theInfoFour){ infoFour = theInfoFour; }

void Computer::setInfoFive(const std::string theInfoFive){ infoFive = theInfoFive; }

//member function to output information provided of each item
void MrGreen::personInformation(std::unordered_map<std::string, std::string>& inventory)
{
     std::cout << "Description of the man is : " << this->description << "\n\n\n";
}

//member function
void MrGreen::otherInfo(std::unordered_map<std::string, std::string>& inventory){

     //initialize mrGreen object
     MrGreen mrGreen;

     //check if you already got the answer
     auto search = inventory.find("vacay notes");
     if (search != inventory.end()){
          //already have vacay note
          std::cout << "\n\nMr. Green \"Son, I don't know anything else. You should ask him about his travel.\"\n\n";
     }
     else{
          //get vacay info 
          std::cout << "\n\nYou press Mr. Green for more information.\n\n";
          std::cout << mrGreen.moreInfo << "\n\n";
          //collect note for inventory
          inventory.insert({ "vacay notes", getVacayNote() });
          std::cout << "\n\nYou note this in your notepad.\n\n";
     }

}

//member function to conversate
void MrGreen::conversate(std::unordered_map<std::string, std::string>& inventory){

     //initialize mr white
     MrGreen mrGreen;
     int firstTime = 0;
     //choice from player
     int choice = 0;
     int retry = 0;
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nMr. Green\n\n\n\n";

     //output info about mr white
     mrGreen.personInformation(inventory);

     //set up navigation
     std::cout << "You approach Mr. Green, who turns away from the window and stands to greet you as you approach.\n\n" <<
          "What would you like to ask Mr. Green? \n\n" <<
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

                         std::cout << "What would you like to ask Mr. Green? \n\n" <<
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


          //output responses from Mr Green
          switch (choice){
          case 1:
               std::cout << mrGreen.doingTonight << "\n\n";
               break;
          case 2:
               std::cout << mrGreen.knowMurderer << "\n\n";
               break;
          case 3:
               std::cout << "\nMr. Green \"I am " << mrGreen.age << "\"\n\n";
               break;
          case 4:
               std::cout << mrGreen.jobDescription << "\n\n";
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

//Accessor Functions for accessing private variables in MrGreen.
std::string MrGreen::getKnowMurderer() const { return knowMurderer; }

std::string MrGreen::getDoingTonight() const { return doingTonight; }

int MrGreen::getAge() const { return age; }

std::string MrGreen::getJobDescription() const { return jobDescription; }

std::string MrGreen::getDescription() const { return description; }

std::string MrGreen::getMoreInfo() const { return moreInfo; }

std::string MrGreen::getVacayNote() const { return vacayNote; }

//Mutator Functions to change private variables.
void MrGreen::setKnowMurderer(const std::string theKnowMurderer){ knowMurderer = theKnowMurderer; }

void MrGreen::setDoingTonight(const std::string theDoingTonight){ doingTonight = theDoingTonight; }

void MrGreen::setAge(const int theAge){ age = theAge; }

void MrGreen::setJobDescription(const std::string theJobDescription){ jobDescription = theJobDescription; }

void MrGreen::setDescription(const std::string theDescription){ description = theDescription; }

void MrGreen::setMoreInfo(const std::string theMoreInfo){ moreInfo = theMoreInfo; }

void MrGreen::setVacayNote(const std::string theVacayNote){ vacayNote = theVacayNote; }

/////Room class functions/////
//get functions
std::string RoomStudy::getName() const { return name; }

int RoomStudy::getNumRooms() const { return numRooms; }

int RoomStudy::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomStudy::getExits() const { return exits; }

std::vector<std::string> RoomStudy::getObjects() const { return objects; }

std::string RoomStudy::getDescription() const { return description; }

//set functions
void RoomStudy::setName(const std::string theName){ name = theName; }

void RoomStudy::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomStudy::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomStudy::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomStudy::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomStudy::setDescription(const std::string theDescription){ description = theDescription; }
