/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/24/16
* Last Modification Date:	5/24/16
* Filename:				DeckHeader.h
*
* Overview:
*	This file is the header file for Deck objects and iteraction of objects.
*
******************************/
//define header
#ifndef DeckHeader_h
#define DeckHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Deck Class
class RoomDeck
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"dining", "billiards", "kitchen", "garden"} };
     std::vector<std::string> objects{ std::vector<std::string>{"chair", "hottub"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomDeck()
     {
          this->name = "The Deck";
          this->numRooms = 4;
          this->numObjects = 2;
          this->description = "You are on the Deck outside of the Mansion.\n\nLooking around, there is a Chair you may want to take a look at (Enter \"chair\").\n\nThere is also a hot tub you may examine more closely (Enter \"hot tub\").\n\n";

     }

     //Virtual Destructor
     virtual ~RoomDeck()
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

//Chair Class
class Chair
{
private:

protected://protected member variables.
     std::string color;
     int numBirds;
     std::string towel;

public:
     //default constructor
     Chair()
     {
          this->color = "Redwood Cherry";
          this->numBirds = 3;
          this->towel = "towel";
     }

     //Virtual Destructor
     virtual ~Chair()
     {}


     //member function to output information provided of each item
     void chairInformation(std::unordered_map<std::string, std::string>& inv);

     //member function to get into the trunk
     void checkChair(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getColor() const;

     int getNumBirds() const;

     std::string getTowel() const;

     //Mutator Functions to change private variables.
     void setColor(const std::string theColor);

     void setNumBirds(const int theNumBirds);

     void setTowel(const std::string theTowel);

};


//Hot Tub Class
class HotTub
{
private:

protected://protected member variables.
     std::string hair;
     std::string description;
     std::string wet;

     //tomorrow.. maybe get wet and need the towel.. even maybe get wet and lose an inventory item?

public:
     //default constructor
     HotTub()
     {
          this->hair = "Long Black hair";
          this->description = "A luxurious gold trim 8 person hot tub with a champagne fountain on one end.";
          this->wet = "no";
     }

     //Virtual Destructor
     virtual ~HotTub()
     {}


     //member function to output information provided of each item
     void hotTubInformation();

     //member function to get into the trunk
     std::string checkHotTub(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getHair() const;

     std::string getDescription() const;

     std::string getWet() const;

     //Mutator Functions to change private variables.
     void setHair(const std::string theHair);

     void setDescription(const std::string theDescription);

     void setWet(const std::string theWet);

};


#endif