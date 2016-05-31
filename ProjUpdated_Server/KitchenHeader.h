/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/22/16
* Last Modification Date:	5/22/16
* Filename:				KitchenHeader.h
*
* Overview:
*	This file is the header file for Kitchen objects and iteraction of objects.
*
******************************/
//define header
#ifndef KitchenHeader_h
#define KitchenHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Kitchen Class
class RoomKitchen
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"dining room", "cellar", "smoking room", "deck", "foyer"} };
     std::vector<std::string> objects{ std::vector<std::string>{"knifeblock", "refrigerator"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomKitchen()
     {
          this->name = "The Kitchen";
          this->numRooms = 5;
          this->numObjects = 2;
          this->description = "You are in the Kitchen.\n\nLooking around, you see a knife block and refrigerator (you can open the refrigerator door) that may be worth checking out.\n\n";
     }

     //Virtual Destructor
     virtual ~RoomKitchen()
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

//Knife Block Object
class KnifeBlock
{
private:

protected://protected member variables.
     std::string material;
     int numKnives;
     std::string knife;

public:
     //default constructor
     KnifeBlock()
     {
          this->material = "Beech Tree Wood";
          this->numKnives = 1;
          this->knife = "Knife";

     }

     //Virtual Destructor
     virtual ~KnifeBlock()
     {}
     
     //member function to get into the trunk
     void checkKnifeBlock(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getMaterial() const;

     int getNumKnives() const;

     std::string getKnife() const;

     //Mutator Functions to change private variables.
     void setMaterial(const std::string theMaterial);

     void setNumKnives(const int theNumKnives);

     void setKnife(const std::string theKnife);

};


//Refrigerator Class
class Refrigerator
{
private:

protected://protected member variables.
     std::string steak;
     std::string pie;
     std::string description;

public:
     //default constructor
     Refrigerator()
     {
          this->steak = "steak";
          this->pie = "piece of Blueberry Pie";
          this->description = "A silver refrigerator with black trimming. Fit for a king.";

     }

     //Virtual Destructor
     virtual ~Refrigerator()
     {}


     //member function to output information provided of each item
     void fridgeInformation();

     //member function to get into the trunk
     void checkFridge(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getSteak() const;

     std::string getPie() const;

     std::string getDescription() const;

     //Mutator Functions to change private variables.
     void setSteak(const std::string theSteak);

     void setPie(const std::string thePie);

     void setDescription(const std::string theDescription);

};

#endif
