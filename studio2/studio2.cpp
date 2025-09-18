/*
 *  Richard Meyer
 *
 *  studio2.cpp
 */

#include "studio2.h"
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

Weekday& operator++(Weekday& w)
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
        case Weekday::sun:
            w = Weekday::mon;
            break;
    };

    return w;
}
