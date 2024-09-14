#pragma once

#include <string>
#include <iostream>

class personType
{
private:
	std::string firstName;
	std::string lastName;

public:
	// Default and parameterized constructor
	personType(std::string fName = "", std::string lName = "")
	:firstName(fName), lastName(lName) {}

	void setFirstName(const std::string& fName) { firstName = fName; }
	void setLastName(const std::string& lName) { lastName = lName; }

	std::string getFirstName() const { return firstName; }
	std::string getLastName() const { return lastName; }

	void print() const {
		std::cout << "Name: " << firstName << " " << lastName << std::endl;
	}

	std::string getFirstName() const {

	}

};

