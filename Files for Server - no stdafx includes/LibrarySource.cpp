/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/26/16
* Last Modification Date:	4/28/16
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

//include library header
#include "LibraryHeader.h"

int movePlayerFromLibrary(std::string location)
{
	int intChoice;
	if (location.compare("Ballroom") == 0) {
		std::cout << "\nGoing into the Ballroom.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 16;
	}
	else {
		std::cout << "\nGoing into the Study.\n";
		//change choice to reflect our room mapping and update move
		intChoice = 4;
	}
	return intChoice;
}

//member function 
void Desk::checkDesk(std::unordered_map<std::string, std::string>& inv)
{
	//user input var
	std::string ans;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//coat closet info
	std::cout << "\n\nDesk\n\n\n\n";

	std::cout << "\nSherlock walks up to the desk and notes the following: " << this->description << "\n\n";

	//check if old will is already in inventory
	auto search = inv.find("old will");
	if (search != inv.end()) {
		std::cout << "\nSherlock inspects the desk, however you have already grabbed \'" << getOldWill() << "\' from here.\n\n";
	}
	else {

		std::cout << "\nSherlock inspects the desk, and among the files, he is intrigued to find a will for Mr. Glass dated January 21st 2015.\n\n";

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

		if (ans == "y") {
			inv.insert({ "old will", getOldWill() });
			std::cout << "\nOkay, " << getOldWill() << " added to inventory.\n\n";
		}
		else {
			std::cout << "\nOkay, " << getOldWill() << " not added to inventory.\n\n";
		}
	}

}

//Accessor Functions for accessing private variables in Desk.
std::string Desk::getDescription() const { return description; }

std::string Desk::getOldWill() const { return oldWill; }

//Mutator Functions to change private variables.
void Desk::setDescription(const std::string theDescription) { description = theDescription; }

void Desk::setOldWill(const std::string theOldWill) { oldWill = theOldWill; }

