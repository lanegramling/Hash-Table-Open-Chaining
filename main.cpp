#include <iostream>   //I/O
#include <fstream>    //File Input handling
#include <string>     //String convenience

#include "Hash.h"	    //Our Hash class

//Load a Hash from a (.txt) file
Hash<int> loadHash(std::string fName) {
  std::ifstream file(fName);
  int num;
  std::cout << "\n\nAttempting to read in from file " << fName << "...";
  if (file.is_open()) {
    file >> num; //Read in size first
    Hash<int>* hash = new Hash<int>(num);
    while(file >> num) hash->insert(num); //Load numbers to table.
    file.close();
    ///////////////////
      // std::cout << "\nTesting: Returning from loadHash with file loaded.\n";
    return *hash;
  }
  else {
      std::cout << "\nError: File could not be opened. Preparing empty table with default size of 7.";
      Hash<int>* hash = new Hash<int>(7);
      return *hash;
  }
}

//Main function
int main(int argc, char* argv[])
{
	std::string fileName = (argv[1]) ? argv[1] : "data.txt"; //File name assignment
	Hash<int> hash = loadHash(fileName);
	int choice = 0;
	do {
    std::cout << "\n................................................................"
									<< "\nPlease choose one of the following commands:"
									<< "\n1- Insert"
									<< "\n2- Delete"
									<< "\n3- Find"
									<< "\n4- Print"
									<< "\n5- Exit"
									<< "\n> ";
    std::cin >> choice;
		int num = 0; //Contains I/O responses
    switch(choice) {
      case 1: //Handle Insert
        std::cout << "\nEnter a number to be inserted: \n> ";
				std::cin >> num;
				hash.insert(num);
        break;
      case 2: //Handle Delete
        std::cout << "\nEnter a number to be deleted: \n> ";
				std::cin >> num;
				hash.erase(num);
        break;
      case 3: //Handle Find
        std::cout << "\nEnter a number to search for: \n> ";
				std::cin >> num;
				std::cout << "\n" << num << " was " << ((hash.find(num)) ? "" : "not ") << "found in the table.";
        break;
      case 4: //Handle Print
        std::cout << "\nTable:  ";
				hash.print();
        break;
      case 5: break; //Handle Exit
      default:
        std::cout << "\nThat option was not found. Please try again.";
        break;
    }

  } while (choice != 5);
  std::cout << "\n\nExiting - dumping table...\n";
}
