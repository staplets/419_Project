/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/25/16
* Last Modification Date:	4/26/16
* Filename:				BallroomHeader.h
*
* Overview:
*	This file is the header file for Ballroom Room objects and iteraction of objects.
*
******************************/
//define header
#ifndef BallroomHeader_h
#define BallroomHeader_h

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

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


//navigation function to handle game play while the player is in the billiards room
int ballroomNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif