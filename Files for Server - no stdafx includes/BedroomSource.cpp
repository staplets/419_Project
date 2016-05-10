/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/04/16
* Last Modification Date:	     5/05/16
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

//include bedroom header
#include "BedroomHeader.h"

//member function for the Bed
void Bed::checkBed(std::unordered_map<std::string, std::string>& inv)
{
     //initialize the parrott
     Bed bed;
     int firstTime = 0;
     //choice from player
     int choice = 0;
     int retry = 0;
     std::string ans;

     //initialize random seed
     srand((unsigned int)time(NULL));

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Bed\n\n\n\n";

     std::cout << "\nWalking towards the bed, Sherlock notes it as: " << getDescription() << "\n\n";

     //check if pen is already in inventory
     auto search = inv.find("pen");
     if (search != inv.end()){
          std::cout << "\nSherlock moves closer to examine the bed. He carefully looks under the pillows and sheets being mindful of the body.\n\n" <<
               "\nSherlock has already grabbed the " << getPen() << " and does not see anything else out of the ordinary.\n\n";
     }
     else{

          std::cout << "\nSherlock moves closer to examine the bed. He carefully looks under the pillows and sheets being mindful of the body.\n\n" <<
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
     int checkInventory = 0;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nThe Body of Mr. Cunningham\n\n\n\n";

     std::cout << "\nSherlock approaches the body to examine. " << getDescription() << getDescriptionTwo() << getDescriptionThree();

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
          std::cout << "\nSherlock pats down the body and checks all of Mr. Cunningham's pockets.\n\nHe doesn't find anything of use in the pants or outer coat pockets.\n\n" <<
               "He has also already grabbed the " << getGrape() << " from the inner pocket so he finds no evidence of use here.\n\n";
     }
     else{

          std::cout << "\nSherlock pats down the body and checks all of Mr. Cunningham's pockets.\n\nHe doesn't find anything of use in the pants or outer coat pockets.\n\n" <<
               "When he feels into an inside coat pocket he pulls out a grape. From Sherlock's knowledge of the fruit, he recognizes the type as a " << getGrape() << ".\n\n" <<
               "\"Peculiar ... \" Sherlock he thinks to himself. He knows they are not native to this region of America, as he believes they come from an area of France.\n\n";

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

//navigation function to handle game play while the player is in the bedroom
int bedroomNavigate(std::unordered_map<std::string, std::string>& inventory){

     //boolean to find out if player wants to move to another room
     bool move = false;
     int firstTime = 0;

     //intialize objects
     Bed bed;
     Body body;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Bedroom\n\n\n\n" <<
          "Sherlock is in the Bedoom.\n\nThe body of Willie Cunningham lies on the bed in the middle of the room.\n\n" <<
          "Otherwise the room looks to be in pristine condition.\n\n" <<
          "Any of the evidence in this room is either on the body or the bed of which he lies.\n\n" <<
          "Additionally the bedroom leads to it's own personal bathroom.\n\n" <<
          "Examine the body? (Enter \"1\").\n\n" <<
          "Examine the bed? (Enter \"2\").\n\n" <<
          "You may go into the Bathroom (Enter \"3\")\n\n" <<
          "You may go out into the hallway (Enter \"4\").\n\n" <<
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

                         std::cout << "\n\nThe Bedroom\n\n\n\n" <<
                              "Sherlock is in the Bedoom.\n\nThe body of Willie Cunningham lies on the bed in the middle of the room.\n\n" <<
                              "Otherwise the room looks to be in pristine condition.\n\n" <<
                              "Any of the evidence in this room is either on the body or the bed of which he lies.\n\n" <<
                              "Additionally the bedroom leads to it's own personal bathroom.\n\n" <<
                              "Examine the body? (Enter \"1\").\n\n" <<
                              "Examine the bed? (Enter \"2\").\n\n" <<
                              "You may go into the Bathroom (Enter \"3\")\n\n" <<
                              "You may go out into the hallway (Enter \"4\").\n\n" <<
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
               body.checkBody(inventory);
               break;
          case 2:
               bed.checkBed(inventory);
               break;
          case 3:
               std::cout << "\nGoing into the Bathroom.\n";
               //change choice to reflect our room mapping and update move
               choice = 19;
               move = true;
               break;
          case 4:
               std::cout << "\nWalking into the Hallway.\n";
               //change choice to reflect our room mapping and update move
               choice = 14;
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