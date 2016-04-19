/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/19/16
* Last Modification Date:	4/19/16
* Filename:				GardenHeader.h
*
* Overview:
*	This file is the header file for garden objects.
*
******************************/
/*
//define header
#ifndef GardenHeader_h
#define GardenHeader_h

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

//Luxury Car Class
class Dog
{
private:

protected://protected member variables.
     std::string color;
     int doors;
     std::string model;
     std::string wineBottle;

public:
     //default constructor
     Dog()
     {
          this->color = "Silver";
          this->doors = 2;
          this->model = "Porsche";
          this->wineBottle = "Wine Bottle of Beaujolais";

     }

     //Virtual Destructor
     virtual ~Dog()
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

//Miss Wolf Class
class MsWolf
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
     MsWolf()
     {
          this->knowMurderer = "\nSir, I haven't a clue what those yuppies do in there. You should leave my wife out of this too because she doesn't get mixed up with their kind.";
          this->doingTonight = "\nI've been up to my usual routine clipping these bushes here and keeping the plants watered.";
          this->age = 55;
          this->wife = "Eleanor";
          this->jobDescription = "\nI work here with my wife around the place doing landscaping while she takes care of the inside of the house.";
          this->description = "Middle aged white male. About 6'1. Brown hair. Torn jeans at the knees, a dirty green shirt and leathery skin from the sun's rays.";

     }

     //Virtual Destructor
     virtual ~MsWolf()
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

//navigation function to handle game play while the player is in the driveway
int gardenNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif
*/