/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/21/16
* Last Modification Date:	4/21/16
* Filename:				BilliardsHeader.h
*
* Overview:
*	This file is the header file for Billiards Room objects and iteraction of objects.
*
******************************/
//define header
#ifndef BilliardsHeader_h
#define BilliardsHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

//Pool Table Object
class PoolTable
{
private:

protected://protected member variables.
     std::string description;
     std::string ball;
     std::string stick;

public:
     //default constructor
     PoolTable()
     {
          this->description = "Regulation sized green carpeted pool table with two pool sticks and a few pool balls on the table scattered.";
          this->ball = "pool ball";
          this->stick = "pool stick";

     }

     //Virtual Destructor
     virtual ~PoolTable()
     {}

     //member function to get into the trunk
     void checkTable(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getBall() const;

     std::string getStick() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setBall(const std::string theBall);

     void setStick(const std::string theStick);

};


//Coffee Table
class CoffeeTable
{
private:

protected://protected member variables.
     std::string brochure;
     std::string description;

public:
     //default constructor
     CoffeeTable()
     {
          this->brochure = "brochure for beaujolis wine vineyards with a URL address written on the inside";
          this->description = "A mocha colored wooden coffee table about 3 feet high with some reading material on top.";

     }

     //Virtual Destructor
     virtual ~CoffeeTable()
     {}


     //member function to get into the trunk
     void checkCoffeeTable(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getBrochure() const;

     std::string getDescription() const;

     //Mutator Functions to change private variables.
     void setBrochure(const std::string theBrochure);

     void setDescription(const std::string theDescription);

};


//navigation function to handle game play while the player is in the billiards room
int billiardsNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif