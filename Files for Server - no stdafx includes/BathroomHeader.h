/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/30/16
* Last Modification Date:	     5/30/16
* Filename:					BathroomHeader.h
*
* Overview:
*	This file is the header file for Bathroom objects and iteraction of objects.
*
******************************/
//define header
#ifndef BathroomHeader_h
#define BathroomHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Bathroom Class
class RoomBathroom
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"bedroom"} };
     std::vector<std::string> objects{ std::vector<std::string>{"cabinet", "bath"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomBathroom()
     {
          this->name = "The Bathroom";
          this->numRooms = 1;
          this->numObjects = 2;
          this->description = "You are in the Bathroom.\n\nIn this room you see a sizable bath tub and a fancy vanity cabinet which you can open and inspect.\n\nThe Toilet and sink look to be in order without traces of anything interesting.\n\n";
     }

     //Virtual Destructor
     virtual ~RoomBathroom()
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


//Cabinet Object
class Cabinet
{
private:

protected://protected member variables.
     std::string description;
     std::string lightBulb;

public:
     //default constructor
     Cabinet()
     {
          this->description = "A silver metallic bathroom cabinet with a mirror above it.";
          this->lightBulb = "an unused light bulb";

     }

     //Virtual Destructor
     virtual ~Cabinet()
     {}

     //member function to check dining table
     void checkCabinet(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getLightBulb() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

	 void setLightBulb(const std::string theLightBulb);

};


//Bath
class Bath
{
private:

protected://protected member variables.
     std::string ducky;
     std::string soap;
     std::string description;
     std::string takeBath;

public:
     //default constructor
     Bath()
     {
          this->ducky = "rubber ducky";
          this->soap = "bar of soap";
          this->description = "A jacuzzi style white porcelain bath tub, with no signs of foul play.";
          this->takeBath = "\n\nYou may want to take a dip out in the hot tub on the deck and not in the victims bath tub.\n\n";
     }

     //Virtual Destructor
     virtual ~Bath()
     {}


     //member function to get into the trunk
     void checkBath(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDucky() const;

     std::string getSoap() const;

     std::string getDescription() const;

	 std::string getTakeBath() const;

     //Mutator Functions to change private variables.
     void setDucky(const std::string ducky);

     void setSoap(const std::string soap);

     void setDescription(const std::string theDescription);

	 void setTakeBath(const std::string takeBath);

};

#endif
