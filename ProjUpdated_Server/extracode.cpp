     //split choice string words into vector
     std::stringstream ss(choice);
     std::istream_iterator<std::string> begin(ss);
     std::istream_iterator<std::string> end;
     std::vector<std::string> vstrings(begin, end);
     std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));     

     for (i = 0; i < theRoom.getNumRooms(); i++){
          //check if choice matches room names
          
          if(vstrings[0].compare(theRoom.getExits()[i]) == 0) {
	    for(j = 0; j < theRoom.getExits()[i].length(); j++) {
	      parsedChoice[j] = tolower(theRoom.getExits()[i][j]);
	    }
	  }
     }
/*
		std::cout << vstrings[2] << std::endl;

     if(vstrings[0].compare("go") == 0 || vstrings[0].compare("Go") == 0) {
	for (i = 0; i < theRoom.getNumRooms(); i++){
	 if(vstrings[2].compare(theRoom.getExits()[i]) == 0) {
		std::cout << "in here" << std::endl;
	    for(j = 0; j < theRoom.getExits()[i].length(); j++) {
	      parsedChoice[j] = tolower(theRoom.getExits()[i][j]);
		std::cout << "parsed choice " << parsedChoice[j] << std::endl;
	    }
	 }
	}
     }
     else if(vstrings[0].compare("inspect") == 0 || vstrings[0].compare("Inspect") == 0) {
	for (i = 0; i < theRoom.getNumObjects(); i++){
	 if(vstrings[1].compare(theRoom.getObjects()[i]) == 0) {
	    for(j = 0; j < theRoom.getObjects()[i].length(); j++) {
	      choice[j] = tolower(theRoom.getObjects()[i][j]);
		std::cout << choice[j] << std::endl;
	    }
	 }
	}

     }
*/

     return parsedChoice;

