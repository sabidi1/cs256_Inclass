//
//  DayofYearMod.cpp
//  DayOfTheYear
//
//  Created by Zeeshan Abidi on 5/3/18.
//

#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;

class DayOfYear
{
private:
    int day;
public:
    static int daysAtEndOfMonth[];
    static string monthName[];
    void print();
    void setDay(int day){
        this-> day = day;
    }

    DayOfYear* operator++(int);
    DayOfYear* operator--(int);
};

int DayOfYear::daysAtEndOfMonth[] = { 31, 59, 90, 120, 151, 181,
    212, 243, 273,304, 334, 365 };

string DayOfYear::monthName[]= { "January", "February",
    "March", "April", "May", "June","July", "August",
    "September", "October", "November", "December" };

// DayOfYear::print. *
// Convert and print day of year *
void DayOfYear::print()
{
    int month = 0;
    while (daysAtEndOfMonth[month] < day)           //d
        month = (month + 1) %12;

    if (month == 0)
        cout << "\nJanuary " << day << endl <<endl;
    else
    {
        cout << endl << monthName[month] << " "
        << day - daysAtEndOfMonth[month-1];
    }
}

DayOfYear* DayOfYear::operator++(int)
{
    day = (day++) %365;
    return this;
}

DayOfYear* DayOfYear::operator--(int)
{
    day = (day--) %365;
    return this;
}

int main()
{
    // Create an instance of the DayOfYear class
    DayOfYear dayOfYearObj;
    int day; // To hold the day

    // Get the day as input from the user.
    cout << "Enter a number between 1 and 365: ";
    cin >> day;

    dayOfYearObj.setDay(day);   //set the day
    dayOfYearObj.print();       //display object

    return 0;

}



