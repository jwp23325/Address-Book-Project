// This program tests the functionalities of the DateType class,
// including its constructors, date validation, and printing methods.
// It demonstrates how the class handles valid and invalid dates.
// This code was outlined using ChatGPT and modified by the coder.

#include <iostream>
#include "DateType.h"

using namespace std;

int main() {
    cout << "Testing default constructor ... ";
    DateType defDate;
    defDate.print();
    cout << endl;

    cout << "Testing constructor with parameters ... ";
    DateType date(2, 29, 2016);
    date.print();
    cout << endl;

    cout << "Setting date with invalid year (1000) ... ";
    date.setDate(2, 29, 1000);
    date.print();
    cout << endl;

    cout << "Setting date with invalid month (13) ... ";
    date.setDate(13, 29, 2016);
    date.print();
    cout << endl;

    cout << "Setting date with invalid day (4, 31) ... ";
    date.setDate(4, 31, 2016);
    date.print();
    cout << endl;

    cout << "Setting invalid date: Feb 29, 2015 ... ";
    date.setDate(2, 29, 2015);
    date.print();
    cout << endl;

    cout << "Setting valid date: Feb 28, 2015 ... ";
    date.setDate(2, 28, 2015);
    date.print();
    cout << endl;

    cout << "Setting valid date (August 15, 2016) ... ";
    date.setDate(8, 15, 2016);
    date.print();
    cout << endl;

    return 0;
}
