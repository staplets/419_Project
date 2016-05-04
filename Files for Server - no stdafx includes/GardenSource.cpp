/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/19/16
* Last Modification Date:	4/19/16
* Filename:				GardenSource.cpp
*
* Overview:
*	This file holds the implementation for the Garden objects.
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

//guards for header
#include "GardenHeader.h"

//member function to output information provided of each item in Dog
void Dog::dogInformation()
{
     std::cout << "\n\nType of dog is: " << this->type << "\n\nDescription of dog: " << this->description << "\n\n\n";
}

//member function to check if user has treat and get hydrangea sap if so
void Dog::giveTreat(std::unordered_map<std::string, std::string>& inv){

     //user input var
     std::string ans;

     //check if sap is already in inventory
     auto search = inv.find("sap");
     if (search != inv.end()){
          std::cout << "\nSherlock gives the dog the treat and he moves, however you have already grabbed the " << getSap() << " from behind him.\n\n";
     }
     else{

          //check if dog treat is already in inventory
          auto search = inv.find("dog treat");
          if (search != inv.end()){
               std::cout << "\nSherlock gives the dog the treat and he allows sherlock to pass. Sherlock inspects the plant behind him and notices it is a Hydrangea plant.\n\n";
               std::cout << "He can collect a sample of the sap in one of his containers.\n\n";

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
                    inv.insert({ "sap", getSap() });
                    std::cout << "\nOkay, " << getSap() << " added to inventory.\n\n";
                    getSap();
               }
               else{
                    std::cout << "\nOkay, " << getSap() << " not added to inventory.\n\n";
               }

          }
          else{

               std::cout << "\nSherlock doesn't have any treats on him to give to the dog!\n\n";
          }                   
     }

}

//member function to get into the trunk of LuxuryCar
void Dog::dogInteract(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;
     int firstTime = 0;
     Dog dog;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Dog\n\n\n\n";

     //get bowl info
     dog.dogInformation();

     //set up navigation
     std::cout << "As Sherlock approaches the dog, he looks playful but growls as he gets closer.\n\n" <<
          "What would you like to do? \n\n" <<
          "Attempt to pet the dog? (Enter \"1\").\n\n" <<
          "Give the dog a treat? (Enter \"2\") \n\n" <<
          "Walk away from dog? (Enter \"3\")\n\n" <<
          "Check your inventory of items ( Enter \"4\").\n\n" <<
          "Choose a number between 1 and 4.";

     //choice from player
     int choice = 0;
     int retry = 0;

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

                         std::cout << "\n\nThe Dog\n\n\n\n" <<
                              "What would you like to do? \n\n" <<
                              "Attempt to pet the dog? (Enter \"1\").\n\n" <<
                              "Give the dog a treat? (Enter \"2\") \n\n" <<
                              "Walk away from dog? (Enter \"3\")\n\n" <<
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
               std::cout << dog.bark << "\n\n";
               std::cout << "The dog doesn't appear to be friendly unless you have a treat. Maybe you can find one around ... \n\n";
               break;
          case 2:
               //call function to give treat to dog
               giveTreat(inv);
               break;
          case 3:
               std::cout << "\nSherlock: \"See you later dog.\"\n\n";
               break;
          case 4:
               std::cout << "\n\nInventory contains: \n\n";
               int c = 1;
               for (auto it = inv.begin(); it != inv.end(); ++it){
                    std::cout << c << ": " << it->second << "\n";
                    c++;
               }
               break;
          }

     } while (choice != 3);
}

//Accessor Functions for accessing private variables in LuxuryCar.
std::string Dog::getType() const { return type; }

std::string Dog::getDescription() const { return description; }

bool Dog::getTreat() const { return treat; }

std::string Dog::getBark() const { return bark; }

std::string Dog::getSap() const { return sap; }

//Mutator Functions to change private variables.
void Dog::setType(const std::string theType){ type = theType; }

