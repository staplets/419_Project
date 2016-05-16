/***********************************************************
* Author:					Shaun Stapleton
* Date Created:			5/12/16
* Last Modification Date:	5/12/16
* Filename:				BalconyHeader.h
*
* Overview:
*	This file is the header file for Balcony objects.
*
******************************/

//define header
#ifndef BalconyHeader_h
#define BalconyHeader_h

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <unordered_map>


//FoldingTable Class
class FoldingTable
{
private:

protected://protected member variables.
     std::string description;
     std::string lipstick;
     std::string cigarettes;

public:
     //default constructor
     FoldingTable()
     {
          this->description = "A folding table with a weathered black wooden finish propped up on it's four folding legs.";
          this->lipstick = "bright red lipstick";
          this->cigarettes = "cigarettes";

     }

     //Virtual Destructor
     virtual ~FoldingTable()
     {}

     //member function to look at couch
     void checkTable(std::unordered_map<std::string, std::string>& inv);

     //Accessor Functions for accessing private variables.
     std::string getDescription() const;

     std::string getLipstick() const;

     std::string getCigarettes() const;

     //Mutator Functions to change private variables.
     void setDescription(const std::string theDescription);

     void setLipstick(const std::string theLipstick);

     void setCigarettes(const std::string theCigarettes);

};


//Mr Deeds Class
class MrDeeds
{
private:

protected://protected member variables.
     std::string knowMurderer;
     std::string doingTonight;
     int age;
     std::string jobDescription;
     std::string description;
     std::string moreInfo;
     std::string diningNote;

public:
     //default constructor
     MrDeeds()
     {
          this->knowMurderer = "\nMr. Deeds \"I can't help you there sir, however I've always had a funny feeling about Miss Wolf. Just a gut feeling nothing more.\"";
          this->doingTonight = "\nMr. Deeds \"My wife worked for Mr. Glass when she graduated from college and they have been friends since.\n\nWe have been having weekend get togethers for years.\"";
          this->age = 39;
          this->jobDescription = "\nMr. Deeds \"Mrs. Deeds and I are both employed now at the local bank as bank tellers.\"";
          this->description = "A middle aged caucasian man. Standing a towering 6'5. Short dirty blonde hair. A green jacket and white trousers.";
          this->moreInfo = "\nMr. Deeds \"The last time I saw Mr. Cunningham alive was in the dining room after dinner.\n\nI was walking past the room and didn't catch who was with him, but i do recall a female's voice.\"\n\n";
          this->diningNote = "Notepad: Mr. Cunningham was in the dining romo with a female speaking after dinner.";
     }

     //Virtual Destructor
     virtual ~MrDeeds()
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

     std::string getDiningNote() const;

     //Mutator Functions to change private variables.
     void setKnowMurderer(const std::string theKnowMurderer);

     void setDoingTonight(const std::string theDoingTonight);

     void setAge(const int theAge);

     void setJobDescription(const std::string theJobDescription);

     void setDescription(const std::string theDescription);

     void setMoreInfo(const std::string theMoreInfo);

     void setDiningNote(const std::string theDiningNote);

};

//navigation function to handle game play while the player is in the balcony
int balconyNavigate(std::unordered_map<std::string, std::string>& inventory);

#endif
