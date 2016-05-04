/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/12/16
* Last Modification Date:	4/14/16
* Filename:				DrivewaySource.cpp
*
* Overview:
*	This file holds the implementation for the driveway objects.
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

//guards for header
//#ifndef DrivewayHeader_h
//#define DrivewayHeader_h
#include "DrivewayHeader.h"
//#endif

//member function to output information provided of each item in LuxuryCar
void LuxuryCar::carInformation()
{
     std::cout << "\n\nCar color is : " << this->color << "\n\nNumber of doors is: " << this->doors
          << "\n\nThe Car Model is: " << this->model << "\n\n\n";
}

//member function to get into the trunk of LuxuryCar
void LuxuryCar::openTrunk(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;

     auto search = inv.find("knife");
     if (search != inv.end()){
          std::cout << "\nYou have a knife on you and you are able to pick the lock to open the trunk\n\n";
          
          //check if bottle is already in inventory
          auto search = inv.find("bottle");
          if (search != inv.end()){
               std::cout << "\nNothing in the trunk. You have already grabbed the bottle of wine from here.\n\n";
          }
          else{

               std::cout << "Inside there is a " << getWineBottle() << "\n\n";

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
                    inv.insert({ "bottle", getWineBottle() });
               }
               else{
                    std::cout << "\nOkay, " << getWineBottle() << " not added to inventory.\n\n";
               }
          }
     }
     else{
          std::cout << "\nHmm unable to open the trunk. If only we had something sharp like a knife to pick it with...\n";
     }
}

//Accessor Functions for accessing private variables in LuxuryCar.
std::string LuxuryCar::getColor() const { return color; }

int LuxuryCar::getDoors() const { return doors; }

std::string LuxuryCar::getModel() const { return model; }

std::string LuxuryCar::getWineBottle() const { return wineBottle; }

//Mutator Functions to change private variables.
void LuxuryCar::setColor(const std::string theType){ color = theType; }

void LuxuryCar::setDoors(const int theDoors){ doors = theDoors; }

void LuxuryCar::setModel(const std::string theModel){ model = theModel; }

void LuxuryCar::setWineBottle(const std::string theWineBottle){ wineBottle = theWineBottle; }

//member function to output information provided of each item
void MrWhite::personInformation(std::unordered_map<std::string, std::string>& inventory)
{
     std::cout << "\n\nDescription of the man is : " << this->description << "\n\n\n";
}


void MrWhite::conversate(std::unordered_map<std::string, std::string>& inventory){

     //initialize mr white
     MrWhite mrWhite;
     int firstTime = 0;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nMr. White\n\n\n\n";

     //output info about mr white
     mrWhite.personInformation(inventory);

     //set up navigation
     std::cout << "As you approach Mr. White, he says \"Sir I don't want any trouble. I just work here!\"\n\n" <<
          "What would you like to ask Mr. White? \n\nWhat have you been doing tonight? (Enter \"1\").\n\n" <<
          "Do you know who the murderer may be? (Enter \"2\").\n\n" <<
          "What's your age? (Enter \"3\") \n\n" <<
          "What do you do around here for work? (Enter \"4\").\n\n" <<
          "Finished questioning him (Enter \"5\")\n\n" <<
          "Check your inventory of items ( Enter \"6\").\n\n" <<
          "Choose a number between 1 and 6.";

     //choice from player
     int choice = 0;
     int retry = 0;
     std::string ans;

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

                         std::cout << "What would you like to ask Mr. White? \n\nWhat have you been doing tonight? (Enter \"1\").\n\n" <<
                              "Do you know who the murderer may be? (Enter \"2\").\n\n" <<
                              "What's your age? (Enter \"3\") \n\n" <<
                              "What do you do around here for work? (Enter \"4\").\n\n" <<
                              "Finished questioning him (Enter \"5\")\n\n" <<
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
               std::cout << mrWhite.doingTonight << "\n\n";
               break;
          case 2:
               std::cout << mrWhite.knowMurderer << "\n\n";
               break;
          case 3:
               std::cout << "\nI am " << mrWhite.age << "\n\n";
               break;
          case 4:
               std::cout << mrWhite.jobDescription << "\n\n";
               
               std::cout << "Ask for wife's name? \n\n";

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
                    std::cout << "\nHer name is " << mrWhite.wife << "\n\n";
               }
               break;
          case 5:
               std::cout << "\nSherlock: \"Thank you for your time Mr. White.\"\n\n";
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

