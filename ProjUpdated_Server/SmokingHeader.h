/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/24/16
* Last Modification Date:	5/24/16
* Filename:				SmokingHeader.h
*
* Overview:
*	This file is the header file for Smoking Room objects and iteraction of objects.
*
******************************/
//define header
#ifndef SmokingHeader_h
#define SmokingHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Smoking Class
class RoomSmoking
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"kitchen", "sitting room", "billiards room"} };
     std::vector<std::string> objects{ std::vector<std::string>{"recliningchair", "painting"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomSmoking()
     {
          this->name = "The Smoking Room";
          this->numRooms = 3;
          this->numObjects = 2;
          this->description = "You are in the Smoking Room.\n\nLooking around, you see a Reclining Chair and you also see a painting on the wall that it noteworthy. You may want to examine these items.\n\n";
     }

     //Virtual Destructor
     virtual ~RoomSmoking()
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

//RecliningChair Object
class RecliningChair
{
private:

protected://protected member variables.
     std::string description;
     std::string pipe;

public:
     //default constructor
     RecliningChair()
     {
          this->description = "A large burgundy plush reclining chair that a small child could disappear into.";
          this->pipe = "smoking pipe";
     }

     //Virtual Destructor
     virtual ~RecliningChair()
     {}

     //member function
     void checkRecliningChair(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getPipe() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setPipe(const std::string thePipe);

};


//Painting
class Painting
{
private:

protected://protected member variables.
     std::string revolver;
     std::string description;

public:
     //default constructor
     Painting()
     {
          this->revolver = "revolver";
          this->description = "An impressionist art painting by Claude Monet.";

     }

     //Virtual Destructor
     virtual ~Painting()
     {}


     //member function
     void checkPainting(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getRevolver() const;

     std::string getDescription() const;

     //Mutator Functions to change private variables.
     void setRevolver(const std::string theRevolver);

     void setDescription(const std::string theDescription);

};

#endif
