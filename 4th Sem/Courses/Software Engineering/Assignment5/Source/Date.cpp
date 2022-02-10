#include "Date.h"
#include "Exceptions.h"

// Name: Kaushal Banthia
// Roll Number: 19CS10039

// Vector to store the month names
const vector<string> Date::sMonthName = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const vector<int> Date::sDaysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int Date::sStartYear = 1990;
const int Date::sEndYear = 2099;

// Constructor
Date::Date(const int d, const int m, const int y):
    d_(d), m_(m), y_(y), date_(to_string(d_) + '/' + sMonthName[m_-1] + '/' + to_string(y_))
{}

// Copy Constructor
Date::Date(const Date& d): d_(d.d_), m_(d.m_), y_(d.y_), date_(d.date_)
{}

Date Date::CreateDate(const int d, const int m, const int y)
{
    if (d < 1 || d > 31)
        throw DateOutOfBound();
    else if (m < 1 || m > 12)
        throw MonthOutOfBound();
    else if (y < sStartYear || y > sEndYear)
        throw YearOutOfBound();
    
    if (d > GetDaysInMonth(m ,y))
        throw DateDoesntExist();

    return Date(d, m, y);
}

// Copy Assignment Operator
Date& Date::operator=(const Date& d)
{
    return *this;
}

vector<int> Date::GetAge(const Date &d) const
{
    int current_date = d.GetDay();
    int current_month = d.GetMonth();
    int current_year = d.GetYear();;

    if (d_ > current_date) {
        current_date = current_date + Date::sDaysInMonth[m_];
        current_month = current_month - 1;
    }
    
    if (m_ > current_month) {
        current_year = current_year - 1;
        current_month = current_month + 12;
    }

    vector<int> diff;
    int calculated_date = current_date - d_;
    diff.push_back(calculated_date);
    int calculated_month = current_month - m_;
    diff.push_back(calculated_month);
    int calculated_year = current_year - y_;
    diff.push_back(calculated_year);

    return diff;
}

// Destructor
Date::~Date() {}

// Output Streaming Operator
ostream& operator<<(ostream &output, Date d)
{
    output<<d.date_<<endl;
    return output;
}