/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/23/16
* Last Modification Date:	5/23/16
* Filename:				CellarSource.cpp
*
* Overview:
*	This file holds the implementation for the Cellar objects and interaction.
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
#include "CellarHeader.h"

//include animation header
#include "animation.hpp"

//member function to get into the trunk of LuxuryCar
void Dresser::checkDresser(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nDresser\n\n\n\n";

     std::cout << "\nFrom closer inspection of the dresser, you note the following:\n";

     std::cout << "\n\nIt is made of: " << this->material << "\n\nNumber of drawers in the dresser are: " << this->numDrawers << "\n\n\n";

     //check if knife is already in inventory
     auto search = inv.find("dog treat");
     if (search != inv.end()){
          std::cout << "\nThere is nothing in the dresser drawers. You have already grabbed the " << getDogTreat() << " from here.\n\n";
     }
     else{

          std::cout << "\nThere is a " << getDogTreat() << " in one of the drawers.\n\n";

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
               inv.insert({ "dog treat", getDogTreat() });
               std::cout << "\nOkay, " << getDogTreat() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getDogTreat() << " not added to inventory.\n\n";
          }
     }

}

//Accessor Functions for accessing private variables in CoatCloset.
std::string Dresser::getMaterial() const { return material; }

int Dresser::getNumDrawers() const { return numDrawers; }

std::string Dresser::getDogTreat() const { return dogTreat; }

//Mutator Functions to change private variables.
void Dresser::setMaterial(const std::string theMaterial){ material = theMaterial; }

void Dresser::setNumDrawers(const int theNumDrawers){ numDrawers = theNumDrawers; }

void Dresser::setDogTreat(const std::string theDOgTreat){ dogTreat = theDOgTreat; }



//member function to output information provided of each item
void Box::boxInformation()
{
     std::cout << "\n\nDescription: " << this->description << "\n\n";
}

void Box::checkBox(std::unordered_map<std::string, std::string>& inv){

     //initialize the fish bowl object
     Box box;
     //user input var
     std::string ans;
     int checkInventory = 0;

	 //animation variables
	 int start_row = 4;
	 int start_column = 4;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Box\n\n\n\n";

     //get bowl info
     box.boxInformation();

     //check if steak is already in inventory
     auto search = inv.find("pictures");
     if (search != inv.end()){
          checkInventory = 1;
     }

     //check if pie is already in inventory
     search = inv.find("bowlingBall");
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

     //handle output to user based on whether the pictures or bowling ball are in the box
     switch (checkInventory){
     case 0: // pictures and bowling ball not in user inventory
          //output choices
          std::cout << "In the box, you find two things. Some " << getPictures() << " and a " << getBowlingBall() << "\n\n";

          //check to add steak to inventory
          std::cout << "Would you like to add the " << getPictures() << " to your inventory?\n\n";

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

			  //pictures animation
			  initscr();
			  printOldPhoto(start_row, start_column);
			  refresh();
			  getch();
			  endwin();

               inv.insert({ "pictures", getPictures() });
               std::cout << "\nOkay, the " << getPictures() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, the " << getPictures() << " not added to inventory.\n\n";
          }

          //check to add pie to inventory
          std::cout << "Would you like to add a " << getBowlingBall() << " to your inventory?\n\n";

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
               inv.insert({ "bowlingBall", getBowlingBall() });
               std::cout << "\nOkay, " << getBowlingBall() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getBowlingBall() << " not added to inventory.\n\n";
          }

          break;
     case 1: //only pictures in user inventory
          //output choices
          std::cout << "You find only a " << getBowlingBall() << " as you've already grabbed the pictures.\n\n";

          std::cout << "Would you like to add a " << getBowlingBall() << " to your inventory?\n\n";

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
               inv.insert({ "bowlingBall", getBowlingBall() });
               std::cout << "\nOkay, " << getBowlingBall() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getBowlingBall() << " not added to inventory.\n\n";
          }
          break;
     case 2: // pictures and bowling ball in user inventory
          //output choices
          std::cout << "You see nothing in the box, since you already grabbed the pictures and " << getBowlingBall() << ".\n\n";
          break;
     case 3: // bowling ball found but not pictures in user inventory
          //output choices
          std::cout << "You find only some " << getPictures() << " as you've already grabbed the " << getBowlingBall() << ".\n\n";

          std::cout << "Would you like to add a " << getPictures() << " to your inventory?\n\n";

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
               inv.insert({ "steak", getPictures() });
               std::cout << "\nOkay, " << getPictures() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getPictures() << " not added to inventory.\n\n";
          }
          break;
     }

}


//Accessor Functions for accessing private variables in Box.
std::string Box::getPictures() const { return pictures; }

std::string Box::getBowlingBall() const { return bowlingBall; }

std::string Box::getDescription() const { return description; }

//Mutator Functions to change private variables.
void Box::setPictures(const std::string thePictures){ pictures = thePictures; }

void Box::setBowlingBall(const std::string theBowlingBall){ bowlingBall = theBowlingBall; }

void Box::setDescription(const std::string theDescription){ description = theDescription; }

/////Room class functions/////
//get functions
std::string RoomCellar::getName() const { return name; }

int RoomCellar::getNumRooms() const { return numRooms; }

int RoomCellar::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomCellar::getExits() const { return exits; }

std::vector<std::string> RoomCellar::getObjects() const { return objects; }

std::string RoomCellar::getDescription() const { return description; }

//set functions
void RoomCellar::setName(const std::string theName){ name = theName; }

void RoomCellar::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomCellar::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomCellar::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomCellar::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomCellar::setDescription(const std::string theDescription){ description = theDescription; }
