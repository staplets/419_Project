/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/05/16
* Last Modification Date:	     5/06/16
* Filename:					BathroomHeader.h
*
* Overview:
*	This file is the header file for Bathroom objects and iteraction of objects.
*
******************************/
//define header
#ifndef BathroomHeader_h
#define BathroomHeader_h

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

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
          this->takeBath = "\n\nSherlock may want to take a dip out in the hot tub out on the deck and not in the victims bath tub.\n\n";
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


//navigation function to handle game play while the player is in the bathroom
int bathroomNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif