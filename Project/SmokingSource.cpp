/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/24/16
* Last Modification Date:	4/24/16
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

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

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

     std::cout << "\nFrom closer inspection of the recliner, Sherlock notes: " << getDescription() << "\n\n";

     //check if pipe is already in inventory
     auto search = inv.find("pipe");
     if (search != inv.end()){
          std::cout << "\nThe recliner has nothing of note as Sherlock already grabbed the " << getPipe() << " that interested him.\n\n";
     }
     else{

          std::cout << "\nSherlock notices a " << getPipe() << " on the recliner, which catches his eye.\n\n";

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

          if (ans == "y"){
               inv.insert({ "pipe", getPipe() });
               std::cout << "\nOkay, " << getPipe() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getPipe() << " not added to inventory.\n\n";
          }
     }

}

//Accessor Functions for accessing private variables in RecliningChair.
std::string RecliningChair::getDescription() const { return description; }

std::string RecliningChair::getPipe() const { return pipe; }

//Mutator Functions to change private variables.
void RecliningChair::setDescription(const std::string theDescription){ description = theDescription; }

void RecliningChair::setPipe(const std::string thePipe){ pipe = thePipe; }


//member function to output information provided of each item
void Painting::checkPainting(std::unordered_map<std::string, std::string>& inv){

     //initialize the painting object
     Painting painting;
     int firstTime = 0;
     //user input var
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Painting\n\n\n\n";

     //coffee table info
     std::cout << "\nWalking over to the painting, Sherlock notes: " << getDescription() << "\n\n";

     //check if knife is already in inventory
     auto search = inv.find("knife");
     if (search != inv.end()){
          std::cout << "\nSherlock admires the painting, however he notices it may be hanging a bit askew.\n\n" <<
               "He thinks there may be something behind it, but it appears to be stuck to the wall.\n\n" <<
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

          if (ans == "y"){
               
               //check if revolver is already in inventory
               auto search = inv.find("revolver");
               if (search != inv.end()){
                    std::cout << "\n\nSherlock uses the knife and is able to open the painting from the right side with what appears to be hinges.\n\n" <<
                         "There is a small hiding spot behind the painting, however Sherlock has already grabbed the revolver.\n\n";
               }
               else{

                    std::cout << "\n\nSherlock uses the knife and is able to open the painting from the right side with what appears to be hinges.\n\n" <<
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

                    if (ans == "y"){
                         inv.insert({ "revolver", getRevolver() });
                         std::cout << "\nOkay, " << getRevolver() << " added to inventory.\n\n";
                    }
                    else{
                         std::cout << "\nOkay, " << getRevolver() << " not added to inventory.\n\n";
                    }
               }
          }
          else{
               //user decides not to pull forward painting
               std::cout << "\nOkay, Sherlock leaves the painting as is.\n\n";
          }

     }
     else{

          std::cout << "\nSherlock admires the painting, however he notices it may be hanging a bit askew.\n\n" <<
               "He thinks there may be something behind it, but it appears to be stuck to the wall.\n\n" <<
               "Perhaps if you had something sharp with you, such as a knife, you could pry it open ...\n\n";
     }
}


//Accessor Functions for accessing private variables in Painting.
std::string Painting::getRevolver() const { return revolver; }

std::string Painting::getDescription() const { return description; }

//Mutator Functions to change private variables.
void Painting::setRevolver(const std::string theRevolver){ revolver = theRevolver; }

void Painting::setDescription(const std::string theDescription){ description = theDescription; }

//navigation function to handle game play while the player is in the smoking room
int smokingRoomNavigate(std::unordered_map<std::string, std::string>& inventory){

     //boolean to find out if player wants to move to another room
     bool move = false;
     int firstTime = 0;

     //intialize objects
     RecliningChair recliningChair;
     Painting painting;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Smoking Room\n\n\n\n" <<
          "Sherlock is in the Smoking Room.\n\nLooking around, he sees a Reclining Chair and he also sees a painting on the wall that it noteworthy.\n\n" <<
          "Examine the Reclining Chair? (Enter \"1\").\n\n" <<
          "Go over to look at Painting? (Enter \"2\").\n\n" <<
          "You may go into the Kitchen (Enter \"3\")\n\nYou may go into the Sitting Room (Enter \"4\").\n\n" <<
          "You may walk into the Billiards Room (Enter \"5\")\n\n" <<
          "Check your inventory of items ( Enter \"6\").\n\n" <<
          "What would you like to do? Choose a number between 1 and 6.";

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
                    std::cout << "\n\nPlease select a number between 1 and 6 to navigate: \n\n";
               }
               else{
                    if (firstTime != 0){
                         //formatting
                         std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

                         std::cout << "\n\nThe Smoking Room\n\n\n\n" <<
                              "Sherlock is in the Smoking Room.\n\nLooking around, he sees a Reclining Chair and also sees a painting on the wall that it noteworthy.\n\n" <<
                              "Examine the Reclining Chair? (Enter \"1\").\n\n" <<
                              "Go over to look at Painting? (Enter \"2\").\n\n" <<
                              "You may go into the Kitchen (Enter \"3\")\n\nYou may go into the Sitting Room (Enter \"4\").\n\n" <<
                              "You may walk into the Billiards Room (Enter \"5\")\n\n" <<
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
               recliningChair.checkRecliningChair(inventory);
               break;
          case 2:
               painting.checkPainting(inventory);
               break;
          case 3:
               std::cout << "\nGoing into the Kitchen.\n";
               //change choice to reflect our room mapping and update move
               choice = 9;
               move = true;
               break;
          case 4:
               std::cout << "\nGoing into the Sitting Room.\n";
               //change choice to reflect our room mapping and update move
               choice = 5;
               move = true;
               break;
          case 5:
               std::cout << "\nWalking into the Billiards Room.\n";
               //change choice to reflect our room mapping and update move
               choice = 7;
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