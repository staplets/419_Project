/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/26/16
* Last Modification Date:	5/28/16
* Filename:				LibraryHeader.h
*
* Overview:
*	This file is the header file for Library objects and iteraction of objects.
*
******************************/
//define header
#ifndef LibraryHeader_h
#define LibraryHeader_h

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>
#include <vector>

//Room Library Class
class RoomLibrary
{
private:

protected://protected member variables.
     std::string name;
     std::vector<std::string> exits{ std::vector<std::string>{"ballroom", "study"} };
     std::vector<std::string> objects{ std::vector<std::string>{"desk", "bookshelf"} };
     int numRooms;
     int numObjects;
     std::string description;

public:
     //default constructor
     RoomLibrary()
     {
          this->name = "The Library";
          this->numRooms = 2;
          this->numObjects = 2;
          this->description = "You are in the Library.\n\nUpon initial glance, you see several book shelves throughout the room, but one that seems to catch your attention.\n\nYou also see a desk by the side of the room where there are several windows overlooking the expansive landscape of the estate.\n\nWhat would you like to do?\n\nExamine the Book Shelf? (Enter \"1\").\n\nGo over to look at Desk? (Enter \"2\").\n\n";
     }

     //Virtual Destructor
     virtual ~RoomLibrary()
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

//Desk Object
class Desk
{
private:

protected://protected member variables.
     std::string description;
     std::string oldWill;

public:
     //default constructor
     Desk()
     {
          this->description = "A crimson colored executive desk with some files scattered across the top and a small green lamp on top.";
          this->oldWill = "Mr. Glass' Will: Dated January 21st 2015";
     }

     //Virtual Destructor
     virtual ~Desk()
     {}

     //member function
     void checkDesk(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getOldWill() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setOldWill(const std::string theOldWill);

};


//BookShelf
class BookShelf
{
private:

protected://protected member variables.
     std::string book;
     std::string description;

public:
     //default constructor
     BookShelf()
     {
          this->book = "Oliver Twist";
          this->description = "A 12 feet high book shelf running across half of the wall that looks slighty out of place with the other book shelves.";

     }

     //Virtual Destructor
     virtual ~BookShelf()
     {}


     //member function
     int checkBookShelf(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getBook() const;

     std::string getDescription() const;

     //Mutator Functions to change private variables.
     void setBook(const std::string theBook);

     void setDescription(const std::string theDescription);

};


#endif