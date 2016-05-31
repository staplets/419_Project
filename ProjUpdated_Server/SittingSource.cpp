/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/25/16
* Last Modification Date:	5/25/16
* Filename:				SittingSource.cpp
*
* Overview:
*	This file holds the implementation for the Sitting Room objects.
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
//included for sleeping functionality
#include <chrono>
#include <thread>
#include <vector>

//guards for header
#include "SittingHeader.h"

//member function of couch for a nap
void Couch::takeNap()
{
     std::string ans;

     do{
          //logic to imitate sherlock sleeping for three seconds
          std::this_thread::sleep_for(std::chrono::seconds(1));
          std::cout << "\n\nZzz ...\n\n";

          std::this_thread::sleep_for(std::chrono::seconds(1));
          std::cout << "\n\nZzz ...\n\n";

          std::this_thread::sleep_for(std::chrono::seconds(1));
          std::cout << "\n\nZzz ...\n\n";

          std::cout << "\nWould you like to wake up?\n\n";

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

     } while (ans != "y");
}

//member function for Couch
void Couch::checkCouch(std::unordered_map<std::string, std::string>& inv)
{
     //initialize the couch object
     Couch couch;
     int firstTime = 0;
     //user input var
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Couch\n\n\n\n";

     //coffee table info
     std::cout << "\nWalking over to the Couch, you note: " << getDescription() << "\n\n";

     auto search = inv.find("book");
     if (search != inv.end()){

          //set up navigation
          std::cout << "You have already grabbed a book on the couch, but you see the opportunity for relaxation.\n\n" <<
               "What would you like to do? \n\n" <<
               "Take a nap? (Enter \"1\") \n\n" <<
               "Done with couch? (Enter \"2\")\n\n" <<
               "Check your inventory of items ( Enter \"3\").\n\n" <<
               "Choose a number between 1 and 3.";

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
                         std::cout << "\n\nPlease select a number between 1 and 3: \n\n";
                    }
                    else{
                         if (firstTime != 0){
                              //formatting
                              std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                              std::cout << "\n\nThe Couch\n\n\n\n" <<
                                   "You have already grabbed a book on the couch, but you see the opportunity for relaxation.\n\n" <<
                                   "What would you like to do? \n\n" <<
                                   "Take a nap? (Enter \"1\") \n\n" <<
                                   "Done with couch? (Enter \"2\")\n\n" <<
                                   "Check your inventory of items ( Enter \"3\").\n\n" <<
                                   "Choose a number between 1 and 3.";
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

               } while (choice < 1 || choice > 3);


               //navigate based on choice
               switch (choice){
               case 1:
                    //call function to take nap
                    takeNap();
                    std::cout << "\n\nYou awake from the nap feeling nice and rested!\n\n";
                    break;
               case 2:
                    std::cout << "\nYou move away from the couch.\n\n";
                    break;
               case 3:
                    std::cout << "\n\nInventory contains: \n\n";
                    int c = 1;
                    for (auto it = inv.begin(); it != inv.end(); ++it){
                         std::cout << c << ": " << it->second << "\n";
                         c++;
                    }
                    break;
               }

          } while (choice != 2);
     }
     else{

          //set up navigation
          std::cout << "You notice what appears to be a book on the couch. You also see the opportunity for relaxation.\n\n" <<
               "What would you like to do? \n\n" <<
               "Look at book? (Enter \"1\").\n\n" <<
               "Take a nap? (Enter \"2\") \n\n" <<
               "Done with couch? (Enter \"3\")\n\n" <<
               "Check your inventory of items ( Enter \"4\").\n\n" <<
               "Choose a number between 1 and 4.";

          //choice from player
          int choice = 0;
          int retry = 0;

          //inspect the couch
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

                              std::cout << "\n\nThe Couch\n\n\n\n" <<
                                   "You notice what appears to be a book on the couch. You also see the opportunity for relaxation.\n\n" <<
                                   "What would you like to do? \n\n" <<
                                   "Look at book? (Enter \"1\").\n\n" <<
                                   "Take a nap? (Enter \"2\") \n\n" <<
                                   "Done with couch? (Enter \"3\")\n\n" <<
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
                    std::cout << "\nYou notice a " << getBook() << " on the recliner, which catches your eye.\n\n";

                    std::cout << "Would you like to add the " << getBook() << " to your inventory?\n\n";

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
                         inv.insert({ "book", getBook() });
                         std::cout << "\nOkay, " << getBook() << " added to inventory.\n\n";
                         //change choice to go back out to room loop
     //                    choice = 3;
                    }
                    else{
                         std::cout << "\nOkay, " << getBook() << " not added to inventory.\n\n";
                    }
                    break;
               case 2:
                    //call function to take nap
                    takeNap();
                    std::cout << "\n\nYou awake from the nap feeling nice and rested!\n\n";
                    break;
               case 3:
                    std::cout << "\nYou move away from the couch.\n\n";
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
}

//Accessor Functions for accessing private variables in LuxuryCar.
std::string Couch::getBook() const { return book; }

std::string Couch::getDescription() const { return description; }

std::string Couch::getNap() const { return nap; }

//Mutator Functions to change private variables.
void Couch::setBook(const std::string theBook){ book = theBook; }

void Couch::setDescription(const std::string theDescription){ description = theDescription; }

void Couch::setNap(const std::string theNap){ nap = theNap; }


