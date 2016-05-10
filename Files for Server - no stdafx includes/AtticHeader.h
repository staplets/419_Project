/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/09/16
* Last Modification Date:	5/09/16
* Filename:					AtticHeader.h
*
* Overview:
*	This file is the header file for Attic room objects.
*
******************************/

//define header
#ifndef AtticHeader_h
#define AtticHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>


//NightStand Class
class NightStand
{
private:

protected://protected member variables.
	std::string description;
	std::string wrapper;

public:
	//default constructor
	NightStand()
	{
		this->description = "A 3 foot high black wired trash can with a fresh scent garbage bag in it.";
		this->wrapper = "snickers candy bar wrapper";

	}

	//Virtual Destructor
	virtual ~NightStand()
	{}

	//member function to look at night stand
	void checkStand(std::unordered_map<std::string, std::string>& inv);

	//Accessor Functions for accessing private variables.
	std::string getDescription() const;

	std::string getWrapper() const;

	//Mutator Functions to change private variables.
	void setDescription(const std::string theDescription);

	void setWrapper(const std::string theWrapper);

};


//Mr Glass Class
class MrGlass
{
private:

protected://protected member variables.
	std::string knowMurderer;
	std::string doingTonight;
	int age;
	std::string jobDescription;
	std::string description;
	std::string pass;
	std::string passTwo;
	std::string passwordInfo;

public:
	//default constructor
	MrGlass()
	{
		this->knowMurderer = "\nMrs. White \"Honey if I knew they would need a police man to come for me. What they have done to George is awful.\"";
		this->doingTonight = "\nMrs. White \"I've been working the house cooking dinner for the guests and cleaning up.\"";
		this->age = 55;
		this->jobDescription = "\nMrs. White \"I handle the day to day routine of cooking and cleaning around here.\n\nI'm sure you've noticed how much work it is with the size of this place.\"";
		this->description = "A middle aged Caucasian woman. About 5 feet on the dot in height. Black mid length hair. A bit of a nervous edge to her.";
		this->pass = "\nMrs. White \"I can provide you with the password to the computer downstairs,\n\nbut I'd appreciate a cigarette to help take the edge off of what happened tonight first.\"\n\n";
		this->passTwo = "\nMrs. White \"Thank you so much sir! Here's the password.\" Mrs. White hands Sherlock a slip of paper with the password on it.\n\n";
		this->passwordInfo = "Computer Password: \'MoMoneyMoProblems\'.";
	}

	//Virtual Destructor
	virtual ~MrGlass()
	{}


	//member function to output information provided of each item
	void personInformation(std::unordered_map<std::string, std::string>& inventory);

	//member function for Mrs Deeds
	void conversate(std::unordered_map<std::string, std::string>& inventory);

	//member function for Mrs Deeds
	void getPassword(std::unordered_map<std::string, std::string>& inventory);

	//Accessor Functions for accessing private variables.
	std::string getKnowMurderer() const;

	std::string getDoingTonight() const;

	int getAge() const;

	std::string getJobDescription() const;

	std::string getDescription() const;

	std::string getPass() const;

	std::string getPassTwo() const;

	std::string getPasswordInfo() const;

	//Mutator Functions to change private variables.
	void setKnowMurderer(const std::string theKnowMurderer);

	void setDoingTonight(const std::string theDoingTonight);

	void setAge(const int theAge);

	void setJobDescription(const std::string theJobDescription);

	void setDescription(const std::string theDescription);

	void setPass(const std::string thePass);

	void setPassTwo(const std::string thePassTwo);

	void setPasswordInfo(const std::string thePasswordInfo);

};

//navigation function to handle game play while the player is in the attic room
int atticNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif
