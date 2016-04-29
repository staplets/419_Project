/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/24/16
* Last Modification Date:	4/24/16
* Filename:				SmokingHeader.h
*
* Overview:
*	This file is the header file for Smoking Room objects and iteraction of objects.
*
******************************/
//define header
#ifndef SmokingHeader_h
#define SmokingHeader_h

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

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
		this->pipe = "pipe";
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
	std::string sculpture;

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


//navigation function to handle game play while the player is in the hallway room
int smokingRoomNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif