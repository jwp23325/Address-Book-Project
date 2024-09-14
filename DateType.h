// This code was outline using ChatGPT and modified by the programmer.

#pragma once
# include <iostream>



class DateType
{
private:
	int dMonth;
	int dDay;
	int dYear;

public:
	// Constructor with default parameters
	DateType(int month = 1, int day = 1, int year = 1900) {
		setDate(month, day, year);
	}
	
	// Checks if year is a leap year
	bool isLeapYear(int year) {
		return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	}

	// Sets date with validtion
	void setDate(int month, int day, int year) {

		// Validates year
		if (year >= 1900) {
			dYear = year;
		}

		// Default year
		else {
			dYear = 1900;
		}

		// Validates month
		if (month >= 1 && month <= 12) {
			dMonth = month;
		}

		// Default month
		else {
			dMonth = 1;
		}

		// Maximum day in a month based on the year
		int maxDay = getDaysInMonth(dMonth, dYear); {

			// Validates day
			if (day >= 1 && day <= maxDay) {
				dDay = day;
			}

			// Default day
			else {
				dDay = 1;
			}
		}
	}

	// Gets the number of days in the month
	int getDaysInMonth(int month, int year) {

		// Control flow
		switch(month) {
			// January, March, May, July, August, October, December
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
				return 31;

			// April, June, September, November
			case 4: case 6: case 9: case 11:
				return 30;
		
			// Febuary 
			case 2:
				return isLeapYear(year) ? 29 : 28;

		}
	}

	// Gets day
	int getDay() {
		return dDay;
	}

	// Gets month
	int getMonth() {
		return dMonth;
	}

	// Gets year
	int getYear() {
		return dYear;
	}
	
	// Print method
	void print() const {
		std::cout << dMonth << "/" << dDay << "/" << dYear << std::endl;
	}
};

