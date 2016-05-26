/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/24/16
* Last Modification Date:	     5/25/16
* Filename:					BedroomHeader.h
*
* Overview:
*	This file is the header file for Bedroom objects and iteraction of objects.
*
******************************/
//define header
#ifndef BedroomHeader_h
#define BedroomHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Bedroom Class
class RoomBedroom
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"bathroom", "hallway"} };
     std::vector<std::string> objects{ std::vector<std::string>{"bed", "body"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomBedroom()
     {
          this->name = "The Bedroom";
          this->numRooms = 2;
          this->numObjects = 2;
          this->description = "You are in the Bedroom.\n\nThe body of Willie Cunningham lies on the bed in the middle of the room.\n\nOtherwise the room looks to be in pristine condition.\n\nAny of the evidence in this room is either on the body or the bed of which he lies.\n\nAdditionally the bedroom leads to it's own personal bathroom.\n\nExamine the body? (Enter \"body\").\n\nExamine the bed? (Enter \"bed\").\n\n";
     }

     //Virtual Destructor
     virtual ~RoomBedroom()
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

//Bed Object
class Bed
{
private:

protected://protected member variables.
     std::string description;
     std::string pen;

public:
     //default constructor
     Bed()
     {
          this->description = "An elegant King bed with a golden European style bed frame.";
          this->pen = "pen inscribed with the word \'Beaujolais\'";

     }

     //Virtual Destructor
     virtual ~Bed()
     {}

     //member function to check dining table
     void checkBed(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getPen() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setPen(const std::string thePen);

};


//Body
class Body
{
private:

protected://protected member variables.
     std::string grape;
     std::string pulse;
     std::string description;
     std::string descriptionTwo;
     std::string descriptionThree;

public:
     //default constructor
     Body()
     {
          this->grape = "Gamay Grape";
          this->pulse = "\n\nYou check the vitals and find no pulse.\n\n";
          this->description = "\n\nThere are no signs of strangulation or suicide.\n\nMr. Cunningham has dried blood around his nose and mouth. He is a caucasian male in his mid twenties.\n\n";
          this->descriptionTwo = "He is dressed in a tan sports jacket and brown pants.\n\nIt appears as though he had come into the room and passed away shortly after. He is still wearing his shoes.\n\n";
          this->descriptionThree = "You deduct that he has been poisoned, but how and why...\n\n";
     }

     //Virtual Destructor
     virtual ~Body()
     {}


     //member function to get into the trunk
     void checkBody(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getGrape() const;

     std::string getPulse() const;

     std::string getDescription() const;

     std::string getDescriptionTwo() const;

     std::string getDescriptionThree() const;

     //Mutator Functions to change private variables.
     void setGrape(const std::string theGrape);

     void setPulse(const std::string thePulse);

     void setDescription(const std::string theDescription);

     void setDescriptionTwo(const std::string theDescriptionTwo);

     void setDescriptionThree(const std::string theDescriptionThree);

};


#endif