/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/24/16
* Last Modification Date:	5/24/16
* Filename:				SmokingSource.cpp
*
* Overview:
*	This file holds the implementation for the Smoking Room objects and interaction.
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

//include animation header
#include "animation.hpp"

//include hallway header
#include "SmokingHeader.h"

//member function 
void RecliningChair::checkRecliningChair(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Reclining Chair\n\n\n\n";

     std::cout << "\nFrom closer inspection of the recliner, You note: " << getDescription() << "\n\n";

     //check if pipe is already in inventory
     auto search = inv.find("pipe");
     if (search != inv.end()) {
          std::cout << "\nThe recliner has nothing of note as you already grabbed the " << getPipe() << " that interested you.\n\n";
     }
     else {

          std::cout << "\nYou notice a " << getPipe() << " on the recliner, which catches your eye.\n\n";

          std::cout << "\nWould you like to add the " << getPipe() << " to your inventory?\n\n";

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

          if (ans == "y") {
               inv.insert({ "pipe", getPipe() });
               std::cout << "\nOkay, " << getPipe() << " added to inventory.\n\n";
          }
          else {
               std::cout << "\nOkay, " << getPipe() << " not added to inventory.\n\n";
          }
     }

}

//Accessor Functions for accessing private variables in RecliningChair.
std::string RecliningChair::getDescription() const { return description; }

std::string RecliningChair::getPipe() const { return pipe; }

//Mutator Functions to change private variables.
void RecliningChair::setDescription(const std::string theDescription) { description = theDescription; }

void RecliningChair::setPipe(const std::string thePipe) { pipe = thePipe; }


//member function to output information provided of each item
void Painting::checkPainting(std::unordered_map<std::string, std::string>& inv) {

     //initialize the painting object
     Painting painting;
     //user input var
     std::string ans;

	 //animation variables
	 int start_row = 4;
	 int start_column = 4;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	 //painting animation
	 initscr();
	 clear();
	 printPainting(start_row, start_column);
	 refresh();
	 getch();
	 endwin();

     //Game Intro
     std::cout << "\n\nThe Painting\n\n\n\n";

     //coffee table info
     std::cout << "\nWalking over to the painting, you note: " << getDescription() << "\n\n";

     //check if knife is already in inventory
     auto search = inv.find("knife");
     if (search != inv.end()) {
          std::cout << "\nYou admire the painting, however you notice it may be hanging a bit askew.\n\n" <<
               "You think there may be something behind it, but it appears to be stuck to the wall.\n\n" <<
               "No worries! You have a knife on you to try and pry this thing open.\n\n";

          std::cout << "Would you like to try and pry the painting off the wall?\n\n";

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

          if (ans == "y") {

               //check if revolver is already in inventory
               auto search = inv.find("revolver");
               if (search != inv.end()) {
                    std::cout << "\n\nYou use the knife and are able to open the painting from the right side with what appears to be hinges.\n\n" <<
                         "There is a small hiding spot behind the painting, however you have already grabbed the revolver.\n\n";
               }
               else {

                    std::cout << "\n\nYou use the knife and are able to open the painting from the right side with what appears to be hinges.\n\n" <<
                         "There is a small hiding spot behind the painting where a revolver sits.\n\nWould you like to add the revolver to the inventory?\n\n";

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

                    if (ans == "y") {
                         inv.insert({ "revolver", getRevolver() });
                         std::cout << "\nOkay, " << getRevolver() << " added to inventory.\n\n";
                    }
                    else {
                         std::cout << "\nOkay, " << getRevolver() << " not added to inventory.\n\n";
                    }
               }
          }
          else {
               //user decides not to pull forward painting
               std::cout << "\nOkay, you leave the painting as is.\n\n";
          }

     }
     else {

          std::cout << "\nYou admire the painting, however you notice it may be hanging a bit askew.\n\n" <<
               "You think there may be something behind it, but it appears to be stuck to the wall.\n\n" <<
               "Perhaps if you had something sharp with you, such as a knife, you could pry it open ...\n\n";
     }
}


//Accessor Functions for accessing private variables in Painting.
std::string Painting::getRevolver() const { return revolver; }

std::string Painting::getDescription() const { return description; }

//Mutator Functions to change private variables.
void Painting::setRevolver(const std::string theRevolver) { revolver = theRevolver; }

void Painting::setDescription(const std::string theDescription) { description = theDescription; }


/////Room class functions/////
//get functions
std::string RoomSmoking::getName() const { return name; }

int RoomSmoking::getNumRooms() const { return numRooms; }

int RoomSmoking::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomSmoking::getExits() const { return exits; }

std::vector<std::string> RoomSmoking::getObjects() const { return objects; }

std::string RoomSmoking::getDescription() const { return description; }

//set functions
void RoomSmoking::setName(const std::string theName){ name = theName; }

void RoomSmoking::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomSmoking::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomSmoking::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomSmoking::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomSmoking::setDescription(const std::string theDescription){ description = theDescription; }