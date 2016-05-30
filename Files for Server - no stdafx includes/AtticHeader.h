/***********************************************************
* Author:					Shaun Stapleton
* Date Created:				5/30/16
* Last Modification Date:     	5/30/16
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
#include <vector>

//Room Attic Class
class RoomAttic
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"hallway", "balcony"} };
     std::vector<std::string> objects{ std::vector<std::string>{"night stand", "mr glass"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomAttic()
     {
          this->name = "The Attic";
          this->numRooms = 2;
          this->numObjects = 2;
          this->description = "You are in the Attic.\n\nThe attic doubles as a suite for Mr. Glass, who has the whole top floor of the mansion to himself.\n\nThere are a few basic bedroom items. Nothing particularly interesting except a night stand with an item or two on it.\n\nMr. Glass is sitting on a sofa in his room staring blankly across the room to the other wall.\n\nWould you like to talk with him (Interact: Enter \"mr glass\").\n\nTake a look night stand (Examine: Enter \"night stand\").\n\n";
     }

     //Virtual Destructor
     virtual ~RoomAttic()
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

//NightStand Class
class NightStand
{
private:

protected://protected member variables.
	std::string description;
	std::string picFrame;

public:
	//default constructor
	NightStand()
	{
		this->description = "An oak colored 4 foot high night stand with a lamp on it.";
          this->picFrame = "framed picture of Mr. Glass and Miss Wolf traveling together at the Swiss Alps";

	}

	//Virtual Destructor
	virtual ~NightStand()
	{}

	//member function to look at night stand
	void checkStand(std::unordered_map<std::string, std::string>& inv);

	//Accessor Functions for accessing private variables.
	std::string getDescription() const;

	std::string getPicFrame() const;

	//Mutator Functions to change private variables.
	void setDescription(const std::string theDescription);

	void setPicFrame(const std::string thePicFrame);

};


//Mr Glass Class
class MrGlass
{
private:

protected://protected member variables.
	std::string knowMurderer;
	int age;
	std::string jobDescription;
	std::string description;
	std::string keyOne;
     std::string keyTwo;
     std::string evidence;
     std::string confessOne;
     std::string confessTwo;
     std::string statement;
     std::string key;

public:
	//default constructor
	MrGlass()
	{
		this->knowMurderer = "\nMr. Glass \"As I said earlier I don't know who may have done this despicable act. No one that I knew of would want to harm Willie.\"";
		this->age = 87;
		this->jobDescription = "\nMr. Glass \"I'm retired of course, however I used to be an Investment banker and I accrued a lot of money over the years.\"";
		this->description = "As noted previously, an elderly white male in his 80's, who appears to be in the early stages of shock.";
          this->keyOne = "\nMr. Glass \"Well, I can give you a key to gain access to a secret safe, but I'm quite protective of it.\n\nI'd appreciate if you could provide me with some evidence that you are making progress before I give it up.\"\n\n";
		this->keyTwo = "\nMr. Glass \"Okay excellent work detective! Here is the key to a secret safe in my house.\n\nMrs. Deeds can tell you where to find it.\" Mr. Glass hands you the key.\n\n";
          this->evidence = "\nMr. Glass \"I'm happy to be of more assistance if you have some more evidence that points us to the murderer.\"\n\n";
          this->confessOne = "\nMr. Glass \"Goodness gracious, I can't believe it but this means my fiance Miss Wolf poisoned Willie!.\n\nWe were out of town in France two weeks ago and she was adamant about picking up those Gamay Grapes and that Beaujolais wine!\"\n\n";
          this->confessTwo = "\nMr. Glass \"She must have seen my new will giving all of my inheritance to Willie. I can't believe it.\n\nI will give you a written statement of our whereabouts and that she purchased those items.\n\nMy boy and now the love of my life!\"\n\n";
          this->statement = "Written statement by Mr. Glass that Ms Wolf purchased the Grapes and Wine that were used to poison Mr. Cunningham";
          this->key = "Key to unlock Safe";
	}

	//Virtual Destructor
	virtual ~MrGlass()
	{}


	//member function to output information provided of each item
	void personInformation(std::unordered_map<std::string, std::string>& inventory);

	//member function for Mrs Deeds
	void conversate(std::unordered_map<std::string, std::string>& inventory);

	//member function for Mr Glass
	void getMoreInfo(std::unordered_map<std::string, std::string>& inventory);

	//Accessor Functions for accessing private variables.
	std::string getKnowMurderer() const;

	int getAge() const;

	std::string getJobDescription() const;

	std::string getDescription() const;

	std::string getKeyOne() const;

     std::string getKeyTwo() const;

     std::string getEvidence() const;

     std::string getConfessOne() const;

     std::string getConfessTwo() const;

	std::string getStatement() const;

     std::string getKey() const;

	//Mutator Functions to change private variables.
	void setKnowMurderer(const std::string theKnowMurderer);

	void setAge(const int theAge);

	void setJobDescription(const std::string theJobDescription);

	void setDescription(const std::string theDescription);

     void setKeyOne(const std::string theKeyOne);

     void setKeyTwo(const std::string theKeyTwo);

     void setEvidence(const std::string theEvidence);

     void setConfessOne(const std::string theConfessOne);

     void setConfessTwo(const std::string theConfessTwo);

     void setStatement(const std::string theStatement);
     
     void setKey(const std::string theKey);

};

//navigation function to handle game play while the player is in the attic room
int atticNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif
