/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/18/16
* Last Modification Date:	4/19/16
* Filename:				CellarHeader.h
*
* Overview:
*	This file is the header file for Cellar objects and iteraction of objects.
*
******************************/
//define header
#ifndef CellarHeader_h
#define CellarHeader_h

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

//Dresser Object
class Dresser
{
private:

protected://protected member variables.
	std::string material;
	int numDrawers;
	std::string dogTreat;

public:
	//default constructor
	Dresser()
	{
		this->material = "Mahogany Cedar";
		this->numDrawers = 4;
		this->dogTreat = "dog treat";

	}

	//Virtual Destructor
	virtual ~Dresser()
	{}

	//member function to get into the trunk
	void checkDresser(std::unordered_map<std::string, std::string>& inv);

	//Accessor Functions for accessing private variables.
	std::string getMaterial() const;

	int getNumDrawers() const;

	std::string getDogTreat() const;

	//Mutator Functions to change private variables.
	void setMaterial(const std::string theMaterial);

	void setNumDrawers(const int theNumDrawers);

	void setDogTreat(const std::string theDogTreat);

};


//Box Class
class Box
{
private:

protected://protected member variables.
	std::string pictures;
	std::string bowlingBall;
	std::string description;

public:
	//default constructor
	Box()
	{
		this->pictures = "pictures of Mr. Glass with Mr. Cunningham as a child";
		this->bowlingBall = "bowling ball";
		this->description = "A 3 foot by 3 foot cardboard box.";

	}

	//Virtual Destructor
	virtual ~Box()
	{}


	//member function to output information provided of each item
	void boxInformation();

	//member function to get into the trunk
	void checkBox(std::unordered_map<std::string, std::string>& inv);

	//Accessor Functions for accessing private variables.
	std::string getPictures() const;

	std::string getBowlingBall() const;

	std::string getDescription() const;

	//Mutator Functions to change private variables.
	void setPictures(const std::string thePictures);

	void setBowlingBall(const std::string theBowlingBall);

	void setDescription(const std::string theDescription);

};


//navigation function to handle game play while the player is in the driveway
int cellarNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif