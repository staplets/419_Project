/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/18/16
* Last Modification Date:	4/19/16
* Filename:				CellarHeader.h
*
* Overview:
*	This file is the header file for Cellar objects and iteraction of objects.
*
******************************/
//define header
#ifndef CellarHeader_h
#define CellarHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Cellar Class
class RoomCellar
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"garden", "kitchen"} };
     std::vector<std::string> objects{ std::vector<std::string>{"dresser", "box"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomCellar()
     {
          this->name = "The Cellar";
          this->numRooms = 2;
          this->numObjects = 2;
          this->description = "You are in the Cellar.\n\nLooking around, you see a Dresser in the corner and a Box in the other far corner that may be worth a look.\n\n";
     }

     //Virtual Destructor
     virtual ~RoomCellar()
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

//Dresser Object
class Dresser
{
private:

protected://protected member variables.
     std::string material;
     int numDrawers;
     std::string dogTreat;

public:
     //default constructor
     Dresser()
     {
          this->material = "Mahogany Cedar";
          this->numDrawers = 4;
          this->dogTreat = "dog treats";

     }

     //Virtual Destructor
     virtual ~Dresser()
     {}

     //member function to get into the trunk
     void checkDresser(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getMaterial() const;

     int getNumDrawers() const;

     std::string getDogTreat() const;

     //Mutator Functions to change private variables.
     void setMaterial(const std::string theMaterial);

     void setNumDrawers(const int theNumDrawers);

     void setDogTreat(const std::string theDogTreat);

};


//Box Class
class Box
{
private:

protected://protected member variables.
     std::string pictures;
     std::string bowlingBall;
     std::string description;

public:
     //default constructor
     Box()
     {
          this->pictures = "pictures of Mr. Glass with Mr. Cunningham as a child";
          this->bowlingBall = "bowling ball";
          this->description = "A 3 foot by 3 foot cardboard box.";

     }

     //Virtual Destructor
     virtual ~Box()
     {}


     //member function to output information provided of each item
     void boxInformation();

     //member function to get into the trunk
     void checkBox(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getPictures() const;

     std::string getBowlingBall() const;

     std::string getDescription() const;

     //Mutator Functions to change private variables.
     void setPictures(const std::string thePictures);

     void setBowlingBall(const std::string theBowlingBall);

     void setDescription(const std::string theDescription);

};

#endif
