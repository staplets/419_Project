/***********************************************************
* Author:					Shaun Stapleton, Robyn Lin
* Date Created:		     4/11/16
* Last Modification Date:	5/26/16
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
#include "DrivewayHeader.h"
#endif

#ifndef FoyerHeader_h
#include "FoyerHeader.h"
#endif

#ifndef KitchenHeader_h
#include "KitchenHeader.h"
#endif

#ifndef CellarHeader_h
#include "CellarHeader.h"
#endif

#ifndef GardenHeader_h
#include "GardenHeader.h"
#endif

#ifndef DeckHeader_h
#include "DeckHeader.h"
#endif

#ifndef BilliardsHeader_h
#include "BilliardsHeader.h"
#endif

#ifndef HallwayHeader_h
#include "HallwayHeader.h"
#endif

#ifndef SmokingHeader_h
#include "SmokingHeader.h"
#endif

#ifndef SittingHeader_h
#include "SittingHeader.h"
#endif

#ifndef BallroomHeader_h
#include "BallroomHeader.h"
#endif

#ifndef StudyHeader_h
#include "StudyHeader.h"
#endif

#ifndef LibraryHeader_h
#include "LibraryHeader.h"
#endif

#ifndef SecretHeader_h
#include "SecretHeader.h"
#endif

#ifndef DiningHeader_h
#include "DiningHeader.h"
#endif

#ifndef BedroomHeader_h
#include "BedroomHeader.h"
#endif

#ifndef BathroomHeader_h
#include "BathroomHeader.h"
#endif

#ifndef ServantsHeader_h
#include "ServantsHeader.h"
#endif

#ifndef AtticHeader_h
#include "AtticHeader.h"
#endif

#ifndef BalconyHeader_h
#include "BalconyHeader.h"
#endif

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <cctype>
#include <sstream>
#include <cstring>
#include "animation.hpp"

#include <ostream>

//namespace code to make objects in rooms a different color
//helps with readability
//source: http://pastebin.com/zWC3t9hC
namespace Color{

        enum Code {

                FG_RED = 31,
                FG_GREEN = 32,
				FG_YELLOW = 33,
                FG_BLUE = 34,
                FG_DEFAULT = 39,

        };

        std::ostream& operator<<(std::ostream& os, Code code){
                return os << "\033[" << static_cast<int>(code) << "m";
        }

}



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

std::string roomMenu(std::unordered_map<std::string, std::string>& inv, X theRoom, int newline){
     
     std::string choice;
     std::string strChoice;
     std::string roomName;
     std::string objName;
     char arr[100];
     memset(arr, 0, sizeof(arr));
     //char arr1[100];
     //     //     //char arr2[100];
     //          //          //char arr3[100];
     int i, j, n;

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

     std::cout << "\nPlease enter a command from this menu of options:\n\n\"Go to (room name, ie: go to dining room)\" or just \"(room name, ie: Dining Room)\",\n \"Inspect (object name, ie: inspect reclining chair)\" or just \"(object name, ie: Reclining Chair)\",\n \"Talk to (person name, ie: Mr.White or Mr White)\",\n \"Interact with (animal name)\",\n \"Get in (object name)\",\n \"Sleep on (furniture name)\",\n \"Switch on (object name)\",\n \"Open (object/door name)\",\n or \"Play (instrument name)\".\n You may additionally check your inventory (\"Check inventory\").\n\n" << std::endl;
 //not using these: \"Give (object name)\", \"Use (object name)\", \"Add (object name) to inventory\", 
     //std::cin.clear();
     //std::cin >> choice;
     //std::cout << newline << std::endl;
     
     if(newline == false) 
       std::getline(std::cin, choice);
     else {
       std::cin.ignore(); //ignore newline character
       std::getline(std::cin, choice);
     }
     
     std::cout << "\n\nChoice is: " << choice << "\n\n";

     //split user input words into vector
     std::stringstream ss(choice);
     std::istream_iterator<std::string> begin(ss);
     std::istream_iterator<std::string> end;
     std::vector<std::string> vstrings(begin, end);
     //std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

     if (vstrings.size() == 1) { //move to room (room name is 1 word)
          for (i = 0; i < theRoom.getNumRooms(); i++){
               //check if choice matches room names in vector
               for (n = 0; n < vstrings[0].length(); n++) {
                    vstrings[0][n] = tolower(vstrings[0][n]);
               }
               if (vstrings[0].compare(theRoom.getExits()[i]) == 0) {
                    std::string roomExit = theRoom.getExits()[i];
                    for (j = 0; j < theRoom.getExits()[i].length(); j++) {
                         //std::cout << tolower(theRoom.getExits()[i][j]) << std::endl;
                         choice[j] = theRoom.getExits()[i][j];
                    }
               }
          }
     }

     if (vstrings[0].compare("go") == 0 || vstrings[0].compare("Go") == 0) //move to room
     {
          std::string roomName = vstrings[2];
          std::cout << roomName.length();
          roomName[roomName.length()] = '\0';

          if (roomName.compare("driveway") == 0 || roomName.compare("Driveway") == 0) {
               choice = "driveway";
          }
          else if (roomName.compare("foyer") == 0 || roomName.compare("Foyer") == 0) {
               choice = "foyer";
          }
          else if (roomName.compare("garden") == 0 || roomName.compare("Garden") == 0) {
               choice = "garden";
          }
          else if (roomName.compare("study") == 0 || roomName.compare("Study") == 0) {
               choice = "study";
          }
          else if (roomName.compare("sitting") == 0 || roomName.compare("Sitting") == 0) {
               choice = "sitting room";
          }
          else if (roomName.compare("smoking") == 0 || roomName.compare("Smoking") == 0) {
               choice = "smoking room";
          }
          else if (roomName.compare("billiards") == 0 || roomName.compare("Billiards") == 0) {
               choice = "billiards room";
          }
          else if (roomName.compare("dining") == 0 || roomName.compare("Dining") == 0) {
               choice = "dining room";
          }
          else if (roomName.compare("kitchen") == 0 || roomName.compare("Kitchen") == 0) {
               choice = "kitchen";
          }
          else if (roomName.compare("cellar") == 0 || roomName.compare("Cellar") == 0) {
               choice = "cellar";
          }
          else if (roomName.compare("library") == 0 || roomName.compare("Library") == 0) {
               choice = "library";
          }
          else if (roomName.compare("secret") == 0 || roomName.compare("Secret") == 0) {
               choice = "secret room";
          }
          else if (roomName.compare("deck") == 0 || roomName.compare("Deck") == 0) {
               choice = "deck";
          }
          else if (roomName.compare("upstairs") == 0 || roomName.compare("Upstairs") == 0) {
               choice = "hallway";
          }
          else if (roomName.compare("hallway") == 0 || roomName.compare("Hallway") == 0) {
               choice = "hallway";
          }
          else if (roomName.compare("bedroom") == 0 || roomName.compare("Bedroom") == 0) {
               choice = "bedroom";
          }
          else if (roomName.compare("ballroom") == 0 || roomName.compare("Ballroom") == 0) {
               choice = "ballroom";
          }
          else if (roomName.compare("servants") == 0 || roomName.compare("Servants") == 0) {
               choice = "servants room";
          }
          else if (roomName.compare("balcony") == 0 || roomName.compare("Balcony") == 0) {
               choice = "balcony";
          }
          else if (roomName.compare("bathroom") == 0 || roomName.compare("Bathroom") == 0) {
               choice = "bathroom";
          }
          else {
               choice = "attic";
          }

     }
     
     //check if choice matches object
     if (vstrings[0].compare("inspect") == 0 || vstrings[0].compare("Inspect") == 0) {
          if (vstrings.size() == 2) { //obj name is 1 word
               for (i = 0; i < theRoom.getNumObjects(); i++){
                    for (n = 0; n < vstrings[1].length(); n++) {
                         vstrings[1][n] = tolower(vstrings[1][n]);
                         //	std::cout<<vstrings[0][n]<<std::endl;
                    }
                    if (vstrings[1].compare(theRoom.getObjects()[i]) == 0) {
                         for (j = 0; j < theRoom.getObjects()[i].length(); j++) {
                              arr[j] = tolower(theRoom.getObjects()[i][j]);
                              //		std::cout << choice[j] << std::endl;
                         }
                    }
               }
               choice = arr;
          }
          else { //obj name is more than 1 word
		if((vstrings[1].compare("night") == 0 && vstrings[2].compare("stand") == 0) || (vstrings[1].compare("Night") == 0 && vstrings[2].compare("Stand") == 0))
		  choice = "nightstand";
		if((vstrings[1].compare("folding") == 0 && vstrings[2].compare("table") == 0) || (vstrings[1].compare("Folding") == 0 && vstrings[2].compare("Table") == 0))
		  choice = "foldingtable";
		if((vstrings[1].compare("pool") == 0 && vstrings[2].compare("table") == 0) || (vstrings[1].compare("Pool") == 0 && vstrings[2].compare("Table") == 0))
		  choice = "pooltable";
		if((vstrings[1].compare("coffee") == 0 && vstrings[2].compare("table") == 0) || (vstrings[1].compare("Coffee") == 0 && vstrings[2].compare("Table") == 0))
		  choice = "coffeetable";
		if((vstrings[1].compare("hot") == 0 && vstrings[2].compare("tub") == 0) || (vstrings[1].compare("Hot") == 0 && vstrings[2].compare("Tub") == 0))
		  choice = "hottub";
		if((vstrings[1].compare("dining") == 0 && vstrings[2].compare("table") == 0) || (vstrings[1].compare("Dining") == 0 && vstrings[2].compare("Table") == 0))
		  choice = "diningtable";
		if((vstrings[1].compare("end") == 0 && vstrings[2].compare("table") == 0) || (vstrings[1].compare("End") == 0 && vstrings[2].compare("Table") == 0))
		  choice = "endtable";
		if((vstrings[1].compare("knife") == 0 && vstrings[2].compare("block") == 0) || (vstrings[1].compare("Knife") == 0 && vstrings[2].compare("Block") == 0))
		  choice = "knifeblock";
		if((vstrings[1].compare("reclining") == 0 && vstrings[2].compare("chair") == 0) || (vstrings[1].compare("Reclining") == 0 && vstrings[2].compare("Chair") == 0))
		  choice = "recliningchair";
		if((vstrings[1].compare("light") == 0 && vstrings[2].compare("switch") == 0) || (vstrings[1].compare("Light") == 0 && vstrings[2].compare("Switch") == 0))
		  choice = "lightswitch";

          }
     }
     
     //check if choice matches person in objects array
     if (vstrings[0].compare("talk") == 0 || vstrings[0].compare("Talk") == 0) {
      if(vstrings[1].compare("to") == 0 || vstrings[1].compare("To") == 0) {
	if(vstrings.size() == 3) { //name is 1 word
	 if(vstrings[2].compare("parrot") == 0 || vstrings[2].compare("Parrot") == 0 || vstrings[2].compare("dog") == 0 || vstrings[2].compare("Dog") == 0)
	    choice = "error";
	 else { 
          for (i = 0; i < theRoom.getNumObjects(); i++){
               for (n = 0; n < vstrings[2].length(); n++) {
                    vstrings[2][n] = tolower(vstrings[2][n]);
                   // 	std::cout<<vstrings[0][n]<<std::endl;
               }
               if (vstrings[2].compare(theRoom.getObjects()[i]) == 0) {
                    for (j = 0; j < theRoom.getObjects()[i].length(); j++) {
                         arr[j] = tolower(theRoom.getObjects()[i][j]);
                         //std::cout << choice[j] << std::endl;
                    }
               }
          }
          choice = arr;
         }
	}
	else { //name has space in it
	  if((vstrings[2].compare("Mr") == 0 && vstrings[3].compare("White") == 0) || (vstrings[2].compare("mr") == 0 && vstrings[3].compare("white") == 0)) 
		choice = "mr.white";
	  if((vstrings[2].compare("Mrs") == 0 && vstrings[3].compare("Deeds") == 0) || (vstrings[2].compare("mrs") == 0 && vstrings[3].compare("deeds") == 0)) 
		choice = "mrs.deeds";
	  if((vstrings[2].compare("Mr") == 0 && vstrings[3].compare("Deeds") == 0) || (vstrings[2].compare("mr") == 0 && vstrings[3].compare("deeds") == 0)) 
		choice = "mr.deeds";
	  if((vstrings[2].compare("Mr") == 0 && vstrings[3].compare("Green") == 0) || (vstrings[2].compare("mr") == 0 && vstrings[3].compare("green") == 0)) 
		choice = "mr.green";
	  if((vstrings[2].compare("Ms") == 0 && vstrings[3].compare("Wolf") == 0) || (vstrings[2].compare("ms") == 0 && vstrings[3].compare("wolf") == 0)) 
		choice = "mr.wolf";
	  if((vstrings[2].compare("Mr") == 0 && vstrings[3].compare("Glass") == 0) || (vstrings[2].compare("mr") == 0 && vstrings[3].compare("glass") == 0)) 
		choice = "mr.glass";
	  if((vstrings[2].compare("Mrs") == 0 && vstrings[3].compare("White") == 0) || (vstrings[2].compare("mrs") == 0 && vstrings[3].compare("white") == 0)) 
		choice = "mrs.white";

	}
      }
     }

     //inspect 2-word object (if no "inspect" in front of command)
     if((vstrings[0].compare("night") == 0 && vstrings[1].compare("stand") == 0) || (vstrings[0].compare("Night") == 0 && vstrings[1].compare("Stand") == 0))
	choice = "nightstand";
     if((vstrings[0].compare("folding") == 0 && vstrings[1].compare("table") == 0) || (vstrings[0].compare("Folding") == 0 && vstrings[1].compare("Table") == 0))
	choice = "foldingtable";
     if((vstrings[0].compare("pool") == 0 && vstrings[1].compare("table") == 0) || (vstrings[0].compare("Pool") == 0 && vstrings[1].compare("Table") == 0))
	choice = "pooltable";
     if((vstrings[0].compare("coffee") == 0 && vstrings[1].compare("table") == 0) || (vstrings[0].compare("Coffee") == 0 && vstrings[1].compare("Table") == 0))
	choice = "coffeetable";
     if((vstrings[0].compare("hot") == 0 && vstrings[1].compare("tub") == 0) || (vstrings[0].compare("Hot") == 0 && vstrings[1].compare("Tub") == 0))
	choice = "hottub";
     if((vstrings[0].compare("dining") == 0 && vstrings[1].compare("table") == 0) || (vstrings[0].compare("Dining") == 0 && vstrings[1].compare("Table") == 0))
	choice = "diningtable";
     if((vstrings[0].compare("end") == 0 && vstrings[1].compare("table") == 0) || (vstrings[0].compare("End") == 0 && vstrings[1].compare("Table") == 0))
	choice = "endtable";
     if((vstrings[0].compare("knife") == 0 && vstrings[1].compare("block") == 0) || (vstrings[0].compare("Knife") == 0 && vstrings[1].compare("Block") == 0))
	choice = "knifeblock";
     if((vstrings[0].compare("reclining") == 0 && vstrings[1].compare("chair") == 0) || (vstrings[0].compare("Reclining") == 0 && vstrings[1].compare("Chair") == 0))
	choice = "recliningchair";
     if((vstrings[0].compare("light") == 0 && vstrings[1].compare("switch") == 0) || (vstrings[0].compare("Light") == 0 && vstrings[1].compare("Switch") == 0))
	choice = "lightswitch";

     //check if choice matches piano
     else if (vstrings[0].compare("play") == 0 || vstrings[0].compare("Play") == 0) {
          if (vstrings[1].compare("piano") == 0 || vstrings[1].compare("Piano") == 0)
          {
               choice = "play piano";
          }
     }

     //check if choice matches couch
     else if (vstrings[0].compare("sleep") == 0 || vstrings[0].compare("Sleep") == 0) {
          if (vstrings[1].compare("on") == 0 || vstrings[1].compare("On") == 0)
          {
	    if (vstrings[2].compare("couch") == 0 || vstrings[2].compare("Couch") == 0)
               choice = "sleep on couch";
          }
     }

     //check if choice matches hot tub
     else if (vstrings[0].compare("get") == 0 || vstrings[0].compare("Get") == 0) {
          if (vstrings[1].compare("in") == 0 || vstrings[1].compare("In") == 0)
          {
               if (vstrings[2].compare("hottub") == 0 || (vstrings[2].compare("hot") == 0 && vstrings[3].compare("tub") == 0) || (vstrings[2].compare("Hot") == 0 && vstrings[3].compare("Tub") == 0))
                    choice = "get in hottub";
          }
     }
     //check if choice matches light switch
     else if (vstrings[0].compare("switch") == 0 || vstrings[0].compare("Switch") == 0) {
	if(vstrings[1].compare("on") == 0 || vstrings[1].compare("On") == 0) {
          if ((vstrings[2].compare("light") == 0 || vstrings[2].compare("Light") == 0) || vstrings[2].compare("lightswitch") == 0 || vstrings[2].compare("Lightswitch") == 0)
               choice = "lightswitch";
	}
     }
     //check if choice matches animal name
     else if (vstrings[0].compare("interact") == 0 || vstrings[0].compare("Interact") == 0) {
          if (vstrings[1].compare("with") == 0 || vstrings[1].compare("With") == 0)
          {
               if ((vstrings[2].compare("dog") == 0 || vstrings[2].compare("Dog") == 0))
                    choice = "dog";
          
	       else {
	            choice = "parrot";
	       }
	  }
     }

     //check if choice matches object to open
     else if (vstrings[0].compare("open") == 0 || vstrings[0].compare("Open") == 0) {
          if (vstrings[1].compare("cabinet") == 0 || vstrings[1].compare("Cabinet") == 0)
          {
               choice = "cabinet";
	  }       
          else if (vstrings[1].compare("safe") == 0 || vstrings[1].compare("Safe") == 0)
          {
               choice = "safe";
          }
	  else {
	       choice = "refrigerator";
	  }   
     }

     //check if choice matches inventory
     else if (vstrings[0].compare("check") == 0 || vstrings[0].compare("Check") == 0) {
          if (vstrings[1].compare("inventory") == 0 || vstrings[1].compare("Inventory") == 0)
          {
               choice = "inventory";
          }
     }

     else { //go to room name that is more than 1 word
          //std::cout << "moving to 2 word room" << std::endl;
          for (i = 0; i < theRoom.getNumRooms(); i++){
               //check if choice matches room names  
               for (n = 0; n < choice.length(); n++) {
                    //	    vstrings[0][n] = tolower(vstrings[0][n]);
                    choice[n] = tolower(choice[n]);
               //     std::cout << choice[n] << std::endl;
               }
               if (choice.compare(theRoom.getExits()[i]) == 0) {
                    for (j = 0; j < theRoom.getExits()[i].length(); j++) {
                         //std::cout << tolower(theRoom.getExits()[i][j]) << std::endl;
                         choice[j] = theRoom.getExits()[i][j];
                    }
               }
          }
     }

     return choice;
     

	/* /////Shaun's code used for testing rooms easier. Please leave until all rooms are restructured
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
	 */
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
     RoomGarden roomGarden;
     RoomStudy roomStudy;
     RoomSitting roomSitting;
     RoomSmoking roomSmoking;
     RoomBilliards roomBilliards;
     RoomDining roomDining;
     RoomKitchen roomKitchen;
     RoomCellar roomCellar;
     RoomLibrary roomLibrary;
     RoomSecret roomSecret;
     RoomDeck roomDeck;
     RoomHallway roomHallway;
     RoomBedroom roomBedroom;
     RoomBallroom roomBallroom;
     RoomServants roomServants;
     RoomBalcony roomBalcony;
     RoomBathroom roomBathroom;
     RoomAttic roomAttic;

     //intialize objects for safe room outside of while loop
     //so that the set changes remain
     LightSwitch lightSwitch;
     Safe safe;

     //check whether player is dry before leaving room the deck
     //needs to be declared outside of loop
     bool dry = true;

     //Hash map for the inventory items
     std::unordered_map<std::string, std::string> inventory_Map;

     //testing the vector
     //std::vector<std::string> myVector;
     //myVector.push_back(theCar.getModel());
     //std::cout << "inventory is: " << myVector[0] << "\n";

     //testing!!
     //inventory_Map.insert({ "statement", "the statement from Mr. Glass" });
     //inventory_Map.insert({ "revolver", "revolver" });
     //inventory_Map.insert({ "key", "key" });
     //inventory_Map.insert({ "bulb", "light bulb" });
     //inventory_Map.insert({ "secret note", "secret note" });
     //inventory_Map.insert({ "grape", "Gamay Grape" });
     //inventory_Map.insert({ "old will", "old will" });
     //inventory_Map.insert({ "new will", "new will" });

     //     std::cout << "map shows: " << inventory_Map["knife"] << " with a size of: " << inventory_Map.size() << "\n";
     bool newline = false;
     //Start the game by - Navigating the Driveway
     //Navigate the Driveway
     do{
          //set moving to false
          moving = false;

          //choice from player
          int choice = 0;
          std::string ans;

		  std::cout << Color::FG_DEFAULT << std::endl;
		  
          //intialize objects
          LuxuryCar aCar;
          MrWhite mrWhite;                  
          roomReturn = roomMenu(inventory_Map, roomDriveway, newline);
          //returnedNavChoice = drivewayNavigate(inventory_Map, roomReturn);
		  
		  std::cout << Color::FG_GREEN << std::endl;

		  //set newline flag to false each iteration
		  //this avoids a true flag staying set
		  newline = false;
		  
          //logic to check against parsed input
          if (roomReturn == "car"){
               choice = 1;
          }
          else if (roomReturn == "mr.white"){
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
               //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
               std::cout << Color::FG_RED << std::endl;
			   std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
			   std::cout << Color::FG_DEFAULT << std::endl;
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
	       newline = false;
               choice = 0;
               break;
          case 2:
               mrWhite.conversate(inventory_Map);
               choice = 0;
			   newline = true;
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
          newline = false;

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
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    //intialize objects
                    LuxuryCar aCar;
                    MrWhite mrWhite;
					roomReturn = roomMenu(inventory_Map, roomDriveway, newline);
					
					std::cout << Color::FG_GREEN << std::endl;
				
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //returnedNavChoice = drivewayNavigate(inventory_Map, roomReturn);

                    //logic to check against parsed input
                    if (roomReturn == "car"){
                         choice = 1;

                    }
                    else if (roomReturn == "mr.white"){
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
                         //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;

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
						 newline = false;
                         choice = 0;
                         break;
                    case 2:
                         mrWhite.conversate(inventory_Map);
						 newline = true;
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
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomFoyer, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "closet"){
                         choice = 1;
                    }
                    else if (roomReturn == "fishbowl"){
                         choice = 2;
                    }
                    else if (roomReturn == "dining room"){
                         choice = 3;
                    }
                    else if (roomReturn == "sitting room"){
                         choice = 4;
                    }
                    else if (roomReturn == "kitchen"){
                         choice = 5;
                    }
                    else if (roomReturn == "hallway"){
                         choice = 6;
                    }
                    else if (roomReturn == "driveway"){
                         choice = 7;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 8;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
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
						 newline = true;
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
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;
                    int wolfRet;

                    //intialize objects
                    Dog dog;
                    MsWolf msWolf;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomGarden, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "ms.wolf"){
                         choice = 1;
                    }
                    else if (roomReturn == "dog"){
                         choice = 2;
                    }
                    else if (roomReturn == "driveway"){
                         choice = 3;
                    }
                    else if (roomReturn == "deck"){
                         choice = 4;
                    }
                    else if (roomReturn == "cellar"){
                         choice = 5;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 6;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         wolfRet = msWolf.conversate(inventory_Map);
                         //if 1 returned game over
                         if (wolfRet == 1){
                              moving = true;
                         }
			 newline = true;
                         choice = 0;
                         break;
                    case 2:
                         dog.dogInteract(inventory_Map);
			 newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nWalking around the mansion to the driveway.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 1;
                         break;
                    case 4:
                         std::cout << "\nWalking up to the deck.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 13;
                         break;
                    case 5:
                         std::cout << "\nGoing down into the cellar.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 10;
                         break;
                    case 6:
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

          case 4:
               //Navigate the Study
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    Computer computer;
                    MrGreen mrGreen;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomStudy, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "computer"){
                         choice = 1;
                    }
                    else if (roomReturn == "mr.green"){
                         choice = 2;
                    }
                    else if (roomReturn == "library"){
                         choice = 3;
                    }
                    else if (roomReturn == "billiards room"){
                         choice = 4;
                    }
                    else if (roomReturn == "hallway"){
                         choice = 5;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 6;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         computer.checkComputer(inventory_Map);
			 newline = false;
                         choice = 0;
                         break;
                    case 2:
                         mrGreen.conversate(inventory_Map);
			 newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nWalking into the Library.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 11;
                         break;
                    case 4:
                         std::cout << "\nWalking out into the Billiards Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 7;
                         break;
                    case 5:
                         std::cout << "\nGoing upstairs into the Hallway.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 14;
                         break;
                    case 6:
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
	  
          case 5:
               //Navigate the Sitting Room
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    Couch couch;
                    MrsDeeds mrsDeeds;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomSitting, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "couch"){
                         choice = 1;
                    }
                    else if (roomReturn == "mrs.deeds"){
                         choice = 2;
                    }
                    else if (roomReturn == "smoking room"){
                         choice = 3;
                    }
                    else if (roomReturn == "foyer"){
                         choice = 4;
                    }
		    else if (roomReturn == "ballroom"){
                         choice = 5;
                    }
		    else if (roomReturn == "sleep on couch"){
                         choice = 6;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 7;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         couch.checkCouch(inventory_Map);
			 newline = true;
                         choice = 0;
                         break;

                    case 2:
                         mrsDeeds.conversate(inventory_Map);
			 newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nWalking into the Smoking Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 6;
                         break;
                    case 4:
                         std::cout << "\nWalking out into the Foyer.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 2;
                         break;
                    case 5:
                         std::cout << "\nGoing into the Ballroom.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 16;
                         break;
					case 6:
						couch.takeNap();
						choice = 0;
						break;
                    case 7:
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
	  
          case 6:
               //Navigate the Smoking Room
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    RecliningChair recliningChair;
                    Painting painting;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomSmoking, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "recliningchair"){
                         choice = 1;
                    }
                    else if (roomReturn == "painting"){
                         choice = 2;
                    }
                    else if (roomReturn == "kitchen"){
                         choice = 3;
                    }
                    else if (roomReturn == "sitting room"){
                         choice = 4;
                    }
                    else if (roomReturn == "billiards room"){
                         choice = 5;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 6;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         recliningChair.checkRecliningChair(inventory_Map);
				//		 newline = true;
                         choice = 0;
                         break;
                    case 2:
                         painting.checkPainting(inventory_Map);
				//		 newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nGoing into the Kitchen.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 9;
                         break;
                    case 4:
                         std::cout << "\nGoing into the Sitting Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 5;
                         break;
                    case 5:
                         std::cout << "\nWalking into the Billiards Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 7;
                         break;
                    case 6:
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

          case 7:
               //Navigate the Billiards Room
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    PoolTable poolTable;
                    CoffeeTable coffeeTable;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomBilliards, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "pooltable"){
                         choice = 1;
                    }
                    else if (roomReturn == "coffeetable"){
                         choice = 2;
                    }
                    else if (roomReturn == "deck"){
                         choice = 3;
                    }
                    else if (roomReturn == "study"){
                         choice = 4;
                    }
                    else if (roomReturn == "smoking room"){
                         choice = 5;
                    }
                    else if (roomReturn == "ballroom"){
                         choice = 6;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 7;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         poolTable.checkTable(inventory_Map);
				//		 newline = true;
                         choice = 0;
                         break;
                    case 2:
                         coffeeTable.checkCoffeeTable(inventory_Map);
				//		 newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nGoing out to the Deck.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 13;
                         break;
                    case 4:
                         std::cout << "\nWalking into the Study.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 4;
                         break;
                    case 5:
                         std::cout << "\nWalking into the Smoking Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 6;
                         break;
                    case 6:
                         std::cout << "\nWalking into the Ballroom.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 16;
                         break;
                    case 7:
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
	
          case 8:
               //Navigate the Dining Room
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    DiningTable diningTable;
                    Parrot parrot;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomDining, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "diningtable"){
                         choice = 1;
                    }
                    else if (roomReturn == "parrot"){
                         choice = 2;
                    }
                    else if (roomReturn == "deck"){
                         choice = 3;
                    }
                    else if (roomReturn == "kitchen"){
                         choice = 4;
                    }
                    else if (roomReturn == "foyer"){
                         choice = 5;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 6;
                    }
                    else{
                         //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
                         std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         diningTable.checkDiningTable(inventory_Map);
						 newline = false;
                         choice = 0;
                         break;
                    case 2:
                         parrot.convoParrot(inventory_Map);
						 newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nGoing out to the Deck.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 13;
                         break;
                    case 4:
                         std::cout << "\nWalking into the Kitchen.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 9;
                         break;
                    case 5:
                         std::cout << "\nGoing into the Foyer.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 2;
                         break;
                    case 6:
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
	 
          case 9:
               //Navigate the Kitchen
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    KnifeBlock knifeBlock;
                    Refrigerator refrigerator;

					std::cout << Color::FG_DEFAULT << std::endl;
					
                    roomReturn = roomMenu(inventory_Map, roomKitchen, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "knifeblock"){
                         choice = 1;
                    }
                    else if (roomReturn == "refrigerator"){
                         choice = 2;
                    }
                    else if (roomReturn == "dining room"){
                         choice = 3;
                    }
                    else if (roomReturn == "cellar"){
                         choice = 4;
                    }
                    else if (roomReturn == "smoking room"){
                         choice = 5;
                    }
                    else if (roomReturn == "deck"){
                         choice = 6;
                    }
                    else if (roomReturn == "foyer"){
                         choice = 7;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 8;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         knifeBlock.checkKnifeBlock(inventory_Map);
						 //newline = false;
                         choice = 0;
                         break;
                    case 2:
                         refrigerator.checkFridge(inventory_Map);
						 //newline = false;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nEntering the Dining Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 8;
                         break;
                    case 4:
                         std::cout << "\nEntering the Cellar.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 10;
                         break;
                    case 5:
                         std::cout << "\nEntering the Smoking Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 6;
                         break;
                    case 6:
                         std::cout << "\nGoing outside to the Deck.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 13;
                         break;
                    case 7:
                         std::cout << "\nEntering the Foyer.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 2;
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
	 
          case 10:
               //Navigate the Cellar
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    Dresser dresser;
                    Box box;

					std::cout << Color::FG_DEFAULT << std::endl;
					
                    roomReturn = roomMenu(inventory_Map, roomCellar, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "dresser"){
                         choice = 1;
                    }
                    else if (roomReturn == "box"){
                         choice = 2;
                    }
                    else if (roomReturn == "garden"){
                         choice = 3;
                    }
                    else if (roomReturn == "kitchen"){
                         choice = 4;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 5;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         dresser.checkDresser(inventory_Map);
						 //newline = true;
                         choice = 0;
                         break;
                    case 2:
                         box.checkBox(inventory_Map);
						 //newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nGoing out to the Garden.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 3;
                         break;
                    case 4:
                         std::cout << "\nGoing up to the Kitchen.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 9;
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
	 
          case 11:
               //Navigate the Library
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //get return from shelf
                    int shelfRet;

                    //intialize objects
                    BookShelf bookShelf;
                    Desk desk;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomLibrary, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "bookshelf"){
                         choice = 1;
                    }
                    else if (roomReturn == "desk"){
                         choice = 2;
                    }
                    else if (roomReturn == "ballroom"){
                         choice = 3;
                    }
                    else if (roomReturn == "study"){
                         choice = 4;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 5;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         shelfRet = bookShelf.checkBookShelf(inventory_Map);
                         //if 1 returned go to secret room
                         if (shelfRet == 1){
                              choice = 12;
                         }
                         else{
				//			 newline = true;
                              choice = 0;
                         }
                         break;
                    case 2:
                         desk.checkDesk(inventory_Map);
				//		 newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nGoing into the Ballroom.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 16;
                         break;
                    case 4:
                         std::cout << "\nGoing into the Study.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 4;
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
	 
          case 12:
               //Navigate the Secret Room
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //ret whether there is light
                    int retLight = 0;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomSecret, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "lightswitch"){
                         choice = 1;
                    }
                    else if (roomReturn == "safe"){
                         choice = 2;
                    }
                    else if (roomReturn == "library"){
                         choice = 3;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 4;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice) {
                    case 1:
                         if (lightSwitch.getBroken() == false) { //if room is lit
                              std::cout << "\n\nYou already have a light source for the room to navigate around.\n\n";
                         }
                         else {
                              retLight = lightSwitch.checkLightSwitch(inventory_Map);
//							  newline = true;
                         }
                         //return 1 if new bulb in the inventory.. takes precedence over candle/match combo
                         if (retLight == 1) {
                              lightSwitch.setBroken(false);
                         }
                         else if (retLight == 2) { //return 2 if candle and match in the inventory
                              lightSwitch.setBroken(false);
                         }
                         choice = 0;
                         break;
                    case 2:
                         //if light or candle/match not in posession then can't navigate room
                         if (lightSwitch.getBroken() == false) {
                              safe.checkSafe(inventory_Map);
//							  newline = true;
                         }
                         else {
                              std::cout << "\nIt's too dark in the room for you to navigate around.\n\n" <<
                                   "Maybe you can turn the light on or find a source of light?\n\n";
                         }
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nGoing into the Library.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 11;
                         break;
                    case 4:
                         std::cout << "\n\nInventory contains: \n\n";
                         int c = 1;
                         for (auto it = inventory_Map.begin(); it != inventory_Map.end(); ++it) {
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
	 
          case 13:
               //Navigate the Deck               
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;                                 
					int start_row = 4;
					int start_column = 4;
					int i;
					int speed;

                    //intialize objects
                    Chair chair;
                    HotTub hotTub;
					
					std::cout << Color::FG_DEFAULT << std::endl;
		   
                    roomReturn = roomMenu(inventory_Map, roomDeck, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "chair"){
                         choice = 1;
                    }
                    else if (roomReturn == "hottub"){
                         choice = 2;
                    }
                    else if (roomReturn == "dining room"){
                         choice = 3;
                    }
                    else if (roomReturn == "billiards room"){
                         choice = 4;
                    }
                    else if (roomReturn == "kitchen"){
                         choice = 5;
                    }
                    else if (roomReturn == "garden"){
                         choice = 6;
                    }
					else if (roomReturn == "get in hottub"){
                         choice = 7;
                    }

                    else if (roomReturn == "inventory"){
                         choice = 8;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }


                    if ((dry != true) && (choice == 3 || choice == 4 || choice == 5 || choice == 6)){
                         std::cout << "\n\nSherlock appears to be wet from messing around in the hot tub.\n\n";

                         //check if towel is already in inventory
                         auto search = inventory_Map.find("towel");
                         if (search != inventory_Map.end()){
                              std::cout << "\nLooks like you have a towel in your inventory. Dry off?\n\n";

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
                                   dry = true;
                                   std::cout << "\nOkay, he's dried off. He can now leave the room.\n\n";
                              }
                              else{
                                   std::cout << "\nOkay, not dried off, but he will need to dry off before leaving the deck.\n\n";
                                   //skip the option to leave
                                   choice = 0;
                              }
                         }
                         else{
                              std::cout << "\nSherlock can't leave the deck without drying off! Perhaps there is a towel somewhere around here ...\n\n";
                              //skip the option to leave
                              choice = 0;
                         }
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 0: //is user is wet can't leave
                         break;
                    case 1:
                         chair.checkChair(inventory_Map);
						 newline = false;
                         choice = 0;
                         break;
                    case 2:
                         hotTub.setWet(hotTub.checkHotTub(inventory_Map));
                         //if sherlock gets wet he will have to get the towel to dry off before leaving
                         if (hotTub.getWet() == "yes")
                         {
                              dry = false;
                         }
						 newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nEntering the Dining Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 8;
                         break;
                    case 4:
                         std::cout << "\nEntering the Billiards Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 7;
                         break;
                    case 5:
                         std::cout << "\nEntering the Kitchen.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 9;
                         break;
                    case 6:
                         std::cout << "\nWalking Out to the Garden.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 3;
                         break;
					case 7:
					   std::cout << "\nYou: \"Lovely night for a dip I say ... \"\n\n";
					   
					   //animation of dripping clothes
					   initscr();
					   printSherlock(start_row, start_column);
					   for (i = 0; i < 19; i++)
					   {
							printDrops1(start_row, start_column);
							refresh();
							eraseDrops1(start_row, start_column);
							start_row = start_row + 1;
							for (speed = 1; speed <= 56000000; speed++);
					   }
					   refresh();
					   for (speed = 1; speed <= 5500000; speed++);
					   start_row = start_row - 19;
					   for (i = 0; i < 19; i++)
					   {
							printDrops2(start_row, start_column);
							refresh();
							eraseDrops2(start_row, start_column);
							start_row = start_row + 1;
							for (speed = 1; speed <= 56000000; speed++);
					   }
					   refresh();
					   for (speed = 1; speed <= 5500000; speed++);
					   start_row = start_row - 19;
					   for (i = 0; i < 19; i++)
					   {
							printDrops1(start_row, start_column);
							refresh();
							eraseDrops1(start_row, start_column);
							start_row = start_row + 1;
							for (speed = 1; speed <= 56000000; speed++);
					   }
					   getch();
					   endwin();
					   
					   std::cout << "You are now all wet. Maybe not the greatest idea.\n\n";
					   dry = false;
					   hotTub.setWet("yes");
					   choice = 0;
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
                    if (choice == 3 || choice == 7 || choice == 8 || choice == 9){
                         moving = true;
                    }
                    returnedNavChoice = choice;
		    
               } while (!moving);
               break;
	  
          case 14:
               //Navigate the Hallway
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

		    int trySpiderRet = 0;

                    //intialize objects
                    Shelf shelf;
                    EndTable endTable;

					std::cout << Color::FG_DEFAULT << std::endl;
					
                    roomReturn = roomMenu(inventory_Map, roomHallway, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "shelf"){
                         choice = 1;
                    }
                    else if (roomReturn == "endtable"){
                         choice = 2;
                    }
                    else if (roomReturn == "foyer"){
                         choice = 3;
                    }
                    else if (roomReturn == "study"){
                         choice = 4;
                    }
                    else if (roomReturn == "bedroom"){
                         choice = 5;
                    }
                    else if (roomReturn == "servants room"){
                         choice = 6;
                    }
                    else if (roomReturn == "attic"){
                         choice = 7;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 8;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         trySpiderRet = shelf.checkShelf(inventory_Map);
			
			 if(trySpiderRet == 1){
				newline = true;
			 }
             		 
                         choice = 0;
                         break;
                    case 2:
                         endTable.checkEndTable(inventory_Map);
				//		 newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nGoing down to the Foyer.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 2;
                         break;
                    case 4:
                         std::cout << "\nGoing down into the Study.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 4;
                         break;
                    case 5:
                         std::cout << "\nWalking into the Bedroom.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 15;
                         break;
                    case 6:
                         std::cout << "\nWalking into the Servants Quarters.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 17;
                         break;
                    case 7:
                         std::cout << "\nGoing up to the Attic.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 20;
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
	 
          case 15:
               //Navigate the Bedroom
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    Bed bed;
                    Body body;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomBedroom, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;

					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;
					
                    //logic to check against parsed input
                    if (roomReturn == "body"){
                         choice = 1;
                    }
                    else if (roomReturn == "bed"){
                         choice = 2;
                    }
                    else if (roomReturn == "bathroom"){
                         choice = 3;
                    }
                    else if (roomReturn == "hallway"){
                         choice = 4;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 5;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         body.checkBody(inventory_Map);
				//		 newline = true;
                         choice = 0;
                         break;
                    case 2:
                         bed.checkBed(inventory_Map);
				//		 newline = true;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nGoing into the Bathroom.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 19;
                         break;
                    case 4:
                         std::cout << "\nWalking into the Hallway.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 14;
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
	  
          case 16:
               //Navigate the Ballroom
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    Piano piano;
                    Bar bar;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomBallroom, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "piano"){
                         choice = 1;
                    }
                    else if (roomReturn == "bar"){
                         choice = 2;
                    }
                    else if (roomReturn == "billiards room"){
                         choice = 3;
                    }
                    else if (roomReturn == "library"){
                         choice = 4;
                    }
                    else if (roomReturn == "sitting room"){
                         choice = 5;
                    }
					else if (roomReturn == "play piano") {
					 choice = 6;
					}
                    else if (roomReturn == "inventory"){
                         choice = 7;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         piano.checkPiano(inventory_Map);
						 newline = true;
                         choice = 0;
                         break;
                    case 2:
                         bar.checkBar(inventory_Map);
						 newline = false;
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nGoing out to the Billiards Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 7;
                         break;
                    case 4:
                         std::cout << "\nWalking into the Library.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 11;
                         break;
                    case 5:
                         std::cout << "\nWalking into the Sitting Room.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 5;
                         break;
					case 6:
						piano.playPiano();
						choice = 0;
						break;
                    case 7:
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
	
          case 17:
               //Navigate the Servants Room
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    Trash trash;
                    MrsWhite mrsWhite;

					std::cout << Color::FG_DEFAULT << std::endl;
					
                    roomReturn = roomMenu(inventory_Map, roomServants, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "trash"){
                         choice = 1;
                    }
                    else if (roomReturn == "mrs.white"){
                         choice = 2;
                    }
                    else if (roomReturn == "hallway"){
                         choice = 3;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 4;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         trash.checkTrash(inventory_Map);
						newline = false;
                         choice = 0;
                         break;
                    case 2:
                         mrsWhite.conversate(inventory_Map);
						 newline = true;
                         choice = 0;
                         break;

                    case 3:
                         std::cout << "\nWalking into the Hallway.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 14;
                         break;
                    case 4:
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
	  
          case 18:
                //Navigate the Balcony
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    FoldingTable foldingTable;
                    MrDeeds mrDeeds;

					std::cout << Color::FG_DEFAULT << std::endl;
					
                    roomReturn = roomMenu(inventory_Map, roomBalcony, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "foldingtable"){
                         choice = 1;
                    }
                    else if (roomReturn == "mr.deeds"){
                         choice = 2;
                    }
                    else if (roomReturn == "attic"){
                         choice = 3;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 4;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         foldingTable.checkTable(inventory_Map);
						 newline = false;
                         choice = 0;
                         break;
                    case 2:
                         mrDeeds.conversate(inventory_Map);
						 newline = true;
                         choice = 0;
                         break;

                    case 3:
                         std::cout << "\nWalking into the Attic.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 20;
                         break;
                    case 4:    
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

          case 19:
               //Navigate the Bathroom
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    Cabinet cabinet;
                    Bath bath;
					
					std::cout << Color::FG_DEFAULT << std::endl;

                    roomReturn = roomMenu(inventory_Map, roomBathroom, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "bath"){
                         choice = 1;
                    }
                    else if (roomReturn == "cabinet"){
                         choice = 2;
                    }
                    else if (roomReturn == "bedroom"){
                         choice = 3;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 4;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         bath.checkBath(inventory_Map);
                         choice = 0;
                         break;
                    case 2:
                         cabinet.checkCabinet(inventory_Map);
                         choice = 0;
                         break;
                    case 3:
                         std::cout << "\nGoing into the Bedroom.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 15;
                         break;
                    case 4:
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

          case 20:
               //Navigate the Attic
               do{
                    //set moving to false
                    moving = false;

                    //variables
                    std::string ans;
                    //choice from player
                    int choice = 0;

                    //intialize objects
                    NightStand nightStand;
                    MrGlass mrGlass;

					//change text color
					std::cout << Color::FG_DEFAULT << std::endl;
					
                    roomReturn = roomMenu(inventory_Map, roomAttic, newline);
                    //returnedNavChoice = foyerNavigate(inventory_Map, roomReturn);
					
					std::cout << Color::FG_GREEN << std::endl;
					
					//set newline flag to false each iteration
					//this avoids a true flag staying set
					newline = false;

                    //logic to check against parsed input
                    if (roomReturn == "nightstand"){
                         choice = 1;
                    }
                    else if (roomReturn == "mr.glass"){
                         choice = 2;
                    }
                    else if (roomReturn == "hallway"){
                         choice = 3;
                    }
                    else if (roomReturn == "balcony"){
                         choice = 4;
                    }
                    else if (roomReturn == "inventory"){
                         choice = 5;
                    }
                    else{
                          //std::cout << "\n\nERROR: input was " << roomReturn << "\n\n";
						 std::cout << Color::FG_RED << std::endl;
						 std::cout << "\n\nPlease enter a properly formatted choice from the menu of options.\n\n";
						 std::cout << Color::FG_DEFAULT << std::endl;
                    }

                    //take users choice and interact based on that
                    switch (choice){
                    case 1:
                         nightStand.checkStand(inventory_Map);
						 newline = false;
                         choice = 0;
                         break;
                    case 2:
                         mrGlass.conversate(inventory_Map);
						 newline = true;
                         choice = 0;
                         break;

                    case 3:
                         std::cout << "\nGoing down into the Hallway.\n";
                         //change choice to reflect our room mapping and update move 
						 choice = 14;
                         break;
                    case 4:
                         std::cout << "\nWalking out onto the Balcony.\n";
                         //change choice to reflect our room mapping and update move
                         choice = 18;
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

          }


     } while (!gameOver);
		
	std::cout << Color::FG_DEFAULT << std::endl;
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
