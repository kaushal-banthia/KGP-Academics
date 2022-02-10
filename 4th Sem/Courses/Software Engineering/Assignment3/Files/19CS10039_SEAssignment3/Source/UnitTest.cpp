#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"
#include "Passenger.h"

// Name: Kaushal Banthia
// Roll Number: 19CS10039

// Unit Test Function for Station
void Station::UnitTestStation()
{
    Station to_("Mumbai");
    Station from_("Delhi");
    int distance_ = to_.GetDistance(from_);

    if (to_.name_ != "Mumbai")
        cout<<"Station Construction Error on Station(\"Mumbai\")"<<endl;
    if (from_.name_ != "Delhi")
        cout<<"Station Construction Error on Station(\"Delhi\")"<<endl;
    if (to_.GetName() != "Mumbai")
        cout<<"Station GetName Error on Station(\"Mumbai\").GetName()"<<endl;
    if (distance_ != 1447)
        cout<<"Station GetDistance Error on Station(\"Mumbai\").GetDistance(Station(\"Delhi\"))"<<endl;

    // Output Streaming Operator
    cout<<to_<<endl;
}

// Unit Test Function for Railway
void Railways::UnitTestRailways()
{
    const Railways &system1_ = Railways::IndianRailways();
    const Railways &system2_ = Railways::IndianRailways();
    int distance_ = system1_.GetDistance(Station("Mumbai"), Station("Delhi"));

    if (&system1_ != &system2_)
        cout<<"Railways construction error: Railways is not a Singleton class"<<endl;
    if (distance_ != 1447)
        cout<<"Railways GetDistance Error on Railways::IndianRailways().GetDistance(Station(\"Mumbai\").Station(\"Delhi\"))"<<endl;
    
    // Output Streaming Operator
    cout<<system1_<<endl;
}

// Unit Test Function for Date
void Date::UnitTestDate()
{
    Date newDate_(1, 2, 2012);

    if (newDate_.d_ != 1 || newDate_.m_ != 2 || newDate_.y_ != 2012)
        cout<<"Date Construction Error on Date(1, 2, 2012)"<<endl;
    
    // Output Streaming Operator
    cout<<newDate_<<endl;
}


// Unit Test Function for ACChairCar
void ACChairCar::UnitTestACChairCar()
{
    const BookingClasses &class1_ = ACChairCar::Type();
    const BookingClasses &class2_ = ACChairCar::Type();
    if (class1_.GetName() != "AC Chair Car" || class1_.IsAC() != true || class1_.IsLuxury() != false || class1_.GetLoadFactor() != 1.25)
        cout<<"BookingClasses Construction Error on ACChairCar::Type()"<<endl;
    if (&class1_ != &class2_)
        cout<<"ACChairCar construction error: ACChairCar is not a Singleton class"<<endl;

    // Output Streaming Operator
     cout<<endl<<class1_<<endl;
}

// Unit Test Function for SecondSitting
void SecondSitting::UnitTestSecondSitting()
{
    const BookingClasses &class1_ = SecondSitting::Type();
    const BookingClasses &class2_ = SecondSitting::Type();
    if (class1_.GetName() != "Second Sitting" || class1_.IsAC() != false || class1_.IsLuxury() != false || class1_.GetLoadFactor() != 0.5)
        cout<<"SecondSitting Construction Error on SecondSitting::Type()"<<endl;
    if (&class1_ != &class2_)
        cout<<"SecondSitting construction error: SecondSitting is not a Singleton class"<<endl;

    // Output Streaming Operator
     cout<<endl<<class1_<<endl;
}

// Unit Test Function for ACFirstClass
void ACFirstClass::UnitTestACFirstClass()
{
    const BookingClasses &class1_ = ACFirstClass::Type();
    const BookingClasses &class2_ = ACFirstClass::Type();
    if (class1_.GetName() != "AC First Class" || class1_.IsAC() != true || class1_.IsLuxury() != true || class1_.GetLoadFactor() != 3)
        cout<<"ACFirstClass Construction Error on ACFirstClass::Type()"<<endl;
    if (&class1_ != &class2_)
        cout<<"ACFirstClass construction error: ACFirstClass is not a Singleton class"<<endl;

    // Output Streaming Operator
     cout<<endl<<class1_<<endl;
}

// Unit Test Function for AC2Tier
void AC2Tier::UnitTestAC2Tier()
{
    const BookingClasses &class1_ = AC2Tier::Type();
    const BookingClasses &class2_ = AC2Tier::Type();
    if (class1_.GetName() != "AC 2 Tier" || class1_.IsAC() != true || class1_.IsLuxury() != false || class1_.GetLoadFactor() != 2)
        cout<<"AC2Tier Construction Error on AC2Tier::Type()"<<endl;
    if (&class1_ != &class2_)
        cout<<"AC2Tier construction error: AC2Tier is not a Singleton class"<<endl;

    // Output Streaming Operator
     cout<<endl<<class1_<<endl;
}

// Unit Test Function for FirstClass
void FirstClass::UnitTestFirstClass()
{
    const BookingClasses &class1_ = FirstClass::Type();
    const BookingClasses &class2_ = FirstClass::Type();
    if (class1_.GetName() != "First Class" || class1_.IsAC() != false || class1_.IsLuxury() != true || class1_.GetLoadFactor() != 2)
        cout<<"FirstClass Construction Error on FirstClass::Type()"<<endl;
    if (&class1_ != &class2_)
        cout<<"FirstClass construction error: FirstClass is not a Singleton class"<<endl;

    // Output Streaming Operator
     cout<<endl<<class1_<<endl;
}

// Unit Test Function for AC3Tier
void AC3Tier::UnitTestAC3Tier()
{
    const BookingClasses &class1_ = AC3Tier::Type();
    const BookingClasses &class2_ = AC3Tier::Type();
    if (class1_.GetName() != "AC 3 Tier" || class1_.IsAC() != true || class1_.IsLuxury() != false || class1_.GetLoadFactor() != 1.75)
        cout<<"AC3Tier Construction Error on AC3Tier::Type()"<<endl;
    if (&class1_ != &class2_)
        cout<<"AC3Tier construction error: AC3Tier is not a Singleton class"<<endl;

    // Output Streaming Operator
     cout<<endl<<class1_<<endl;
}

// Unit Test Function for Sleeper
void Sleeper::UnitTestSleeper()
{
    const BookingClasses &class1_ = Sleeper::Type();
    const BookingClasses &class2_ = Sleeper::Type();
    if (class1_.GetName() != "Sleeper" || class1_.IsAC() != false || class1_.IsLuxury() != false || class1_.GetLoadFactor() != 1)
        cout<<"Sleeper Construction Error on Sleeper::Type()"<<endl;
    if (&class1_ != &class2_)
        cout<<"Sleeper construction error: Sleeper is not a Singleton class"<<endl;

    // Output Streaming Operator
     cout<<endl<<class1_<<endl;
}

// Unit Test Function for Booking
void Booking::UnitTestBooking()
{
    Booking booking_(Station("Mumbai"), Station("Delhi"), Date(1, 2, 2012), ACFirstClass::Type());
    const BookingClasses &class_ = ACFirstClass::Type();
    if (booking_.fromStation_.GetName() != "Mumbai" || booking_.toStation_.GetName() != "Delhi" || booking_.date_.GetDay() != 1 || booking_.date_.GetMonth() != 2 || booking_.date_.GetYear() != 2012 || &(booking_.bookingClass_) != &class_)
        cout<<"Booking Construction Error on Booking(Station(\"Mumbai\"), Station(\"Delhi\"), Date(1, 2, 2012), ACFirstClass::Type())"<<endl;
    if (booking_.fare_ != 2776)
        cout<<"Booking Fare Calculation Error"<<endl;
    if (booking_.PNR_ != 1)
        cout<<"PNR Allocation Error"<<endl;
    
    // Output Streaming Operator
    cout<<booking_;
}

// Main Function
int main()
{
    Station::UnitTestStation();
    Railways::UnitTestRailways();
    Date::UnitTestDate();
    ACChairCar::UnitTestACChairCar();
    SecondSitting::UnitTestSecondSitting();
    ACFirstClass::UnitTestACFirstClass();
    AC2Tier::UnitTestAC2Tier();
    FirstClass::UnitTestFirstClass();
    AC3Tier::UnitTestAC3Tier();
    Sleeper::UnitTestSleeper();
    Booking::UnitTestBooking();
}