//member function to output information provided of each item
int BookShelf::checkBookShelf(std::unordered_map<std::string, std::string>& inv) {

	//initialize the book shelf object
	BookShelf bookShelf;
	//user input var
	std::string ans;
	int choice = 0;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe BookShelf\n\n\n\n";

	//coffee table info
	std::cout << "\nWalking over to the Bookshelf, Sherlock sees: " << getDescription() << "\n\n";

	//check if knife is already in inventory
	auto search = inv.find("secret note");
	if (search != inv.end()) {
		std::cout << "\nThanks to the information Sherlock received from Mrs. Deeds, Sherlock knows there is a book shelf that leads to a secret room.\n\n" <<
			"Being as this one looks out of place, perhaps pertruding a little more than the others, he thinks he may be able to push or move it.\n\n";

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

		if (ans == "y") {

			//logic to go to the secret room ********
			std::cout << "\n\nSherlock starts to push the book case from left to right and realizes that it is on a sliding rail.\n\n" <<
				"\n\nThe book shelf slides over and he sees that there is a whole room behind it just as Mrs. Deeds said!\n\n";

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

			if (ans == "y") {
				//flag to go to secret room
				choice = 1;
				return choice;
			}
			else {
				std::cout << "\nOkay, not going into the secret room.\n\n";
				//flag to not go into secret room
				choice = 0;
				return choice;
			}

		}
		else {
			//user decides not to pull forward painting
			std::cout << "\nOkay, Sherlock leaves the Book Shelf as is.\n\n";

			//check inventory for book.
			search = inv.find("oliver twist");
			if (search != inv.end()) { //book grabbed already
				std::cout << "Sherlock sees a few books on the shelf, however he already grabbed " << getBook() << " and the others don't interest him.\n\n";
				//flag to not go into secret room
				choice = 0;
				return choice;
			}
			else {

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

				if (ans == "y") {
					inv.insert({ "oliver twist", getBook() });
					std::cout << "\nOkay, " << getBook() << " added to inventory.\n\n";
					//flag to not go into secret room
					choice = 0;
					return choice;
				}
				else {
					std::cout << "\nOkay, " << getBook() << " not added to inventory.\n\n";
					//flag to not go into secret room
					choice = 0;
					return choice;
				}
			}
		}

	}
	else {

		std::cout << "\nSherlock ponders that it looks a little out of place, however it's not enough to waste more time on.\n\n";

		//check inventory for book.
		search = inv.find("oliver twist");
		if (search != inv.end()) { //book grabbed already
			std::cout << "He sees a few books on the shelf, however he already grabbed " << getBook() << " and the others don't interest him.\n\n";
			//flag to not go into secret room
			choice = 0;
			return choice;

		}
		else {

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

			if (ans == "y") {
				inv.insert({ "oliver twist", getBook() });
				std::cout << "\nOkay, " << getBook() << " added to inventory.\n\n";
				//flag to not go into secret room
				choice = 0;
				return choice;
			}
			else {
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
void BookShelf::setBook(const std::string theBook) { book = theBook; }

void BookShelf::setDescription(const std::string theDescription) { description = theDescription; }

//navigation function to handle game play while the player is in the library
int libraryNavigate(std::unordered_map<std::string, std::string>& inventory) {

	//boolean to find out if player wants to move to another room
	bool move = false;
	int firstTime = 0;
	int shelfRet;

	//intialize objects
	BookShelf bookShelf;
	Desk desk;

	//formatting
	std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

	//Game Intro
	std::cout << "\n\nThe Library\n\n\n\n" <<
		"Sherlock is in the Library.\n\nUpon initial glance, he sees several book shelves throughout the room, but one that seems to catch his attention.\n\n" <<
		"He also sees a desk by the side of the room where several windows overlooking the expansive landscape of the estate.\n\n" <<
		"What would you like to do?\n\n"
		"Examine the Book Shelf? (Enter \"Examine book shelf\").\n\n" <<
		"Go over to look at Desk? (Enter \"Look at desk\").\n\n" <<
		"You may go into the Ballroom (Enter \"Ballroom\")\n\n" <<
		"You may walk into the Study (Enter \"Study\")\n\n" <<
		"Check your inventory of items ( Enter \"Check inventory\").\n\n" <<
		"What would you like to do? ";

	//choice from player
	std::string choice;
	int intChoice;
	int retry = 0;
	std::string ans;

	//inspect the room
	do {

		//navigation choice
		retry = 0;

		do
		{
			if (retry > 0)
			{
				std::cout << "\n\nPlease select an option to navigate: \n\n";
			}
			else {
				if (firstTime != 0) {
					//formatting
					std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

					std::cout << "\n\nThe Library\n\n\n\n" <<
						"Sherlock is in the Library.\n\nUpon initial glance, he sees several book shelves throughout the room, but one that seems to catch his attention.\n\n" <<
						"He also sees a desk by the side of the room where several windows overlooking the expansive landscape of the estate.\n\n" <<
						"What would you like to do?\n\n"
						"Examine the Book Shelf? (Enter \"Examine book shelf\").\n\n" <<
						"Go over to look at Desk? (Enter \"Look at desk\").\n\n" <<
						"You may go into the Ballroom (Enter \"Ballroom\")\n\n" <<
						"You may walk into the Study (Enter \"Study\")\n\n" <<
						"Check your inventory of items ( Enter \"Check inventory\").\n\n" <<
						"What would you like to do? ";
				}
			}
			std::cout << std::endl << std::endl;
			//Take input for program choice.
			std::getline(std::cin, choice);

			while (!std::cin)
			{
				std::cin.clear();
				std::cin.ignore(255, '\n');
				std::cout << "\n\nPlease enter a choice : \n\n";
				std::cin >> choice;
			}
			retry++;
			firstTime++;

		} while ((choice.compare("Examine book shelf") != 0) && (choice.compare("Look at desk") != 0) && (choice.compare("Ballroom") != 0)
			&& (choice.compare("Study") != 0) && (choice.compare("Check inventory") != 0));


		//take users choice and interact based on that
		if (choice.compare("Ballroom") == 0 || choice.compare("Study") == 0) {
			intChoice = movePlayerFromLibrary(choice);
			move = true;
		}
		else if (choice.compare("Check inventory") == 0) {
			std::cout << "\n\nInventory contains: \n\n";
			int c = 1;
			for (auto it = inventory.begin(); it != inventory.end(); ++it) {
				std::cout << c << ": " << it->second << "\n";
				c++;
			}
		}
		else if (choice.compare("Examine book shelf") == 0) {
			shelfRet = bookShelf.checkBookShelf(inventory);
			//if 1 returned go to secret room
			if (shelfRet == 1) {
				move = true;
				choice = 12;
			}
		}
		else {
			desk.checkDesk(inventory);
		}

	} while (!move);

	return intChoice;
}