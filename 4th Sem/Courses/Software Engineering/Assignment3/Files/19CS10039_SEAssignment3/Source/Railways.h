#ifndef _RAILWAYS_H
#define _RAILWAYS_H

// Name: Kaushal Banthia
// Roll Number: 19CS10039

#include <iostream>
#include <vector>
#include <map>
#include <string>

class Station;
using namespace std;

class Railways
{
    // Vector of all the Stations
    static const vector<string> sStations;

    // Map that stores the mutual distance between 2 stations
    static map<vector<string>, int> sDistStations;

    // Constructor
    Railways();
    
    // Copy Constructor
    Railways(const Railways &r);

    // Copy Assignment Operator
    Railways &operator=(const Railways &r);

    public:
    // Implementation for a singleton class
    static const Railways& IndianRailways();

    // Function to get distance between two cities
    int GetDistance(const Station& one, const Station& two) const;
    
    // Output Streaming Operator
    friend ostream& operator<<(ostream &output, const Railways &r);

    // Static Unit Test Function for Railways
    static void UnitTestRailways();
};

#endif