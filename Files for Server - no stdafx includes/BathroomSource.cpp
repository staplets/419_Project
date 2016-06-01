/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/30/16
* Last Modification Date:	     5/30/16
* Filename:					BathroomSource.cpp
*
* Overview:
*	This file holds the implementation for the Bathroom objects and interaction.
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
#include "BathroomHeader.h"

//include animation header
#include "animation.hpp"

//member function for the Bed
void Cabinet::checkCabinet(std::unordered_map<std::string, std::string>& inv)
{
     //initialize the parrott
     Cabinet cabinet;
    
     //choice from player
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Vanity Cabinet\n\n\n\n";

     std::cout << "\nWalking towards the Vanity Cabinet, you note: " << getDescription() << "\n\n";

     //check if light bulb is already in inventory
     auto search = inv.find("bulb");
     if (search != inv.end()){
		 std::cout << "\nYou meticulously review the vanity cabinet.\n\n\nYou see some toiletries in the cabinet and the mirror doesn't have anything on it.\n\n" <<
			 "\nIn the cabinet, there is nothing of note as you've already grabbed " << getLightBulb() << " for your inventory.\n\n";
     }
     else{

          std::cout << "\nYou meticulously review the vanity cabinet. \n\n\nYou see some toiletries in the cabinet and the mirror doesn't have anything on it.\n\n" <<
               "\nIn the cabinet below you do notice " << getLightBulb() << ".\n\n";

          std::cout << "\nWould you like to add the " << getLightBulb() << " to your inventory?\n\n";

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
               inv.insert({ "bulb", getLightBulb() });
			   std::cout << "\nOkay, " << getLightBulb() << " added to inventory.\n\n";
          }
          else{
			  std::cout << "\nOkay, " << getLightBulb() << " not added to inventory.\n\n";
          }
     }

}

//Accessor Functions for accessing private variables in Bed.
std::string Cabinet::getDescription() const { return description; }

std::string Cabinet::getLightBulb() const { return lightBulb; }

//Mutator Functions to change private variables.
void Cabinet::setDescription(const std::string theDescription){ description = theDescription; }

void Cabinet::setLightBulb(const std::string theLightBulb){ lightBulb = theLightBulb; }


//member function to output information provided of each item
void Bath::checkBath(std::unordered_map<std::string, std::string>& inv){

     //user input var
     std::string ans;
     int checkInventory = 0;

	 //animation variables
	 int start_row = 4;
	 int start_column = 4;
	 int i;
	 int speed;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Bath Tub\n\n\n\n";

     std::cout << "\nYou look at the bath tub and note: " << getDescription() << "\n\n";

	 std::cout << "\n\"It has been a long night ...\" You think to yourself. Would you like to take a bath?\n\n";

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

		 //bathtub animation
		 initscr();
		 clear();
		 printTub(start_row, start_column);

		 for (i = 0; i <= 7; i++)
		 {
			 printBubbles1(start_row, start_column);
			 refresh();
			 for (speed = 1; speed <= 55000000; speed++);
			 printBubbles2(start_row, start_column);
			 refresh();
			 for (speed = 1; speed <= 55000000; speed++);
			 printBubbles3(start_row, start_column);
			 refresh();
			 for (speed = 1; speed <= 55000000; speed++);
			 printBubbles4(start_row, start_column);
			 refresh();
			 for (speed = 1; speed <= 55000000; speed++);
		 }
		 endwin();

		 std::cout << getTakeBath();
	 }
	 else{
		 std::cout << "\nOkay, You probably shouldn't have taken a bath anyway.\n\n";
	 }

	 
     //check if soap/wine glass is already in inventory
     auto search = inv.find("soap");
     if (search != inv.end()){
          checkInventory = 1;
     }

     //check if ducky/handkerchief is already in inventory
     search = inv.find("ducky");
     if (search != inv.end()){
          //if ducky found and soap found
          if (checkInventory == 1){
               checkInventory = 2;
          }
          //if ducky found but soap not found
          else if (checkInventory == 0){
               checkInventory = 3;
          }

     }

     //handle output to user based on whether the wglass or handk are on the table
     switch (checkInventory){
     case 0: // ducky and soap not in user inventory
          //output choices
          std::cout << "You take note of a " << getSoap() << " and a " << getDucky() << " and wonder if they would be worthwhile evidence.\n\n";

          //check to add soap to inventory
          std::cout << "Would you like to add a " << getSoap() << " to your inventory?\n\n";

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
               inv.insert({ "soap", getSoap() });
			   std::cout << "\nOkay, " << getSoap() << " added to inventory.\n\n";
          }
          else{
			  std::cout << "\nOkay, " << getSoap() << " not added to inventory.\n\n";
          }

          //check to add ducky to inventory
          std::cout << "Would you like to add a " << getDucky() << " to your inventory?\n\n";

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
			  inv.insert({ "ducky", getDucky() });
			  std::cout << "\nOkay, " << getDucky() << " added to inventory.\n\n";
          }
          else{
			  std::cout << "\nOkay, " << getDucky() << " not added to inventory.\n\n";
          }

          break;
     case 1: //only soap in user inventory
          //output choices
          std::cout << "You take note of the " << getDucky() << ", since you've already grabbed the soap and wonder if it would be worthwhile evidence.\n\n";

          std::cout << "Would you like to add a " << getDucky() << " to your inventory?\n\n";

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
			  inv.insert({ "ducky", getDucky() });
			  std::cout << "\nOkay, " << getDucky() << " added to inventory.\n\n";
          }
          else{
			  std::cout << "\nOkay, " << getDucky() << " not added to inventory.\n\n";
          }
          break;
     case 2: // ducky and soap in user inventory
          //output choices
          std::cout << "The bath tub is clear of any items, since you have already collected the soap and rubber ducky.\n\n";
          break;
     case 3: // ducky found but not soap in user inventory
          //output choices
          std::cout << "You take note of the " << getSoap() << ", since you've already grabbed a " << getDucky() << "\n\nand wonder if it would be worthwhile evidence.\n\n";

		  std::cout << "Would you like to add a " << getSoap() << " to your inventory?\n\n";

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
			  inv.insert({ "soap", getSoap() });
			  std::cout << "\nOkay, " << getSoap() << " added to inventory.\n\n";
          }
          else{
			  std::cout << "\nOkay, " << getSoap() << " not added to inventory.\n\n";
          }
          break;
     }

}


//Accessor Functions for accessing private variables in Bath.
std::string Bath::getSoap() const { return soap; }

std::string Bath::getDucky() const { return ducky; }

std::string Bath::getDescription() const { return description; }

std::string Bath::getTakeBath() const { return takeBath; }

//Mutator Functions to change private variables.
void Bath::setDucky(const std::string theDucky){ ducky = theDucky; }

void Bath::setSoap(const std::string theSoap){ soap = theSoap; }

void Bath::setDescription(const std::string theDescription){ description = theDescription; }

void Bath::setTakeBath(const std::string theTakeBath){ takeBath = theTakeBath; }

/////Room class functions/////
//get functions
std::string RoomBathroom::getName() const { return name; }

int RoomBathroom::getNumRooms() const { return numRooms; }

int RoomBathroom::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomBathroom::getExits() const { return exits; }

std::vector<std::string> RoomBathroom::getObjects() const { return objects; }

std::string RoomBathroom::getDescription() const { return description; }

//set functions
void RoomBathroom::setName(const std::string theName){ name = theName; }

void RoomBathroom::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomBathroom::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomBathroom::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomBathroom::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomBathroom::setDescription(const std::string theDescription){ description = theDescription; }
