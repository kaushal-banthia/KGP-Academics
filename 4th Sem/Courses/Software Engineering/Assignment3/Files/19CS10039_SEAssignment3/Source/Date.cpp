#include "Date.h"

// Name: Kaushal Banthia
// Roll Number: 19CS10039

// Vector to store the month names
const vector<string> Date::sMonthName = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

// Constructor
Date::Date(const int d, const int m, const int y):
    d_(d), m_(m), y_(y), date_(to_string(d_) + '/' + sMonthName[m_-1] + '/' + to_string(y_))
{}

// Copy Constructor
Date::Date(const Date& d): d_(d.d_), m_(d.m_), y_(d.y_), date_(d.date_)
{}

// Copy Assignment Operator
Date& Date::operator=(const Date& d)
{
    return *this;
}

// Destructor
Date::~Date() {}

// Output Streaming Operator
ostream& operator<<(ostream &output, Date d)
{
    output<<d.date_<<endl;
    return output;
}