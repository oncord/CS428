/*
 *  Richard Meyer
 *
 *  main.cpp
 */
#include "studio7.h"
#include <iostream>

using enumerations::Weekday;
using enumerations::Pressure;

int main()
{
    Weekday w = Weekday::sun;
    Pressure p = Pressure::lo;

    for (w = Weekday::sun; w < Weekday::sat; w++)
    {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    for (p = Pressure::lo; p < Pressure::pop; p++)
    {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    return 0;
}
