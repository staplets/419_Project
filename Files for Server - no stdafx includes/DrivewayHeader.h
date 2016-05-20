/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/12/16
* Last Modification Date:	4/12/16
* Filename:				DrivewayHeader.h
*
* Overview:
*	This file is the header file for driveway objects.
*
******************************/
//define header
#ifndef DrivewayHeader_h
#define DrivewayHeader_h
//#include "DrivewayHeader.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <vector>
#include <unordered_map>

//Room Driveway Class
class RoomDriveway
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"Foyer", "Garden"} };
     std::vector<std::string> objects{ std::vector<std::string>{"car", "mrWhite"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomDriveway()
     {
          this->name = "The Driveway";
          this->numRooms = 2;
          this->numObjects = 2;
          this->description = "You are in the driveway.\n\nThere is a fancy luxury car that you may want to take a look at (Enter \"car\").\n\nThere is also a man standing by the front of the driveway smoking a cigarette (To talk with him: Enter \"Talk Mr White\").\n\n";

     }

     //Virtual Destructor
     virtual ~RoomDriveway()
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

//Luxury Car Class
class LuxuryCar
{
private:

protected://protected member variables.
     std::string color;
     int doors;
     std::string model;
     std::string wineBottle;

public:
     //default constructor
     LuxuryCar()
     {
          this->color = "Silver";
          this->doors = 2;
          this->model = "Porsche";
          this->wineBottle = "Wine Bottle of Beaujolais";

     }
     /*
     //Overload Constructor
     LuxuryCar(std::string theColor, int theDoors, std::string theModel)
     {
          //Assign each 
          this->color = theColor;
          this->doors = theDoors;
          this->model = theModel;

     }*/

     //Virtual Destructor
     virtual ~LuxuryCar()
     {}


     //member function to output information provided of each item
     void carInformation();

     //member function to get into the trunk
     void openTrunk(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getColor() const;

     int getDoors() const;

     std::string getModel() const;

     std::string getWineBottle() const;

     //Mutator Functions to change private variables.
     void setColor(const std::string theType);

     void setDoors(const int theDoors);

     void setModel(const std::string theModel);

     void setWineBottle(const std::string theWineBottle);

};

//Mr White Class
class MrWhite
{
private:

protected://protected member variables.
     std::string knowMurderer;
     std::string doingTonight;
     int age;
     std::string wife;
     std::string jobDescription;
     std::string description;

public:
     //default constructor
     MrWhite()
     {
          this->knowMurderer = "\nSir, I haven't a clue what those yuppies do in there. You should leave my wife out of this too because she doesn't get mixed up with their kind.";
          this->doingTonight = "\nI've been up to my usual routine clipping these bushes here and keeping the plants watered.";
          this->age = 55;
          this->wife = "Eleanor";
          this->jobDescription = "\nI work here with my wife around the place doing landscaping while she takes care of the inside of the house.";
          this->description = "Middle aged white male. About 6'1. Brown hair. Torn jeans at the knees, a dirty green shirt and leathery skin from the sun's rays.";

     }

     //Virtual Destructor
     virtual ~MrWhite()
     {}


     //member function to output information provided of each item
     void personInformation(std::unordered_map<std::string, std::string>& inventory);

     //member function to get into the trunk
     void conversate(std::unordered_map<std::string, std::string>& inventory);

     //Accessor Functions for accessing private variables.
     std::string getKnowMurderer() const;

     std::string getDoingTonight() const;

     int getAge() const;

     std::string getWife() const;

     std::string getJobDescription() const;

     std::string getDescription() const;

     //Mutator Functions to change private variables.
     void setKnowMurderer(const std::string theKnowMurderer);

     void setDoingTonight(const std::string theDoingTonight);

     void setAge(const int theAge);

     void setWife(const std::string theWife);

     void setJobDescription(const std::string theJobDescription);

     void setDescription(const std::string theDescription);

};

#endif