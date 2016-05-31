/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/24/16
* Last Modification Date:	     5/25/16
* Filename:					BedroomSource.cpp
*
* Overview:
*	This file holds the implementation for the Bedroom objects and interaction.
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

//include bedroom header
#include "BedroomHeader.h"

//include animation header
#include "animation.hpp"

//member function for the Bed
void Bed::checkBed(std::unordered_map<std::string, std::string>& inv)
{
     //initialize the parrott
     Bed bed;
    
     //choice from player
     std::string ans;

     //initialize random seed
     srand((unsigned int)time(NULL));

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Bed\n\n\n\n";

     std::cout << "\nWalking towards the bed, you note it as: " << getDescription() << "\n\n";

     //check if pen is already in inventory
     auto search = inv.find("pen");
     if (search != inv.end()){
          std::cout << "\nYou move closer to examine the bed. You carefully look under the pillows and sheets being mindful of the body.\n\n" <<
               "\nYou have already grabbed the " << getPen() << " and do not see anything else out of the ordinary.\n\n";
     }
     else{

          std::cout << "\nYou move closer to examine the bed. You carefully look under the pillows and sheets being mindful of the body.\n\n" <<
               "\nStuck between the headboard and the matress is a " << getPen() << ".\n\n";

          std::cout << "\nWould you like to add the " << getPen() << " to your inventory?\n\n";

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
               inv.insert({ "pen", getPen() });
               std::cout << "\nOkay, " << getPen() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getPen() << " not added to inventory.\n\n";
          }
     }

}

//Accessor Functions for accessing private variables in Bed.
std::string Bed::getDescription() const { return description; }

std::string Bed::getPen() const { return pen; }

//Mutator Functions to change private variables.
void Bed::setDescription(const std::string theDescription){ description = theDescription; }

void Bed::setPen(const std::string thePen){ pen = thePen; }


//member function to output information provided of each item
void Body::checkBody(std::unordered_map<std::string, std::string>& inv){

     //user input var
     std::string ans;

	 //animation variables
	 int start_row = 4;
	 int start_column = 4;
    
	 //body outline animation
	 initscr();
	 printOutline(start_row, start_column);
	 refresh();
	 getch();
	 endwin();

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Body of Mr. Cunningham\n\n\n\n";

     std::cout << "\nYou approach the body to examine. " << getDescription() << getDescriptionTwo() << getDescriptionThree();

     std::cout << "\nWould you like to check for a pulse to be conclusive of death?\n\n";

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
          std::cout << getPulse();
     }
     else{
          std::cout << "\nOkay, not checking Mr. Cunningham's vitals.\n\n";
     }

     //check if grape is already in inventory
     auto search = inv.find("grape");
     if (search != inv.end()){
          std::cout << "\nYou pat down the body and check all of Mr. Cunningham's pockets.\n\nYou don't find anything of use in the pants or outer coat pockets.\n\n" <<
               "You have also already grabbed the " << getGrape() << " from the inner pocket so you find no evidence of use here.\n\n";
     }
     else{

          std::cout << "\nYou pat down the body and check all of Mr. Cunningham's pockets.\n\nYou don't find anything of use in the pants or outer coat pockets.\n\n" <<
               "When you feel into an inside coat pocket you pull out a grape. From your knowledge of the fruit, you recognize the type as a " << getGrape() << ".\n\n" <<
               "\"Peculiar ... \" you think to yourself. You know they are not native to this region of America, as you believe they come from an area of France.\n\n";

          std::cout << "\nWould you like to add the " << getGrape() << " to your inventory?\n\n";

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
               inv.insert({ "grape", getGrape() });
               std::cout << "\nOkay, " << getGrape() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getGrape() << " not added to inventory.\n\n";
          }
     }

}


//Accessor Functions for accessing private variables in Body.
std::string Body::getGrape() const { return grape; }

std::string Body::getPulse() const { return pulse; }

std::string Body::getDescription() const { return description; }

std::string Body::getDescriptionTwo() const { return descriptionTwo; }

std::string Body::getDescriptionThree() const { return descriptionThree; }


//Mutator Functions to change private variables.
void Body::setGrape(const std::string theGrape){ grape = theGrape; }

void Body::setPulse(const std::string thePulse){ pulse = thePulse; }

void Body::setDescription(const std::string theDescription){ description = theDescription; }

void Body::setDescriptionTwo(const std::string theDescriptionTwo){ descriptionTwo = theDescriptionTwo; }

void Body::setDescriptionThree(const std::string theDescriptionThree){ descriptionThree = theDescriptionThree; }

/////Room class functions/////
//get functions
std::string RoomBedroom::getName() const { return name; }

int RoomBedroom::getNumRooms() const { return numRooms; }

int RoomBedroom::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomBedroom::getExits() const { return exits; }

std::vector<std::string> RoomBedroom::getObjects() const { return objects; }

std::string RoomBedroom::getDescription() const { return description; }

//set functions
void RoomBedroom::setName(const std::string theName){ name = theName; }

void RoomBedroom::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomBedroom::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomBedroom::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomBedroom::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomBedroom::setDescription(const std::string theDescription){ description = theDescription; }
