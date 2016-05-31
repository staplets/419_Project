/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/21/16
* Last Modification Date:	5/21/16
* Filename:				BilliardsSource.cpp
*
* Overview:
*	This file holds the implementation for the Billiards Room objects and interaction.
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


//include billiards header
#include "BilliardsHeader.h"

//member function to get into the trunk of Pool Table
void PoolTable::checkTable(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;
     int checkInventory = 0;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Pool Table\n\n\n\n";

     std::cout << "\nFrom closer inspection of the pool table, you note: " << getDescription() << "\n\n";

     //check if pool ball is already in inventory
     auto search = inv.find("pool ball");
     if (search != inv.end()){
          checkInventory = 1;
     }

     //check if pool stick is already in inventory
     search = inv.find("pool stick");
     if (search != inv.end()){
          //if stick found and ball found
          if (checkInventory == 1){
               checkInventory = 2;
          }
          //if pie found but steak not found
          else if (checkInventory == 0){
               checkInventory = 3;
          }

     }

     //handle output to user based on whether the ball or stick are on the table
     switch (checkInventory){
     case 0: // stick and ball not in user inventory
          //output choices
          std::cout << "You take note of a " << getBall() << " and the " << getStick() << " and wonder if they would be worthwhile evidence.\n\n";

          //check to add ball to inventory
          std::cout << "Would you like to add a " << getBall() << " to your inventory?\n\n";

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
               inv.insert({ "pool ball", getBall() });
               std::cout << "\nOkay, " << getBall() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getBall() << " not added to inventory.\n\n";
          }

          //check to add stick to inventory
          std::cout << "Would you like to add a " << getStick() << " to your inventory?\n\n";

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
               inv.insert({ "pool stick", getStick() });
               std::cout << "\nOkay, " << getStick() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getStick() << " not added to inventory.\n\n";
          }

          break;
     case 1: //only ball in user inventory
          //output choices
          std::cout << "You take note of the " << getStick() << ", since you already grabbed a pool ball, you wonder if it would be worthwhile evidence.\n\n";

          std::cout << "Would you like to add a " << getStick() << " to your inventory?\n\n";

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
               inv.insert({ "pool stick", getStick() });
               std::cout << "\nOkay, " << getStick() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getStick() << " not added to inventory.\n\n";
          }
          break;
     case 2: // stick and ball in user inventory
          //output choices
          std::cout << "There are still a few pool balls on the pool table and a stick, but you have already collected a stick and ball and are content.\n\n";
          break;
     case 3: // stick found but not ball in user inventory
          //output choices
          std::cout << "You take note of the " << getBall() << ", since you already grabbed a " << getStick() << " and wonder if it would be worthwhile evidence.\n\n";

          std::cout << "Would you like to add a " << getBall() << " to your inventory?\n\n";

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
               inv.insert({ "pool ball", getBall() });
               std::cout << "\nOkay, " << getBall() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getBall() << " not added to inventory.\n\n";
          }
          break;
     }

}

//Accessor Functions for accessing private variables in CoatCloset.
std::string PoolTable::getDescription() const { return description; }

std::string PoolTable::getBall() const { return ball; }

std::string PoolTable::getStick() const { return stick; }

//Mutator Functions to change private variables.
void PoolTable::setDescription(const std::string theDescription){ description = theDescription; }

void PoolTable::setBall(const std::string theBall){ ball = theBall; }

void PoolTable::setStick(const std::string theStick){ stick = theStick; }



//member function to output information provided of each item
void CoffeeTable::checkCoffeeTable(std::unordered_map<std::string, std::string>& inv){

     //initialize the fish bowl object
     CoffeeTable coffeeTable;
     //user input var
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Coffee Table\n\n\n\n";

     //coffee table info
     std::cout << "\nWalking over to the coffee table, you note: " << getDescription() << "\n\n";

     //check if knife is already in inventory
     auto search = inv.find("brochure");
     if (search != inv.end()){
          std::cout << "\nThe table has a Life magazine, but you have already grabbed the " << getBrochure() << " that interested you.\n\n";
     }
     else{

          std::cout << "\nThe table has a copy of Life magazine and a " << getBrochure() << ", which catches his eye.\n\n";

          std::cout << "Would you like to add the brochure to your inventory?\n\n";

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
               inv.insert({ "brochure", getBrochure() });
               std::cout << "\nOkay, " << getBrochure() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getBrochure() << " not added to inventory.\n\n";
          }
     }

}


//Accessor Functions for accessing private variables in CoffeeTable.
std::string CoffeeTable::getBrochure() const { return brochure; }

std::string CoffeeTable::getDescription() const { return description; }

//Mutator Functions to change private variables.
void CoffeeTable::setBrochure(const std::string theBrochure){ brochure = theBrochure; }

void CoffeeTable::setDescription(const std::string theDescription){ description = theDescription; }

/////Room class functions/////
//get functions
std::string RoomBilliards::getName() const { return name; }

int RoomBilliards::getNumRooms() const { return numRooms; }

int RoomBilliards::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomBilliards::getExits() const { return exits; }

std::vector<std::string> RoomBilliards::getObjects() const { return objects; }

std::string RoomBilliards::getDescription() const { return description; }

//set functions
void RoomBilliards::setName(const std::string theName){ name = theName; }

void RoomBilliards::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomBilliards::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomBilliards::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomBilliards::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomBilliards::setDescription(const std::string theDescription){ description = theDescription; }
