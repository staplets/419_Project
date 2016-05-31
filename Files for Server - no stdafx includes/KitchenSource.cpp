/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/22/16
* Last Modification Date:	5/22/16
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
#include <vector>

//include foyer header
#include "KitchenHeader.h"

//include animation header
#include "animation.hpp"

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

	 //animation variables
	 int start_row = 4;
	 int start_column = 4;

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
          std::cout << "There are many items in this large refrigerator, but two things stand out to you. A piece of " << getSteak() << " and a " << getPie() << "\n\n";
          
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

			  //code for pie animation
			  initscr();
			  printPie(start_row, start_column);
			  refresh();
			  getch();
			  endwin();

               inv.insert({ "pie", getPie() });
               std::cout << "\nOkay, " << getPie() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getPie() << " not added to inventory.\n\n";
          }

          break;
     case 1: //only steak in user inventory
          //output choices
          std::cout << "There are many items in this large refrigerator, but since you already grabbed the steak, one thing stands out to you. A piece of " << getPie() << "\n\n";
          
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
          std::cout << "There are many items in this large refrigerator, but since you already grabbed the steak and blueberry pie nothing stands out to you.\n\n";
          break;
     case 3: // pie found but not steak in user inventory
          //output choices
          std::cout << "There are many items in this large refrigerator, but since you already grabbed the blueberry pie, one thing stands out to you. A piece of " << getSteak() << "\n\n";
          
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

/////Room class functions/////
//get functions
std::string RoomKitchen::getName() const { return name; }

int RoomKitchen::getNumRooms() const { return numRooms; }

int RoomKitchen::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomKitchen::getExits() const { return exits; }

std::vector<std::string> RoomKitchen::getObjects() const { return objects; }

std::string RoomKitchen::getDescription() const { return description; }

//set functions
void RoomKitchen::setName(const std::string theName){ name = theName; }

void RoomKitchen::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomKitchen::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomKitchen::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomKitchen::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomKitchen::setDescription(const std::string theDescription){ description = theDescription; }
