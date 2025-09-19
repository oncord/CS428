#include <iostream>

enum class Weekday {
    sun,
    mon,
    tue,
    wed,
    thu,
    fri,
    sat,
};

std::ostream& operator<<(std::ostream& os, Weekday& w);

Weekday& operator++(Weekday& w);

Pressure& operator++(Pressure& p, int);
