/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/11/16
* Last Modification Date:	4/24/16
* Filename:				Mystery_Mansion.cpp
*
* Overview:
*	This program will play the mystery mansion game for a single player.
*    The user will navigate throughout the mansion and solve the puzzle from
*    clues given in each room. Each room will be a separate file provided through header files
*    that the user will go into as they go from one room to the next.
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

//Header files
//guards for header
#ifndef DrivewayHeader_h
#define DrivewayHeader_h
#include "DrivewayHeader.h"
#endif

#ifndef FoyerHeader_h
#define FoyerHeader_h
#include "FoyerHeader.h"
#endif

#ifndef KitchenHeader_h
#define KitchenHeader_h
#include "KitchenHeader.h"
#endif

#ifndef CellarHeader_h
#define CellarHeader_h
#include "CellarHeader.h"
#endif

#ifndef GardenHeader_h
#define GardenHeader_h
#include "GardenHeader.h"
#endif

#ifndef DeckHeader_h
#define DeckHeader_h
#include "DeckHeader.h"
#endif

#ifndef BilliardsHeader_h
#define BilliardsHeader_h
#include "BilliardsHeader.h"
#endif

#ifndef HallwayHeader_h
#define HallwayHeader_h
#include "HallwayHeader.h"
#endif

#ifndef SmokingHeader_h
#define SmokingHeader_h
#include "SmokingHeader.h"
#endif

#ifndef SittingHeader_h
#define SittingHeader_h
#include "SittingHeader.h"
#endif

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <vector>
#include <unordered_map>


//Function to handle and manipulate the game
//Precondition: gamePlay function called from main
//Postcondition: game is run for the player
void gamePlay();

//Calls game menu for user options.
//Precondition: main properly opens.
//Postcondition: Game Menu opens up for user.
void gameIntro();

//Calls game menu for user options.
//Precondition: main properly opens.
//Postcondition: Game Menu opens up for user.
void playRooms();

int main()
{
     //Call to begin game
     gamePlay();
     
	return 0;
}

//Function to handle and manipulate the game
//Precondition: gamePlay function called from main
//Postcondition: game is run for the player
void gamePlay(){

     //Call introduction to game
     gameIntro();
}

//Calls game menu for user options.
//Precondition: main properly opens.
//Postcondition: Game Menu opens up for user.
void gameIntro(){

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     //Game Intro
     std::cout << "\n\nThe Mystery Mansion Game\n\n\n\n" <<
          "It was a cold and clear night in beginning of March. A full moon rested just over the treeline in the distance.\n" <<
          "Detective Sherlock had been taking part in his nightly routine of following up leads\n" <<
          "and keeping a watchful eye over the small town of Salem, Oregon.\n" <<
          "Around 11 PM he received a dispatch to a call at the old Glass Estate on the outskirts of town.\n" <<
          "Sherlock had heard of the Old Estate, but had never been called out that ways for any kind of trouble.\n" <<
          "Tonight apparently everything had changed as he was told over the radio that there was a potential homicide that took place.\n" <<
          "It was his job to go and find out what had happened.\n"
          "Sherlock pulled a U-turn in his Monte Carlo on Main street and drove out through Maple forest and arrived at the Estate.\n" <<
          "The sprawling mansion rested on the hill side with no other properties or signs of life for miles.\n" <<
          "Sherlock pulled up in his Monte Carlo and got out at the end of the driveway for he knew that anywhere he looked,\n" <<
          "there could be evidence that would need to be heavily scrutinized.\n" <<
          "As he approached the large brick archways that led to the front doors of the mansion, a man stepped out of the front door\n" <<
          "who called himself George Glass. Mr. Glass was an elderly gentleman in his 80's, who appeared visibly upset, however he was\n" <<
          "fighting back the tears.\n\nMr Glass explained \"I was having friends over for a dinner party this evening\n" <<
          "and toight a terrible tragedy has occured. One of my guests staying here for the evening was found lifeless in one\n" <<
          "of the bedrooms.\"\n\nHe continued \"Oh my, it was my son Willie Cunningham. He and I had been estranged for some time\n" <<
          "and tonight I was planning to work things out between us. I know I myself don't have much time left.\n" <<
          "No other guests were aware of our relation and they only knew him as an acquaintance of mine. This was a very personal matter to me.\"\n\n" <<
          "\"We were all enjoying a pleasant evening and dinner had concluded. Everyone was having some after dinner drinks and smokes.\n" <<
          "At that point, I realized I hadn't seen my boy for a while, but perhaps it was the right time to go have a private discussion with him about\n" <<
          "bridging the gap between us. Instead I found him dead!\"\n\n" <<
          "Shelock asked if he suspected anyone tonight at the dinner party.\n\n" <<
          "Mr. Glass responded \"Oh heavens no! Everyone here is in as much disbelief as I am! However, I sure hope you can take a look around and\n" <<
          "figure out who is responsible for this! I can't even trust my own friends anymore. Please look around the house, I myself need to go lay\n" <<
          "down for a while. I will be in my quarters in the attic of the house if you need me. Thank you for coming out...\"\n\n";

     //call play Rooms to start game
     playRooms();
}


//Calls game menu for user options.
//Precondition: main properly opens.
//Postcondition: Game Menu opens up for user.
void playRooms(){
     //navigation choice
     int returnedNavChoice;

     //game over bool
     bool gameOver = false;

     //Hash map for the inventory items
     std::unordered_map<std::string, std::string> inventory_Map;

     //testing the vector
     //std::vector<std::string> myVector;
     //myVector.push_back(theCar.getModel());
     //std::cout << "inventory is: " << myVector[0] << "\n";

     //testing!!
     //inventory_Map.insert({ "confession", "the confession" });
     //inventory_Map.insert({ "revolver", "the gun" });

//     std::cout << "map shows: " << inventory_Map["knife"] << " with a size of: " << inventory_Map.size() << "\n";

     //Start the game by - Navigating the Driveway
     returnedNavChoice = drivewayNavigate(inventory_Map);

     //While loop to navigate rooms until game over is evaluated as true
     do{

          //switch case to determin the room to enter based on returned value
          //If game is won return value will be 0
          //room values are Driveway = 1, Foyer = 2, Garden = 3, Study = 4, Sitting Room = 5, Smoking Room = 6, Billiards Room = 7,
          //Dining = 8, Kitchen = 9, Cellar = 10, Library = 11, Secret Room = 12, Deck = 13, Hallway = 14, Bedroom = 15, Ballroom = 16,
          //Servants Room = 17, Balcony = 18, Bathroom = 19, Attic = 20
          switch (returnedNavChoice){
          case 0:
               gameOver = true;
               break;
          case 1:
               //Navigate the Driveway
               returnedNavChoice = drivewayNavigate(inventory_Map);
               break;
          case 2:
               //Navigate the Foyer
               returnedNavChoice = foyerNavigate(inventory_Map);
               break;
          case 3:
               //Navigate the Garden
               returnedNavChoice = gardenNavigate(inventory_Map);
               break;
          case 4:
               //Navigate the Study
               std::cout << "Under construction!" << " choice was: " << returnedNavChoice << "\n\n";
               gameOver = true;
               //returnedNavChoice = studyNavigate(inventory_Map);
               break;
          case 5:
               //Navigate the Sitting Room
               returnedNavChoice = sittingNavigate(inventory_Map);
               break;
          case 6:
               //Navigate the Smoking Room
               returnedNavChoice = smokingRoomNavigate(inventory_Map);
               break;
          case 7:
               returnedNavChoice = billiardsNavigate(inventory_Map);
               break;
          case 8:
               //Navigate the Dining Room
               std::cout << "Under construction!" << " choice was: " << returnedNavChoice << "\n\n";
               gameOver = true;
               //returnedNavChoice = diningRoomNavigate(inventory_Map);
               break;
          case 9:
               //Navigate the Kitchen
               returnedNavChoice = kitchenNavigate(inventory_Map);
               break;
          case 10:
               //Navigate the Cellar
               returnedNavChoice = cellarNavigate(inventory_Map);
               break;
          case 11:
               //Navigate the Library
               std::cout << "Under construction!" << " choice was: " << returnedNavChoice << "\n\n";
               gameOver = true;
               //returnedNavChoice = libraryNavigate(inventory_Map);
               break;
          case 12:
               //Navigate the Secret Room
               std::cout << "Under construction!" << " choice was: " << returnedNavChoice << "\n\n";
               gameOver = true;
               //returnedNavChoice = secretRoomNavigate(inventory_Map);
               break;
          case 13:
               //Navigate the Deck
               returnedNavChoice = deckNavigate(inventory_Map);
               break;
          case 14:
               //Navigate the Hallway
               returnedNavChoice = hallwayNavigate(inventory_Map);
               break;
          case 15:
               //Navigate the Bedroom
               std::cout << "Under construction!" << " choice was: " << returnedNavChoice << "\n\n";
               gameOver = true;
               //returnedNavChoice = bedroomNavigate(inventory_Map);
               break;
          case 16:
               //Navigate the Ballroom
               std::cout << "Under construction!" << " choice was: " << returnedNavChoice << "\n\n";
               gameOver = true;
               //returnedNavChoice = ballroomNavigate(inventory_Map);
               break;
          case 17:
               //Navigate the Servants Room
               std::cout << "Under construction!" << " choice was: " << returnedNavChoice << "\n\n";
               gameOver = true;
               //returnedNavChoice = servantsRoomNavigate(inventory_Map);
               break;
          case 18:
               //Navigate the Balcony
               std::cout << "Under construction!" << " choice was: " << returnedNavChoice << "\n\n";
               gameOver = true;
               //returnedNavChoice = balconyNavigate(inventory_Map);
               break;
          case 19:
               //Navigate the Bathroom
               std::cout << "Under construction!" << " choice was: " << returnedNavChoice << "\n\n";
               gameOver = true;
               //returnedNavChoice = bathroomNavigate(inventory_Map);
               break;
          case 20:
               //Navigate the Attic
               std::cout << "Under construction!" << " choice was: " << returnedNavChoice << "\n\n";
               gameOver = true;
               //returnedNavChoice = atticNavigate(inventory_Map);
               break;
          }


     } while (!gameOver);
     
     
     //test inventory
     std::cout << "Map's inventory contains: \n";
     int c = 1;
     for (auto it = inventory_Map.begin(); it != inventory_Map.end(); ++it){
          std::cout << c << ": " << it->second << "\n";
          c++;
     }
}