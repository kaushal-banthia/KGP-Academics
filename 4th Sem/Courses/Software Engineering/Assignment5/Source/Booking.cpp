// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include "Booking.h"
#include "BookingClasses.h"
#include "Station.h"
#include "Date.h"
#include "Passenger.h"
#include "Railways.h"
#include "BookingCategory.h"
#include "Concession.h"

#include <cmath>

// Static constants that are used for Fare calculation
const float Booking::sBaseFarePerKM = 0.5;

// Static vector that stores the previous bookings
vector<Booking*> Booking::sBookings = {};

// Static variable that stores the next PNR to be allotted
int Booking::sBookingPNRSerial = 0;

// Constructor
Booking::Booking(const Station &fromStation, const Station &toStation, const Date &dateOfBooking, const Date &dateOfReservation, const Passenger &passenger, const BookingClasses& bookingClass):
    fromStation_(fromStation), toStation_(toStation), dateOfBooking_(dateOfBooking), dateOfReservation_(dateOfReservation), bookingClass_(bookingClass), passenger_(passenger)
{
    PNR_ = sBookingPNRSerial++;
}

// Copy Constructor
Booking::Booking(const Booking& b):
    fromStation_(b.fromStation_), toStation_(b.toStation_), dateOfBooking_(b.dateOfBooking_), dateOfReservation_(b.dateOfReservation_), bookingClass_(b.bookingClass_), passenger_(b.passenger_)
{}

// Copy Assignment Operator
Booking& Booking::operator=(const Booking& b)
{  
    return *this;
}

// Destructor for Booking
Booking::~Booking()
{}

void Booking::MakeReservation(const string &from, const string &to, int d, int m, int y, const Passenger &passenger, const BookingClasses &bookingClass, const BookingCategory &bookingCategory)
{
    try
    {
        const Station &fromStation = Railways::IndianRailways().GetStation(from);
        const Station &toStation = Railways::IndianRailways().GetStation(to);
        Date dateOfBooking(Date::CreateDate(d, m, y));
        Date dateOfReservation(Date::CreateDate(9, 4, 2021));

        if(fromStation.GetName() == toStation.GetName())
            throw SameStations();

        vector<int> diff = passenger.GetDOB().GetAge(dateOfReservation);
        if(diff[0] < 0 || diff[1] < 0|| diff[2] < 0) 
            throw InvalidDOB();
        
        vector<int> diffReservations = dateOfReservation.GetAge(dateOfBooking);
        if ((diffReservations[2]==1) && ((diffReservations[1]>0) || (diffReservations[0]>0)))
            throw InvalidDateOfBooking();
        if (diffReservations[0] < 0 || diffReservations[1] < 0 || diffReservations[2] < 0)
            throw InvalidDateOfBooking();

        bool eligible = bookingCategory.CheckEligibility(passenger); // check passenger eligibility in category
        if(eligible)
            sBookings.push_back(bookingCategory.MakeReservation(fromStation, toStation, dateOfBooking, dateOfReservation, passenger, bookingClass));
    }

    catch(const InvalidStation &error)
    {
        cout<<error.what()<<endl;
        throw InvalidStation();
    }

    catch(const Bad_Date &error)
    {
        cout<<error.what()<<endl;
        throw InvalidDate();
    }

    catch(const InvalidDate &error)
    {
        cout<<error.what()<<endl;
        throw InvalidDate();
    }

    catch(const IneligiblePassenger &error)
    {
        cout<<error.what()<<endl;
        throw IneligiblePassenger();
    }
}

void Booking::PrintAllBookings()
{
    for(vector<Booking *>::iterator it = Booking::sBookings.begin(); it != Booking::sBookings.end(); it++)
        cout<<*(*it);   
}

