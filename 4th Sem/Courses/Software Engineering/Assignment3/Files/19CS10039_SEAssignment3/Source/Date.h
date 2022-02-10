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

    // Integers to store the day, month and year respectively
    const int d_, m_, y_;
    
    // Store the formatted date
    const string date_;

    // Copy Assignment Operator
    Date& operator=(const Date& d);

    public:
    // Constructor
    Date(const int d, const int m, const int y);

    // Copy Constructor
    Date(const Date& d);

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
    // Destructor
    ~Date();

    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, Date d);

    // Static Unit Test Function for Date
    static void UnitTestDate();
};

#endif