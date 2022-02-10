#include "Booking.h"
#include "BookingClasses.h"
#include "Station.h"
#include "Date.h"
#include "Passenger.h"
#include <cmath>

// Name: Kaushal Banthia
// Roll Number: 19CS10039

// Static constants that are used for Fare calculation
const float Booking::sBaseFarePerKM = 0.5, Booking::sACSurcharge = 50.0, Booking::sLuxuryTaxPercent = 0.25;

// Static vector that stores the previous bookings
vector<Booking*> Booking::sBookings = {};

// Static variable that stores the next PNR to be allotted
int Booking::sBookingPNRSerial = 0;

// Constructor
Booking::Booking(const Station fromStation, const Station toStation, const Date date, const BookingClasses& bookingClass, Passenger* passenger):
    fromStation_(fromStation), toStation_(toStation), date_(date), bookingClass_(const_cast<BookingClasses&>(bookingClass)), passenger_(passenger)
{
    fare_ = ComputeFare();
}

// Copy Constructor
Booking::Booking(const Booking& b):
    fromStation_(b.fromStation_), toStation_(b.toStation_), date_(b.date_), bookingClass_(b.bookingClass_), passenger_(b.passenger_)
{}

// Copy Assignment Operator
Booking& Booking::operator=(const Booking& b)
{  
    return *this;
}

// Destructor for Booking
Booking::~Booking()
{}

// Output Streaming Operator
ostream& operator<<(ostream &output, const Booking &b)
{
    output<<endl;
    output<<b.bookingMessage_<<endl;
    output<<"PNR Number = "<<b.PNR_<<endl;
    output<<"From Station = "<<b.fromStation_;
    output<<"To Station = "<<b.toStation_;
    output<<"Travel Date = "<<b.date_;
    output<<"Travel Class = "<<b.bookingClass_.GetName()<<endl;
    output<<" : Mode: "<<(b.bookingClass_.IsSitting()?"Sitting":"Sleeping")<<endl;
    output<<" : Comfort: "<<(b.bookingClass_.IsAC()?"AC":"Non-AC")<<endl;
    output<<" : Bunks: "<<b.bookingClass_.GetNumberOfTiers()<<endl;
    output<<" : Luxury: "<<(b.bookingClass_.IsLuxury()?"Yes":"No")<<endl;
    output<<"Fare = "<<b.fare_<<endl;
    
    return output;
}

// Polymorphic function for computing the Fare of the travel
int Booking::ComputeFare()
{
    float baseFare_ = sBaseFarePerKM * static_cast<float>(fromStation_.GetDistance(toStation_));
    float updatedFare_ = baseFare_ * bookingClass_.GetLoadFactor();
    updatedFare_ += (bookingClass_.IsAC()?sACSurcharge:0);
    updatedFare_ *= (bookingClass_.IsLuxury()?(1+sLuxuryTaxPercent):1);

    int finalFare_ = round(updatedFare_);
    PNR_ = ++(sBookingPNRSerial);
    sBookings.push_back(this);

    return finalFare_;
}