/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/18/16
* Last Modification Date:	4/18/16
* Filename:				KitchenSource.cpp
*
* Overview:
*	This file holds the implementation for the Kitchen objects and interaction.
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

//include foyer header
#include "KitchenHeader.h"

//member function to get into the trunk of LuxuryCar
void KnifeBlock::checkKnifeBlock(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nKnife Block\n\n\n\n";

     std::cout << "\nFrom closer inspection of the knife block, you note the following:\n";

     std::cout << "\n\nIt is made of: " << this->material << "\n\nNumber of knives in the block is: " << this->numKnives << "\n\n\n";

     //check if knife is already in inventory
     auto search = inv.find("knife");
     if (search != inv.end()){
          std::cout << "\nThere are no knives in the knife block. You have already grabbed the " << getKnife() << " from here.\n\n";
     }
     else{

          std::cout << "\nThe one knife is a smaller sized knife that looks like it could be handy.\n\n";

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
               inv.insert({ "knife", getKnife() });
               std::cout << "\nOkay, " << getKnife() << " added to inventory.\n\n";
               setNumKnives(0);
          }
          else{
               std::cout << "\nOkay, " << getKnife() << " not added to inventory.\n\n";
          }
     }

}

//Accessor Functions for accessing private variables in CoatCloset.
std::string KnifeBlock::getMaterial() const { return material; }

int KnifeBlock::getNumKnives() const { return numKnives; }

std::string KnifeBlock::getKnife() const { return knife; }

//Mutator Functions to change private variables.
void KnifeBlock::setMaterial(const std::string theMaterial){ material = theMaterial; }

void KnifeBlock::setNumKnives(const int theNumKnives){ numKnives = theNumKnives; }

void KnifeBlock::setKnife(const std::string theKnife){ knife = theKnife; }


//member function to output information provided of each item
void Refrigerator::fridgeInformation()
{
     std::cout << "\n\nDescription: " << this->description << "\n\n";
}

void Refrigerator::checkFridge(std::unordered_map<std::string, std::string>& inv){

     //initialize the fish bowl object
     Refrigerator refrigerator;
     //user input var
     std::string ans;
     int checkInventory = 0;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Refrigerator\n\n\n\n";

     //get bowl info
     refrigerator.fridgeInformation();

     //check if steak is already in inventory
     auto search = inv.find("steak");
     if (search != inv.end()){
          checkInventory = 1;
     }

     //check if pie is already in inventory
     search = inv.find("pie");
     if (search != inv.end()){
          //if pie found and steak found
          if (checkInventory == 1){
               checkInventory = 2;
          }
          //if pie found but steak not found
          else if (checkInventory == 0){
               checkInventory = 3;
          }
          
     }

     //handle output to user based on whether the steak or pie are in the fridge
     switch (checkInventory){
     case 0: // pie and steak not in user inventory
          //output choices
          std::cout << "There are many items in this large refrigerator, but two things stand out to Sherlock. A piece of " << getSteak() << " and a " << getPie() << "\n\n";
          
          //check to add steak to inventory
          std::cout << "Would you like to add a " << getSteak() << " to your inventory?\n\n";

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
               inv.insert({ "steak", getSteak() });
               std::cout << "\nOkay, " << getSteak() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getSteak() << " not added to inventory.\n\n";
          }

          //check to add pie to inventory
          std::cout << "Would you like to add a " << getPie() << " to your inventory?\n\n";

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
               inv.insert({ "pie", getPie() });
               std::cout << "\nOkay, " << getPie() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getPie() << " not added to inventory.\n\n";
          }

          break;
     case 1: //only steak in user inventory
          //output choices
          std::cout << "There are many items in this large refrigerator, but since you already grabbed the steak, one thing stands out to Sherlock. A piece of " << getPie() << "\n\n";
          
          std::cout << "Would you like to add a " << getPie() << " to your inventory?\n\n";

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
               inv.insert({ "pie", getPie() });
               std::cout << "\nOkay, " << getPie() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getPie() << " not added to inventory.\n\n";
          }
          break;
     case 2: // pie and steak in user inventory
          //output choices
          std::cout << "There are many items in this large refrigerator, but since you already grabbed the steak and blueberry pie nothing stands out to Sherlock.\n\n";
          break;
     case 3: // pie found but not steak in user inventory
          //output choices
          std::cout << "There are many items in this large refrigerator, but since you already grabbed the blueberry pie, one thing stands out to Sherlock. A piece of " << getSteak() << "\n\n";
          
          std::cout << "Would you like to add a " << getSteak() << " to your inventory?\n\n";

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
               inv.insert({ "steak", getSteak() });
               std::cout << "\nOkay, " << getSteak() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getSteak() << " not added to inventory.\n\n";
          }
          break;
     }

}


