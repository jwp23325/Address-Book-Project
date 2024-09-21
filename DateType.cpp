// This class implements the DateType class with methods to manage date information.
// It includes functionalities for setting a date with validation,
// checking for leap years, and printing the date.
// This code was outlined using ChatGPT and modified by the coder.

#pragma once
#include "dateType.h"

DateType::DateType(int month, int day, int year) {
    setDate(month, day, year);
}

// Checks if year is a leap year
bool DateType::isLeapYear(int year) const{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Sets date with validation
void DateType::setDate(int month, int day, int year) {
    // Validates year
    if (year >= 1900) {
        dYear = year;
    }
    else {
        dYear = 1900;
    }

    // Validates month
    if (month >= 1 && month <= 12) {
        dMonth = month;
    }
    else {
        dMonth = 1;
    }

    // Maximum day in a month based on the year
    int maxDay = getDaysInMonth(dMonth, dYear);

    // Validates day
    if (day >= 1 && day <= maxDay) {
        dDay = day;
    }
    else {
        dDay = 1;
    }
}

// Gets the number of days in the month
int DateType::getDaysInMonth(int month, int year) const{
    // Control flow
    switch (month) {
        // January, March, May, July, August, October, December
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;

        // April, June, September, November
    case 4: case 6: case 9: case 11:
        return 30;

        // February 
    case 2:
        return isLeapYear(year) ? 29 : 28;
    }
    return 0; // Default return for invalid month
}

// Gets day
int DateType::getDay() const{
    return dDay;
}

// Gets month
int DateType::getMonth() const{
    return dMonth;
}

// Gets year
int DateType::getYear() const{
    return dYear;
}

// Print method
void DateType::print() const {
    std::cout << dMonth << "/" << dDay << "/" << dYear << std::endl;
}

