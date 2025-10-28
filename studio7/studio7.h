/*
 *  Richard Meyer
 *
 *  studio7.h
 */
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

namespace enumerations {

enum class Weekday {
    sun,
    mon,
    tue,
    wed,
    thu,
    fri,
    sat,
};

enum class Pressure {
    lo, 
    med,
    hi,
    pop,
};

std::ostream& operator<<(std::ostream& os, Weekday& w);

Weekday& operator++(Weekday& w, int);

std::ostream& operator<<(std::ostream& os, Pressure& p);

Pressure& operator++(Pressure& p, int);

}
