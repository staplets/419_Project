/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/21/16
* Last Modification Date:	5/21/16
* Filename:				BilliardsHeader.h
*
* Overview:
*	This file is the header file for Billiards Room objects and iteraction of objects.
*
******************************/
//define header
#ifndef BilliardsHeader_h
#define BilliardsHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Billiards Class
class RoomBilliards
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"deck", "study", "smoking room", "ballroom"} };
     std::vector<std::string> objects{ std::vector<std::string>{"pooltable", "coffeetable"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomBilliards()
     {
          this->name = "The Billiards Room";
          this->numRooms = 4;
          this->numObjects = 2;
          this->description = "You are in the Billiards Room.\n\nLooking around, you see a Pool Table in the center of the room and in the corner of the room there is a coffee table. You may want a closer inspection of these items.\n\n";
     }

     //Virtual Destructor
     virtual ~RoomBilliards()
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

//Pool Table Object
class PoolTable
{
private:

protected://protected member variables.
     std::string description;
     std::string ball;
     std::string stick;

public:
     //default constructor
     PoolTable()
     {
          this->description = "Regulation sized green carpeted pool table with two pool sticks and a few pool balls on the table scattered.";
          this->ball = "pool ball";
          this->stick = "pool stick";

     }

     //Virtual Destructor
     virtual ~PoolTable()
     {}

     //member function to get into the trunk
     void checkTable(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getBall() const;

     std::string getStick() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setBall(const std::string theBall);

     void setStick(const std::string theStick);

};


//Coffee Table
class CoffeeTable
{
private:

protected://protected member variables.
     std::string brochure;
     std::string description;

public:
     //default constructor
     CoffeeTable()
     {
          this->brochure = "brochure for beaujolis wine vineyards with a URL address written on the inside";
          this->description = "A mocha colored wooden coffee table about 3 feet high with some reading material on top.";

     }

     //Virtual Destructor
     virtual ~CoffeeTable()
     {}


     //member function to get into the trunk
     void checkCoffeeTable(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getBrochure() const;

     std::string getDescription() const;

     //Mutator Functions to change private variables.
     void setBrochure(const std::string theBrochure);

     void setDescription(const std::string theDescription);

};

#endif
