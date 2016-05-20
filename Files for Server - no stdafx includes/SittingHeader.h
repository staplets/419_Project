/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/25/16
* Last Modification Date:	5/25/16
* Filename:				SittingHeader.h
*
* Overview:
*	This file is the header file for sitting room objects.
*
******************************/

//define header
#ifndef SittingHeader_h
#define SittingHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Sitting Class
class RoomSitting
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"smoking", "foyer", "ballroom"} };
     std::vector<std::string> objects{ std::vector<std::string>{"couch", "mrsdeeds"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomSitting()
     {
          this->name = "The Sitting Room";
          this->numRooms = 3;
          this->numObjects = 2;
          this->description = "You are in the Sitting Room.\n\nIn this room you spot some lovely furniture, however the only noteworthy thing is a couch.\n\nThere is woman dressed in a peach dress reading through a magazine, who you may want to talk with (Interact: Enter \"mrsdeeds\").\n\nYou can also examine the couch (Interact: Enter \"couch\").\n\n";
     }

     //Virtual Destructor
     virtual ~RoomSitting()
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

//Couch Class
class Couch
{
private:

protected://protected member variables.
     std::string description;
     std::string book;
     std::string nap;

public:
     //default constructor
     Couch()
     {
          this->description = "A beige wrap around couch that could hold around 10 people.";
          this->book = "book - \"Clue the board game for dummies\"";
          this->nap = "\n\nYou love naps almost as much as you love your mysteries!\n\n";

     }

     //Virtual Destructor
     virtual ~Couch()
     {}

     //member function to look at couch
     void checkCouch(std::unordered_map<std::string, std::string>& inv);

     //member function for nap
     void takeNap();

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getBook() const;

     std::string getNap() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setBook(const std::string theBook);

     void setNap(const std::string theNap);

};


//Mrs Deeds Class
class MrsDeeds
{
private:

protected://protected member variables.
     std::string knowMurderer;
     std::string doingTonight;
     int age;
     std::string jobDescription;
     std::string description;
     std::string roomOne;
     std::string roomTwo;
     std::string secretNote;

public:
     //default constructor
     MrsDeeds()
     {
          this->knowMurderer = "\nMrs. Deeds \"Oh I wish I could help you. My heart breaks for George and we just found out tonight it was his son! After all these years.\"";
          this->doingTonight = "\nMrs. Deeds \"Mr. Deeds and I were here to spend time with our beloved Georgie boy. He and I go way back ...\"";
          this->age = 36;
          this->jobDescription = "\nMrs. Deeds \"Mr. Deeds and I both work at the local bank here in town. We are both bank tellers.\"";
          this->description = "A young Caucasian woman. About 5'3. Short auburn hair. A green dress with rimmed glasses.";
          this->roomOne = "\nMrs. Deeds \"I may be able to provide you with a little insight on a secret, if you were to find me a piece of that delicious blueberry pie!\"\n\n";
          this->roomTwo = "\nMrs. Deeds \"Why thank you! Alright so there is a secret room in this house through the library. You just need to push on the book shelf.\"\n\n";
          this->secretNote = "Notepad: push on book shelf in library.";
     }

     //Virtual Destructor
     virtual ~MrsDeeds()
     {}


     //member function to output information provided of each item
     void personInformation(std::unordered_map<std::string, std::string>& inventory);

     //member function for Mrs Deeds
     void conversate(std::unordered_map<std::string, std::string>& inventory);

     //member function for Mrs Deeds
     void secretRoom(std::unordered_map<std::string, std::string>& inventory);

     //Accessor Functions for accessing private variables.
     std::string getKnowMurderer() const;

     std::string getDoingTonight() const;

     int getAge() const;

     std::string getJobDescription() const;

     std::string getDescription() const;

     std::string getRoomOne() const;

     std::string getRoomTwo() const;

     std::string getSecretNote() const;

     //Mutator Functions to change private variables.
     void setKnowMurderer(const std::string theKnowMurderer);

     void setDoingTonight(const std::string theDoingTonight);

     void setAge(const int theAge);

     void setJobDescription(const std::string theJobDescription);

     void setDescription(const std::string theDescription);

     void setRoomOne(const std::string theRoomOne);

     void setRoomTwo(const std::string theRoomTwo);

     void setSecretNote(const std::string theSecretNote);

};


#endif
