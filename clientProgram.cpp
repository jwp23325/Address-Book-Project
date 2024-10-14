// This source file serves as the client program for the Address Book application.
// It provides a menu-driven interface for users to interact with the address book, 
// allowing them to display entries, search for individuals, add new contacts, 
// and delete existing entries. 
// This code was outlined using ChatGPT and modified by the coder.

#pragma once
#include <iostream>
#include "addressBookType.h"
#include <string>

void showMenu() {
    std::cout << "On-line Address Book" << std::endl;
    std::cout << "Select an option:" << std::endl;
    std::cout << "1 - Display all entries in the address Book." << std::endl;
    std::cout << "2 - Display an entry by a person's name." << std::endl;
    std::cout << "3 - Display all entries with a given birth month." << std::endl;
    std::cout << "4 - Display all entries with a given relationship tag." << std::endl;
    std::cout << "5 - Add a new entry." << std::endl;
    std::cout << "6 - Delete an entry by name." << std::endl;
    std::cout << "7 - Quit" << std::endl;
}

int main() {
    addressBookType myAddressBook;
    std::string filename = "AddressBookData.txt";
    myAddressBook.initEntry(filename);

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
            std::string lastName,firstName;
            std::cout << "Enter last name: ";
            std::getline(std::cin, lastName);
            std::cout << "Enter first name: ";
            std::getline(std::cin, firstName);
            myAddressBook.findPerson(lastName,firstName);
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
        case 5: // Add new entry
            myAddressBook.addInteractiveEntry();
            break;
        case 6: { // Delete an entry by name
            std::string firstName, lastName;
            std::cout << "Enter first name: ";
            std::cin >> firstName;
            std::cout << "Enter last name: ";
            std::cin >> lastName;
            myAddressBook.deleteEntry(lastName, firstName);
            break;
        }
        case 7:
            myAddressBook.saveData(filename); // Automatically save data when quitting
            std::cout << "Quitting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice, try again." << std::endl;
        }
    } while (choice != 7);

    return 0;
}
