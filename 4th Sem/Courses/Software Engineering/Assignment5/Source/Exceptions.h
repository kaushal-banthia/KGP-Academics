// Kaushal Banthia
// 19CS10039

#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H

#include <exception>
using namespace std;

class Bad_Booking : public exception
{
    public:  
        const char *what() const throw()
        {  
            return "Invalid booking.\n";  
        } 
};

class InvalidStation : public Bad_Booking
{
    public:  
        const char *what() const throw()
        {  
            return "Invalid station.\n";  
        }
};

class SameStations : public InvalidStation
{
    public:  
        const char *what() const throw()
        {  
            return "Both station can't be the same.\n";  
        }
};

class StationUnfound : public InvalidStation
{
    public:  
        const char *what() const throw()
        {  
            return "Station not found.\n";  
        }
};

class InvalidDate : public Bad_Booking
{
    public:  
        const char *what() const throw()
        {  
            return "Invalid date input in booking.\n";  
        }
};

class InvalidDOB : public InvalidDate
{
    public:  
        const char *what() const throw()
        {  
            return "Date of birth must be before the date of reservation.\n";  
        }
};

class InvalidDateOfBooking : public InvalidDate
{
    public:  
        const char *what() const throw()
        {  
            return "Booking date can't precede date of reservation and should be within one year from it.\n";  
        }
};

class TatkalInvalid : public InvalidDate
{
    public:  
        const char *what() const throw()
        {  
            return "Tatkal booking date is invalid.\n";  
        }
};

class IneligiblePassenger : public Bad_Booking
{
    public:  
        const char *what() const throw()
        {  
            return "Passenger is not eligible due to bad booking.\n";  
        }
};

class IneligibleForDivyaang : public IneligiblePassenger
{
    public:  
        const char *what() const throw()
        {  
            return "Passenger ineligible for travelling in the divyaang category.\n";  
        }
};

class IneligibleForSeniorCitizen : public IneligiblePassenger
{
    public:  
        const char *what() const throw()
        {  
            return "Passenger ineligible for travelling in the for senior citizen category.\n";  
        }
};

class IneligibleForLadies : public IneligiblePassenger
{
    public:  
        const char *what() const throw()
        {  
            return "Passenger ineligible for travelling in the for ladies category.\n";  
        }
};

class Bad_Date : public exception{
    public:  
        const char *what() const throw(){  
            return "Invalid date.\n";  
        } 
};

class YearOutOfBound : public Bad_Date{
    public:  
        const char *what() const throw(){  
            return "Year is required in 1900 to 2099.\n";  
        }
};

class MonthOutOfBound : public Bad_Date{
    public:  
        const char *what() const throw(){  
            return "Month is required in between 1 to 12.\n";  
        }
};

class DateOutOfBound : public Bad_Date{
    public:  
        const char *what() const throw(){  
            return "Date is required in between 1 to 31.\n";  
        }
};

class DateDoesntExist : public Bad_Date{
    public:  
        const char *what() const throw(){  
            return "No such date exists.\n";  
        }
};

class Bad_Passenger : public exception{
    public:  
        const char *what() const throw(){  
            return "Invalid passenger.\n";  
        } 
};

class InvalidName : public Bad_Passenger
{
    public:  
        const char *what() const throw(){  
            return "First and last name can't both be empty.\n";  
        }
};

class Invalid_Date_Of_Birth : public Bad_Passenger
{
    public:  
        const char *what() const throw(){  
            return "Invalid DOB.\n";  
        }
};

class InvalidAadharNumber : public Bad_Passenger
{
    public:  
        const char *what() const throw(){  
            return "Invalid aadhar number.\n";  
        }
};

class InvalidMobileNumber : public Bad_Passenger
{
    public:  
        const char *what() const throw(){  
            return "Invalid mobile number.\n";  
        }
};

class InvalidDisabilityID : public Bad_Passenger
{
    public:  
        const char *what() const throw(){  
            return "Invalid disability ID.\n";  
        }
};

#endif