// Output Streaming Operator
ostream& operator<<(ostream &output, const Booking &b)
{
    output<<endl;
    output<<b.bookingMessage_<<endl;
    output<<"PNR Number = "<<b.PNR_<<endl;
    output<<"From Station = "<<b.fromStation_;
    output<<"To Station = "<<b.toStation_;
    output<<"Reservation Date = "<<b.dateOfReservation_;
    output<<"Travel Date = "<<b.dateOfBooking_;
    output<<"Travel Class = "<<b.bookingClass_.GetName()<<endl;
    output<<" : Mode: "<<(b.bookingClass_.IsSitting()?"Sitting":"Sleeping")<<endl;
    output<<" : Comfort: "<<(b.bookingClass_.IsAC()?"AC":"Non-AC")<<endl;
    output<<" : Bunks: "<<b.bookingClass_.GetNumberOfTier()<<endl;
    output<<" : Luxury: "<<(b.bookingClass_.IsLuxury()?"Yes":"No")<<endl;
    output<<"Fare = "<<b.fare_<<endl;
    output<<b.passenger_<<endl;
    output<<"Fare = "<<b.fare_<<'\n'<<endl;
    return output;
}

template<> int Booking::GeneralBooking::ComputeFare() const
{
    double fare = 0.0;
    int distance = fromStation_.GetDistance(toStation_);

    fare += distance * sBaseFarePerKM;
    fare *= bookingClass_.GetLoadFactor();

    fare -= fare * GeneralConcession::Type().GetConcessionFactor();

    fare += bookingClass_.GetReservationCharge();
    return static_cast<int>(round(fare));
}

template<> int Booking::LadiesBooking::ComputeFare() const
{
    double fare = 0.0;
    int distance = fromStation_.GetDistance(toStation_);

    fare += distance * sBaseFarePerKM;
    fare *= bookingClass_.GetLoadFactor();

    fare -= fare * LadiesConcession::Type().GetConcessionFactor(passenger_);

    fare += bookingClass_.GetReservationCharge();
    return static_cast<int>(round(fare));
}

template<> int Booking::SeniorCitizenBooking::ComputeFare() const
{
    double fare = 0.0;
    int distance = fromStation_.GetDistance(toStation_);

    fare += distance * sBaseFarePerKM;
    fare *= bookingClass_.GetLoadFactor();

    fare -= fare * SeniorCitizenConcession::Type().GetConcessionFactor(passenger_);

    fare += bookingClass_.GetReservationCharge();
    return static_cast<int>(round(fare));
}

template<> int Booking::DivyaangBooking::ComputeFare() const
{
    double fare = 0.0;
    int distance = fromStation_.GetDistance(toStation_);

    fare += distance * sBaseFarePerKM;
    fare *= bookingClass_.GetLoadFactor();

    fare -= fare * DivyaangConcession::Type().GetConcessionFactor(passenger_, bookingClass_);

    fare += bookingClass_.GetReservationCharge();
    return static_cast<int>(round(fare));
}

template<> int Booking::TatkalBooking::ComputeFare() const
{
    double fare = 0.0;
    int distance = fromStation_.GetDistance(toStation_);
    fare += distance * sBaseFarePerKM;
    fare *= bookingClass_.GetLoadFactor();

    double premium = 0.0;

    if(distance >= bookingClass_.GetMinimumTatkalDistance())
    {
        premium = max(fare*bookingClass_.GetTatkalLoadFactor(), bookingClass_.GetMinimumTatkalCharge());
        premium = min(premium, bookingClass_.GetMaximumTatkalCharge());
    }

    fare += premium;
    fare += bookingClass_.GetReservationCharge();
    return static_cast<int>(round(fare));
}

template<> int Booking::PremiumTatkalBooking::ComputeFare() const
{
    double fare = 0.0;
    int distance = fromStation_.GetDistance(toStation_);
    fare += distance * sBaseFarePerKM;
    fare *= bookingClass_.GetLoadFactor();

    double premium = 0.0;
    if(distance >= bookingClass_.GetMinimumTatkalDistance()){ 
        premium = max(fare*bookingClass_.GetTatkalLoadFactor(), bookingClass_.GetMinimumTatkalCharge());
        premium = min(premium, bookingClass_.GetMaximumTatkalCharge());
    }
    premium *= 2.0;

    fare += premium;
    fare += bookingClass_.GetReservationCharge();
    return static_cast<int>(round(fare));
}