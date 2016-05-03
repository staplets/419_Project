/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			4/26/16
* Last Modification Date:	4/28/16
* Filename:				LibraryHeader.h
*
* Overview:
*	This file is the header file for Library objects and iteraction of objects.
*
******************************/
//define header
#ifndef LibraryHeader_h
#define LibraryHeader_h

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>

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


//navigation function to handle game play while the player is in the library room
int libraryNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif