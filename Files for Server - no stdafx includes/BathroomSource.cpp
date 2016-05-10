/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/05/16
* Last Modification Date:	     5/06/16
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

//include bedroom header
#include "BathroomHeader.h"

//member function for the Bed
void Cabinet::checkCabinet(std::unordered_map<std::string, std::string>& inv)
{
     //initialize the parrott
     Cabinet cabinet;
     int firstTime = 0;
     //choice from player
     int choice = 0;
     int retry = 0;
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Vanity Cabinet\n\n\n\n";

     std::cout << "\nWalking towards the Vanity Cabinet, Sherlock notes: " << getDescription() << "\n\n";

     //check if light bulb is already in inventory
     auto search = inv.find("bulb");
     if (search != inv.end()){
		 std::cout << "\nSherlock meticulously reviews the vanity cabinet.\n\n\nHe sees some toiletries in the cabinet and the mirror doesn't have anything on it.\n\n" <<
			 "\nIn the cabinet, there is nothing of note as he already grabbed " << getLightBulb() << " for his inventory.\n\n";
     }
     else{

          std::cout << "\nSherlock meticulously reviews the vanity cabinet. \n\n\nHe sees some toiletries in the cabinet and the mirror doesn't have anything on it.\n\n" <<
               "\nIn the cabinet below he does notice " << getLightBulb() << ".\n\n";

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

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Bath Tub\n\n\n\n";

     std::cout << "\nSherlock looks at the bath tub and notes: " << getDescription() << "\n\n";

	 std::cout << "\n\"It has been a long night ...\" Sherlock thinks to himself. Would you like to take a bath?\n\n";

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
		 std::cout << getTakeBath();
	 }
	 else{
		 std::cout << "\nOkay, Sherlock probably shouldn't have taken a bath anyway.\n\n";
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
          std::cout << "Sherlock takes note of a " << getSoap() << " and a " << getDucky() << " and wonders if they would be worthwhile evidence.\n\n";

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
          std::cout << "Sherlock takes note of the " << getDucky() << ", since he already grabbed the soap and wonders if it would be worthwhile evidence.\n\n";

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
          std::cout << "The bath tub is clear of any items, since Sherlock has already collected the soap and rubber ducky.\n\n";
          break;
     case 3: // ducky found but not soap in user inventory
          //output choices
          std::cout << "Sherlock takes note of the " << getSoap() << ", since he already grabbed a " << getDucky() << "\n\nand wonders if it would be worthwhile evidence.\n\n";

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

//navigation function to handle game play while the player is in the Bathroom
int bathroomNavigate(std::unordered_map<std::string, std::string>& inventory){

     //boolean to find out if player wants to move to another room
     bool move = false;
     int firstTime = 0;

     //intialize objects
     Cabinet cabinet;
     Bath bath;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Bathroom\n\n\n\n" <<
          "Sherlock is in the Bathroom.\n\nIn this room he see a sizable bath tub and a fancy vanity cabinet.\n\n" <<
          "The toilet and sink look to be in order without traces of anything interesting.\n\n" <<
          "Examine the bath tub? (Enter \"1\").\n\n" <<
          "Check out the vanity cabinet? (Enter \"2\").\n\n" <<
          "Walk into the Bedroom (Enter \"3\")\n\n" <<
          "Check your inventory of items ( Enter \"4\").\n\n" <<
          "What would you like to do? Choose a number between 1 and 4.";

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
                    std::cout << "\n\nPlease select a number between 1 and 4 to navigate: \n\n";
               }
               else{
                    if (firstTime != 0){
                         //formatting
                         std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

						 std::cout << "\n\nThe Bathroom\n\n\n\n" <<
							 "Sherlock is in the Bathroom.\n\nIn this room he see a sizable bath tub and a fancy vanity cabinet.\n\n" <<
							 "The Toilet and sink look to be in order without traces of anything interesting.\n\n" <<
							 "Examine the bath tub? (Enter \"1\").\n\n" <<
							 "Check out the vanity cabinet? (Enter \"2\").\n\n" <<
							 "Walk into the Bedroom (Enter \"3\")\n\n" <<
							 "Check your inventory of items ( Enter \"4\").\n\n" <<
							 "What would you like to do? Choose a number between 1 and 4.";
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

          } while (choice < 1 || choice > 4);


          //take users choice and interact based on that
          switch (choice){
          case 1:
               bath.checkBath(inventory);
               break;
          case 2:
               cabinet.checkCabinet(inventory);
               break;
          case 3:
               std::cout << "\nGoing into the Bedroom.\n";
               //change choice to reflect our room mapping and update move
               choice = 15;
               move = true;
               break;
          case 4:
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