/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/18/16
* Last Modification Date:	4/19/16
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

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

//include foyer header
#include "CellarHeader.h"

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
     int firstTime = 0;
     //user input var
     std::string ans;
     int checkInventory = 0;

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
          std::cout << "In the box, Sherlock finds two things. Some " << getPictures() << " and a " << getBowlingBall() << "\n\n";

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
          std::cout << "Sherlock finds only a " << getBowlingBall() << " as you've already grabbed the pictures.\n\n";

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
          std::cout << "Sherlock sees nothing in the box, since you already grabbed the pictures and " << getBowlingBall() << ".\n\n";
          break;
     case 3: // bowling ball found but not pictures in user inventory
          //output choices
          std::cout << "Sherlock finds only some " << getPictures() << " as you've already grabbed the " << getBowlingBall() << ".\n\n";

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


//navigation function to handle game play while the player is in the Cellar
int cellarNavigate(std::unordered_map<std::string, std::string>& inventory){

     //boolean to find out if player wants to move to another room
     bool move = false;
     int firstTime = 0;

     //intialize objects
     Dresser dresser;
     Box box;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Cellar\n\n\n\n" <<
          "Sherlock is in the Cellar.\n\nLooking around, he sees a Dresser in the corner and a Box in the other far corner that may be worth a look.\n\nLook at Dresser? (Enter \"1\").\n\n" <<
          "Open the Box? (Enter \"2\").\n\n" <<
          "You may go to the Garden outside (Enter \"3\")\n\nYou may go up to the Kitchen (Enter \"4\").\n\n" <<
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

                         std::cout << "\n\nThe Cellar\n\n\n\n" <<
                              "Sherlock is in the Cellar.\n\nLooking around, he sees a Dresser in the corner and a Box in the other far corner that may be worth a look.\n\nLook at Dresser? (Enter \"1\").\n\n" <<
                              "Open the Box? (Enter \"2\").\n\n" <<
                              "You may go to the Garden outside (Enter \"3\")\n\nYou may go up to the Kitchen (Enter \"4\").\n\n" <<
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
               dresser.checkDresser(inventory);
               break;
          case 2:
               box.checkBox(inventory);
               break;
          case 3:
               std::cout << "\nGoing out to the Garden.\n";
               //change choice to reflect our room mapping and update move
               choice = 3;
               move = true;
               break;
          case 4:
               std::cout << "\nGoing up to the Kitchen.\n";
               //change choice to reflect our room mapping and update move
               choice = 9;
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