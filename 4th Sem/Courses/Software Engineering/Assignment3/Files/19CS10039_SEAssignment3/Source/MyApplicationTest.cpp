#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"
#include "Passenger.h"

// Name: Kaushal Banthia
// Roll Number: 19CS10039

// Test application for booking
void MyApplicationTest()
{
    // Bookings by different booking classes
    // <BookingClasses>::Type() returns the constant object of the respective type
    Booking b1(Station("Mumbai"), Station("Bangalore"), Date(1, 4, 2001), ACFirstClass::Type());
    Booking b2(Station("Mumbai"), Station("Chennai"), Date(1, 4, 2001), ACFirstClass::Type());
    Booking b3(Station("Mumbai"), Station("Delhi"), Date(1, 4, 2001), ACFirstClass::Type());
    Booking b4(Station("Mumbai"), Station("Kolkata"), Date(1, 4, 2001), ACFirstClass::Type());
    Booking b5(Station("Delhi"), Station("Bangalore"), Date(1, 4, 2001), ACFirstClass::Type());
    Booking b6(Station("Delhi"), Station("Chennai"), Date(1, 4, 2001), ACFirstClass::Type());
    Booking b7(Station("Delhi"), Station("Kolkata"), Date(1, 4, 2001), ACFirstClass::Type());
    Booking b8(Station("Bangalore"), Station("Chennai"), Date(1, 4, 2001), ACFirstClass::Type());
    Booking b9(Station("Bangalore"), Station("Kolkata"), Date(1, 4, 2001), ACFirstClass::Type());
    Booking b10(Station("Chennai"), Station("Kolkata"), Date(1, 4, 2001), ACFirstClass::Type());
    
    // Output the bookings done where sBookings is the collection of bookings done
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it)
    {
        cout << *(*it);
    }

    cout<<endl<<"Number of Bookings done: "<<Booking::sBookings.size()<<endl;
}

int main()
{
    MyApplicationTest();
}