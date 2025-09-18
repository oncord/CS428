#ifndef STUDIO1_H
#define STUDIO1_H

#include <ostream>
using std::ostream;

// forward declaration of class
template <typename T = int>
class S;

// forward declaration of operator<<
template <typename T>
ostream& operator<<(ostream& os, const S<T>& obj);

template <typename T>
class S {
private:
    T val;
public:
    S(T v); // constructor declaration
    
    //S(const S&) = delete;            // no copy constructor
    //S& operator=(const S&) = delete; // no copy assignment
    //~S() = delete;                   // no destructor

    friend ostream& operator<< <>(ostream& os, const S<T>& obj);
};

#include "studio1.cpp" // treat source file as template source

#endif // STUDIO1_H
