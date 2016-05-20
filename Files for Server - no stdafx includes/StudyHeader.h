/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/25/16
* Last Modification Date:	4/26/16
* Filename:				StudyHeader.h
*
* Overview:
*	This file is the header file for Study objects.
*
******************************/

//define header
#ifndef StudyHeader_h
#define StudyHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Study Class
class RoomStudy
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"library", "billiards", "hallway"} };
     std::vector<std::string> objects{ std::vector<std::string>{"computer", "mrgreen"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomStudy()
     {
          this->name = "The Study";
          this->numRooms = 3;
          this->numObjects = 2;
          this->description = "You are in the Study.\n\nIn this room, you see a gentleman sitting in a chair staring out the window.\n\nYou also notice a computer on a desk in the corner of the room.\n\nWould you like to talk to the man (Interact: Enter \"mrgreen\").\n\nYou can also take a look at the computer (Interact: Enter \"computer\").\n\n";
     }

     //Virtual Destructor
     virtual ~RoomStudy()
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

//Computer Class
class Computer
{
private:

protected://protected member variables.
     std::string description;
     std::string comboNote;
     std::string info;
     std::string infoTwo;
     std::string infoThree;
     std::string infoFour;
     std::string infoFive;

public:
     //default constructor
     Computer()
     {
          this->description = "A desktop black Windows Computer turned on, but at the login screen.";
          this->comboNote = "Notepad: Gamay Grape makes Beaujolais wine. Mixed with Hydrangea plant sap, it is deadly to humans.";
          this->info = "\n\nFrom the website: Beaujolais Wine Vineyards goes into details about their wonderful tourist attractions and wine shipped throughout the world.\n\n";
          this->infoTwo = "\n\nYou peruse the website and at the bottom in smaller lettering, you see the following:\n\n";
          this->infoThree = "\n\nDISCLAIMER: It has been brought to our attention when the wine, made from the Gamay Grape,\n\n";
          this->infoFour = "\n\nis mixed with sap from a Hydrangea plant it has been found to be deadly to human consumption.\n\n";
          this->infoFive = "\n\nOne can look for carbonation or sizzling as a way to identify if the wine shows signs of mixing of the ingredients.\n\n";

     }

     //Virtual Destructor
     virtual ~Computer()
     {}

     //member function to look at couch
     void checkComputer(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getComboNote() const;

     std::string getInfo() const;

     std::string getInfoTwo() const;

     std::string getInfoThree() const;

     std::string getInfoFour() const;

     std::string getInfoFive() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setComboNote(const std::string theComboNote);

     void setInfo(const std::string theInfo);

     void setInfoTwo(const std::string theInfoTwo);

     void setInfoThree(const std::string theInfoThree);

     void setInfoFour(const std::string theInfoFour);

     void setInfoFive(const std::string theInfoFive);

};


//Mr Green Class
class MrGreen
{
private:

protected://protected member variables.
     std::string knowMurderer;
     std::string doingTonight;
     int age;
     std::string jobDescription;
     std::string description;
     std::string moreInfo;
     std::string vacayNote;

public:
     //default constructor
     MrGreen()
     {
          this->knowMurderer = "\nMr. Green \"I'm not too sure, but that butler is suspicious if you ask me. Just something about him makes me uneasy.\"";
          this->doingTonight = "\nMr. Green \"Well I have been a good friend of Mr. George Glass for decades. I was here to have a lovely weekend with George, Miss Wolf and the Deeds'. We were enjoying dinner until Willie got sick.\"";
          this->age = 62;
          this->jobDescription = "\nMr. Green \"I work at the hospital in town as a anesthesiologist.\"";
          this->description = "An older Asian man. About 5'7. Long black hair kept in a pony tail. A brown sports jacket and a hawaiian shirt on underneath.";
          this->moreInfo = "\nMr. Green \"I'm not sure if this could help at all with your investigation, however I do recall Mr. Glass was out of the country recently. Perhaps in Europe somewhere.\"\n\n";
          this->vacayNote = "Notepad: Mr. Glass was out of the country recently - Potentially in Europe.";
     }

     //Virtual Destructor
     virtual ~MrGreen()
     {}


     //member function to output information provided of each item
     void personInformation(std::unordered_map<std::string, std::string>& inventory);

     //member function for Mr Green
     void conversate(std::unordered_map<std::string, std::string>& inventory);

     //member function Mr Green
     void otherInfo(std::unordered_map<std::string, std::string>& inventory);

     //Accessor Functions for accessing private variables.
     std::string getKnowMurderer() const;

     std::string getDoingTonight() const;

     int getAge() const;

     std::string getJobDescription() const;

     std::string getDescription() const;

     std::string getMoreInfo() const;

     std::string getVacayNote() const;

     //Mutator Functions to change private variables.
     void setKnowMurderer(const std::string theKnowMurderer);

     void setDoingTonight(const std::string theDoingTonight);

     void setAge(const int theAge);

     void setJobDescription(const std::string theJobDescription);

     void setDescription(const std::string theDescription);

     void setMoreInfo(const std::string theMoreInfo);

     void setVacayNote(const std::string theVacayNote);

};

#endif
