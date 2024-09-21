// This class represents a date with validation features.
// It includes methods for setting and getting date details,
// as well as checking for leap years and calculating the number of days in a month.
// This code was outlined using ChatGPT and modified by the coder.

#pragma once
#include <iostream>


class DateType {
private:
    int dMonth;
    int dDay;
    int dYear;

public:
    // Constructor with default parameters
    DateType(int month = 1, int day = 1, int year = 1900);

    // Checks if year is a leap year
    bool isLeapYear(int year);

    // Sets date with validation
    void setDate(int month, int day, int year);

    // Gets the number of days in the month
    int getDaysInMonth(int month, int year) const;

    // Gets day
    int getDay();

    // Gets month
    int getMonth() const;

    // Gets year
    int getYear();

    // Print method
    void print() const;
};
