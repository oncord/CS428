/*
 *  Richard Meyer
 *
 *  studio2.cpp
 */

#include "studio4.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Weekday& w)
{
    switch (w)
    {
        case Weekday::sun:
            os << "Sunday" << " ";
            break;
        case Weekday::mon:
            os << "Monday" << " ";
            break;
        case Weekday::tue:
            os << "Tuesday" << " ";
            break;
        case Weekday::wed:
            os << "Wednesday" << " ";
            break;
        case Weekday::thu:
            os << "Thusday" << " ";
            break;
        case Weekday::fri:
            os << "Friday" << " ";
            break;
        case Weekday::sat:
            os << "Saturday" << " ";
            break;
        default:
            os << "Undefined" << " ";
            break;
    };

    return os;
}

Weekday& operator++(Weekday& w, int)
{
    switch (w)
    {
        case Weekday::sun:
            w = Weekday::mon;
            break;
        case Weekday::mon:
            w = Weekday::tue;
            break;
        case Weekday::tue:
            w = Weekday::wed;
            break;
        case Weekday::wed:
            w = Weekday::thu;
            break;
        case Weekday::thu:
            w = Weekday::fri;
            break;
        case Weekday::fri:
            w = Weekday::sat;
            break;
        case Weekday::sat:
            w=  Weekday::sun;
            break;
    };

    return w;
}

std::ostream& operator<<(std::ostream& os, Pressure& p)
{
    switch (p)
    {
        case Pressure::lo:
            os << "Low" << " ";
            break;
        case Pressure::med:
            os << "Medium" << " ";
            break;
        case Pressure::hi:
            os << "High" << " ";
            break;
        case Pressure::pop:
            os << "Pop" << " ";
            break;
    };

    return os;
}

Pressure& operator++(Pressure& p, int)
{
    switch (p)
    {
        case Pressure::lo:
            p = Pressure::med;
            break;
        case Pressure::med:
            p = Pressure::hi;
            break;
        case Pressure::hi:
            p = Pressure::pop;
            break;
        case Pressure::pop:
            break;
            
    };

    return p;
}