void Dog::setDescription(const std::string theDescription){ description = theDescription; }

void Dog::setTreat(const bool theTreat){ treat = theTreat; }

void Dog::setBark(const std::string theBark){ bark = theBark; }

void Dog::setSap(const std::string theSap){ sap = theSap; }


//member function to output information provided of each item
void MsWolf::personInformation(std::unordered_map<std::string, std::string>& inventory)
{
     std::cout << "\n\nDescription of the woman is : " << this->description << "\n\n\n";
}


int MsWolf::conversate(std::unordered_map<std::string, std::string>& inventory){

     //initialize mr white
     MsWolf msWolf;
     int firstTime = 0;
     //choice from player
     int choice = 0;
     int retry = 0;
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nMs. Wolf\n\n\n\n";

     //output info about mr white
     msWolf.personInformation(inventory);

     //check if the confession is already in inventory
     auto search = inventory.find("confession");
     if (search != inventory.end()){
          
          //set up navigation
          std::cout << "Ms. Wolf greets Sherlock as he approaches.\n\n" <<
               "What would you like to ask Ms. Wolf? \n\n" <<
               "\n\nPresent her with the written confession and clues to her murder!!! (Enter \"1\").\n\n\n" <<
               "What have you been doing tonight? (Enter \"2\").\n\n" <<
               "Do you know who the murderer may be? (Enter \"3\").\n\n" <<
               "What's your age? (Enter \"4\") \n\n" <<
               "What do you do around here for work? (Enter \"5\").\n\n" <<
               "Finished questioning her (Enter \"6\")\n\n" <<
               "Check your inventory of items (Enter \"7\").\n\n" <<
               "Choose a number between 1 and 7.";

          //inspect the room
          do{

               //navigation choice
               choice = 0;
               retry = 0;

               do
               {
                    if (retry > 0)
                    {
                         std::cout << "\n\nPlease select a number between 1 and 7 for questioning: \n\n";
                    }
                    else{
                         if (firstTime != 0){
                              //formatting
                              std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                              std::cout << "What would you like to ask Ms. Wolf? \n\n" << 
                                   "\n\nPresent her with the written confession and clues to her murder!!! (Enter \"1\").\n\n\n" <<
                                   "What have you been doing tonight? (Enter \"2\").\n\n" <<
                                   "Do you know who the murderer may be? (Enter \"3\").\n\n" <<
                                   "What's your age? (Enter \"4\") \n\n" <<
                                   "What do you do around here for work? (Enter \"5\").\n\n" <<
                                   "Finished questioning her (Enter \"6\")\n\n" <<
                                   "Check your inventory of items (Enter \"7\").\n\n" <<
                                   "Choose a number between 1 and 7.";
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

               } while (choice < 1 || choice > 7);


               //output responses from Mr Whtie
               switch (choice){
               case 1:
                    //check if the revolver is already in inventory
                    search = inventory.find("revolver");
                    if (search != inventory.end()){

                         std::cout << "\n\nSherlock presents Ms. Wolf with the signed confession from Mr. Glass and Ms. Wolf looks as though she will burst into tears.\n\n";
                         std::cout << "Then she says \"" << getConfession() << getConfessionTwo() << getConfessionThree() << "\n\n";
                         std::cout << "Sherlock then handcuffed her and walked her out to his Monte Carlo and took her to the station.\n\n\nWell done detective!!!\n\nThanks for playing!\n\n";

                    }
                    else{
                         //don't end game
                         choice = 0;
                         std::cout << "\nBefore presenting Ms. Wolf with the evidence, you may want to grab a weapon for protection. This is a murderer after all! Something like a gun perhaps ... \n\n";
                    }
                    break;
               case 2:
                    std::cout << msWolf.doingTonight << "\n\n";
                    break;
               case 3:
                    std::cout << msWolf.knowMurderer << "\n\n";
                    break;
               case 4:
                    std::cout << "\nI am " << msWolf.age << "\n\n";
                    break;
               case 5:
                    std::cout << msWolf.jobDescription << "\n\n";
                    break;
               case 6:
                    std::cout << "\nSherlock: \"Thank you for your time Ms. Wolf.\"\n\n";
                    break;
               case 7:
                    std::cout << "\n\nInventory contains: \n\n";
                    int c = 1;
                    for (auto it = inventory.begin(); it != inventory.end(); ++it){
                         std::cout << c << ": " << it->second << "\n";
                         c++;
                    }
                    break;
               }

           } while (choice != 6 && choice != 1);

               //if choice is 1, game is over
               if (choice == 1){
                    return choice;
               }

          }
          else{


               //set up navigation
               std::cout << "Ms. Wolf greets Sherlock as he approaches.\"\n\n" <<
                    "What would you like to ask Ms. Wolf? \n\nWhat have you been doing tonight? (Enter \"1\").\n\n" <<
                    "Do you know who the murderer may be? (Enter \"2\").\n\n" <<
                    "What's your age? (Enter \"3\") \n\n" <<
                    "What do you do around here for work? (Enter \"4\").\n\n" <<
                    "Finished questioning her (Enter \"5\")\n\n" <<
                    "Check your inventory of items ( Enter \"6\").\n\n" <<
                    "Choose a number between 1 and 6.";
                    
               //inspect the room
               do{

                    //navigation choice
                    choice = 0;
                    retry = 0;

                    do
                    {
                         if (retry > 0)
                         {
                              std::cout << "\n\nPlease select a number between 1 and 6 for questioning: \n\n";
                         }
                         else{
                              if (firstTime != 0){
                                   //formatting
                                   std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                                   std::cout << "What would you like to ask Ms. Wolf? \n\nWhat have you been doing tonight? (Enter \"1\").\n\n" <<
                                        "Do you know who the murderer may be? (Enter \"2\").\n\n" <<
                                        "What's your age? (Enter \"3\") \n\n" <<
                                        "What do you do around here for work? (Enter \"4\").\n\n" <<
                                        "Finished questioning her (Enter \"5\")\n\n" <<
                                        "Check your inventory of items ( Enter \"6\").\n\n" <<
                                        "Choose a number between 1 and 6.";
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

                    } while (choice < 1 || choice > 6);


                    //output responses from Mr Whtie
                    switch (choice){
                    case 1:
                         std::cout << msWolf.doingTonight << "\n\n";
                         break;
                    case 2:
                         std::cout << msWolf.knowMurderer << "\n\n";
                         break;
                    case 3:
                         std::cout << "\nI am " << msWolf.age << "\n\n";
                         break;
                    case 4:
                         std::cout << msWolf.jobDescription << "\n\n";
                         break;
                    case 5:
                         std::cout << "\nSherlock: \"Thank you for your time Ms. Wolf.\"\n\n";
                         break;
                    case 6:
                         std::cout << "\n\nInventory contains: \n\n";
                         int c = 1;
                         for (auto it = inventory.begin(); it != inventory.end(); ++it){
                              std::cout << c << ": " << it->second << "\n";
                              c++;
                         }
                         break;
                    }

               } while (choice != 5);

               return 0;
          }

          return 0;
}

//Accessor Functions for accessing private variables in MrWhite.
std::string MsWolf::getKnowMurderer() const { return knowMurderer; }

std::string MsWolf::getDoingTonight() const { return doingTonight; }

int MsWolf::getAge() const { return age; }

std::string MsWolf::getJobDescription() const { return jobDescription; }

std::string MsWolf::getDescription() const { return description; }

std::string MsWolf::getConfession() const { return confession; }

std::string MsWolf::getConfessionTwo() const { return confessionTwo; }

std::string MsWolf::getConfessionThree() const { return confessionThree; }

//Mutator Functions to change private variables.
void MsWolf::setKnowMurderer(const std::string theKnowMurderer){ knowMurderer = theKnowMurderer; }

void MsWolf::setDoingTonight(const std::string theDoingTonight){ doingTonight = theDoingTonight; }

void MsWolf::setAge(const int theAge){ age = theAge; }

void MsWolf::setJobDescription(const std::string theJobDescription){ jobDescription = theJobDescription; }

void MsWolf::setDescription(const std::string theDescription){ description = theDescription; }

void MsWolf::setConfession(const std::string theConfession){ confession = theConfession; }

void MsWolf::setConfessionTwo(const std::string theConfessionTwo){ confession = theConfessionTwo; }

void MsWolf::setConfessionThree(const std::string theConfessionThree){ confession = theConfessionThree; }


//navigation function to handle game play while the player is in the garden
int gardenNavigate(std::unordered_map<std::string, std::string>& inventory){

     //boolean to find out if player wants to move to another room
     bool move = false;
     int firstTime = 0;

     //intialize objects
     Dog dog;
     MsWolf msWolf;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Garden\n\n\n\n" <<
          "Sherlock is in the garden.\n\nMany unique and colorful plants mix in to create an otherwordly atmosphere.\n\n" <<
          "There is woman dressed in a black evening gown smoking a cigarrette on a bench, who you may want to talk with (Interact: Enter \"1\").\n\n" <<
          "There is also a dog laying down chained to a water fountain in front of what looks like a Hydrangea plant (Interact: Enter \"2\").\n\n" <<
          "You may also go around to the driveway (Enter \"3\")\n\nYou may go up on the deck (Enter \"4\").\n\n" <<
          "You may go down into the cellar ( Enter \"5\").\n\n" <<
          "Check your inventory of items ( Enter \"6\").\n\n" <<
          "What would you like to do? Choose a number between 1 and 6.";

     //choice from player
     int choice = 0;
     int retry = 0;
     std::string ans;
     int wolfRet;

     //inspect the room
     do{

          //navigation choice
          choice = 0;
          retry = 0;

          do
          {
               if (retry > 0)
               {
                    std::cout << "\n\nPlease select a number between 1 and 6 to navigate: \n\n";
               }
               else{
                    if (firstTime != 0){
                         //formatting
                         std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                         std::cout << "\n\nThe Garden\n\n\n\n" <<
                              "Sherlock is in the garden.\n\nMany unique and colorful plants mix in to create an otherwordly atmosphere.\n\n" <<
                              "There is woman dressed in a black evening gown smoking a cigarrette on a bench, who you may want to talk with (Interact: Enter \"1\").\n\n" <<
                              "There is also a dog laying down chained to a water fountain in front of what looks like a Hydrangea plant (Interact: Enter \"2\").\n\n" <<
                              "You may also go around to the driveway (Enter \"3\")\n\nYou may go up on the deck (Enter \"4\").\n\n" <<
                              "You may go down into the cellar ( Enter \"5\").\n\n" <<
                              "Check your inventory of items ( Enter \"6\").\n\n" <<
                              "What would you like to do? Choose a number between 1 and 6.";
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

          } while (choice < 1 || choice > 6);


          //take users choice and interact based on that
          switch (choice){
          case 1:
               wolfRet = msWolf.conversate(inventory);
               //if 1 returned game over
               if (wolfRet == 1){
                    move = true;
                    choice = 0;
               }
               break;
          case 2:
               dog.dogInteract(inventory);
               break;
          case 3:
               std::cout << "\nWalking around the mansion to the driveway.\n";
               //change choice to reflect our room mapping and update move
               choice = 1;
               move = true;
               break;
          case 4:
               std::cout << "\nWalking up to the deck.\n";
               //change choice to reflect our room mapping and update move
               choice = 13;
               move = true;
               break;
          case 5:
               std::cout << "\nGoing down into the cellar.\n";
               //change choice to reflect our room mapping and update move
               choice = 10;
               move = true;
               break;
          case 6:
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

