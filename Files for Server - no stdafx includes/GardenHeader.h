/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/19/16
* Last Modification Date:	4/19/16
* Filename:				GardenHeader.h
*
* Overview:
*	This file is the header file for garden objects.
*
******************************/

//define header
#ifndef GardenHeader_h
#define GardenHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Garden Class
class RoomGarden
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"driveway", "deck", "cellar"} };
     std::vector<std::string> objects{ std::vector<std::string>{"dog", "ms.wolf"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomGarden()
     {
          this->name = "The Garden";
          this->numRooms = 3;
          this->numObjects = 2;
          this->description = "You are in the garden.\n\nMany unique and colorful plants mix in to create an otherwordly atmosphere.\n\nThere is woman dressed in a black evening gown smoking a cigarrette on a bench, who you may want to talk with.\n\nYou can also interact with a dog laying down chained to a water fountain in front of what looks like a Hydrangea plant.\n\n";
     }

     //Virtual Destructor
     virtual ~RoomGarden()
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

//Luxury Car Class
class Dog
{
private:

protected://protected member variables.
     std::string type;
     std::string description;
     bool treat;
     std::string bark;
     std::string sap;

public:
     //default constructor
     Dog()
     {
          this->type = "Black lab";
          this->description = "Older in age with grey hair highlighting his eyebrows and mouth.";
          this->treat = false;
          this->bark = "\nRuff Ruff!";
          this->sap = "Hydrangea Plant Sap";

     }

     //Virtual Destructor
     virtual ~Dog()
     {}


     //member function to output information provided of each item
     void dogInformation();

     //member function to get into the trunk
     void dogInteract(std::unordered_map<std::string, std::string>& inv);

     void giveTreat(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getType() const;

     std::string getDescription() const;

     bool getTreat() const;

     std::string getBark() const;

     std::string getSap() const;

     //Mutator Functions to change private variables.
     void setType(const std::string theType);

     void setDescription(const std::string theDescription);

     void setTreat(const bool theTreat);

     void setBark(const std::string theBark);

     void setSap(const std::string theSap);

};

//Miss Wolf Class
class MsWolf
{
private:

protected://protected member variables.
     std::string knowMurderer;
     std::string doingTonight;
     int age;
     std::string jobDescription;
     std::string description;
     std::string confession;
     std::string confessionTwo;
     std::string confessionThree;

public:
     //default constructor
     MsWolf()
     {
          this->knowMurderer = "\nI cannot say unfortunately. Tonight was a terrible tragedy. My fiance's child was lost and we are grieving.";
          this->doingTonight = "\nWe were having a lovely dinner party with friends. I was cherishing my time with my beloved Robert and friends!";
          this->age = 45;
          this->jobDescription = "\nMy job is to spend time with George and give him all the love he can take. He's getting up there in years you know.";
          this->description = "A middle aged Italian female. About 5'9. Long dark hair. A black dress with piercing blue eyes.";
          this->confession = "Alright I confess! Everything simply went wrong tonight! \n\nThe inheritance was going to be mine until George grew a conscience and decided that he was going to give all the money to Willie!\n\n";
          this->confessionTwo = "Willie is not a golden boy you know. He was in on this with me to take care of George! \n\nI couldn't let him know that the arrangements had changed or he would have left me out of the money.\n\n";
          this->confessionThree = "We purchased the grapes and wine while in France and once we were happily married, George was going to take one fatal sip of the wine with the poisonous sap.\n\nHowever I had to take care of Willie before George made the new will official!\"\n\n";

     }

     //Virtual Destructor
     virtual ~MsWolf()
     {}


     //member function to output information provided of each item
     void personInformation(std::unordered_map<std::string, std::string>& inventory);

     //member function to get into the trunk
     int conversate(std::unordered_map<std::string, std::string>& inventory);

     //Accessor Functions for accessing private variables.
     std::string getKnowMurderer() const;

     std::string getDoingTonight() const;

     int getAge() const;

     std::string getJobDescription() const;

     std::string getDescription() const;

     std::string getConfession() const;

     std::string getConfessionTwo() const;

     std::string getConfessionThree() const;

     //Mutator Functions to change private variables.
     void setKnowMurderer(const std::string theKnowMurderer);

     void setDoingTonight(const std::string theDoingTonight);

     void setAge(const int theAge);

     void setJobDescription(const std::string theJobDescription);

     void setDescription(const std::string theDescription);

     void setConfession(const std::string theConfession);

     void setConfessionTwo(const std::string theConfessionTwo);

     void setConfessionThree(const std::string theConfessionThree);

};

#endif
