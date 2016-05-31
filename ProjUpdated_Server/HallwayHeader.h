/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/24/16
* Last Modification Date:	5/24/16
* Filename:				HallwayHeader.h
*
* Overview:
*	This file is the header file for Hallway Room objects and iteraction of objects.
*
******************************/
//define header
#ifndef HallwayHeader_h
#define HallwayHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

//Room Hallway Class
class RoomHallway
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"foyer", "study", "bedroom", "servants room", "attic" } };
     std::vector<std::string> objects{ std::vector<std::string>{"shelf", "endtable"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomHallway()
     {
          this->name = "The Hallway";
          this->numRooms = 5;
          this->numObjects = 2;
          this->description = "You are in the upstairs Hallway.\n\nLooking around, you see a Shelf on the wall and also see an end table along the hall. You may want to take a closer look at these items.\n\n";
     }

     //Virtual Destructor
     virtual ~RoomHallway()
     {}


     //Accessor Functions for accessing private variables.
     std::string getName() const;

     int getNumRooms() const;

     int getNumObjects() const;

     std::vector<std::string> getExits() const;

     std::vector<std::string> getObjects() const;

     std::string getDescription() const;

     //Mutator Functions to change private variables.
     void setName(const std::string theName);

     void setNumRooms(const int theNumRooms);

     void setNumObjects(const int theNumObjects);

     void setExits(const std::vector<std::string> theExits);

     void setObjects(const std::vector<std::string> theObjects);

     void setDescription(const std::string theDescription);

};

//Shelf Object
class Shelf
{
private:

protected://protected member variables.
     std::string description;
     std::string spider;
     bool dead;
     std::string candle;

public:
     //default constructor
     Shelf()
     {
          this->description = "A recessed shelf in the hallway with an arching top that could only hold a small item or two.";
          this->spider = "spider";
          this->dead = false;
          this->candle = "candle";

     }

     //Virtual Destructor
     virtual ~Shelf()
     {}

     //member function
     void checkShelf(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getSpider() const;

     bool getDead() const;

     std::string getCandle() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setSpider(const std::string theSpider);

     void setDead(const bool theDead);

     void setCandle(const std::string theCandle);

};


//End Table
class EndTable
{
private:

protected://protected member variables.
     std::string mirror;
     std::string description;
     std::string sculpture;

public:
     //default constructor
     EndTable()
     {
          this->mirror = "\n\nYou look in the mirror and see it has been a while since your last shave. Not a pretty site. Otherwise nothing stands out.";
          this->description = "A victorian style white end table about 4 feet off the ground with a mirror above it and sculpture on it.";
          this->sculpture = "sculpture of a wolf";

     }

     //Virtual Destructor
     virtual ~EndTable()
     {}


     //member function
     void checkEndTable(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getMirror() const;

     std::string getDescription() const;

     std::string getSculpture() const;

     //Mutator Functions to change private variables.
     void setMirror(const std::string theMirror);

     void setDescription(const std::string theDescription);

     void setSculpture(const std::string theSculpture);

};


//navigation function to handle game play while the player is in the hallway room
int hallwayNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif
