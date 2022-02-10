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

using namespace std;

class Passenger;

// Base Class Booking
class Booking
{
    // Static constants that are used for Fare calculation
    static const float sBaseFarePerKM, sACSurcharge, sLuxuryTaxPercent;

    // Static variable that stores the next PNR to be allotted
    static int sBookingPNRSerial;
    
    // Source and Destination
    const Station &fromStation_, &toStation_;

    // Date of travel
    const Date &date_;

    // Booking Class of travel
    const BookingClasses &bookingClass_;

    // Passenger who is travelling
    Passenger *passenger_;
    
    // Fare for the travel
    float fare_;

    // PNR of the travel
    int PNR_;

    // Booking Status of travel
    bool bookingStatus_ = true;

    // Message displayed on the for the status of the booking
    string bookingMessage_ = "BOOKING SUCCEEDED";
    
    //Copy Assignment Operator
    Booking& operator=(const Booking &b);
    
    public:
    // Static vector that stores the previous bookings
    static vector<Booking*> sBookings;

    // Constructor
    Booking(const Station fromStation, const Station toStation, const Date date, const BookingClasses& bookingClass, Passenger* passenger = NULL);
    
    // Copy Constructor
    Booking(const Booking& b);

    // Polymorphic function for computing the Fare of the travel
    virtual int ComputeFare();

    // Destructor for Booking
    virtual ~Booking();

    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, const Booking &b);

    // Static Unit Test Function for Booking
    static void UnitTestBooking();
};

#endif