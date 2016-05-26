/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/25/16
* Last Modification Date:	5/26/16
* Filename:				BallroomHeader.h
*
* Overview:
*	This file is the header file for Ballroom Room objects and iteraction of objects.
*
******************************/
//define header
#ifndef BallroomHeader_h
#define BallroomHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Ballroom Class
class RoomBallroom
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"billiards", "library", "sitting" } };
     std::vector<std::string> objects{ std::vector<std::string>{"piano", "bar"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomBallroom()
     {
          this->name = "The Ballroom";
          this->numRooms = 3;
          this->numObjects = 2;
          this->description = "You are in the Ballroom.\n\nLooking around, you see a Piano in the center of the room and along the side of the room, there is a Bar.\n\nExamine the Piano? (Enter \"piano\").\n\nGo over to look at the Bar? (Enter \"bar\").\n\n";
     }

     //Virtual Destructor
     virtual ~RoomBallroom()
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

//Piano Object
class Piano
{
private:

protected://protected member variables.
     std::string description;
     std::string notes;

public:
     //default constructor
     Piano()
     {
          this->description = "A black and white grand piano made for a maestro.";
          this->notes = "music notes";
     }

     //Virtual Destructor
     virtual ~Piano()
     {}

     //member function for piano
     void playPiano();

     //member function to get into the trunk
     void checkPiano(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getNotes() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setNotes(const std::string theNotes);

};


//Bar
class Bar
{
private:

protected://protected member variables.
     std::string alcohol;
     std::string description;
     int numDrinks;

public:
     //default constructor
     Bar()
     {
          this->alcohol = "Dom Perignon Champagne";
          this->description = "A 15 foot wide bar, with gold lining around a silver granite top.";
          this->numDrinks = 0;

     }

     //Virtual Destructor
     virtual ~Bar()
     {}


     //member function to get into the trunk
     void checkBar(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getAlcohol() const;

     std::string getDescription() const;

     int getNumDrinks() const;

     //Mutator Functions to change private variables.
     void setAlcohol(const std::string theAlcohol);

     void setDescription(const std::string theDescription);

     void setNumDrinks(const int theNumDrinks);

};

#endif