// This program implements an online address book with various functionalities.
// Users can view all entries, search by name, find birthdays, and filter by relationships.
// The program interacts with the user through a menu-driven interface.
// This code was outlined using ChatGPT and modified by the coder.


#include <iostream>
#include "addressBookType.h"

void showMenu() {
    std::cout << "On-line Address Book" << std::endl;
    std::cout << "Select an option:" << std::endl;
    std::cout << "1 - Display all entries in the address Book." << std::endl;
    std::cout << "2 - Display an entry by a person's name." << std::endl;
    std::cout << "3 - Display all entries with a given birth month." << std::endl;
    std::cout << "4 - Display all entries with a given relationship tag." << std::endl;
    std::cout << "5 - Quit" << std::endl;
}

int main() {
    addressBookType myAddressBook;
    myAddressBook.initEntry("AddressBookData.txt"); // Initializes entries from the file
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