//Accessor Functions for accessing private variables in MrWhite.
std::string MrWhite::getKnowMurderer() const { return knowMurderer; }

std::string MrWhite::getDoingTonight() const { return doingTonight; }

int MrWhite::getAge() const { return age; }

std::string MrWhite::getWife() const { return wife; }

std::string MrWhite::getJobDescription() const { return jobDescription; }

std::string MrWhite::getDescription() const { return description; }

//Mutator Functions to change private variables.
void MrWhite::setKnowMurderer(const std::string theKnowMurderer){ knowMurderer = theKnowMurderer; }

void MrWhite::setDoingTonight(const std::string theDoingTonight){ doingTonight = theDoingTonight; }

void MrWhite::setAge(const int theAge){ age = theAge; }

void MrWhite::setWife(const std::string theWife){ wife = theWife; }

void MrWhite::setJobDescription(const std::string theJobDescription){ jobDescription = theJobDescription; }

void MrWhite::setDescription(const std::string theDescription){ description = theDescription; }


//navigation function to handle game play while the player is in the driveway
int drivewayNavigate(std::unordered_map<std::string, std::string>& inventory){

     //boolean to find out if player wants to move to another room
     bool move = false;
     int firstTime = 0;

     //intialize objects
     LuxuryCar aCar;
     MrWhite mrWhite;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Driveway\n\n\n\n" <<
          "Sherlock is in the driveway.\n\nThere is a fancy luxury car that you may want to take a look at (Enter \"1\").\n\n" <<
          "There is also a man standing by the front of the driveway smoking a cigarette (To talk with him: Enter \"2\").\n\n" <<
          "You may also enter the mansion (Enter \"3\")\n\nYou may go around the back to the garden (Enter \"4\").\n\n" <<
          "Check your inventory of items ( Enter \"5\").\n\n" <<
          "What would you like to do? Choose a number between 1 and 5.";
          
     //choice from player
     int choice = 0;
     int retry = 0;
     std::string ans;

     //inspect the room
     do{
     
          //navigation choice
          choice = 0;
          retry = 0;

          do
          {
               if (retry > 0)
               {
                    std::cout << "\n\nPlease select a number between 1 and 5 to navigate: \n\n";
               }
               else{
                    if (firstTime != 0){
                         //formatting
                         std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                         std::cout << "Sherlock is in the driveway.\n\nThere is a fancy luxury car that you may want to take a look at (Enter \"1\").\n\n" <<
                              "There is also a man standing by the front of the driveway smoking a cigarette (To talk with him: Enter \"2\").\n\n" <<
                              "You may also enter the mansion (Enter \"3\")\n\nYou may go around the back to the garden (Enter \"4\").\n\n" <<
                              "Check your inventory of items ( Enter \"5\").\n\n" <<
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

          } while (choice < 1 || choice > 5);

     
          //take users choice and interact based on that
          switch (choice){
          case 1:
               std::cout << "\nFrom inspecting the car you note the following:\n";
               aCar.carInformation();
               std::cout << "There doesn't appear to be anything inside of the car from plain sight. Would you like to try to open the trunk?\n\n";

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
                    aCar.openTrunk(inventory);
               }
               break;
          case 2:
               mrWhite.conversate(inventory);
               break;
          case 3:
               std::cout << "\nEntering the mansion into the foyer.\n";
               //change choice to reflect our room mapping and update move
               choice = 2;
               move = true;
               break;
          case 4:
               std::cout << "\nWalking around the side of the mansion to the garden.\n";
               //change choice to reflect our room mapping and update move
               choice = 3;
               move = true;
               break;
          case 5:
               std::cout << "\n\nInventory contains: \n\n";
               int c = 1;
               for (auto it = inventory.begin(); it != inventory.end(); ++it){
                    std::cout << c << ": " << it->second << "\n";
                    c++;
               }
               break;
          }

     } while (!move);

     return choice;
}