/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/29/16
* Last Modification Date:	5/29/16
* Filename:				SecretHeader.h
*
* Overview:
*	This file is the header file for Secret objects and iteraction of objects.
*
******************************/
//define header
#ifndef SecretHeader_h
#define SecretHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Secret Class
class RoomSecret
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"library"} };
     std::vector<std::string> objects{ std::vector<std::string>{"lightswitch", "safe"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomSecret()
     {
          this->name = "The Secret Room";
          this->numRooms = 1;
          this->numObjects = 2;
          this->description = "You are in the Secret Room.\n\nIt is quite dark in there, however you make out a safe in the corner of the room that you can try to open.\n\nFeeling around you notice there is a light switch you can switch on as well.\n\n";
     }

     //Virtual Destructor
     virtual ~RoomSecret()
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

//Safe Object
class Safe
{
private:

protected://protected member variables.
	std::string description;
	std::string newWill;
	std::string jfkFiles;

public:
	//default constructor
	Safe()
	{
		this->description = "A 3 foot by 3 foot silver titanium safe with George Glass' initials inscribed on the side.";
		this->newWill = "Mr. Glass' Will: Dated February 22nd 2016";
		this->jfkFiles = "some files that may implicate who shot JFK";
	}

	//Virtual Destructor
	virtual ~Safe()
	{}

	//member function
	void checkSafe(std::unordered_map<std::string, std::string>& inv);

	//Accessor Functions for accessing private variables.
	std::string getDescription() const;

	std::string getNewWill() const;

	std::string getJfkFiles() const;

	//Mutator Functions to change private variables.
	void setDescription(const std::string theDescription);

	void setNewWill(const std::string theNewWill);

	void setJfkFiles(const std::string theJfkFiles);

};


//LightSwitch
class LightSwitch
{
private:

protected://protected member variables.
	bool broken;
	std::string description;

public:
	//default constructor
	LightSwitch()
	{
		this->broken = true;
		this->description = "An average light switch that appears to run to the single light bulb in the ceiling.";

	}

	//Virtual Destructor
	virtual ~LightSwitch()
	{}


	//member function
	int checkLightSwitch(std::unordered_map<std::string, std::string>& inv);

	//Accessor Functions for accessing private variables.
	bool getBroken() const;

	std::string getDescription() const;

	//Mutator Functions to change private variables.
	void setBroken(const bool theBroken);

	void setDescription(const std::string theDescription);

};

#endif
