/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/02/16
* Last Modification Date:	     5/02/16
* Filename:					DiningHeader.h
*
* Overview:
*	This file is the header file for Dining Room objects and iteraction of objects.
*
******************************/
//define header
#ifndef DiningHeader_h
#define DiningHeader_h

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

//Dining Table Object
class DiningTable
{
private:

protected://protected member variables.
	std::string description;
	std::string handk;
	std::string lipGlass;

public:
	//default constructor
	DiningTable()
	{
		this->description = "A rustic hand carved dining table that seats at least 20 guests.";
		this->handk = "handkerchief";
		this->lipGlass = "a glass of wine with a red lipstick smudge on the rim";

	}

	//Virtual Destructor
	virtual ~DiningTable()
	{}

	//member function to check dining table
	void checkDiningTable(std::unordered_map<std::string, std::string>& inv);

	//Accessor Functions for accessing private variables.
	std::string getDescription() const;

	std::string getHandk() const;

	std::string getLipGlass() const;

	//Mutator Functions to change private variables.
	void setDescription(const std::string theDescription);

	void setHandk(const std::string theHandk);

	void setLipGlass(const std::string theLipGlass);

};


//Parrot
class Parrot
{
private:

protected://protected member variables.
	std::string speak;
	std::string speakTwo;
	std::string description;

public:
	//default constructor
	Parrot()
	{
		this->speak = "\nParrot: \"Polly wants a cracker!\"";
		this->speakTwo = "\nParrot: \"Poison they said!\"";
		this->description = "A parrot that stands on his perch in a golden cage twitching his head around.";

	}

	//Virtual Destructor
	virtual ~Parrot()
	{}


	//member function to get into the trunk
	void convoParrot(std::unordered_map<std::string, std::string>& inv);

	//Accessor Functions for accessing private variables.
	std::string getSpeak() const;

	std::string getSpeakTwo() const;

	std::string getDescription() const;

	//Mutator Functions to change private variables.
	void setSpeak(const std::string theSpeak);

	void setSpeakTwo(const std::string theSpeakTwo);

	void setDescription(const std::string theDescription);

};


//navigation function to handle game play while the player is in the dining room
int diningNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif