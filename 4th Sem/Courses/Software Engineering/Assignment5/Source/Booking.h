#ifndef _BOOKING_H
#define _BOOKING_H

// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include <iostream>
#include <string>
#include <vector>

#include "Station.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Passenger.h"
#include "Category.h"

using namespace std;

class Passenger;
class BookingCategory;

template<typename T>
class BookingTypes;

// Base Class Booking
class Booking
{
    
    //Copy Assignment Operator
    Booking& operator=(const Booking &b);

    protected:
        // Static constants that are used for Fare calculation
        static const float sBaseFarePerKM;

        // Static variable that stores the next PNR to be allotted
        static int sBookingPNRSerial;
        
        // Source and Destination
        const Station &fromStation_, &toStation_;

        const Date dateOfBooking_;
        const Date dateOfReservation_;

        // Booking Class of travel
        const BookingClasses &bookingClass_;

        // Passenger who is travelling
        const Passenger &passenger_;
        
        // Fare for the travel
        float fare_;

        // PNR of the travel
        int PNR_;

        // Booking Status of travel
        bool bookingStatus_;

        // Message displayed on the for the status of the booking
        string bookingMessage_;

        // Static vector that stores the previous bookings
        static vector<Booking*> sBookings;

        // Constructor
        Booking(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses& bookingClass);
        
        // Copy Constructor
        Booking(const Booking& b);

        // Polymorphic function for computing the Fare of the travel
        virtual int ComputeFare() const = 0;

        // Destructor for Booking
        virtual ~Booking();
        
    public:
        static void MakeReservation(const string &fromStation, const string &toStation, int d, int m, int y, const Passenger &passenger, const BookingClasses &bookingClass, const BookingCategory &bookingCategory);
        static void PrintAllBookings();

        typedef BookingTypes<Category::GeneralType> GeneralBooking;
        typedef BookingTypes<Category::LadiesType> LadiesBooking;
        typedef BookingTypes<Category::SeniorCitizenType> SeniorCitizenBooking;
        typedef BookingTypes<Category::DivyaangType> DivyaangBooking;
        typedef BookingTypes<Category::TatkalType> TatkalBooking;
        typedef BookingTypes<Category::PremiumTatkalType> PremiumTatkalBooking;

        // Output Streaming Operator
        friend ostream& operator<<(ostream &output, const Booking &b);

        // Static Unit Test Function for Booking
        static void UnitTestBooking();
};

template<typename T>
class BookingTypes : public Booking
{
    int ComputeFare() const;
    public:
        BookingTypes(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses &bookingClass, const string &category);
        ~BookingTypes();
};

// booking  types implementations
template<typename T> BookingTypes<T>::BookingTypes(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses &bookingClass, const string &category) : Booking(fromStation, toStation, dateOfBooking, dateOfReservation, passenger, bookingClass)
{
    bookingStatus_ = true;
    bookingMessage_ = category + " Booking Succeeded.";
    fare_ = ComputeFare();
}

template<typename T> BookingTypes<T>::~BookingTypes() {}

#endif
