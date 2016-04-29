/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/18/16
* Last Modification Date:	4/18/16
* Filename:				KitchenHeader.h
*
* Overview:
*	This file is the header file for Kitchen objects and iteraction of objects.
*
******************************/
//define header
#ifndef KitchenHeader_h
#define KitchenHeader_h

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

//Knife Block Object
class KnifeBlock
{
private:

protected://protected member variables.
	std::string material;
	int numKnives;
	std::string knife;

public:
	//default constructor
	KnifeBlock()
	{
		this->material = "Beech Tree Wood";
		this->numKnives = 1;
		this->knife = "Knife";

	}

	//Virtual Destructor
	virtual ~KnifeBlock()
	{}

	//member function to get into the trunk
	void checkKnifeBlock(std::unordered_map<std::string, std::string>& inv);

	//Accessor Functions for accessing private variables.
	std::string getMaterial() const;

	int getNumKnives() const;

	std::string getKnife() const;

	//Mutator Functions to change private variables.
	void setMaterial(const std::string theMaterial);

	void setNumKnives(const int theNumKnives);

	void setKnife(const std::string theKnife);

};


//Refrigerator Class
class Refrigerator
{
private:

protected://protected member variables.
	std::string steak;
	std::string pie;
	std::string description;

public:
	//default constructor
	Refrigerator()
	{
		this->steak = "steak";
		this->pie = "piece of Blueberry Pie";
		this->description = "A silver refrigerator with black trimming. Fit for a king.";

	}

	//Virtual Destructor
	virtual ~Refrigerator()
	{}


	//member function to output information provided of each item
	void fridgeInformation();

	//member function to get into the trunk
	void checkFridge(std::unordered_map<std::string, std::string>& inv);

	//Accessor Functions for accessing private variables.
	std::string getSteak() const;

	std::string getPie() const;

	std::string getDescription() const;

	//Mutator Functions to change private variables.
	void setSteak(const std::string theSteak);

	void setPie(const std::string thePie);

	void setDescription(const std::string theDescription);

};


//navigation function to handle game play while the player is in the driveway
int kitchenNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif