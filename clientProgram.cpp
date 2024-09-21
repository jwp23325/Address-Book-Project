#include <iostream>
#include "addressBookType.h"

/*
void showMenu() {
    std::cout << "On-line Address Book" << std::endl;
    std::cout << "Select an option:" << std::endl;
    std::cout << "1 - Display all entries in the address Book." << std::endl;
    std::cout << "2 - Display an entry by a person’s name." << std::endl;
    std::cout << "3 - Display all entries with a given birth month." << std::endl;
    std::cout << "4 - Display all entries with a given relationship tag." << std::endl;
    std::cout << "5 - Quit" << std::endl;
}

int main() {
    addressBookType myAddressBook;
    myAddressBook.initEntry("AddressBookData.txt");
    int choice = 0;


   
    do {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline character

        switch (choice) {
        case 1:
            myAddressBook.print();
            break;
        case 2: {
            std::string lastName;
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            myAddressBook.findPerson(lastName);
            break;
        }
        case 3: {
            int month;
            std::cout << "Enter month: ";
            std::cin >> month;
            myAddressBook.findBirthdays(month);
            break;
        }
        case 4: {
            std::string relation;
            std::cout << "Enter relationship: ";
            std::getline(std::cin, relation);
            myAddressBook.findRelations(relation);
            break;
        }
        case 5:
            std::cout << "Quitting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, try again." << std::endl;
        }
    } while (choice != 5);
    
    return 0;
}
*/

#include <iostream>
#include <fstream>
#include <string>

void readAddressBook(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string fName, lName, street, city, state, phone, relation;
    int month, day, year, zip;

    while (std::getline(inputFile, fName)) {
        std::getline(inputFile, lName);
        inputFile >> month >> day >> year;
        inputFile.ignore(); // Ignore the newline character
        std::getline(inputFile, street);
        std::getline(inputFile, city);
        inputFile >> state >> zip;
        inputFile.ignore(); // Ignore the newline character
        std::getline(inputFile, phone);
        std::getline(inputFile, relation);

        // Output the read data to verify correctness
        std::cout << "Name: " << fName << " " << lName << "\n"
            << "Birthday: " << month << "/" << day << "/" << year << "\n"
            << "Address: " << street << ", " << city << ", " << state << " " << zip << "\n"
            << "Phone: " << phone << "\n"
            << "Relation: " << relation << "\n\n";
    }

    inputFile.close(); // Close the file
}

int main() {
    std::string filename = "AddressBookData.txt";
    readAddressBook(filename);
    return 0;
}