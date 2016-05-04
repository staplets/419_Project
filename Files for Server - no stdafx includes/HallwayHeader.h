/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/24/16
* Last Modification Date:	4/24/16
* Filename:				HallwayHeader.h
*
* Overview:
*	This file is the header file for Hallway Room objects and iteraction of objects.
*
******************************/
//define header
#ifndef HallwayHeader_h
#define HallwayHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

//Shelf Object
class Shelf
{
private:

protected://protected member variables.
     std::string description;
     std::string spider;
     bool dead;
     std::string candle;

public:
     //default constructor
     Shelf()
     {
          this->description = "A recessed shelf in the hallway with an arching top that could only hold a small item or two.";
          this->spider = "spider";
          this->dead = false;
          this->candle = "candle";

     }

     //Virtual Destructor
     virtual ~Shelf()
     {}

     //member function
     void checkShelf(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getSpider() const;

     bool getDead() const;

     std::string getCandle() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setSpider(const std::string theSpider);

     void setDead(const bool theDead);

     void setCandle(const std::string theCandle);

};


//End Table
class EndTable
{
private:

protected://protected member variables.
     std::string mirror;
     std::string description;
     std::string sculpture;

public:
     //default constructor
     EndTable()
     {
          this->mirror = "\n\nSherlock looks in the mirror and sees it has been a while since his last shave. Not a pretty site. Otherwise nothing stands out.";
          this->description = "A victorian style white end table about 4 feet off the ground with a mirror above it and sculpture on it.";
          this->sculpture = "sculpture of a wolf";

     }

     //Virtual Destructor
     virtual ~EndTable()
     {}


     //member function
     void checkEndTable(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getMirror() const;

     std::string getDescription() const;

     std::string getSculpture() const;

     //Mutator Functions to change private variables.
     void setMirror(const std::string theMirror);

     void setDescription(const std::string theDescription);

     void setSculpture(const std::string theSculpture);

};


//navigation function to handle game play while the player is in the hallway room
int hallwayNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif