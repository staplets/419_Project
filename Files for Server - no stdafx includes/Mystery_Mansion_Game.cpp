/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				4/11/16
* Last Modification Date:	5/06/16
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
//#define DrivewayHeader_h
#include "DrivewayHeader.h"
#endif

#ifndef FoyerHeader_h
//#define FoyerHeader_h
#include "FoyerHeader.h"
#endif

#ifndef KitchenHeader_h
//#define KitchenHeader_h
#include "KitchenHeader.h"
#endif

#ifndef CellarHeader_h
//#define CellarHeader_h
#include "CellarHeader.h"
#endif

#ifndef GardenHeader_h
//#define GardenHeader_h
#include "GardenHeader.h"
#endif

#ifndef DeckHeader_h
//#define DeckHeader_h
#include "DeckHeader.h"
#endif

#ifndef BilliardsHeader_h
//#define BilliardsHeader_h
#include "BilliardsHeader.h"
#endif

#ifndef HallwayHeader_h
//#define HallwayHeader_h
#include "HallwayHeader.h"
#endif

#ifndef SmokingHeader_h
//#define SmokingHeader_h
#include "SmokingHeader.h"
#endif

#ifndef SittingHeader_h
//#define SittingHeader_h
#include "SittingHeader.h"
#endif

#ifndef BallroomHeader_h
//#define BallroomHeader_h
#include "BallroomHeader.h"
#endif

#ifndef StudyHeader_h
//#define StudyHeader_h
#include "StudyHeader.h"
#endif

#ifndef LibraryHeader_h
//#define LibraryHeader_h
#include "LibraryHeader.h"
#endif

#ifndef SecretHeader_h
//#define SecretHeader_h
#include "SecretHeader.h"
#endif

#ifndef DiningHeader_h
//#define DiningHeader_h
#include "DiningHeader.h"
#endif

#ifndef BedroomHeader_h
//#define BedroomHeader_h
#include "BedroomHeader.h"
#endif

#ifndef BathroomHeader_h
//#define BathroomHeader_h
#include "BathroomHeader.h"
#endif

#ifndef ServantsHeader_h
//#define ServantsHeader_h
#include "ServantsHeader.h"
#endif

#ifndef AtticHeader_h
//#define AtticHeader_h
#include "AtticHeader.h"
#endif

#ifndef BalconyHeader_h
//#define BalconyHeader_h
#include "BalconyHeader.h"
#endif

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
          "You are Detective Sherlock and you have been taking part in your nightly routine of following up leads\n" <<
          "and keeping a watchful eye over the small town of Salem, Oregon.\n" <<
          "Around 11 PM you receive a dispatch to a call at the old Glass Estate on the outskirts of town.\n" <<
          "You have heard of the Old Estate, but have never been called out that ways for any kind of trouble.\n" <<
          "Tonight apparently everything had changed as you are told over the radio that there was a potential homicide that took place.\n" <<
          "It's your job to go and find out what had happened.\n"
          "You pull a U-turn in your Monte Carlo on Main street and drive out through Maple forest and arrive at the Estate.\n" <<
          "The sprawling mansion rests on the hill side with no other properties or signs of life for miles.\n" <<
          "You pull up in the Monte Carlo and get out at the end of the driveway for you know that anywhere you look,\n" <<
          "there could be evidence that may need to be heavily scrutinized.\n" <<
          "As you approach the large brick archways that lead to the front doors of the mansion, a man steps out of the front door\n" <<
          "and he introduces himself as George Glass. Mr. Glass is an elderly gentleman in his 80's, who appears visibly upset and he is\n" <<
          "fighting back tears.\n\nMr Glass explains \"I was having friends over for a dinner party this evening\n" <<
          "and a terrible tragedy has occured. One of my guests staying here for the evening was found lifeless in one\n" <<
          "of the bedrooms.\"\n\nHe continues \"Oh my, it was my son Willie Cunningham. He and I had been estranged for some time\n" <<
          "and tonight I was planning to work things out between us. I know I myself don't have much time left.\n" <<
          "No other guests were aware of our relation and they only knew him as an acquaintance of mine. This was a very personal matter to me.\"\n\n" <<
          "\"We were all enjoying a pleasant evening and dinner had concluded. Everyone was having some after dinner drinks and smokes.\n" <<
          "At that point, I realized I hadn't seen my boy for a while, but perhaps it was the right time to go have a private discussion with him about\n" <<
          "bridging the gap between us. Instead I found him dead!\"\n\n" <<
          "You ask if he suspected anyone tonight at the dinner party.\n\n" <<
          "Mr. Glass responded \"Oh heavens no! Everyone here is in as much disbelief as I am! However, I sure hope you can take a look around and\n" <<
          "figure out who is responsible for this! I can't even trust my own friends anymore. Please look around the house, I myself need to go lay\n" <<
          "down for a while. I will be in my quarters in the attic of the house if you need me. Thank you for coming out...\"\n\n";

     //call play Rooms to start game
     playRooms();
}

//Function to handle menu for each room 
//Precondition: room is called and must be handled
//Postcondition: game provides menu in each room
//template intialization to handle any room class passed
template<typename X>

std::string roomMenu(std::unordered_map<std::string, std::string>& inv, X theRoom){

     std::string choice;
     int i;

     //formatting
     std::cout << "\n\n////////////////////////////////////////////////////////////////////////////////////\n\n";

     std::cout << "\n\n" << theRoom.getName() << "\n\n\n\n" << theRoom.getDescription();

     std::cout << "There are also " << theRoom.getNumRooms() << " exits from this room: \n\n";

     for (i = 0; i < theRoom.getNumRooms(); i++){
          //output the room exits
          std::cout << i + 1 << "." << " " << theRoom.getExits()[i] << "\n";
     }

     std::cout << "\nThere are also " << theRoom.getNumObjects() << " objects from this room: \n\n";
     for (i = 0; i < theRoom.getNumObjects(); i++){
          //output the room objects
          std::cout << i + 1 << "." << " " << theRoom.getObjects()[i] << "\n";
     }

     std::cout << "\nYou may additionally check your inventory (\"Check Inventory\")\n\n";

     //std::cin.clear();
     std::cin >> choice;
     std::cin.ignore(255, '\n');
     //std::getline (std::cin, choice);
     std::cout << "\n\nChoice is " << choice << "\n\n";

     return choice;
}


//Calls game menu for user options.
//Precondition: main properly opens.
//Postcondition: Game Menu opens up for user.
void playRooms(){
     //navigation choice
     int returnedNavChoice;

     //game over bool
     bool gameOver = false;

     //variables to handle user input
     bool moving = false;
     std::string roomReturn;

     //initialize room objects for menu
     RoomFoyer roomFoyer;
     RoomDriveway roomDriveway;

     //Hash map for the inventory items
     std::unordered_map<std::string, std::string> inventory_Map;

     //testing the vector
     //std::vector<std::string> myVector;
     //myVector.push_back(theCar.getModel());
     //std::cout << "inventory is: " << myVector[0] << "\n";

     //testing!!
     //inventory_Map.insert({ "confession", "the confession" });
     //inventory_Map.insert({ "password", "password" });
	 //inventory_Map.insert({ "key", "key" });
	 //inventory_Map.insert({ "cigs", "cigarettes" });
      //inventory_Map.insert({ "sap", "sap" });
      //inventory_Map.insert({ "grape", "Gamay Grape" });
      //inventory_Map.insert({ "old will", "old will" });
      //inventory_Map.insert({ "new will", "new will" });

//     std::cout << "map shows: " << inventory_Map["knife"] << " with a size of: " << inventory_Map.size() << "\n";

     //Start the game by - Navigating the Driveway
     //Navigate the Driveway
     do{
          //set moving to false
          moving = false;
          //choice from player
          int choice = 0;
          std::string ans;

          //intialize objects
          LuxuryCar aCar;
          MrWhite mrWhite;

          roomReturn = roomMenu(inventory_Map, roomDriveway);
          //returnedNavChoice = drivewayNavigate(inventory_Map, roomReturn);

          //logic to check against parsed input
          if (roomReturn == "car"){
               choice = 1;
          }
          else if (roomReturn == "mrWhite"){
               choice = 2;
          }
          else if (roomReturn == "foyer"){
               choice = 3;
          }
          else if (roomReturn == "garden"){
               choice = 4;
          }
          else if (roomReturn == "inventory"){
               choice = 5;
          }
          else{
               std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
          }


          //take users choice and interact based on that
          switch (choice){
          case 1:
               std::cout << "\nFrom inspecting the car you note the following:\n";
               aCar.carInformation();
               std::cout << "There doesn't appear to be anything inside of the car from plain sight. Would you like to try to open the trunk?\n\n";

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
                    aCar.openTrunk(inventory_Map);
               }
               choice = 0;
               break;
          case 2:
               mrWhite.conversate(inventory_Map);
               choice = 0;
               break;
          case 3:
               std::cout << "\nEntering the mansion into the foyer.\n";
               //change choice to reflect our room mapping
               choice = 2;
               break;
          case 4:
               std::cout << "\nWalking around the side of the mansion to the garden.\n";
               //change choice to reflect our room mapping
               choice = 3;
               break;
          case 5:
               std::cout << "\n\nInventory contains: \n\n";
               int c = 1;
               for (auto it = inventory_Map.begin(); it != inventory_Map.end(); ++it){
                    std::cout << c << ": " << it->second << "\n";
                    c++;
               }
               choice = 0;
               break;
          }


          //if returned code is to leave room then break loop
          if (choice != 0){
               moving = true;
          }
          returnedNavChoice = choice;
     } while (!moving);

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
               do{
                    //set moving to false
                    moving = false;
                    //choice from player
                    int choice = 0;
                    std::string ans;

                    //intialize objects
                    LuxuryCar aCar;
                    MrWhite mrWhite;

                    roomReturn = roomMenu(inventory_Map, roomDriveway);
                    //returnedNavChoice = drivewayNavigate(inventory_Map, roomReturn);

                    //logic to check against parsed input
                    if (roomReturn == "car"){
                         choice = 1;
                    }
                    else if (roomReturn == "mrWhite"){
                         choice = 2;
                    }
                    else if (roomReturn == "foyer"){
                         choice = 3;
                    }
                    else if (roomReturn == "garden"){
                         choice = 4;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 5;
                    }
                    else{
                         std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
                    }


                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         std::cout << "\nFrom inspecting the car you note the following:\n";
                         aCar.carInformation();
                         std::cout << "There doesn't appear to be anything inside of the car from plain sight. Would you like to try to open the trunk?\n\n";

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
                              aCar.openTrunk(inventory_Map);
                         }
                         choice = 0;
                         break;
                    case 2:
                         mrWhite.conversate(inventory_Map);
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nEntering the mansion into the foyer.\n";
                         //change choice to reflect our room mapping
                         choice = 2;
                         break;
                    case 4:
                         std::cout << "\nWalking around the side of the mansion to the garden.\n";
                         //change choice to reflect our room mapping
                         choice = 3;
                         break;
                    case 5:
                         std::cout << "\n\nInventory contains: \n\n";
                         int c = 1;
                         for (auto it = inventory_Map.begin(); it != inventory_Map.end(); ++it){
                              std::cout << c << ": " << it->second << "\n";
                              c++;
                         }
                         choice = 0;
                         break;
                    }
                    

                    //if returned code is to leave room then break loop
                    if (choice != 0){
                         moving = true;
                    }
                    returnedNavChoice = choice;
               } while (!moving);
               break;
          case 2:
               //Navigate the Foyer
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    CoatCloset Closet;
                    FishBowl fishBowl;

                    roomReturn = roomMenu(inventory_Map, roomFoyer);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);

                    //logic to check against parsed input
                    if (roomReturn == "closet"){
                         choice = 1;
                    }
                    else if (roomReturn == "fishBowl"){
                         choice = 2;
                    }
                    else if (roomReturn == "dining"){
                         choice = 3;
                    }
                    else if (roomReturn == "sitting"){
                         choice = 4;
                    }
                    else if (roomReturn == "kitchen"){
                         choice = 5;
                    }
                    else if (roomReturn == "upstairs"){
                         choice = 6;
                    }
                    else if (roomReturn == "driveway"){
                         choice = 7;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 8;
                    }
                    else{
                         std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
                    }
                                                            
                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         Closet.closetInformation(inventory_Map);
                         std::cout << "\nWould you like to check the coats?\n\n";

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
                              Closet.checkCoats(inventory_Map);
                         }
                         choice = 0;
                         break;
                    case 2:
                         fishBowl.fishConvo(inventory_Map);
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nEntering the Dining Room.\n";
                         //change choice to reflect our room mapping
                         choice = 8;
                         break;
                    case 4:
                         std::cout << "\nEntering the Sitting Room.\n";
                         //change choice to reflect our room mapping
                         choice = 5;
                         break;
                    case 5:
                         std::cout << "\nEntering the Kitchen.\n";
                         //change choice to reflect our room mapping
                         choice = 9;
                         break;
                    case 6:
                         std::cout << "\nGoing Upstairs.\n";
                         //change choice to reflect our room mapping
                         choice = 14;
                         break;
                    case 7:
                         std::cout << "\nGoing outside into the Driveway.\n";
                         //change choice to reflect our room mapping
                         choice = 1;
                         break;
                    case 8:
                         std::cout << "\n\nInventory contains: \n\n";
                         int c = 1;
                         for (auto it = inventory_Map.begin(); it != inventory_Map.end(); ++it){
                              std::cout << c << ": " << it->second << "\n";
                              c++;
                         }
                         choice = 0;
                         break;
                    }


                    //if returned code is to leave room then break loop
                    if (choice != 0){
                         moving = true;
                    }
                    returnedNavChoice = choice;
               } while (!moving);
               break;
          case 3:
               //Navigate the Garden
               returnedNavChoice = gardenNavigate(inventory_Map);
               break;
          case 4:
               //Navigate the Study
               returnedNavChoice = studyNavigate(inventory_Map);
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
               returnedNavChoice = diningNavigate(inventory_Map);
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
               returnedNavChoice = libraryNavigate(inventory_Map);
               break;
          case 12:
               //Navigate the Secret Room
               returnedNavChoice = secretNavigate(inventory_Map);
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
               returnedNavChoice = bedroomNavigate(inventory_Map);
               break;
          case 16:
               //Navigate the Ballroom
               returnedNavChoice = ballroomNavigate(inventory_Map);
               break;
          case 17:
               //Navigate the Servants Room
               returnedNavChoice = servantsNavigate(inventory_Map);
               break;
          case 18:
               //Navigate the Balcony
               returnedNavChoice = balconyNavigate(inventory_Map);
               break;
          case 19:
               //Navigate the Bathroom
               returnedNavChoice = bathroomNavigate(inventory_Map);
               break;
          case 20:
               //Navigate the Attic
               returnedNavChoice = atticNavigate(inventory_Map);
               break;
          }


     } while (!gameOver);
     
     /*
     //test inventory
     std::cout << "Map's inventory contains: \n";
     int c = 1;
     for (auto it = inventory_Map.begin(); it != inventory_Map.end(); ++it){
          std::cout << c << ": " << it->second << "\n";
          c++;
     }
     */
}