//member function to output information provided of each item
void MrsDeeds::personInformation(std::unordered_map<std::string, std::string>& inventory)
{
     std::cout << "Description of the woman is : " << this->description << "\n\n\n";
}


void MrsDeeds::secretRoom(std::unordered_map<std::string, std::string>& inventory){

     //initialize mrsDeeds object
     MrsDeeds mrsDeeds;

     //check if the pie is already in inventory
     auto search = inventory.find("pie");
     if (search != inventory.end()){

          search = inventory.find("secret note");
          if (search != inventory.end()){
               //already have secret note
               std::cout << "\n\nMrs. Deeds \"My dear boy, I already told you all I know about the secrets of this house. I'll take another piece of pie though!\"\n\n";
          }
          else{
               //get secret room info 
               std::cout << mrsDeeds.roomOne;
               std::cout << "\n\nYou give Mrs. Deeds a piece of blueberry pie that you have.\n\n";
               std::cout << mrsDeeds.roomTwo << "\n\n";
               //collect note for inventory
               inventory.insert({ "secret note", getSecretNote() });
               std::cout << "\n\nYou note this in your notepad.\n\n";
          }
     }
     else{

          //get secret room info 
          std::cout << mrsDeeds.roomOne << "\n\n";
     }
}

void MrsDeeds::conversate(std::unordered_map<std::string, std::string>& inventory){

     //initialize mr white
     MrsDeeds mrsDeeds;
     int firstTime = 0;
     //choice from player
     int choice = 0;
     int retry = 0;
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nMrs. Deeds\n\n\n\n";

     //output info about mr white
     mrsDeeds.personInformation(inventory);

     //set up navigation
     std::cout << "Mrs. Deeds is sitting on one of the seats and stands to greet you as he approaches.\n\n" <<
          "What would you like to ask Mrs. Deeds? \n\n" <<
          "What have you been doing tonight? (Enter \"1\").\n\n" <<
          "Do you know who the murderer may be? (Enter \"2\").\n\n" <<
          "What's your age? (Enter \"3\") \n\n" <<
          "What do you do for work? (Enter \"4\").\n\n" <<
          "Is there anything else you can tell me? (Enter \"5\").\n\n" <<
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

                         std::cout << "What would you like to ask Mrs. Deeds? \n\n" <<
                              "What have you been doing tonight? (Enter \"1\").\n\n" <<
                              "Do you know who the murderer may be? (Enter \"2\").\n\n" <<
                              "What's your age? (Enter \"3\") \n\n" <<
                              "What do you do for work? (Enter \"4\").\n\n" <<
                              "Is there anything else you can tell me? (Enter \"5\").\n\n" <<
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
               std::cout << mrsDeeds.doingTonight << "\n\n";
               break;
          case 2:
               std::cout << mrsDeeds.knowMurderer << "\n\n";
               break;
          case 3:
               std::cout << "\nMrs. Deeds \"I am " << mrsDeeds.age << "\"\n\n";
               break;
          case 4:
               std::cout << mrsDeeds.jobDescription << "\n\n";
               break;
          case 5:
               //check as to whether she will give up the secret room or not
               secretRoom(inventory);
               break;
          case 6:
               std::cout << "\nYou: \"Thank you for your time Mrs. Deeds.\"\n\n";
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

     } while (choice != 6);

}

//Accessor Functions for accessing private variables in MrWhite.
std::string MrsDeeds::getKnowMurderer() const { return knowMurderer; }

std::string MrsDeeds::getDoingTonight() const { return doingTonight; }

int MrsDeeds::getAge() const { return age; }

std::string MrsDeeds::getJobDescription() const { return jobDescription; }

std::string MrsDeeds::getDescription() const { return description; }

std::string MrsDeeds::getRoomOne() const { return roomOne; }

std::string MrsDeeds::getRoomTwo() const { return roomTwo; }

std::string MrsDeeds::getSecretNote() const { return secretNote; }

//Mutator Functions to change private variables.
void MrsDeeds::setKnowMurderer(const std::string theKnowMurderer){ knowMurderer = theKnowMurderer; }

void MrsDeeds::setDoingTonight(const std::string theDoingTonight){ doingTonight = theDoingTonight; }

void MrsDeeds::setAge(const int theAge){ age = theAge; }

void MrsDeeds::setJobDescription(const std::string theJobDescription){ jobDescription = theJobDescription; }

void MrsDeeds::setDescription(const std::string theDescription){ description = theDescription; }

void MrsDeeds::setRoomOne(const std::string theRoomOne){ roomOne = theRoomOne; }

void MrsDeeds::setRoomTwo(const std::string theRoomTwo){ roomTwo = theRoomTwo; }

void MrsDeeds::setSecretNote(const std::string theSecretNote){ secretNote = theSecretNote; }

/////Room class functions/////
//get functions
std::string RoomSitting::getName() const { return name; }

int RoomSitting::getNumRooms() const { return numRooms; }

int RoomSitting::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomSitting::getExits() const { return exits; }

std::vector<std::string> RoomSitting::getObjects() const { return objects; }

std::string RoomSitting::getDescription() const { return description; }

//set functions
void RoomSitting::setName(const std::string theName){ name = theName; }

void RoomSitting::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomSitting::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomSitting::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomSitting::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomSitting::setDescription(const std::string theDescription){ description = theDescription; }
