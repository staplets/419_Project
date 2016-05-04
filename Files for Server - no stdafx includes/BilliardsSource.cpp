/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/21/16
* Last Modification Date:	4/21/16
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

     std::cout << "\nFrom closer inspection of the pool table, Sherlock notes it as: " << getDescription() << "\n\n";

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
          std::cout << "Sherlock takes note of a " << getBall() << " and the " << getStick() << " and wonders if they would be worthwhile evidence.\n\n";

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
          std::cout << "Sherlock takes note of the " << getStick() << ", since he already grabbed a pool ball and wonders if it would be worthwhile evidence.\n\n";

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
          std::cout << "There are still a few pool balls on the pool table and a stick, but Sherlock has already collected a stick and ball and is content.\n\n";
          break;
     case 3: // stick found but not ball in user inventory
          //output choices
          std::cout << "Sherlock takes note of the " << getBall() << ", since he already grabbed a " << getStick() << " and wonders if it would be worthwhile evidence.\n\n";

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
     std::cout << "\nWalking over to the coffee table, Sherlock notes: " << getDescription() << "\n\n";

     //check if knife is already in inventory
     auto search = inv.find("brochure");
     if (search != inv.end()){
          std::cout << "\nThe table has a Life magazine, but Sherlock already grabbed the " << getBrochure() << " that interested him.\n\n";
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

//navigation function to handle game play while the player is in the billiards room
int billiardsNavigate(std::unordered_map<std::string, std::string>& inventory){

     //boolean to find out if player wants to move to another room
     bool move = false;
     int firstTime = 0;

     //intialize objects
     PoolTable poolTable;
     CoffeeTable coffeeTable;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Billiards Room\n\n\n\n" <<
          "Sherlock is in the Billiards Room.\n\nLooking around, he sees a Pool Table in the center of the room and in the corner of the room there is a coffee table.\n\nLook at Pool Table? (Enter \"1\").\n\n" <<
          "Go over to look at Coffee Table? (Enter \"2\").\n\n" <<
          "You may go to the Deck outside (Enter \"3\")\n\nYou may go into the Study (Enter \"4\").\n\n" <<
          "You may walk into the Smoking Room (Enter \"5\")\n\nYou may go into the Ballroom (Enter \"6\").\n\n" <<
          "Check your inventory of items ( Enter \"7\").\n\n" <<
          "What would you like to do? Choose a number between 1 and 7.";

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
                    std::cout << "\n\nPlease select a number between 1 and 7 to navigate: \n\n";
               }
               else{
                    if (firstTime != 0){
                         //formatting
                         std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                         std::cout << "\n\nThe Billiards Room\n\n\n\n" <<
                              "Sherlock is in the Billiards Room.\n\nLooking around, he sees a Pool Table in the center of the room and in the corner of the room there is a coffee table.\n\nLook at Pool Table? (Enter \"1\").\n\n" <<
                              "Go over to look at Coffee Table? (Enter \"2\").\n\n" <<
                              "You may go to the Deck outside (Enter \"3\")\n\nYou may go into the Study (Enter \"4\").\n\n" <<
                              "You may walk into the Smoking Room (Enter \"5\")\n\nYou may go into the Ballroom (Enter \"6\").\n\n" <<
                              "Check your inventory of items ( Enter \"7\").\n\n" <<
                              "What would you like to do? Choose a number between 1 and 7.";
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


          //take users choice and interact based on that
          switch (choice){
          case 1:
               poolTable.checkTable(inventory);
               break;
          case 2:               
               coffeeTable.checkCoffeeTable(inventory);
               break;
          case 3:
               std::cout << "\nGoing out to the Deck.\n";
               //change choice to reflect our room mapping and update move
               choice = 13;
               move = true;
               break;
          case 4:
               std::cout << "\nWalking into the Study.\n";
               //change choice to reflect our room mapping and update move
               choice = 4;
               move = true;
               break;
          case 5:
               std::cout << "\nWalking into the Smoking Room.\n";
               //change choice to reflect our room mapping and update move
               choice = 6;
               move = true;
               break;
          case 6:
               std::cout << "\nWalking into the Ballroom.\n";
               //change choice to reflect our room mapping and update move
               choice = 16;
               move = true;
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

     } while (!move);

     return choice;
}