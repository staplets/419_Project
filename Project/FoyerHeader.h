/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/14/16
* Last Modification Date:	4/18/16
* Filename:				FoyerHeader.h
*
* Overview:
*	This file is the header file for Foyer objects and iteraction of objects.
*
******************************/
//define header
#ifndef FoyerHeader_h
#define FoyerHeader_h

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

//Coat Closet Class
class CoatCloset
{
private:

protected://protected member variables.
     std::string color;
     int numCoats;
     std::string umbrella;
     std::string matches;

public:
     //default constructor
     CoatCloset()
     {
          this->color = "Oak";
          this->numCoats = 3;
          this->umbrella = "Umbrella";
          this->matches = "Matches with the label 'Wellington Oil Company'";

     }

     //Virtual Destructor
     virtual ~CoatCloset()
     {}


     //member function to output information provided of each item
     void closetInformation(std::unordered_map<std::string, std::string>& inv);

     //member function to get into the trunk
     void checkCoats(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getColor() const;

     int getNumCoats() const;

     std::string getUmbrella() const;

     std::string getMatches() const;

     //Mutator Functions to change private variables.
     void setColor(const std::string theColor);

     void setNumCoats(const int theNumCoats);

     void setUmbrella(const std::string theUmbrella);

     void setMatches(const std::string theMatches);

};


//Fish Bowl Class
class FishBowl
{
private:

protected://protected member variables.
     std::string fishOneType;
     std::string fishTwoType;
     std::string fishOneAnswer;
     std::string fishTwoAnswer;

public:
     //default constructor
     FishBowl()
     {
          this->fishOneType = "\nThe first fish is a burnt orange Goldfish";
          this->fishTwoType = "\nThe second fish is a dark purple Betta.";
          this->fishOneAnswer = "\nThe goldfish looks at Sherlock with a dumbfounded look and blows a bubble.";
          this->fishTwoAnswer = "\nThe Betta fish goes and hides under a rock.";

     }

     //Virtual Destructor
     virtual ~FishBowl()
     {}


     //member function to output information provided of each item
     void bowlInformation();

     //member function to get into the trunk
     void fishConvo(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getFishOneType() const;

     std::string getFishTwoType() const;

     std::string getFishOneAnswer() const;

     std::string getFishTwoAnswer() const;

     //Mutator Functions to change private variables.
     void setFishOneType(const std::string theFishOneType);

     void setFishTwoType(const std::string theFishTwoType);

     void setFishOneAnswer(const std::string theFishOneAnswer);

     void setFishTwoAnswer(const std::string theFishTwoAnswer);

};


//navigation function to handle game play while the player is in the driveway
int foyerNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif