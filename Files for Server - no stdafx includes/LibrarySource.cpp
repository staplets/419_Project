/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/26/16
* Last Modification Date:	5/28/16
* Filename:				LibrarySource.cpp
*
* Overview:
*	This file holds the implementation for the Library objects and interaction.
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

//include library header
#include "LibraryHeader.h"

//member function 
void Desk::checkDesk(std::unordered_map<std::string, std::string>& inv)
{
     //user input var
     std::string ans;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //coat closet info
     std::cout << "\n\nDesk\n\n\n\n";

     std::cout << "\nYou walk up to the desk and note the following: " << this->description << "\n\n";

     //check if old will is already in inventory
     auto search = inv.find("old will");
     if (search != inv.end()){
          std::cout << "\nYou inspect the desk, however you have already grabbed \'" << getOldWill() << "\' from here.\n\n";
     }
     else{

          std::cout << "\nYou inspect the desk, and among the files, you are intrigued to find a will for Mr. Glass dated January 21st 2015.\n\n";

          std::cout << "\nWould you like to add this item to your inventory?\n\n";

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
               inv.insert({ "old will", getOldWill() });
               std::cout << "\nOkay, " << getOldWill() << " added to inventory.\n\n";
          }
          else{
               std::cout << "\nOkay, " << getOldWill() << " not added to inventory.\n\n";
          }
     }

}

//Accessor Functions for accessing private variables in Desk.
std::string Desk::getDescription() const { return description; }

std::string Desk::getOldWill() const { return oldWill; }

//Mutator Functions to change private variables.
void Desk::setDescription(const std::string theDescription){ description = theDescription; }

void Desk::setOldWill(const std::string theOldWill){ oldWill = theOldWill; }

//member function to output information provided of each item
int BookShelf::checkBookShelf(std::unordered_map<std::string, std::string>& inv){

     //initialize the book shelf object
     BookShelf bookShelf;
     //user input var
     std::string ans;
     int choice = 0;

	 //animation variables
	 int start_row = 4;
	 int start_column = 4;
	 int i;
	 int speed;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe BookShelf\n\n\n\n";

     //coffee table info
     std::cout << "\nWalking over to the Bookshelf, you see: " << getDescription() << "\n\n";

     //check if knife is already in inventory
     auto search = inv.find("secret note");
     if (search != inv.end()){
          std::cout << "\nThanks to the information you received from Mrs. Deeds, you know there is a book shelf that leads to a secret room.\n\n" <<
               "Being as this one looks out of place, perhaps pertruding a little more than the others, you think you may be able to push or move it.\n\n";
           
          std::cout << "Would you like to move or push the Book Shelf?\n\n";

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

			  //bookshelf animation
			  initscr();
			  clear();
			  printBookshelf(start_row, start_column);

			  getch();

			  for (i = 0; i < 17; i++)
			  {
				  printDoorway(start_row, start_column);
				  start_column--;
				  for (speed = 1; speed <= 50000000; speed++);
				  refresh();
			  }

			  getch();
			  endwin();

               //logic to go to the secret room ********
               std::cout << "\n\nYou start to push the book case from left to right and realize that it is on a sliding rail.\n\n" <<
                    "\n\nThe book shelf slides over and you see that there is a whole room behind it just as Mrs. Deeds said!\n\n";

               std::cout << "Would you like to go into the secret room? \n\n";

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
                    //flag to go to secret room
                    choice = 1;
                    return choice;
               }
               else{
                    std::cout << "\nOkay, not going into the secret room.\n\n";
                    //flag to not go into secret room
                    choice = 0;
                    return choice;
               }

          }
          else{
               //user decides not to pull forward painting
               std::cout << "\nOkay, you leave the Book Shelf as is.\n\n";
             
               //check inventory for book.
               search = inv.find("oliver twist");
               if (search != inv.end()){ //book grabbed already
                    std::cout << "You see a few books on the shelf, however you already grabbed " << getBook() << " and the others don't interest you.\n\n";
                    //flag to not go into secret room
                    choice = 0;
                    return choice;
               }
               else{

                    std::cout << "He sees an old favorite book of his ," << getBook() << " on the shelf that catches his attention.\n\n" <<
                         "Would you like to add " << getBook() << " to the inventory ? \n\n";

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
                         inv.insert({ "oliver twist", getBook() });
                         std::cout << "\nOkay, " << getBook() << " added to inventory.\n\n";
                         //flag to not go into secret room
                         choice = 0;
                         return choice;
                    }
                    else{
                         std::cout << "\nOkay, " << getBook() << " not added to inventory.\n\n";
                         //flag to not go into secret room
                         choice = 0;
                         return choice;
                    }
               }
          }

     }
     else{

          std::cout << "\nYou ponder that it looks a little out of place, however it's not enough to waste more time on.\n\n";

          //check inventory for book.
          search = inv.find("oliver twist");
          if (search != inv.end()){ //book grabbed already
               std::cout << "He sees a few books on the shelf, however he already grabbed " << getBook() << " and the others don't interest him.\n\n";
               //flag to not go into secret room
               choice = 0;
               return choice;

          }
          else{

              std::cout << "He sees an old favorite book of his ," << getBook() << " on the shelf that catches his attention.\n\n" <<
                    "Would you like to add " << getBook() << " to the inventory ? \n\n";

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
                    inv.insert({ "oliver twist", getBook() });
                    std::cout << "\nOkay, " << getBook() << " added to inventory.\n\n";
                    //flag to not go into secret room
                    choice = 0;
                    return choice;
               }
               else{
                    std::cout << "\nOkay, " << getBook() << " not added to inventory.\n\n";
                    //flag to not go into secret room
                    choice = 0;
                    return choice;
               }
          }
     }
}


//Accessor Functions for accessing private variables in Painting.
std::string BookShelf::getBook() const { return book; }

std::string BookShelf::getDescription() const { return description; }

//Mutator Functions to change private variables.
void BookShelf::setBook(const std::string theBook){ book = theBook; }

void BookShelf::setDescription(const std::string theDescription){ description = theDescription; }

/////Room class functions/////
//get functions
std::string RoomLibrary::getName() const { return name; }

int RoomLibrary::getNumRooms() const { return numRooms; }

int RoomLibrary::getNumObjects() const { return numObjects; }

std::vector<std::string> RoomLibrary::getExits() const { return exits; }

std::vector<std::string> RoomLibrary::getObjects() const { return objects; }

std::string RoomLibrary::getDescription() const { return description; }

//set functions
void RoomLibrary::setName(const std::string theName){ name = theName; }

void RoomLibrary::setNumRooms(const int theNumRooms){ numRooms = theNumRooms; }

void RoomLibrary::setNumObjects(const int theNumObjects){ numObjects = theNumObjects; }

void RoomLibrary::setExits(const std::vector<std::string> theExits){ exits = theExits; }

void RoomLibrary::setObjects(const std::vector<std::string> theObjects){ objects = theObjects; }

void RoomLibrary::setDescription(const std::string theDescription){ description = theDescription; }
