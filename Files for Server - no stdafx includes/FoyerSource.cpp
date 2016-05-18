/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/14/16
* Last Modification Date:	4/18/16
* Filename:				FoyerSource.cpp
*
* Overview:
*	This file holds the implementation for the foyer objects and interaction.
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
#include "FoyerHeader.h"

//member function to output information provided of each item in CoatCloset
void CoatCloset::closetInformation(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nCoat Closet\n\n\n\n";

     std::cout << "\nFrom inspection of the coat closet, you note the following:\n";

     std::cout << "\n\nThe Closet door color is : " << this->color << "\n\nNumber of coats in the closet is: " << this->numCoats << "\n\n\n";

     //check if bottle is already in inventory
     auto search = inv.find("umbrella");
     if (search != inv.end()){
          std::cout << "\nNothing besides the coats. You have already grabbed the umbrella from here.\n\n";
     }
     else{

          std::cout << "\nBesides the coats there is also an " << getUmbrella() << " to the side\n\n";

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
               inv.insert({ "umbrella", getUmbrella() });
               std::cout << "\nOkay, " << getUmbrella() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getUmbrella() << " not added to inventory.\n\n";
          }
     }
}

//member function to get into the trunk of LuxuryCar
void CoatCloset::checkCoats(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;
     
          //check if bottle is already in inventory
          auto search = inv.find("matches");
          if (search != inv.end()){
               std::cout << "\nNothing in the coats. You have already grabbed the matches from here.\n\n";
          }
          else{

               std::cout << "\nSherlock goes through the coats and only finds " << getMatches() << "\n\n";

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
                    inv.insert({ "matches", getMatches() });

                    std::cout << "\nOkay, " << getMatches() << " added to inventory.\n\n";
               }
               else{
                    std::cout << "\nOkay, " << getMatches() << " not added to inventory.\n\n";
               }
          }
    
}

//Accessor Functions for accessing private variables in CoatCloset.
std::string CoatCloset::getColor() const { return color; }

int CoatCloset::getNumCoats() const { return numCoats; }

std::string CoatCloset::getUmbrella() const { return umbrella; }

std::string CoatCloset::getMatches() const { return matches; }

//Mutator Functions to change private variables.
void CoatCloset::setColor(const std::string theColor){ color = theColor; }

void CoatCloset::setNumCoats(const int theNumCoats){ numCoats = theNumCoats; }

void CoatCloset::setUmbrella(const std::string theUmbrella){ umbrella = theUmbrella; }

void CoatCloset::setMatches(const std::string theMatches){ matches = theMatches; }


//member function to output information provided of each item
void FishBowl::bowlInformation()
{
     std::cout << "\n\nThere are two fish in the fish bowl.\n\n" << this->fishOneType << "\n" << this->fishTwoType << "\n\n";
}

void FishBowl::fishConvo(std::unordered_map<std::string, std::string>& inventory){

     //initialize the fish bowl object
     FishBowl fishBowl;
     int firstTime = 0;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nFish Bowl\n\n\n\n";

     //get bowl info
     fishBowl.bowlInformation();

     //output choices
     std::cout << "There doesn't appear to be anything out of the ordinary with the bowl, however you can question the fish.\"\n\n" <<
          "What would you like to do? \n\nInterrogate the Gold Fish? (Enter \"1\").\n\n" <<
          "Interrogate the Betta Fish? (Enter \"2\").\n\n" <<
          "Finished questioning (Enter \"3\")\n\n" <<
          "Check your inventory of items ( Enter \"4\").\n\n" <<
          "Choose a number between 1 and 4.";

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
                    std::cout << "\n\nPlease select a number between 1 and 4: \n\n";
               }
               else{
                    if (firstTime != 0){
                         //formatting
                         std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                         std::cout << "There doesn't appear to be anything out of the ordinary with the bowl, however you can question the fish.\"\n\n" <<
                              "What would you like to do? \n\nInterrogate the Gold Fish? (Enter \"1\").\n\n" <<
                              "Interrogate the Betta Fish? (Enter \"2\").\n\n" <<
                              "Finished questioning (Enter \"3\")\n\n" <<
                              "Check your inventory of items ( Enter \"4\").\n\n" <<
                              "Choose a number between 1 and 4.";
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


          //output responses from Mr Whtie
          switch (choice){
          case 1:
               std::cout << "\nSherlock: \"Have you seen anything out of the ordinary tonight goldfish?\"\n\n" << fishBowl.fishOneAnswer << "\n\n";
               break;
          case 2:
               std::cout << "\nSherlock: \"Any suspects Betta fish?\"\n\n" << fishBowl.fishTwoAnswer << "\n\n";
               break;
          case 3:
               std::cout << "\nSherlock: \"Alright they aren't talking.\"\n\n";
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

     } while (choice != 3);
}


//Accessor Functions for accessing private variables in MrWhite.
std::string FishBowl::getFishOneType() const { return fishOneType; }

std::string FishBowl::getFishTwoType() const { return fishTwoType; }

std::string FishBowl::getFishOneAnswer() const { return fishOneAnswer; }

std::string FishBowl::getFishTwoAnswer() const { return fishTwoAnswer; }

//Mutator Functions to change private variables.
void FishBowl::setFishOneType(const std::string theFishOneType){ fishOneType = theFishOneType; }

void FishBowl::setFishTwoType(const std::string theFishTwoType){ fishTwoType = theFishTwoType; }

void FishBowl::setFishOneAnswer(const std::string theFishOneAnswer){ fishOneAnswer = theFishOneAnswer; }

void FishBowl::setFishTwoAnswer(const std::string theFishTwoAnswer){ fishTwoAnswer = theFishTwoAnswer; }

/////Room class functions/////
//get functions
std::string RoomFoyer::getName() const { return name; }

int RoomFoyer::getNumRooms() const { return numRooms; }

int RoomFoyer::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomFoyer::getExits() const { return exits; }

std::vector<std::string> RoomFoyer::getObjects() const { return objects; }

std::string RoomFoyer::getDescription() const { return description; }

//set functions
void RoomFoyer::setName(const std::string theName){ name = theName; }

void RoomFoyer::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomFoyer::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomFoyer::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomFoyer::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomFoyer::setDescription(const std::string theDescription){ description = theDescription; }
