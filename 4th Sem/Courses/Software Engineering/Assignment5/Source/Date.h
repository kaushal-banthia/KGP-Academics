#ifndef _DATE_H
#define _DATE_H

// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date
{
    // Vector to store the month names
    static const vector<string> sMonthName;
    static const vector<int> sDaysInMonth;

    // Integers to store the day, month and year respectively
    const int d_, m_, y_;
    
    static const int sStartYear, sEndYear;

    // Store the formatted date
    const string date_;

    // Copy Assignment Operator
    Date& operator=(const Date& d);

    public:
    // Constructor
    Date(const int d, const int m, const int y);

    // Copy Constructor
    Date(const Date& d);

    static Date CreateDate(const int d, const int m, const int y);

    // Checks if the year is a leap year or not
    inline static bool IsLeap(int y)
    {
        if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400U == 0))
            return true;
        return false;
    }

    // Gets the number of day in a month (It considers leap years too!)
    inline static int GetDaysInMonth(int month, int year)
    {
        if (IsLeap(year) && month == 2)
            return 29;
        else 
            return sDaysInMonth[month];
    }

    // Getter function for getting the day
    inline int GetDay() const
    {
        return d_;
    }

    // Getter function for getting the month
    inline int GetMonth() const
    {
        return m_;
    }

    // Getter function for getting the year
    inline int GetYear() const
    {
        return y_;
    }

    vector<int> GetAge(const Date &d) const;

    // Destructor
    ~Date();

    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, Date d);

    // Static Unit Test Function for Date
    static void UnitTestDate();
};

#endif