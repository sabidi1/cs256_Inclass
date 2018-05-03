//
//  DayOfYear.cpp
//  DayOfTheYear
//
//  Created by Zeeshan Abidi on 5/3/18.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


//Day of the year class declaration
class DayOfYear
{
private:

public:
    void print(int);
};
static const int MonthDays[] = {31, 59, 90, 120, 151, 181, 212,
                                        243, 273, 304, 334, 365};

static const string MonthName[] = {"January", "February", "March", "April",
                                "May", "June", "July", "August", "September",
                                "October", "November", "December"};

//display month and day
void DayOfYear::print(int day)
{
    int month = 0;
    while (MonthDays[month] < day)
        month = (month + 1) %12;

    //Display month and day
    cout << MonthName[month] << " ";
    if(month == 0)
        cout << day;
    else
        cout << day - MonthDays[month-1];
}


int main()
{
    DayOfYear dYear;


    int day;

    //Ask user for input
    cout << "\nEnter a number between 1-365: ";
    cin >> day;

    //Check for invalid input
    if(day <= 0 || day > 365)
    {
        cout << "Error, invalid number" << endl;
    }

    //Send entered day number to the print() function
    dYear.print(day);
    return 0;

}
