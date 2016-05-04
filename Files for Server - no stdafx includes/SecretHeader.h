/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				4/29/16
* Last Modification Date:	4/29/16
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


//navigation function to handle game play while the player is in the secret room
int secretNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif