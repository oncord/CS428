/*
 *  Richard Meyer
 *
 *  main.cpp
 */

#include "studio4.h"
#include <iostream>

using namespace std;

const int SUCCESS = 0;

int main()
{
    Pressure p1 = Pressure::lo;
    Pressure p2 = Pressure::med;
    Weekday w1 = Weekday::mon;
    Weekday w2 = Weekday::tue;

    set<Weekday> workdays = {Weekday::mon, Weekday::tue, Weekday::wed, Weekday::thu, Weekday::fri};
    set<Weekday> weekend = {Weekday::fri, Weekday::sat, Weekday::sun};
    set<Weekday> combined;

    set_union(
        workdays.begin(), workdays.end(),
        weekend.begin(), weekend.end(),
        inserter(combined, combined.end())
    );

    for (Weekday day : combined)
    {
        cout << day << "\n";
    }

    /*
    cout << "Workdays:\n";
    for (Weekday day : workdays)
    {
        cout << day << "\n";
    }

    cout << "Weekend:\n";
    for (Weekday day : weekend)
    {
        cout << day << "\n";
    }
    */

    /*
    cout << p1++ << endl;

    cout << w1++ << endl;
    
    if (p1 < p2)
    {
        cout << p1 << "is less than " << p2 << endl;
    }

    if (w1 < w2)
    {
        cout << w1 << "is less than " << w2 << endl;
    }
    */

    return SUCCESS;
}