//Accessor Functions for accessing private variables in Refrigerator.
std::string Refrigerator::getSteak() const { return steak; }

std::string Refrigerator::getPie() const { return pie; }

std::string Refrigerator::getDescription() const { return description; }

//Mutator Functions to change private variables.
void Refrigerator::setSteak(const std::string theSteak){ steak = theSteak; }

void Refrigerator::setPie(const std::string thePie){ pie = thePie; }

void Refrigerator::setDescription(const std::string theDescription){ description = theDescription; }

//navigation function to handle game play while the player is in the Kitchen
int kitchenNavigate(std::unordered_map<std::string, std::string>& inventory){

     //boolean to find out if player wants to move to another room
     bool move = false;
     int firstTime = 0;

     //intialize objects
     KnifeBlock knifeBlock;
     Refrigerator refrigerator;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Kitchen\n\n\n\n" <<
          "Sherlock is in the Kitchen.\n\nLooking around, he sees a knife block and refrigerator that may be worth checking out.\n\nLook at Knife Block? (Enter \"1\").\n\n" <<
          "Open the refrigerator? (Enter \"2\").\n\n" <<
          "You may enter the Dining Room (Enter \"3\")\n\nYou may enter the Cellar (Enter \"4\").\n\n" <<
          "You may enter the Smoking Room (Enter \"5\").\n\nYou may go outside to the Deck (Enter \"6\").\n\n" <<
          "You may go to the Foyer (Enter \"7\").\n\n"
          "Check your inventory of items ( Enter \"8\").\n\n" <<
          "What would you like to do? Choose a number between 1 and 8.";

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
                    std::cout << "\n\nPlease select a number between 1 and 8 to navigate: \n\n";
               }
               else{
                    if (firstTime != 0){
                         //formatting
                         std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                         std::cout << "\n\nThe Kitchen\n\n\n\n" <<
                              "Sherlock is in the Kitchen.\n\nLooking around, he sees a knife block and refrigerator that may be worth checking out.\n\nLook at Knife Block? (Enter \"1\").\n\n" <<
                              "Open the refrigerator? (Enter \"2\").\n\n" <<
                              "You may enter the Dining Room (Enter \"3\")\n\nYou may enter the Cellar (Enter \"4\").\n\n" <<
                              "You may enter the Smoking Room (Enter \"5\").\n\nYou may go outside to the Deck (Enter \"6\").\n\n" <<
                              "You may go to the Foyer (Enter \"7\").\n\n"
                              "Check your inventory of items ( Enter \"8\").\n\n" <<
                              "What would you like to do? Choose a number between 1 and 8.";
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

          } while (choice < 1 || choice > 8);


          //take users choice and interact based on that
          switch (choice){
          case 1:
               knifeBlock.checkKnifeBlock(inventory);
               break;
          case 2:
               refrigerator.checkFridge(inventory);
               break;
          case 3:
               std::cout << "\nEntering the Dining Room.\n";
               //change choice to reflect our room mapping and update move
               choice = 8;
               move = true;
               break;
          case 4:
               std::cout << "\nEntering the Cellar.\n";
               //change choice to reflect our room mapping and update move
               choice = 10;
               move = true;
               break;
          case 5:
               std::cout << "\nEntering the Smoking Room.\n";
               //change choice to reflect our room mapping and update move
               choice = 6;
               move = true;
               break;
          case 6:
               std::cout << "\nGoing outside to the Deck.\n";
               //change choice to reflect our room mapping and update move
               choice = 13;
               move = true;
               break;
          case 7:
               std::cout << "\nEntering the Foyer.\n";
               //change choice to reflect our room mapping and update move
               choice = 2;
               move = true;
               break;
          case 8:
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