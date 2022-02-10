// Name: Kaushal Banthia
// Roll Number: 19CS10039
#ifndef _STATION_H
#define _STATION_H

// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include <iostream>
#include <string>
class Railways;

using namespace std;

class Station
{
    // Name of the Station
    const string name_;

    // Copy Assignment Operator
    Station& operator=(const Station& s);

    public:
    // Constructor
    Station(const string name);

    // Copy Constructor
    Station(const Station& s);

    // Destructor
    ~Station();
    
    // Getter function for getting the Name of the Station
    inline string GetName() const
    {
        return name_;
    }

    // Function for finding out the distance between two Stations
    int GetDistance(const Station& s) const;

    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, Station s);

    // Static Unit Test Function for Station
    static void UnitTestStation();
};

#endif